//---------------------------------------------------------------------------

#include <vcl.h>
#include "map.h"
#include <stdio.h>
#pragma hdrstop

#include "Unit10.h"
#include "Unit1.h"
#include "crc32.h"
#include "Unit12.h"
#include "napr.h"
#include "progutil.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDk *FormDk;

#pragma pack (1)

 struct {
    bool proj_load_succ; // ����� ��������� ��������
    bool prog_load_succ; //
 } LOAD_STATUS;
 //
 bool test_mode=false;
 ///
 #define MAX_ARGC  20
 AnsiString  argv[MAX_ARGC];
 int   argc;

  void Parse_Answer(AnsiString s, AnsiString sep);
  //
  using namespace std;
  //
  map<AnsiString,AnsiString> STATE_PAR;

  /*#define  PARAMS_N     20
  // �������� ���������� � �� ��������
  AnsiString state_params[PARAMS_N]={"PROGRAM=","PROG_FAZA=","SINGLE_FAZA=",
        "LEVEL=", "SPEC_PROG=", "RED=", "YEL=", "GREEN="};
  AnsiString  state_znach[PARAMS_N];*/
  //
  int was_read=0;
  int jor_size=0;

  //
  TPROJECT_DK PAP_RL;
  TPROGRAMS   PAPROGS_RL; //���������

  // ������ ������� � �������
  #define JORNAL_SIZE   1000
  // ������� �����
  int dump_start, dump_end;
  int dump_len;

  #define TRANSP_proj_flashwr     2
  #define TRANSP_pflashwr         1
  #define TRANSP_ERR              0

  int transp_type; //��� ����������

  void Read_Jornal();
  int  curr_ring=1;  //������������ ������
  ///
  bool boot_mode=false;
  bool upload_mode=false;

/*----------------------------------------------------------------------------*/
// ���������� ��� ������ "��������"
void Butt_load_State()
{
boot_mode = !boot_mode;
if (boot_mode)
    {
    FormDk->btnLoad->Caption = "������!!!";
    FormDk->btnUpLoad->Enabled = false;
    }
    else
    {
    FormDk->btnLoad->Caption = "��������� ������ � ��";
    FormDk->btnUpLoad->Enabled = true;
    }
}
//---------------------------------------------------------------------------
// ���������� ��� ������ "��������"
void Butt_upload_State()
{
    upload_mode = !upload_mode;
    if (upload_mode)
    {
    FormDk->btnUpLoad->Caption = "������!!!";
    FormDk->btnLoad->Enabled = false;
    }
    else
    {
    FormDk->btnUpLoad->Caption = "��������� ������ �� ��";
    FormDk->btnLoad->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void Status(const AnsiString s)
{
FormDk->edtLog->Text = s;
}
//---------------------------------------------------------------------------
// ��������� ����� "�������"
void Undo_See_OFF()
{
FormDk->Timer1->Enabled = false;
FormDk->btnLook->Down = false;
}
// ��������� ����� ����
void Undo_SURD_OFF()
{
FormDk->btnSurd->Down = false;
FormDk->tmrSURD->Enabled = false;
}
// ��������� ����� "�������" � ����� ����
void Undo_See_STATE()
{
Undo_See_OFF();
Undo_SURD_OFF();
}
//---------------------------------------------------------------------------
//
/*void Clear_Parsers()
{
for(int i_sp=0; i_sp<PARAMS_N; i_sp++)state_znach[i_sp]="";
}*/
//------------------------------------------------------------------------------
void Parse_Answer(AnsiString s, AnsiString sep)
{
    char* tk;
    //
    for (int i=0; i<MAX_ARGC; i++) argv[i]="";
    //
    tk = strtok(s.c_str(), sep.c_str());
    for (argc = 0; argc < MAX_ARGC - 1; ++argc)
    {
        if (tk == NULL)
            break;
        //
        argv[argc] = AnsiString(tk);
        //
        tk = strtok(NULL, sep.c_str());
    }
}
//---------------------------------------------------------------------------
// states - ������ ���������� ���� "����1=����1 ����2=����2 ..."
void Parse_States(AnsiString states)
{
AnsiString s_key, s_param;
Parse_Answer(states, " ");
//
for (int ip=0; ip<argc; ip++)
        {
        const int eqp = argv[ip].Pos("=");
        if (eqp){
                s_key = argv[ip].SubString(1,eqp-1);
                s_param = argv[ip].SubString(eqp+1, argv[ip].Length() - eqp);
                STATE_PAR[s_key]=s_param;
                }
        }
}
//------------------------------------------------------------------------------
// ��������
void Print_Channels(TMemo *mem, AnsiString s_chan)
{
        int i_len;
        AnsiString s;
        ///
        mem->Clear();
        i_len = s_chan.Length();
        if (i_len>8) i_len=8;
        //
        for (int i=0; i<i_len; i++)
        {
          s = IntToStr(i+1) + ". ";
          if (s_chan[i+1]=='1')
           s = s + "���";
          else
           s = s + "----";
          //
           mem->Lines->Add(s);

        }
}
//------------------------------------------------------------------------------

void Print_Lines()
{
        AnsiString s;
        FormDk->mmoRed->Clear();
        FormDk->mmoYellow->Clear();
        FormDk->mmoGreen->Clear();
        ///
        s = STATE_PAR["RED_CHANNEL"];
        if (s!=NULL)
          Print_Channels(FormDk->mmoRed, s);
        ///
        s = STATE_PAR["YEL_CHANNEL"];
        if (s!=NULL)
          Print_Channels(FormDk->mmoYellow, s);
        ///
        s = STATE_PAR["GREEN_CHANNEL"];
        if (s!=NULL)
          Print_Channels(FormDk->mmoGreen, s);
}
//------------------------------------------------------------------------------
void Print_Params()
{
AnsiString s,ss;
//
FormDk->pnlmodesurd->Caption = "";
FormDk->pnlstsurd->Caption = "";
FormDk->pnlphase->Caption = "";
FormDk->pnlStat->Caption = "";
FormDk->pnlsource->Caption = "";
FormDk->pnlTime->Caption = "";
FormDk->pnlnet->Caption = "";
FormDk->pnlQuality->Caption = "";
//
s = STATE_PAR["WORK"];
//
if (s=="PROGRAM"){
        FormDk->pnlmodesurd->Caption = "���������";
        // phase
        s = STATE_PAR["PROG_FAZA"];
        FormDk->pnlphase->Caption = s;
        }
//
if (s=="SINGLE_FAZA"){
        FormDk->pnlmodesurd->Caption = "��������� ����";
        s = STATE_PAR["SINGLE_FAZA"];
        FormDk->pnlphase->Caption = s;
        }
//
if (s=="SPEC_PROG"){
        FormDk->pnlmodesurd->Caption = "����. ���������";
        s = STATE_PAR["SPEC_PROG"];
        if (s=="FLASH") s="��";
        if (s=="OFF") s="��";
        if (s=="KK") s="KK";
        FormDk->pnlphase->Caption = s;
        }
//
ss="";
s = STATE_PAR["LEVEL"];
if (s=="ALARM")   ss = "������";
if (s=="TUMBLER") ss = "�������";
if (s=="SERVICE") ss = "������";
if (s=="VPU")     ss = "���";
if (s=="TVP")     ss = "���";
if (s=="PLAN")    ss = "����";
//output
FormDk->pnlsource->Caption = ss;
// ��������� ��
ss="";
s = STATE_PAR["STATUS"];
if (s=="OK") ss = "��������";
if (s=="NO") ss = "����������";
FormDk->pnlStat->Caption = ss;
// ������ ����
ss="";
s = STATE_PAR["SURD"];
if (s=="OK")  ss = "���� ��������";
if (s=="NO")  ss = "���� ����������";
FormDk->pnlstsurd->Caption = ss;
// ��������� ethernet
s = STATE_PAR["NET"];
if (s=="OK")  ss = "��� �� � ����";
if (s=="NO")  ss = "�� �� � ����";
FormDk->pnlnet->Caption = ss;
// �������� �����
s = STATE_PAR["QUAL"];
FormDk->pnlQuality->Caption = s+"%";
// ����� ��������� ���� ��� ����. �����
ss="";
//s = STATE_PAR["LEVEL"];
//if(s=="VPU"){
        //ss = "- (���:���)";
        //}else{
        s = STATE_PAR["TIME"];
        if(!s.IsEmpty()){
                const int Time = StrToInt(s);
                ss = DiagramPainter::retConvertToTime(Time)+" (���:���)";
                }
        //}
FormDk->pnlTime->Caption = ss;
}
//------------------------------------------------------------------------------
// ����� ���������� �� �������
void console_load(const AnsiString s)
{
FormDk->mmoConsole->Lines->Add(s);
}
//---------------------------------------------------------------------------
void cons_res(const AnsiString s)
{
FormDk->Memo3->Lines->Add(s);
}
//------------------------------------------------------------------------------
//��������� ��� ��������
int  Check_Transport_Type()
{
        bool   send_succ;
        //������� ������� ����� ��������
        for (int i=0; i<7; i++)
        {
             if ((!boot_mode) && (!upload_mode))
                return 0;
             send_succ = FormMain->Send_Data_UDP("proj_flashrd 0 0");
             ////
             Application->ProcessMessages();
             //
             if (send_succ)
             {
               //console_load("������� � " + IntToStr(i+1) + " - OK");
               //cons_res("����������. �� ������ > 1.0.3");
               return (TRANSP_proj_flashwr);
             }
             else
             {
              //console_load("������� � " + IntToStr(i+1) + " - ������");
              console_load(FormMain->retStrUDP());
             }
        }
        //cons_res("�������  �� ������ < 1.0.4");
        for (int i=0; i<7; i++)
        {
             send_succ = FormMain->Send_Data_UDP("pflashwr 0x1000 0 00");
             ////
             Application->ProcessMessages();
             //
             if (send_succ)
             {
               //console_load("������� � " + IntToStr(i+1) + " - OK");
               //cons_res("����������. �� ������ < 1.0.4");
               return (TRANSP_pflashwr);
             }
             else
             {
              //console_load("������� � " + IntToStr(i+1) + " - ������");
              //console_load(UDP_String);
             }
        }
        //
        cons_res("�� ���������� ������ ��!!!");
        return (TRANSP_ERR);
}
//---------------------------------------------------------------------------
// ��������� ������ � ����������
void Load_Proj(int i_dk)
{
int i_succ=0;
TPROJECT_DK  PAP_L;
TPROGRAMS    PAPROGS_L;
// ���� ������
FormMain->makeProject(i_dk);
// �������� ������
TDateDk dateDk(&PAP_RINGS[i_dk]); // ������ ��� ������ �����������
const int crDk = FormDk->cbbDk->ItemIndex;
const TPROJECT_DK *pDk = dateDk.retDatePrj(crDk);
if(pDk==0)return; // ������ ���� ����������
memcpy(&PAP_L,pDk,sizeof(TPROJECT_DK));
memcpy(&PAPROGS_L,&PAPROGS_RINGS[i_dk], sizeof(PAPROGS_L));
//������� �������
PAP_L.ProjectSize = sizeof(TPROJECT_DK);
PAPROGS_L.ProgramsSize = sizeof(TPROGRAMS);
PAP_L.CRC32_IDP = PAP_RINGS[i_dk].CRC32; // CRC ��� ������ ��
//����������� �����
PAPROGS_L.CRC32 = crc32_calc((unsigned char*)&PAPROGS_L,sizeof(PAPROGS_L)-sizeof(PAPROGS_L.CRC32));
PAP_L.CRC32_programs = PAPROGS_L.CRC32;
PAP_L.CRC32 = crc32_calc((unsigned char*)&PAP_L,sizeof(PAP_L)-sizeof(PAP_L.CRC32));
//
int i_addr, i_len;
unsigned char *p_p;
unsigned char buf[2*PACK_LEN];
AnsiString s,ss;
bool   send_succ;
// ���������� ������ ��������
LOAD_STATUS.proj_load_succ = false;
LOAD_STATUS.prog_load_succ = false;
// ������ ������
// ���-�� �������
int pacs_full = sizeof(TPROJECT_DK)/PACK_LEN;
if(sizeof(TPROJECT_DK) % PACK_LEN)
        pacs_full++;
//
i_len=PACK_LEN;
i_addr=0;
int i_addr_offs = sizeof(TPROJECT_DK)*i_dk;
//
p_p =(unsigned char *) &PAP_L;
for (int i_p=0; i_p<pacs_full; i_p++)
        {
           if ((sizeof(TPROJECT_DK)-i_addr)>PACK_LEN )
              i_len= PACK_LEN;
           else
              i_len = (sizeof(TPROJECT_DK)-i_addr);
           //
           BinToHex(p_p,buf,i_len);
           s = AnsiString((const char*)buf,2*i_len);
           console_load("����� �=" + IntToStr(i_p+1));
           // tryes
           for (int i=0; i<7; i++)
           {
             if (!boot_mode)
                return;
             FormMain->clearStrUDP();
             /////////////////
             if (transp_type==TRANSP_pflashwr)
             send_succ = FormMain->Send_Data_UDP("pflashwr " + IntToHex(4096 + i_addr,4) + " "  +
                                       IntToStr(i_len) + " " + s );
             //////////////////
             if (transp_type==TRANSP_proj_flashwr)
             send_succ = FormMain->Send_Data_UDP("proj_flashwr " + IntToHex(i_addr+i_addr_offs,4) + " "
                      + IntToStr(i_len) + " " + s );
             //////////////////
             Application->ProcessMessages();
             //
             if (send_succ)
             {
               console_load("������� � " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
             {
              console_load("������� � " + IntToStr(i+1) + " - ������");
              //console_load(FormMain->retStrUDP());
             }
           }
           //////
           if (send_succ)
             i_succ++;
           else
           {
            i_succ--;
             break; //loading
           }
           ///////
           p_p = p_p + PACK_LEN;
           i_addr+=PACK_LEN;
        }
        //
        if (i_succ==pacs_full)
        {
          LOAD_STATUS.proj_load_succ=true;
           //cons_res("������ ������� ��������!");
        }
        else
        {
           //MessageDlg("������ �� ��������!",mtError, mbOKCancel,0);
           return;
        }
        // ������ ���������
        // ���-�� ������ �������
        PAPROGS_L.ProgramsSize = sizeof(TPROGRAMS);
        pacs_full = sizeof(TPROGRAMS) / PACK_LEN;
        if (sizeof(TPROGRAMS) % PACK_LEN)
           pacs_full++;
        //
        i_len=PACK_LEN;
        i_addr=0;
        i_addr_offs = sizeof(TPROGRAMS)*i_dk;
        i_succ=0;
        //
        p_p =(unsigned char *) &PAPROGS_L;
        for (int i_p=0; i_p<pacs_full; i_p++)
        {

           if ( (sizeof(TPROGRAMS)-i_addr)>PACK_LEN )
              i_len= PACK_LEN;
           else
              i_len = (sizeof(TPROGRAMS)-i_addr);
           //
           BinToHex(p_p,buf,i_len);
           s = AnsiString((const char*)buf,2*i_len);
           console_load("����� �=" + IntToStr(i_p+1));
           //tryes
           for (int i=0; i<5; i++)
           {
              //
              if (!boot_mode)
                return;
              //
             if (transp_type==TRANSP_pflashwr)
             {
               ss = "pflashwr " + IntToHex(208896 + i_addr,4) + " "  +
                    IntToStr(i_len) + " " + s ;

                send_succ = FormMain->Send_Data_UDP(ss );
             }
             //////////////////
             if (transp_type==TRANSP_proj_flashwr)
             {
                ss = "progs_flashwr " + IntToHex(i_addr+i_addr_offs,4) + " " +  IntToStr(i_len)
                     + " " + s ;
                 //
                 send_succ = FormMain->Send_Data_UDP(ss );

             }
             //////////////////
              //send_succ = Send_Data_UDP(ss);
             //
             Application->ProcessMessages();
             //
             if (send_succ)
             {
               console_load("������� � " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
              console_load("������� � " + IntToStr(i+1) + " - ������");
           }
           //////
           if (send_succ)
             i_succ++;
           else
           {
            i_succ--;
             break;  //loading
           }
           ///
           p_p = p_p + PACK_LEN;
           i_addr+=PACK_LEN;
        }
//
if (i_succ==pacs_full){
        LOAD_STATUS.prog_load_succ=true;
        }
        else{}
}
//---------------------------------------------------------------------------
// ��������� ������ �� ������ i_dk � ����������
void Load_Empty_Proj(int i_dk)
{
        int i_succ=0;
        int i_addr, i_len;
        unsigned char *p_p;
        unsigned char buf_zero[PACK_LEN];
        unsigned char buf[2*PACK_LEN];
        AnsiString s,ss;
        bool   send_succ;
        //////////////////////
        //////////////////////
        LOAD_STATUS.proj_load_succ = false;
        LOAD_STATUS.prog_load_succ = false;
        ////////////////////////
           i_len = PACK_LEN;
           memset(buf_zero, 0, PACK_LEN);
           BinToHex(buf_zero,buf,i_len);
           s = AnsiString((const char*)buf,2*i_len);
           i_succ=0;
           // tryes
           i_addr = sizeof(TPROJECT)*i_dk;
           for (int i=0; i<7; i++)
           {
             if (transp_type==TRANSP_proj_flashwr)
             send_succ = FormMain->Send_Data_UDP("proj_flashwr " + IntToHex(i_addr,4) + " "
                      + IntToStr(i_len) + " " + s );

             //////////////////
             Application->ProcessMessages();
             //
             if (send_succ)
             {
               console_load("������� � " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
             {
              console_load("������� � " + IntToStr(i+1) + " - ������");
              console_load(FormMain->retStrUDP());
             }
           }
           //
           LOAD_STATUS.proj_load_succ=send_succ;
           //cons_res("������ ������� ��������!");
        ////////////////////////////////
        //////////////////////////////
        ///////////////////////////
           ///tryes
           i_addr = sizeof(TPROGRAMS)*i_dk;
           for (int i=0; i<5; i++)
           {
              ss = "progs_flashwr " + IntToHex(i_addr,4) + " " +  IntToStr(i_len)
                   + " " + s ;
              //
              send_succ = FormMain->Send_Data_UDP(ss );
              Application->ProcessMessages();
             //
             if (send_succ)
             {
               console_load("������� � " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
              console_load("������� � " + IntToStr(i+1) + " - ������");
           }

        ///
        ////
           LOAD_STATUS.prog_load_succ=true;

        ///
}
//---------------------------------------------------------------------------
// ��������!!!!!
void ReLoad_Proj(int i_dk)
{
        int is,i_succ=0;
        int i_addr, i_len;
        unsigned char *p_p;
        unsigned char buf[2*PACK_LEN];
        AnsiString s,ss;
        bool   send_succ;
        //char   *proj_reload;
        //////////////////////
        //////////////////////
        LOAD_STATUS.proj_load_succ = false;
        LOAD_STATUS.prog_load_succ = false;
        ////////////////////////

        // ������ ������
        // ���-�� ������ �������
        int pacs_full = sizeof(TPROJECT_DK) / PACK_LEN;
        if (sizeof(TPROJECT_DK) % PACK_LEN)
           pacs_full++;
        //
        i_len=PACK_LEN;
        i_addr=0;
        int i_addr_offs = sizeof(TPROJECT_DK)*i_dk;
        /////
        //cons_res("��������� ������. ������ ������=" + IntToStr(sizeof(TPROJECT)));
        //cons_res("������� = " + IntToStr(pacs_full));
        //
        p_p =(char *) &PAP_RL;
        for (int i_p=0; i_p<pacs_full; i_p++)
        {

           if ( (sizeof(TPROJECT_DK)-i_addr)>PACK_LEN )
              i_len= PACK_LEN;
           else
              i_len = (sizeof(TPROJECT_DK)-i_addr);
           //
           //BinToHex(p_p,buf,i_len);
           //s = AnsiString((const char*)buf,2*i_len);
           console_load("����� �=" + IntToStr(i_p+1));
           // tryes
           for (int i=0; i<7; i++)
           {
             if (!upload_mode)
                return;

             if (transp_type==TRANSP_pflashwr)
             {
                send_succ = FormMain->Send_Data_UDP("flashrd " + IntToHex(4096 + i_addr,4) + " "  +
                                       IntToStr(i_len));
             }
             //
             if (transp_type==TRANSP_proj_flashwr)
             {
                send_succ = FormMain->Send_Data_UDP("proj_flashrd " + IntToHex(i_addr + i_addr_offs,4) + " "  +
                                       IntToStr(i_len));

             }
             ////
             Application->ProcessMessages();
             //
             if (send_succ)
             {
                is = FormMain->retStrUDP().Length();
                if (is==2*i_len)
                {
                   console_load("������� � " + IntToStr(i+1) + " - OK");
                   //
                   HexToBin(FormMain->retStrUDP().c_str(),p_p,i_len);
                   //
                   break; //tryes
                }
             }
             else
              console_load("������� � " + IntToStr(i+1) + " - ������");
           }
           //////
           if (send_succ)
             i_succ++;
           else
           {
            i_succ--;
             break; //loading
           }
           ///////

           p_p = p_p + PACK_LEN;
           i_addr+=PACK_LEN;
        }
        //
        if (i_succ==pacs_full)
        {
          LOAD_STATUS.proj_load_succ=true;
           //cons_res("������ ������� ��������!");
        }
        else
        {
           //MessageDlg("������ �� ��������!",mtError, mbOKCancel,0);
           return;
        }
        ////////////////////////////////
        //////////////////////////////
        ///////////////////////////
        // ������ ���������
        // ���-�� ������ �������
        pacs_full = sizeof(TPROGRAMS) / PACK_LEN;
        if (sizeof(TPROGRAMS) % PACK_LEN)
           pacs_full++;
        //
        i_len=PACK_LEN;
        i_addr=0;
        i_addr_offs = sizeof(TPROGRAMS)*i_dk;
        i_succ=0;
        //
        //cons_res("��������� ���������. ������ ������=" + IntToStr(sizeof(TPROGRAMS)));
        //cons_res("������� = " + IntToStr(pacs_full));
        //
        p_p =(unsigned char *) &PAPROGS_RL;
        for (int i_p=0; i_p<pacs_full; i_p++)
        {
           if (!upload_mode)
                return;
           ////
           if ( (sizeof(TPROGRAMS)-i_addr)>PACK_LEN )
              i_len= PACK_LEN;
           else
              i_len = (sizeof(TPROGRAMS)-i_addr);
           //
           //BinToHex(p_p,buf,i_len);
           //s = AnsiString((const char*)buf,2*i_len);
           console_load("����� �=" + IntToStr(i_p+1));
           ///tryes
           for (int i=0; i<5; i++)
           {

             if (!upload_mode)
                return;
             //
             if (transp_type==TRANSP_pflashwr)
             {
                ss = "flashrd " + IntToHex(208896 + i_addr,4) + " "  +
                    IntToStr(i_len);
                send_succ = FormMain->Send_Data_UDP(ss);
             }
             //
             if (transp_type==TRANSP_proj_flashwr)
             {
                send_succ = FormMain->Send_Data_UDP("progs_flashrd " + IntToHex(i_addr + i_addr_offs,4) + " "  +
                                       IntToStr(i_len));

             }
             //
             Application->ProcessMessages();
             //
             if (send_succ)
             {
               is = FormMain->retStrUDP().Length();
                if (is==2*i_len)
                {
                   console_load("������� � " + IntToStr(i+1) + " - OK");
                   //
                   HexToBin(FormMain->retStrUDP().c_str(),p_p,i_len);
                   break; //tryes
                }
             }
             else
              console_load("������� � " + IntToStr(i+1) + " - ������");
           }
           //////
           if (send_succ)
             i_succ++;
           else
           {
            i_succ--;
             break;  //loading
           }
           ///
           p_p = p_p + PACK_LEN;
           i_addr+=PACK_LEN;
        }
        ///
        ////
         if (i_succ==pacs_full)
         {
           LOAD_STATUS.prog_load_succ=true;
           //cons_res("��������� ������� ���������!");
        }
        else
        {
           //cons_res("��������� �� ���������!");
        }
        ////
        /*
        if (i_succ==pacs_full)
           MessageDlg("������ ������� ��������!",mtInformation, mbOKCancel,0);
        else
           MessageDlg("������ �� ��������!",mtError, mbOKCancel,0);
        */
        ///
        //Application->MessageBoxA("","",1);
}
//---------------------------------------------------------------------------
__fastcall TFormDk::TFormDk(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFormDk::btnExitClick(TObject *Sender)
{
Undo_See_STATE();
FormDk->Visible = false;
}
//---------------------------------------------------------------------------
// ��������� ������
void __fastcall TFormDk::btnLoadClick(TObject *Sender)
{
//DEBUD
//Load_Proj(0);
//DEBUD
AnsiString s;
bool check_confl=false;
// �������� ����������� �� ������
if (boot_mode){
        Butt_load_State();
        FormDk->Memo3->Lines->Add("�������� ��������!");
        return;
        }
Butt_load_State();
//
for (int i_ring=0; i_ring<FormMain->retVIS()->count_dk; i_ring++)
        {
        check_confl = FormMain->Check_Confl_In_Sh_Faze(&PAP);
        if (check_confl)break;
        }
//
if (check_confl){
        MessageBox(0,"������ �������: ������� ���������� �� ������������� �������� ���",
                  "��������!", MB_YESNO);
        return;
        }
//
FormDk->Memo3->Clear();
Undo_See_STATE();
//
transp_type = Check_Transport_Type();
if(transp_type == TRANSP_ERR){
        FormDk->Memo3->Lines->Add("�� �� ��������!");
        return;
        }
//
int ring_loaded=0;
// get ver - ��������� ������ � �������
bool send_succ = FormMain->Send_Data_UDP("get ver" );
int load_dk_n=1;
if (send_succ)
      load_dk_n = N_DK;
//
if (send_succ==false){
        int i = MessageBox(0,"�� �������������� ������. ������ 1 ������?",
                  "������ ������ 1.1.0 !", MB_YESNO);
        if(i!=6)
                return;
        }
// ������� �������� ���������
for (int i=0; i < load_dk_n; i++)
  {
      ///
      if (i<FormMain->retVIS()->count_dk)
      {
        FormDk->Memo3->Lines->Add("��������� ������: " + IntToStr(i+1) );
        Load_Proj(i);// �������� �������
        if (LOAD_STATUS.proj_load_succ)
                s = "������ ������� ��������!";
                else
                s = "������ �� ��������!";
        FormDk->Memo3->Lines->Add(s);
        //
        if (LOAD_STATUS.prog_load_succ)
                s = "��������� ������� ���������!";
                else
                s = "��������� �� ���������!";
        FormDk->Memo3->Lines->Add(s);
        //
      }
      else
      {
        FormDk->Memo3->Lines->Add("�������: " + IntToStr(i+1) );
        Load_Empty_Proj(i);
      }
      //
      Application->ProcessMessages();
      //
    if (LOAD_STATUS.proj_load_succ && LOAD_STATUS.prog_load_succ){
        //FormDk->Memo3->Lines->Add("������ ���������!");
        ring_loaded++;
        }else{
        //  FormDk->Memo3->Lines->Add("������ �� ���������!");
        break;
        }
  //
  FormDk->Memo3->Lines->Add("---------------------------------");
  }
//
if (ring_loaded==N_DK){
        FormDk->Memo3->Lines->Add("�� ���������!");
        }else{
        FormDk->Memo3->Lines->Add("������!");
        }
// ������� �� �������
if (boot_mode)
    Butt_load_State();
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::FormCreate(TObject *Sender)
{
for(int i=0; i<MaxMULBlocks; i++)
        {
        FormDk->ListBox1->Items->Add(IntToStr(i+1));
        }
FormDk->mmoRed->Clear();
FormDk->mmoYellow->Clear();
FormDk->mmoGreen->Clear();
//
FormDk->ListBox1->ItemIndex=0;
FormDk->ListBox2->ItemIndex=0;
//
//FormDk->StringGridJor->ColCount=4;
FormDk->StringGridJor->Cells[0][0] = "�";
FormDk->StringGridJor->Cells[1][0] = "   ����     �����    �������";
                                      //26.07.2015- 18:00:20
/*FormDk->StringGridJor->Cells[2][0] = "�����";
FormDk->StringGridJor->Cells[3][0] = "�������";
FormDk->StringGridJor->ColWidths[0] = 50;
FormDk->StringGridJor->ColWidths[1] = 200;
FormDk->StringGridJor->ColWidths[2] = 150;
FormDk->StringGridJor->ColWidths[3] = 150;*/
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnTestOnClick(TObject *Sender)
{
Undo_See_STATE();
bool send_succ = FormMain->Send_Packet_UDP("set test on",5);

if (send_succ){
        FormDk->Edit2->Text = "���� ����� ���.";
        test_mode = true;
        // set rele
        bool send_succ = FormMain->Send_Packet_UDP("set rele on",3);
        if(!send_succ){
                FormDk->Edit2->Text = "���� ����� ����";
                test_mode = false;
                FormDk->btnTestOn->Down = false;
                FormDk->btnTestOff->Down = true;
                }
        }else{
        FormDk->Edit2->Text = "���";
        test_mode = false;
        FormDk->btnTestOn->Down = false;
        FormDk->btnTestOff->Down = true;
        }
}
//------------------------------------------------------------------------------
void __fastcall TFormDk::btnTestOffClick(TObject *Sender)
{
// ��������� �������
bool send_succ = FormMain->Send_Packet_UDP("set test off",5);

if (send_succ){
        FormDk->Edit2->Text = "���� ����.";
        test_mode = false;
        FormDk->btnTestOn->Down = false;
        FormDk->btnTestOff->Down = false;
        }else{
        FormDk->btnTestOn->Down = false;
        FormDk->btnTestOff->Down = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormDk::btnChannelOnClick(TObject *Sender)
{
    AnsiString s, sc,sp;
    int  chan = FormDk->ListBox1->ItemIndex;
    int col = FormDk->ListBox2->ItemIndex;
    bool send_succ;
    //
    if (!test_mode)
        goto err;
    //
    FormDk->Memo2->Clear();
    //
    if (col==0) {sc = "r"; sp="�"; }
    if (col==1) {sc = "y";sp="�";}
    if (col==2) {sc = "g";sp="�";}
    //
    s = "channel " + IntToStr(chan+1) + " " + sc + " on";
    send_succ = FormMain->Send_Packet_UDP(s,5);
    //
    if (send_succ)
    {
        FormDk->Memo2->Lines->Add("����� " + IntToStr(chan+1) + " " + sp);
        FormDk->Memo2->Lines->Add("���!");
        ::Sleep(100);
        if (col==0)
        {
            // ����� ����������
            ::Sleep(1000);
            s = "get lineADC";
            send_succ = FormMain->Send_Packet_UDP(s,5);
            if (send_succ)
            {
                Parse_Answer(FormMain->retStrUDP(), " ");
                AnsiString s_res;
                if (argv[chan].Pos("1"))
                  s_res = "��� ����.";
                else
                  s_res = "���� ���.";
                FormDk->Memo2->Lines->Add(s_res);
            }
        }
        //
        if (col==2)
        {
            // ����� ����
            s = "get linePWM";
            ::Sleep(1000);
            send_succ = FormMain->Send_Packet_UDP(s,5);
            if (send_succ)
            {
                Parse_Answer(FormMain->retStrUDP(), " ");
                AnsiString s_res;
                if (argv[chan].Pos("1"))
                  s_res = "���������� ����.";
                else
                  s_res = "���������� ���.";
                FormDk->Memo2->Lines->Add(s_res);
            }
        }
    }
err:
}
//---------------------------------------------------------------------------

void __fastcall TFormDk::btnChannelOffClick(TObject *Sender)
{
    AnsiString s, sc, sp;
    int  chan = FormDk->ListBox1->ItemIndex;
    int col = FormDk->ListBox2->ItemIndex;

    if (col==0) {sc = "r"; sp="�"; }
    if (col==1) {sc = "y";sp="�";}
    if (col==2) {sc = "g";sp="�";}
    //
    s = "channel " + IntToStr(chan+1) + " " + sc + " off";
    const bool sendOk = FormMain->Send_Packet_UDP(s,5);
    //
    if (sendOk)
    {
    FormDk->Memo2->Clear();
    FormDk->Memo2->Lines->Add("����!");
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::Timer1Timer(TObject *Sender)
{
AnsiString s, sc;
bool send_succ;
//
FormDk->Timer1->Enabled  =false;
//
//Clear_Parsers();
STATE_PAR.clear();
//
s = "get state " + IntToStr(curr_ring);
send_succ = FormMain->Send_Packet_UDP(s,1);
//
if (send_succ){
        Parse_States(FormMain->retStrUDP());
        }
// �����
s = "get lines";
send_succ = FormMain->Send_Packet_UDP(s,1);
//
if (send_succ){
        Parse_States(FormMain->retStrUDP());
        Print_Params();
        Print_Lines();
        }
FormDk->Timer1->Enabled  =true;
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnLookClick(TObject *Sender)
{
Undo_SURD_OFF();
FormDk->Timer1->Enabled = FormDk->btnLook->Down;
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnDumpClick(TObject *Sender)
{
        AnsiString s;
        int i_size;
        bool send_succ;
        //
        Undo_See_STATE();
        //
        FormDk->ProgressBar1->Position = 0;
        //Form10->Button6->Enabled = false;
        Status("");
        was_read=0;
        /////////////
        if (!TryStrToInt(FormDk->Edit4->Text,dump_start))
        {
          Status("������������ �����!!");
          return;
        }
        //
        if (!TryStrToInt(FormDk->Edit5->Text,dump_end))
        {
          Status("������������ �����!!");
          return;
        }
        //
        dump_len = dump_end - dump_start +1 ;
        //
        if (dump_len<1)
        {
          Status("������������ �����!!");
          return;
        }
        ////
        ////
        FormDk->StringGridJor->RowCount = (dump_len)+1;
        //
        for (int i=1; i< FormDk->StringGridJor->RowCount-1; i++)
        {
          FormDk->StringGridJor->Cells[0][i] = "";
          FormDk->StringGridJor->Cells[1][i] = "";

        }
        //
        FormDk->Timer3->Enabled = true;
}
//---------------------------------------------------------------------------
// ��������
void __fastcall TFormDk::btnCleanClick(TObject *Sender)
{
        AnsiString s;
        bool send_succ;
        //
        int btn=mrNone;
        TMsgDlgButtons  butts;
        //
        btn = MessageBox(0,"�������� �������!!! ����������?","��������",
          MB_YESNO);
        //
        if (btn!=6)
          return;
        //
        s = "event erase";
        send_succ = FormMain->Send_Packet_UDP(s,2);
           //
           if (send_succ)
           {
           Status("������� - ��!");
           Read_Jornal();
           }
           else
           {
           Status("������!!");
           }
}
//---------------------------------------------------------------------------
// ������� �����
void __fastcall TFormDk::FormClose(TObject *Sender, TCloseAction &Action)
{
Undo_See_STATE();
}
//---------------------------------------------------------------------------
// �������� �����
void __fastcall TFormDk::FormHide(TObject *Sender)
{
FormDk->Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
// ������������� �������
void __fastcall TFormDk::btnTimeSynClick(TObject *Sender)
{

       AnsiString s;
        bool send_succ;
        TDateTime now = Now();
        //
        Undo_See_STATE();
        //FormatDateTime('dd/mm/yy', myDate)
        //s = "set ds1390_time " + DateToStr(now) + "-" + TimeToStr(now);
        s = "set ds1390_time " + FormatDateTime("dd.mm.yyyy", now) + "-" +
             FormatDateTime("hh:mm:ss", now);
        FormConsole->mmoOut->Lines->Add(s);
        send_succ = FormMain->Send_Packet_UDP(s,1);
        //
        if (send_succ)
           {
           Status("����� �����������!!!");
           }
           else
           {
           Status("������!!!!. ����� �� �����������!!!!1");
           }
}
// �� ���� ��
void __fastcall TFormDk::btnSyncAllDkClick(TObject *Sender)
{
AnsiString ds = "���������� ����� ��� �� ����?\n";
if (Application->MessageBox(ds.c_str(),
        "������� ����� ��",
        MB_YESNO +MB_TOPMOST+ MB_ICONQUESTION)==IDYES){
        //
        const TDateTime newTime = Now();
        const AnsiString strDate = getDateTime(newTime);
        Undo_See_STATE();
        sendMultiCommand(strDate);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnSeeTimeClick(TObject *Sender)
{
    AnsiString s;
    bool send_succ;
    //
    Undo_See_STATE();
    //
    s = "get ds1390_time";
    send_succ = FormMain->Send_Packet_UDP(s,1);
    //
    if (send_succ)
    {
    FormDk->Edit3->Text = FormMain->retStrUDP().Trim();
    }
    else
    {
    FormDk->Edit3->Text = "���";
    }
}
//---------------------------------------------------------------------------
// ���������� ������ �������
void __fastcall TFormDk::btnStopReadJornalClick(TObject *Sender)
{
        AnsiString s;
        bool send_succ;
        //
        FormDk->Timer2->Enabled = false;
        FormDk->Timer3->Enabled = false;
        return;
        //
        s = "event erase";
           send_succ = FormMain->Send_Packet_UDP(s,2);
           //
           if (send_succ)
           {
           //FormDk->Edit1->Text="������� - ��";
           Status("������� - ��");
           }
           else
           {
           //FormDk->Edit1->Text="������� - ������!!!1";
           Status("������� - ������!!!1");
           }
}
//---------------------------------------------------------------------------
void Read_Jornal()
{
     AnsiString s;
        int i_size;
        bool send_succ;
        ///////
        Undo_See_STATE();
        //
        FormDk->ProgressBar1->Position = 0;
        //Form10->Button6->Enabled = false;
        Status("");
        was_read=0;
        //
        for (int i=1; i< FormDk->StringGridJor->RowCount-1; i++)
        {
          FormDk->StringGridJor->Cells[0][i] = "";
          FormDk->StringGridJor->Cells[1][i] = "";

        }

        ///
        s = "event init";
        send_succ = FormMain->Send_Packet_UDP(s,2);
        if (!send_succ)
          return;
        //

        ::Sleep(20);
        s = "event used";
        send_succ = FormMain->Send_Packet_UDP(s,1);
        //
        jor_size=0;
        //
        if (send_succ)
        if (TryStrToInt(FormMain->retStrUDP(), i_size))
        {
          jor_size = i_size;
          FormDk->StringGridJor->RowCount = i_size+1;
          //Form10->Edit1->Text = "������������� ������� - OK. ";
        }
        else
        {
          //FormDk->Edit1->Text = "O����� ������ �������!!!";
          Status("O����� ������ �������!!!");
          return;
        }
        //

        //jor_size = 1000;
        ///
        if (jor_size>0)
        {
           FormDk->Timer2->Enabled = true;
           jor_size++;
        }
        //Form10->Button6->Enabled = true;
        //Status("������������� ������� - OK. ");
}
//---------------------------------------------------------------------------
// ������ �������
void __fastcall TFormDk::btnReadJornalClick(TObject *Sender)
{
Read_Jornal();
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnInfoDkClick(TObject *Sender)
{
//
const AnsiString scmd("get info");
//
bool send_succ = FormMain->Send_Packet_UDP(scmd,2);
if (send_succ){
        Status("OK. ");
        FormDk->Memo4->Clear();
        FormDk->Memo4->Lines->Add(FormMain->retStrUDP());
        }
        else{
        Status("������");
        }
}
//---------------------------------------------------------------------------
// ��������
void __fastcall TFormDk::btnUpLoadClick(TObject *Sender)
{
    AnsiString s;
    unsigned long crc;
    //
    if (upload_mode)
    {
      Butt_upload_State();
      FormDk->Memo3->Lines->Add("�������� ��������!");
      return;
    }
    Butt_upload_State();
    //
    FormDk->Memo3->Clear(); //
    Undo_See_STATE();
    // get ver - ��������� ������ � �������
    bool send_succ = FormMain->Send_Data_UDP("get ver" );
    int load_dk_n=1;
    if (send_succ)
      load_dk_n = N_DK;
    //
    transp_type = Check_Transport_Type();
    if (transp_type == TRANSP_ERR)
         {
           FormDk->Memo3->Lines->Add("�� �� ��������!");
           return;
         }
int reload_rings=0;
//
  for (int i=0; i < load_dk_n; i++)
  {
    FormDk->Memo3->Lines->Add("��������� ������������: " + IntToStr(i+1));
    // ������ ������
    ReLoad_Proj(i);
    //
    if ((LOAD_STATUS.prog_load_succ) && (LOAD_STATUS.proj_load_succ))
    {
      //�������� CRC
        crc = crc32_calc((unsigned char*)&PAP_RL,sizeof(PAP_RL)-sizeof(PAP_RL.CRC32));
        if (PAP_RL.CRC32 != crc)
        {
           FormDk->Memo3->Lines->Add("����������� ����� � ������� �� ���������!");
           break;
        }
        //
        crc = crc32_calc((unsigned char*)&PAPROGS_RL,sizeof(PAPROGS_RL)-sizeof(PAPROGS_RL.CRC32));
        if (PAPROGS_RL.CRC32 != crc){
                FormDk->Memo3->Lines->Add("����������� ����� � ���������� �� ���������!");
                break;
                }
        //
        FormDk->Memo3->Lines->Add("������������ ���������!");
        //������ ������ � ������� ��
        cpyStructure(reload_rings);
        reload_rings++;
    }
  FormDk->Memo3->Lines->Add("-------------------------------------------");
  }
if (reload_rings){
    FormDk->Memo3->Lines->Add("-------------------------------------------");
    FormDk->Memo3->Lines->Add("����� - ��������� " + IntToStr(reload_rings));
    FormMain->retVIS()->count_dk = reload_rings;

    memcpy(&PAP, &PAP_RINGS[0], sizeof(PAP));
    memcpy(&PAPROGS, &PAPROGS_RINGS[0],sizeof(PAPROGS));
    }
if (upload_mode)
      Butt_upload_State();
FormMain->RefreshAllForms();
// ���� ����������� ���
for(int i=0;i<PAP.Program.AmountFasa;i++)
        {
        if(PAP.Program.fazas[i].FasaProperty==PHASE_PROP_TVP){ // ���� ��������
          PAP.Program.fazas[i].Tosn = 0;
          PAPROGS.Program[0].fazas[i].Tosn = 0;
          }else{
          //PAP.Program.fazas[i].Tosn = FormMain->retTosnGlb(0,i);
          //PAPROGS.Program[0].fazas[i].Tosn += FormMain->retTosnGlb(0,i);
          }
        }
FormMain->RefreshAllForms();
}
/*----------------------------------------------------------------------------*/
void TFormDk::cpyStructure(const int count)
{
memset(&PAP_RINGS[count],0,sizeof(PAP_RINGS[count]));
memcpy(&PAP_RINGS[count].surd,&PAP_RL.surd,sizeof(ExData::TSURD));
memcpy(&PAP_RINGS[count].jornal,&PAP_RL.jornal,sizeof(ExData::TJORNAL));
memcpy(&PAP_RINGS[count].comments,&PAP_RL.comments,sizeof(ExData::TCOMMENT_EX));
memcpy(&PAP_RINGS[count].maxDK,&PAP_RL.maxDK,sizeof(BYTE));
memcpy(&PAP_RINGS[count].guard,&PAP_RL.guard,sizeof(ExData::TGUARD));
memcpy(&PAP_RINGS[count].Program,&PAP_RL.Program,sizeof(ExData::TPROGRAM ));
memcpy(&PAP_RINGS[count].Year,&PAP_RL.Year,sizeof(ExData::TYEARCALENDAR));
for(int i=0;i<MaxWeeksPlans;i++)
        memcpy(&PAP_RINGS[count].WeeksPlans[i],&PAP_RL.WeeksPlans[i],sizeof(ExData::TWEEKCALENDAR));
for(int i=0;i<MaxDaysPlans;i++)
        memcpy(&PAP_RINGS[count].DaysPlans[i],&PAP_RL.DaysPlans[i],sizeof(ExData::TCALENDAR));
for(int i=0;i<MaxFase;i++)
        memcpy(&PAP_RINGS[count].Fasa[i],&PAP_RL.Fasa[i],sizeof(ExData::TSHABLONFASA));
memcpy(&PAP_RINGS[count].AmountMuls,&PAP_RL.AmountMuls,sizeof(BYTE));
memcpy(&PAP_RINGS[count].ExpUDZ,&PAP_RL.ExpUDZ,sizeof(ExData::TEXPRESSIONS));
// ������ �����������
PAP_RINGS[count].AmountDirects = PAP_RL.AmountDirects;
PAP_RINGS[count].Directs.countDirectCCG = PAP_RL.Directs.countDirectCCG;
for(int i=0;i<PAP_RL.AmountDirects;i++)
        {
        PAP_RINGS[count].Directs.OneDirect[i].Type = PAP_RL.Directs.OneDirect[i].Type;
        // red
        memcpy(&PAP_RINGS[count].Directs.OneDirect[i].out.red[0],
                                &PAP_RL.Directs.OneDirect[i].out.red,sizeof(ExData::TNAPROUT));
        // yellow
        memcpy(&PAP_RINGS[count].Directs.OneDirect[i].out.yel[0],
                                &PAP_RL.Directs.OneDirect[i].out.yellow,sizeof(ExData::TNAPROUT));
        // green
        memcpy(&PAP_RINGS[count].Directs.OneDirect[i].out.green[0],
                                &PAP_RL.Directs.OneDirect[i].out.green,sizeof(ExData::TNAPROUT));
        }
PAP_RINGS[count].ProjectSize  = PAP_RL.ProjectSize;
PAP_RINGS[count].CRC32_programs = PAP_RL.CRC32_programs;
PAP_RINGS[count].CRC32 = PAP_RL.CRC32;
// �������� ���������
memcpy(&PAPROGS_RINGS[count], &PAPROGS_RL, sizeof(PAPROGS));
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnExportClick(TObject *Sender)
{
        AnsiString      file_s, s;
        FILE            *in_file;
        char            f_name[100];
        char            *buf_read;
        char            rec[300];
        int             bytes_in;
        int             b_sens_all;
        char            buf_temp[30000];
        //
        file_s = "jor.txt";
        strcpy(f_name,file_s.c_str());
        //
        in_file=fopen(f_name,"w");
        //
          for (int i=1; i< FormDk->StringGridJor->RowCount; i++)
          {
          s = FormDk->StringGridJor->Cells[1][i];
          fprintf(in_file,s.c_str());
          }
          //
          fclose(in_file);
          //
          Status("������ ������� � jor.txt � ���������� ���������!");
}
//---------------------------------------------------------------------------
// 
void __fastcall TFormDk::Timer2Timer(TObject *Sender)
{
        AnsiString s;
        bool send_succ;
        int i_size;
        int  perc_rez;
        /////
        FormDk->Timer2->Enabled = false;
        Undo_See_STATE();
        ////
        for (int i=0; i< 20; i++)
        {
           s = "event get";
           send_succ = FormMain->Send_Packet_UDP(s,5);
           //
           if (was_read>=FormDk->StringGridJor->RowCount)
               FormDk->StringGridJor->RowCount=was_read+10;
           ///
           FormDk->StringGridJor->Cells[0][was_read+1] = IntToStr(was_read+1);
           //
           if (send_succ)
           {
               if (FormMain->retStrUDP().Pos("+++NO events"))
                 goto stop;
               FormDk->StringGridJor->Cells[1][was_read+1]=FormMain->retStrUDP();
               was_read++;
           }
           else
           {
              FormDk->StringGridJor->Cells[1][was_read]="NO events";
              goto stop;
           }
        }
        ///
        perc_rez = ((float)was_read / jor_size)*100;
        FormDk->ProgressBar1->Position = perc_rez;
        //
        if (perc_rez>99)
        {
             goto stop;
         }
         else
         {
           FormDk->Timer2->Enabled = true;
         }
FormDk->ProgressBar1->Update();
return;

stop:
        FormDk->Timer2->Enabled = false;
        FormDk->ProgressBar1->Position = 100;
        Status("������ ��������! ����� ������� ���������=" + IntToStr(was_read));
}
//---------------------------------------------------------------------------
// ���� ������
void __fastcall TFormDk::Timer3Timer(TObject *Sender)
{
        AnsiString s;
        bool send_succ;
        int i_size;
        int  perc_rez;
        //
        FormDk->Timer3->Enabled = false;
        Undo_See_STATE();
        //
        for (int i=0; i< 20; i++)
        {
           s = "event get " + IntToStr(was_read + dump_start);
           send_succ = FormMain->Send_Packet_UDP(s,5);
           FormDk->StringGridJor->Cells[0][was_read+1] = IntToStr(was_read+dump_start);
           //
           if (send_succ)
           {
               if (FormMain->retStrUDP().Pos("+++NO events"))
                 FormMain->clearStrUDP();
               //  break;
               FormDk->StringGridJor->Cells[1][was_read+1]=FormMain->retStrUDP();
               was_read++;
           }
           else
           {
           goto stop;
           }
        }
        //
        perc_rez = ((float)was_read / dump_len)*100;
        FormDk->ProgressBar1->Position = perc_rez;
        //
        if (perc_rez>99)
        {
           goto stop;
         }
         else
         {
           FormDk->Timer3->Enabled = true;
         }
        //
        FormDk->ProgressBar1->Update();
        //
return;

stop:
        FormDk->Timer3->Enabled = false;
        Status("������ ��������! ����� ������� ���������=" + IntToStr(was_read-1));
}
//---------------------------------------------------------------------------
// ���������� ����� ���������
AnsiString TFormDk::getDateTime(TDateTime &newTime)
{
AnsiString strTime;
//TDateTime now = FormDk->DateTimePicker1->Time;
strTime = "set ds1390_time " + FormatDateTime("dd.mm.yyyy", newTime) + "-" +
             FormatDateTime("hh:mm:ss", newTime);
return strTime;
}
void __fastcall TFormDk::btnSetTimeClick(TObject *Sender)
{
        AnsiString s;
        bool   send_succ;
        //TDateTime now = FormDk->DateTimePicker1->Time;
        //
        Undo_See_STATE();
        //
        /*s = "set ds1390_time " + FormatDateTime("dd.mm.yyyy", now) + "-" +
             FormatDateTime("hh:mm:ss", now);*/
        s = getDateTime(FormDk->DateTimePicker1->Time);
        //
        FormConsole->mmoOut->Lines->Add(s);
        send_succ = FormMain->Send_Packet_UDP(s,1);
        //
        if (send_succ)
           {
           Status("����� �����������!!!");
           }
           else
           {
           Status("������!!!!. ����� �� �����������!!!!1");
           }
}
// ���������� ����� �� ��� ��
void __fastcall TFormDk::btnMultiTimeClick(TObject *Sender)
{
AnsiString ds = "���������� ����� ��� �� ����?\n";
if (Application->MessageBox(ds.c_str(),
        "������� ����� ��",
        MB_YESNO +MB_TOPMOST+ MB_ICONQUESTION)==IDYES){
        //
        const AnsiString strDate = getDateTime(FormDk->DateTimePicker1->Time);
        Undo_See_STATE();
        sendMultiCommand(strDate);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnClearFlashClick(TObject *Sender)
{
        const AnsiString strcmd("flash_reset 255");
        //
        int btn=mrNone;
        //
        btn = MessageBox(0,"������ �������� ���������� FLASH ������!!! ����������?","��������",
          MB_YESNO);
        if (btn!=mrYes)//
          return;
        //send and cj
        bool send_succ = FormMain->Send_Packet_UDP(strcmd,2);
        //
        if (send_succ)
           {
           Status("������� - ��!");
           }
           else
           {
           Status("������!!");
           }
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::btnDkDefaultClick(TObject *Sender)
{
FormDk->cbbDk->ItemIndex = 0;
FormDk->medtIP->Text = "169.254.016.001";
FormDk->edtPassword->Text = "999999";
}
//---------------------------------------------------------------------------
// �������� ���������
void TFormDk::updateNetDk(IPDATA *pdate)
{
// ���������� ��������� �� ������
pDateIp = pdate;
// ���������� ������ ��
FormDk->cbbDk->Items->Clear();
const int countIp = pdate->getCountIp();
for(int i=0;i<countIp;i++)
        {
        FormDk->cbbDk->Items->Add("�"+IntToStr(i+1));
        }
FormDk->cbbDk->ItemIndex = 0;
// ���������� ����� IP �����
const AnsiString ip_current = pdate->getOneIp(0);
FormDk->medtIP->Text = ip_current;
// ���������� ������
const ExData::TPROJECT *prj = FormMain->retDataProject();
const int Password = prj->surd.Pass;
FormDk->edtPassword->Text = IntToStr(Password);
// ���������� ����
FormDk->edtPort->Text = IntToStr(prj->surd.PORT);
// ����� ������� ��������� ������
ManualNetParametrs(false);
// ���������� ��������� �����
//ChangeDk(FormDk->cbbDk->ItemIndex);
// �������� ������
if(FormDk->checkPasswordSURD_OK()!=anOk){
        FormDk->PageControl1->Visible = false;
        return;
        }
FormDk->PageControl1->Visible = true;
}
// ����� ������ �����������---------------------------------------------------//
void TFormDk::ChangeDk(const int NumberDk)
{
const AnsiString ip_current = pDateIp->getOneIp(NumberDk);
const int port = pDateIp->getPort();
// ���������� IP
FormDk->medtIP->Text = ip_current;
// ���������� ����
FormDk->edtPort->Text = IntToStr(port);
// �������� ��������� �����.
FormMain->setActiveClientUDP(ip_current,port);//���������� �������
FormMain->setActiveServerUDP(port); // ���������� ������
// ���������� � �����
setTextIP(" IP:"+ip_current+" PORT:"+IntToStr(port));
}
// ������� ������ ��
void __fastcall TFormDk::cbbDkChange(TObject *Sender)
{
// ������ ID � ����������
const int crDk = FormDk->cbbDk->ItemIndex;
ChangeDk(crDk);
}
//--------------------------------------------------------------------------
//��������� ��������
void __fastcall TFormDk::ButtonOSClick(TObject *Sender)
{
// �������� ������
if(checkPasswordSURD_OK()!=anOk)return;
const AnsiString s = "light OS";
bool send_succ;
send_succ = FormMain->Send_Packet_UDP(s,2);
if (send_succ){
        Status("OK. �� ����������");
        }
        else{
        Status("������");
        }
}
/*----------------------------------------------------------------------------*/
void TFormDk::sendMultiCommand(AnsiString cmd)
{
AnsiString out = "��������� �������";
std::vector<AnsiString> answerErrDK;
bool send_succ;
int MaxDk = pDateIp->getCountIp();// max. IP

// ���������� ����, ����� ������ �������
for(int i=(MaxDk-1);i>=0;i--)
        {
        const AnsiString ip = pDateIp->getOneIp(i);
        const int port = pDateIp->getPort();
        FormMain->setActiveClientUDP(ip,port);//���������� �������
        FormMain->setActiveServerUDP(port);   // ���������� ������
        // ���������� ���������
        send_succ = FormMain->Send_Packet_UDP(cmd,2);
        if (!send_succ){
                answerErrDK.push_back("��"+IntToStr(i+1));
                }
        ::Sleep(50);
        Application->ProcessMessages();
        }
// ������� ���������
if(!answerErrDK.empty()){
        AnsiString strDk;
        for(int i=0;i<answerErrDK.size();i++)
                {
                strDk +=" "+answerErrDK[i];
                }
        out = "������ ������" +strDk;
        }
Status(out);
// ���������� ��������� �����
const int crDk = FormDk->cbbDk->ItemIndex;
ChangeDk(crDk);
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::ButtonOSUrgClick(TObject *Sender)
{
// ��������� ��� �� � ����� ��
AnsiString ds = "��������� � ����� �� ��� �� ����?\n";
if (Application->MessageBox(ds.c_str(),
        "������� ����� ��",
        MB_YESNO +MB_TOPMOST+ MB_ICONQUESTION)==IDYES){
     if(checkPasswordSURD_OK()!=anOk)return;
     sendMultiCommand("light OS");
     }
}
//---------------------------------------------------------------------------
// ��� ������
void __fastcall TFormDk::ButtonRUNClick(TObject *Sender)
{
// �������� ������
if(checkPasswordSURD_OK()!=anOk)return;
AnsiString s;
bool send_succ;
s = "light undo";
send_succ = FormMain->Send_Packet_UDP(s,2);

if (send_succ){
        Status("OK. �� �������");
        }
        else{
        Status("������");
        }

}
//---------------------------------------------------------------------------
void TFormDk::ManualNetParametrs(bool fCheck)
{
chkNet->Checked=fCheck;
if(fCheck){
        cbbDk->Enabled = false;
        btnNet->Enabled = true;
        medtIP->Enabled = true;
        edtPort->Enabled = true;
        edtPassword->Enabled = true;
        btnDkDefault->Enabled = true;
        }else{
        cbbDk->Enabled = true;
        cbbDk->ItemIndex = 0;
        ChangeDk(cbbDk->ItemIndex);
        btnDkDefault->Enabled = false;
        edtPort->Enabled = false;
        btnNet->Enabled = false;
        medtIP->Enabled = false;
        edtPassword->Enabled = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::chkNetClick(TObject *Sender)
{
ManualNetParametrs(chkNet->Checked);
}
//---------------------------------------------------------------------------
// ��������� ���������
void __fastcall TFormDk::btnNetClick(TObject *Sender)
{
int PassValue;
int PortValue;

try  {PassValue = StrToInt(edtPassword->Text.Trim());}
        catch(...){
        Application->MessageBox("������ ����� ������ ����", "������", MB_OK);
        return;
        }
try  {PortValue = StrToInt(edtPort->Text.Trim());}
        catch(...){
        Application->MessageBox("������ ����� ����� ethrernet", "������", MB_OK);
        return;
        }
const AnsiString ip = medtIP->Text.Trim();
if(!IPDATA::checkAdressIP(ip)){
        Application->MessageBox("������ ����� IP ������", "������", MB_OK);
        return;
        }
// init UDP server
FormMain->setActiveServerUDP(PortValue);//���������� ������
// init UPD client
FormMain->setActiveClientUDP(ip,PortValue);//���������� �������
// �������� � �����
setTextIP(" IP:"+ip+" PORT:"+IntToStr(PortValue)+" PASSW:"+IntToStr(PassValue));
// �������� ������
if(FormDk->checkPasswordSURD_OK()!=anOk){
        FormDk->PageControl1->Visible = false;
        return;
        }
FormDk->PageControl1->Visible = true;
}
//---------------------------------------------------------------------------
void TFormDk::setTextIP(const AnsiString txt)
{
textCurrentIP=txt;
FormDk->Caption = "�� � ������ "+txt;
}
//---------------------------------------------------------------------------
// ����� ��������� �������
void __fastcall TFormDk::btnConsolClick(TObject *Sender)
{
FormConsole->Visible = true;
}
//---------------------------------------------------------------------------
// button active surd
void __fastcall TFormDk::btnSurdClick(TObject *Sender)
{
Undo_See_OFF();
tmrSURD->Enabled = btnSurd->Down; //��������� ������ SURD
if(!btnSurd->Down){
        updateNetDk(pDateIp); // ����������� IP ������
        }
}
//---------------------------------------------------------------------------
// timer status SURD
void __fastcall TFormDk::tmrSURDTimer(TObject *Sender)
{
FormDk->tmrSURD->Enabled =false;
const AnsiString scmd("allpollingdk"); //"allpollingdk\r"
// �������, ��� ��������
bool send_succ = FormMain->Send_Data_UDP(scmd);
static WORD inpsk=0;
if (send_succ){
        Status("OK");
        FormDk->Memo4->Lines->Add("/*** SURD BEGIN "+IntToStr(++inpsk)+" ***/");
        AnsiString UDP_BUFF = FormMain->retStrUDP();
        FormDk->Memo4->Lines->Add(UDP_BUFF);
        }
        else{
        Status("������");
        }
if(btnSurd->Down)
        FormDk->tmrSURD->Enabled = true;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormDk::btnRestartClick(TObject *Sender)
{
// ������� ���� ��
AnsiString ds = "������� ��� �� ����?\n";
if (Application->MessageBox(ds.c_str(),
        "��������� � �������",
        MB_YESNO +MB_TOPMOST+ MB_ICONQUESTION)==IDYES){
     if(checkPasswordSURD_OK()!=anOk)return;
     sendMultiCommand("light undo");  //light undo reboot
     }
}
//---------------------------------------------------------------------------
BYTE TFormDk::checkPasswordSURD_OK(void)
{
// +DEBUG
        return anOk;
// -DEBUG
const AnsiString scmd("get password");
BYTE result = noAnswer;
//
bool send_succ = FormMain->Send_Packet_UDP(scmd,3);
if(send_succ){
        Status("OK. ");
        FormDk->Memo4->Clear();
        FormDk->Memo4->Lines->Add(FormMain->retStrUDP());
        DWORD PassValue,PassRead;
        try{PassValue = StrToInt(edtPassword->Text.Trim());}
                catch(...){
                        result = anError;}
        try{PassRead = StrToInt(FormMain->retStrUDP().Trim());}
                catch(...){
                        result = anError;}
        if(PassRead==PassValue)
                result = anOk;
        if(result != anOk)
                MessageDlg("�������� ������ �������!", mtError,TMsgDlgButtons() << mbOK,0);
        }
        else{
        Status("������ ������. ");
        result = noAnswer;
        MessageDlg("������ ����������!", mtError,TMsgDlgButtons() << mbOK,0);
        }
return result;
}
//---------------------------------------------------------------------------
