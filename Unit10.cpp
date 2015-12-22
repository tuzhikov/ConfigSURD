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
    bool proj_load_succ; // общий результат загрузки
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
  // названия параметров и их значения
  AnsiString state_params[PARAMS_N]={"PROGRAM=","PROG_FAZA=","SINGLE_FAZA=",
        "LEVEL=", "SPEC_PROG=", "RED=", "YEL=", "GREEN="};
  AnsiString  state_znach[PARAMS_N];*/
  //
  int was_read=0;
  int jor_size=0;

  //
  TPROJECT_DK PAP_RL;
  TPROGRAMS   PAPROGS_RL; //программы

  // размер журнала в записях
  #define JORNAL_SIZE   1000
  // позиции дампа
  int dump_start, dump_end;
  int dump_len;

  #define TRANSP_proj_flashwr     2
  #define TRANSP_pflashwr         1
  #define TRANSP_ERR              0

  int transp_type; //тип транспорта

  void Read_Jornal();
  int  curr_ring=1;  //отображаемое кольцо
  ///
  bool boot_mode=false;
  bool upload_mode=false;

/*----------------------------------------------------------------------------*/
// информация для кнопки "загрузка"
void Butt_load_State()
{
boot_mode = !boot_mode;
if (boot_mode)
    {
    FormDk->btnLoad->Caption = "ОТМЕНА!!!";
    FormDk->btnUpLoad->Enabled = false;
    }
    else
    {
    FormDk->btnLoad->Caption = "Загрузить проект в ДК";
    FormDk->btnUpLoad->Enabled = true;
    }
}
//---------------------------------------------------------------------------
// информация для кнопки "выгрузка"
void Butt_upload_State()
{
    upload_mode = !upload_mode;
    if (upload_mode)
    {
    FormDk->btnUpLoad->Caption = "ОТМЕНА!!!";
    FormDk->btnLoad->Enabled = false;
    }
    else
    {
    FormDk->btnUpLoad->Caption = "Выгрузить проект из ДК";
    FormDk->btnLoad->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void Status(const AnsiString s)
{
FormDk->edtLog->Text = s;
}
//---------------------------------------------------------------------------
// отключить режим "следить"
void Undo_See_OFF()
{
FormDk->Timer1->Enabled = false;
FormDk->btnLook->Down = false;
}
// отключить режим СУРД
void Undo_SURD_OFF()
{
FormDk->btnSurd->Down = false;
FormDk->tmrSURD->Enabled = false;
}
// отключить режим "следить" и режим СУРД
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
// states - строка параметров вида "ключ1=знач1 ключ2=знач2 ..."
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
// Печатает
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
           s = s + "ВКЛ";
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
        FormDk->pnlmodesurd->Caption = "Программа";
        // phase
        s = STATE_PAR["PROG_FAZA"];
        FormDk->pnlphase->Caption = s;
        }
//
if (s=="SINGLE_FAZA"){
        FormDk->pnlmodesurd->Caption = "Отдельная фаза";
        s = STATE_PAR["SINGLE_FAZA"];
        FormDk->pnlphase->Caption = s;
        }
//
if (s=="SPEC_PROG"){
        FormDk->pnlmodesurd->Caption = "Спец. программа";
        s = STATE_PAR["SPEC_PROG"];
        if (s=="FLASH") s="ЖМ";
        if (s=="OFF") s="ОС";
        if (s=="KK") s="KK";
        FormDk->pnlphase->Caption = s;
        }
//
ss="";
s = STATE_PAR["LEVEL"];
if (s=="ALARM")   ss = "АВАРИЯ";
if (s=="TUMBLER") ss = "ТУМБЛЕР";
if (s=="SERVICE") ss = "СЕРВИС";
if (s=="VPU")     ss = "ВПУ";
if (s=="TVP")     ss = "ТВП";
if (s=="PLAN")    ss = "ПЛАН";
//output
FormDk->pnlsource->Caption = ss;
// состояние ДК
ss="";
s = STATE_PAR["STATUS"];
if (s=="OK") ss = "ИСПРАВЕН";
if (s=="NO") ss = "НЕИСПРАВЕН";
FormDk->pnlStat->Caption = ss;
// статус СУРД
ss="";
s = STATE_PAR["SURD"];
if (s=="OK")  ss = "СУРД ИСПРАВНА";
if (s=="NO")  ss = "СУРД НЕИСПРАВНА";
FormDk->pnlstsurd->Caption = ss;
// состояние ethernet
s = STATE_PAR["NET"];
if (s=="OK")  ss = "Все ДК в сети";
if (s=="NO")  ss = "ДК не в сети";
FormDk->pnlnet->Caption = ss;
// качество связи
s = STATE_PAR["QUAL"];
FormDk->pnlQuality->Caption = s+"%";
// фремя окончания фазы или пром. такта
ss="";
//s = STATE_PAR["LEVEL"];
//if(s=="VPU"){
        //ss = "- (мин:сек)";
        //}else{
        s = STATE_PAR["TIME"];
        if(!s.IsEmpty()){
                const int Time = StrToInt(s);
                ss = DiagramPainter::retConvertToTime(Time)+" (мин:сек)";
                }
        //}
FormDk->pnlTime->Caption = ss;
}
//------------------------------------------------------------------------------
// вывод информации на консоль
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
//Определем тип загрузки
int  Check_Transport_Type()
{
        bool   send_succ;
        //пробуем вначале новые протокол
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
               //console_load("Попытка № " + IntToStr(i+1) + " - OK");
               //cons_res("Определено. ДК версии > 1.0.3");
               return (TRANSP_proj_flashwr);
             }
             else
             {
              //console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
              console_load(FormMain->retStrUDP());
             }
        }
        //cons_res("Пробуем  ДК версии < 1.0.4");
        for (int i=0; i<7; i++)
        {
             send_succ = FormMain->Send_Data_UDP("pflashwr 0x1000 0 00");
             ////
             Application->ProcessMessages();
             //
             if (send_succ)
             {
               //console_load("Попытка № " + IntToStr(i+1) + " - OK");
               //cons_res("Определено. ДК версии < 1.0.4");
               return (TRANSP_pflashwr);
             }
             else
             {
              //console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
              //console_load(UDP_String);
             }
        }
        //
        cons_res("Не определена версия ДК!!!");
        return (TRANSP_ERR);
}
//---------------------------------------------------------------------------
// Загружаем проект в контроллер
void Load_Proj(int i_dk)
{
int i_succ=0;
TPROJECT_DK  PAP_L;
TPROGRAMS    PAPROGS_L;
// весь проект
FormMain->makeProject(i_dk);
// сохраним проетк
TDateDk dateDk(&PAP_RINGS[i_dk]); // данные для одного контроллера
const int crDk = FormDk->cbbDk->ItemIndex;
const TPROJECT_DK *pDk = dateDk.retDatePrj(crDk);
if(pDk==0)return; // ошибка надо отработать
memcpy(&PAP_L,pDk,sizeof(TPROJECT_DK));
memcpy(&PAPROGS_L,&PAPROGS_RINGS[i_dk], sizeof(PAPROGS_L));
//размеры проекта
PAP_L.ProjectSize = sizeof(TPROJECT_DK);
PAPROGS_L.ProgramsSize = sizeof(TPROGRAMS);
PAP_L.CRC32_IDP = PAP_RINGS[i_dk].CRC32; // CRC для обмена ДК
//контрольные сыммы
PAPROGS_L.CRC32 = crc32_calc((unsigned char*)&PAPROGS_L,sizeof(PAPROGS_L)-sizeof(PAPROGS_L.CRC32));
PAP_L.CRC32_programs = PAPROGS_L.CRC32;
PAP_L.CRC32 = crc32_calc((unsigned char*)&PAP_L,sizeof(PAP_L)-sizeof(PAP_L.CRC32));
//
int i_addr, i_len;
unsigned char *p_p;
unsigned char buf[2*PACK_LEN];
AnsiString s,ss;
bool   send_succ;
// сбрасываем статус загрузки
LOAD_STATUS.proj_load_succ = false;
LOAD_STATUS.prog_load_succ = false;
// Грузим проект
// кол-во пакетов
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
           console_load("Пакет №=" + IntToStr(i_p+1));
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
               console_load("Попытка № " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
             {
              console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
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
           //cons_res("Проект успешно загружен!");
        }
        else
        {
           //MessageDlg("Проект НЕ загружен!",mtError, mbOKCancel,0);
           return;
        }
        // Грузим программы
        // кол-во полных пакетов
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
           console_load("Пакет №=" + IntToStr(i_p+1));
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
               console_load("Попытка № " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
              console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
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
// Загружаем проект из кольца i_dk в контроллер
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
               console_load("Попытка № " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
             {
              console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
              console_load(FormMain->retStrUDP());
             }
           }
           //
           LOAD_STATUS.proj_load_succ=send_succ;
           //cons_res("Проект успешно загружен!");
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
               console_load("Попытка № " + IntToStr(i+1) + " - OK");
               break; //tryes
             }
             else
              console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
           }

        ///
        ////
           LOAD_STATUS.prog_load_succ=true;

        ///
}
//---------------------------------------------------------------------------
// ВЫГРУЗКА!!!!!
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

        // Грузим проект
        // кол-во полных пакетов
        int pacs_full = sizeof(TPROJECT_DK) / PACK_LEN;
        if (sizeof(TPROJECT_DK) % PACK_LEN)
           pacs_full++;
        //
        i_len=PACK_LEN;
        i_addr=0;
        int i_addr_offs = sizeof(TPROJECT_DK)*i_dk;
        /////
        //cons_res("Загружаем проект. Размер данных=" + IntToStr(sizeof(TPROJECT)));
        //cons_res("Пакетов = " + IntToStr(pacs_full));
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
           console_load("Пакет №=" + IntToStr(i_p+1));
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
                   console_load("Попытка № " + IntToStr(i+1) + " - OK");
                   //
                   HexToBin(FormMain->retStrUDP().c_str(),p_p,i_len);
                   //
                   break; //tryes
                }
             }
             else
              console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
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
           //cons_res("Проект успешно загружен!");
        }
        else
        {
           //MessageDlg("Проект НЕ загружен!",mtError, mbOKCancel,0);
           return;
        }
        ////////////////////////////////
        //////////////////////////////
        ///////////////////////////
        // Грузим программы
        // кол-во полных пакетов
        pacs_full = sizeof(TPROGRAMS) / PACK_LEN;
        if (sizeof(TPROGRAMS) % PACK_LEN)
           pacs_full++;
        //
        i_len=PACK_LEN;
        i_addr=0;
        i_addr_offs = sizeof(TPROGRAMS)*i_dk;
        i_succ=0;
        //
        //cons_res("ВЫгружаем программы. Размер данных=" + IntToStr(sizeof(TPROGRAMS)));
        //cons_res("Пакетов = " + IntToStr(pacs_full));
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
           console_load("Пакет №=" + IntToStr(i_p+1));
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
                   console_load("Попытка № " + IntToStr(i+1) + " - OK");
                   //
                   HexToBin(FormMain->retStrUDP().c_str(),p_p,i_len);
                   break; //tryes
                }
             }
             else
              console_load("Попытка № " + IntToStr(i+1) + " - ОШИБКА");
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
           //cons_res("Программы успешно ВЫгружены!");
        }
        else
        {
           //cons_res("Программы НЕ ВЫгружены!");
        }
        ////
        /*
        if (i_succ==pacs_full)
           MessageDlg("Проект успешно загружен!",mtInformation, mbOKCancel,0);
        else
           MessageDlg("Проект НЕ загружен!",mtError, mbOKCancel,0);
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
// загрузить проект
void __fastcall TFormDk::btnLoadClick(TObject *Sender)
{
//DEBUD
//Load_Proj(0);
//DEBUD
AnsiString s;
bool check_confl=false;
// изменить отображение на кнопке
if (boot_mode){
        Butt_load_State();
        FormDk->Memo3->Lines->Add("Операция прервана!");
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
        MessageBox(0,"Ошибка проекта: матрица конфликтов не соответствует шаблонам фаз",
                  "Отменено!", MB_YESNO);
        return;
        }
//
FormDk->Memo3->Clear();
Undo_See_STATE();
//
transp_type = Check_Transport_Type();
if(transp_type == TRANSP_ERR){
        FormDk->Memo3->Lines->Add("ДК не отвечает!");
        return;
        }
//
int ring_loaded=0;
// get ver - появилась только в кольцах
bool send_succ = FormMain->Send_Data_UDP("get ver" );
int load_dk_n=1;
if (send_succ)
      load_dk_n = N_DK;
//
if (send_succ==false){
        int i = MessageBox(0,"Не поддерживаются кольца. Грузим 1 кольцо?",
                  "Версия меньше 1.1.0 !", MB_YESNO);
        if(i!=6)
                return;
        }
// текущий контекст сохраняем
for (int i=0; i < load_dk_n; i++)
  {
      ///
      if (i<FormMain->retVIS()->count_dk)
      {
        FormDk->Memo3->Lines->Add("Загружаем проект: " + IntToStr(i+1) );
        Load_Proj(i);// загрузка проетка
        if (LOAD_STATUS.proj_load_succ)
                s = "Проект успешно загружен!";
                else
                s = "Проект НЕ загружен!";
        FormDk->Memo3->Lines->Add(s);
        //
        if (LOAD_STATUS.prog_load_succ)
                s = "Программы успешно загружены!";
                else
                s = "Программы НЕ загружены!";
        FormDk->Memo3->Lines->Add(s);
        //
      }
      else
      {
        FormDk->Memo3->Lines->Add("Стираем: " + IntToStr(i+1) );
        Load_Empty_Proj(i);
      }
      //
      Application->ProcessMessages();
      //
    if (LOAD_STATUS.proj_load_succ && LOAD_STATUS.prog_load_succ){
        //FormDk->Memo3->Lines->Add("Кольцо загружено!");
        ring_loaded++;
        }else{
        //  FormDk->Memo3->Lines->Add("Кольцо НЕ загружено!");
        break;
        }
  //
  FormDk->Memo3->Lines->Add("---------------------------------");
  }
//
if (ring_loaded==N_DK){
        FormDk->Memo3->Lines->Add("Всё загружено!");
        }else{
        FormDk->Memo3->Lines->Add("ОШИБКА!");
        }
// натписи на кнопках
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
FormDk->StringGridJor->Cells[0][0] = "№";
FormDk->StringGridJor->Cells[1][0] = "   Дата     Время    Событие";
                                      //26.07.2015- 18:00:20
/*FormDk->StringGridJor->Cells[2][0] = "Время";
FormDk->StringGridJor->Cells[3][0] = "Событие";
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
        FormDk->Edit2->Text = "ТЕСТ режим ВКЛ.";
        test_mode = true;
        // set rele
        bool send_succ = FormMain->Send_Packet_UDP("set rele on",3);
        if(!send_succ){
                FormDk->Edit2->Text = "ТЕСТ режим ВЫКЛ";
                test_mode = false;
                FormDk->btnTestOn->Down = false;
                FormDk->btnTestOff->Down = true;
                }
        }else{
        FormDk->Edit2->Text = "НЕТ";
        test_mode = false;
        FormDk->btnTestOn->Down = false;
        FormDk->btnTestOff->Down = true;
        }
}
//------------------------------------------------------------------------------
void __fastcall TFormDk::btnTestOffClick(TObject *Sender)
{
// отправить команду
bool send_succ = FormMain->Send_Packet_UDP("set test off",5);

if (send_succ){
        FormDk->Edit2->Text = "ТЕСТ ВЫКЛ.";
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
    if (col==0) {sc = "r"; sp="К"; }
    if (col==1) {sc = "y";sp="Ж";}
    if (col==2) {sc = "g";sp="З";}
    //
    s = "channel " + IntToStr(chan+1) + " " + sc + " on";
    send_succ = FormMain->Send_Packet_UDP(s,5);
    //
    if (send_succ)
    {
        FormDk->Memo2->Lines->Add("Канал " + IntToStr(chan+1) + " " + sp);
        FormDk->Memo2->Lines->Add("ВКЛ!");
        ::Sleep(100);
        if (col==0)
        {
            // зирим напряжение
            ::Sleep(1000);
            s = "get lineADC";
            send_succ = FormMain->Send_Packet_UDP(s,5);
            if (send_succ)
            {
                Parse_Answer(FormMain->retStrUDP(), " ");
                AnsiString s_res;
                if (argv[chan].Pos("1"))
                  s_res = "Ток есть.";
                else
                  s_res = "Тока нет.";
                FormDk->Memo2->Lines->Add(s_res);
            }
        }
        //
        if (col==2)
        {
            // зирим токи
            s = "get linePWM";
            ::Sleep(1000);
            send_succ = FormMain->Send_Packet_UDP(s,5);
            if (send_succ)
            {
                Parse_Answer(FormMain->retStrUDP(), " ");
                AnsiString s_res;
                if (argv[chan].Pos("1"))
                  s_res = "Напряжение есть.";
                else
                  s_res = "Напряжения нет.";
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

    if (col==0) {sc = "r"; sp="К"; }
    if (col==1) {sc = "y";sp="Ж";}
    if (col==2) {sc = "g";sp="З";}
    //
    s = "channel " + IntToStr(chan+1) + " " + sc + " off";
    const bool sendOk = FormMain->Send_Packet_UDP(s,5);
    //
    if (sendOk)
    {
    FormDk->Memo2->Clear();
    FormDk->Memo2->Lines->Add("ВЫКЛ!");
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
// линии
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
          Status("Некорректные числа!!");
          return;
        }
        //
        if (!TryStrToInt(FormDk->Edit5->Text,dump_end))
        {
          Status("Некорректные числа!!");
          return;
        }
        //
        dump_len = dump_end - dump_start +1 ;
        //
        if (dump_len<1)
        {
          Status("Некорректные числа!!");
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
// очистить
void __fastcall TFormDk::btnCleanClick(TObject *Sender)
{
        AnsiString s;
        bool send_succ;
        //
        int btn=mrNone;
        TMsgDlgButtons  butts;
        //
        btn = MessageBox(0,"Стирание журнала!!! Продолжить?","Стирание",
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
           Status("Очистка - ОК!");
           Read_Jornal();
           }
           else
           {
           Status("ОШИБКА!!");
           }
}
//---------------------------------------------------------------------------
// закрыть форму
void __fastcall TFormDk::FormClose(TObject *Sender, TCloseAction &Action)
{
Undo_See_STATE();
}
//---------------------------------------------------------------------------
// спрятать форму
void __fastcall TFormDk::FormHide(TObject *Sender)
{
FormDk->Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
// Синхронизация времени
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
           Status("Время установлено!!!");
           }
           else
           {
           Status("Ошибка!!!!. Время НЕ установлено!!!!1");
           }
}
// на всех ДК
void __fastcall TFormDk::btnSyncAllDkClick(TObject *Sender)
{
AnsiString ds = "Установить время все ДК СУРД?\n";
if (Application->MessageBox(ds.c_str(),
        "Выбрать режим ОС",
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
    FormDk->Edit3->Text = "НЕТ";
    }
}
//---------------------------------------------------------------------------
// остановить чтение журнала
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
           //FormDk->Edit1->Text="СТЕРЕТЬ - ОК";
           Status("СТЕРЕТЬ - ОК");
           }
           else
           {
           //FormDk->Edit1->Text="СТЕРЕТЬ - ОШИБКА!!!1";
           Status("СТЕРЕТЬ - ОШИБКА!!!1");
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
          //Form10->Edit1->Text = "Инициализация журнала - OK. ";
        }
        else
        {
          //FormDk->Edit1->Text = "Oшибка чтения журнала!!!";
          Status("Oшибка чтения журнала!!!");
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
        //Status("Инициализация журнала - OK. ");
}
//---------------------------------------------------------------------------
// Чтение журнала
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
        Status("Ошибка");
        }
}
//---------------------------------------------------------------------------
// Выгрузка
void __fastcall TFormDk::btnUpLoadClick(TObject *Sender)
{
    AnsiString s;
    unsigned long crc;
    //
    if (upload_mode)
    {
      Butt_upload_State();
      FormDk->Memo3->Lines->Add("Операция прервана!");
      return;
    }
    Butt_upload_State();
    //
    FormDk->Memo3->Clear(); //
    Undo_See_STATE();
    // get ver - появилась только в кольцах
    bool send_succ = FormMain->Send_Data_UDP("get ver" );
    int load_dk_n=1;
    if (send_succ)
      load_dk_n = N_DK;
    //
    transp_type = Check_Transport_Type();
    if (transp_type == TRANSP_ERR)
         {
           FormDk->Memo3->Lines->Add("ДК не отвечает!");
           return;
         }
int reload_rings=0;
//
  for (int i=0; i < load_dk_n; i++)
  {
    FormDk->Memo3->Lines->Add("Выгружаем конфигурацию: " + IntToStr(i+1));
    // читаем проект
    ReLoad_Proj(i);
    //
    if ((LOAD_STATUS.prog_load_succ) && (LOAD_STATUS.proj_load_succ))
    {
      //проверка CRC
        crc = crc32_calc((unsigned char*)&PAP_RL,sizeof(PAP_RL)-sizeof(PAP_RL.CRC32));
        if (PAP_RL.CRC32 != crc)
        {
           FormDk->Memo3->Lines->Add("Контрольная сумма в проекте не совпадает!");
           break;
        }
        //
        crc = crc32_calc((unsigned char*)&PAPROGS_RL,sizeof(PAPROGS_RL)-sizeof(PAPROGS_RL.CRC32));
        if (PAPROGS_RL.CRC32 != crc){
                FormDk->Memo3->Lines->Add("Контрольная сумма в программах не совпадает!");
                break;
                }
        //
        FormDk->Memo3->Lines->Add("Конфигурация выгружена!");
        //данные только с одногог ДК
        cpyStructure(reload_rings);
        reload_rings++;
    }
  FormDk->Memo3->Lines->Add("-------------------------------------------");
  }
if (reload_rings){
    FormDk->Memo3->Lines->Add("-------------------------------------------");
    FormDk->Memo3->Lines->Add("Итого - выгружено " + IntToStr(reload_rings));
    FormMain->retVIS()->count_dk = reload_rings;

    memcpy(&PAP, &PAP_RINGS[0], sizeof(PAP));
    memcpy(&PAPROGS, &PAPROGS_RINGS[0],sizeof(PAPROGS));
    }
if (upload_mode)
      Butt_upload_State();
FormMain->RefreshAllForms();
// пока реализовано так
for(int i=0;i<PAP.Program.AmountFasa;i++)
        {
        if(PAP.Program.fazas[i].FasaProperty==PHASE_PROP_TVP){ // фаза вызывная
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
// задать направления
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
// копируем программы
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
          Status("Журнал записан в jor.txt в директории программы!");
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
        Status("Журнал прочитан! Всего записей прочитано=" + IntToStr(was_read));
}
//---------------------------------------------------------------------------
// дамп памяти
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
        Status("Журнал прочитан! Всего записей прочитано=" + IntToStr(was_read-1));
}
//---------------------------------------------------------------------------
// установить время выбранное
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
           Status("Время установлено!!!");
           }
           else
           {
           Status("Ошибка!!!!. Время НЕ установлено!!!!1");
           }
}
// установить время на все ДК
void __fastcall TFormDk::btnMultiTimeClick(TObject *Sender)
{
AnsiString ds = "Установить время все ДК СУРД?\n";
if (Application->MessageBox(ds.c_str(),
        "Выбрать режим ОС",
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
        btn = MessageBox(0,"Полное стирание микросхемы FLASH памяти!!! Продолжить?","Стирание",
          MB_YESNO);
        if (btn!=mrYes)//
          return;
        //send and cj
        bool send_succ = FormMain->Send_Packet_UDP(strcmd,2);
        //
        if (send_succ)
           {
           Status("Очистка - ОК!");
           }
           else
           {
           Status("ОШИБКА!!");
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
// обновить параметры
void TFormDk::updateNetDk(IPDATA *pdate)
{
// глобальный указатель на данные
pDateIp = pdate;
// установить номера ДК
FormDk->cbbDk->Items->Clear();
const int countIp = pdate->getCountIp();
for(int i=0;i<countIp;i++)
        {
        FormDk->cbbDk->Items->Add("№"+IntToStr(i+1));
        }
FormDk->cbbDk->ItemIndex = 0;
// установить новый IP адрес
const AnsiString ip_current = pdate->getOneIp(0);
FormDk->medtIP->Text = ip_current;
// установить пароль
const ExData::TPROJECT *prj = FormMain->retDataProject();
const int Password = prj->surd.Pass;
FormDk->edtPassword->Text = IntToStr(Password);
// установить порт
FormDk->edtPort->Text = IntToStr(prj->surd.PORT);
// снять ручноую установку адреса
ManualNetParametrs(false);
// установить параметры связи
//ChangeDk(FormDk->cbbDk->ItemIndex);
// проверка пароля
if(FormDk->checkPasswordSURD_OK()!=anOk){
        FormDk->PageControl1->Visible = false;
        return;
        }
FormDk->PageControl1->Visible = true;
}
// выбор номера контроллера---------------------------------------------------//
void TFormDk::ChangeDk(const int NumberDk)
{
const AnsiString ip_current = pDateIp->getOneIp(NumberDk);
const int port = pDateIp->getPort();
// отображаем IP
FormDk->medtIP->Text = ip_current;
// отобразить порт
FormDk->edtPort->Text = IntToStr(port);
// изменить параметры связи.
FormMain->setActiveClientUDP(ip_current,port);//Активируем клиента
FormMain->setActiveServerUDP(port); // активируем сервер
// отображаем в шапке
setTextIP(" IP:"+ip_current+" PORT:"+IntToStr(port));
}
// событие выбора ДК
void __fastcall TFormDk::cbbDkChange(TObject *Sender)
{
// задать ID в контроллер
const int crDk = FormDk->cbbDk->ItemIndex;
ChangeDk(crDk);
}
//--------------------------------------------------------------------------
//отключить светофор
void __fastcall TFormDk::ButtonOSClick(TObject *Sender)
{
// проверка пароля
if(checkPasswordSURD_OK()!=anOk)return;
const AnsiString s = "light OS";
bool send_succ;
send_succ = FormMain->Send_Packet_UDP(s,2);
if (send_succ){
        Status("OK. ОС установлен");
        }
        else{
        Status("Ошибка");
        }
}
/*----------------------------------------------------------------------------*/
void TFormDk::sendMultiCommand(AnsiString cmd)
{
AnsiString out = "Выполнено успешно";
std::vector<AnsiString> answerErrDK;
bool send_succ;
int MaxDk = pDateIp->getCountIp();// max. IP

// сбрасываем всех, потом только мастера
for(int i=(MaxDk-1);i>=0;i--)
        {
        const AnsiString ip = pDateIp->getOneIp(i);
        const int port = pDateIp->getPort();
        FormMain->setActiveClientUDP(ip,port);//Активируем клиента
        FormMain->setActiveServerUDP(port);   // активируем сервер
        // отправляем сообщение
        send_succ = FormMain->Send_Packet_UDP(cmd,2);
        if (!send_succ){
                answerErrDK.push_back("ДК"+IntToStr(i+1));
                }
        ::Sleep(50);
        Application->ProcessMessages();
        }
// выводим сообщения
if(!answerErrDK.empty()){
        AnsiString strDk;
        for(int i=0;i<answerErrDK.size();i++)
                {
                strDk +=" "+answerErrDK[i];
                }
        out = "Ошибка опроса" +strDk;
        }
Status(out);
// предыдущие параметры связи
const int crDk = FormDk->cbbDk->ItemIndex;
ChangeDk(crDk);
}
//---------------------------------------------------------------------------
void __fastcall TFormDk::ButtonOSUrgClick(TObject *Sender)
{
// перевести все ДК в режим ОС
AnsiString ds = "Перевести в режим ОС все ДК СУРД?\n";
if (Application->MessageBox(ds.c_str(),
        "Выбрать режим ОС",
        MB_YESNO +MB_TOPMOST+ MB_ICONQUESTION)==IDYES){
     if(checkPasswordSURD_OK()!=anOk)return;
     sendMultiCommand("light OS");
     }
}
//---------------------------------------------------------------------------
// вкл работа
void __fastcall TFormDk::ButtonRUNClick(TObject *Sender)
{
// проверка пароля
if(checkPasswordSURD_OK()!=anOk)return;
AnsiString s;
bool send_succ;
s = "light undo";
send_succ = FormMain->Send_Packet_UDP(s,2);

if (send_succ){
        Status("OK. ДК включен");
        }
        else{
        Status("Ошибка");
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
// применить применить
void __fastcall TFormDk::btnNetClick(TObject *Sender)
{
int PassValue;
int PortValue;

try  {PassValue = StrToInt(edtPassword->Text.Trim());}
        catch(...){
        Application->MessageBox("Ошибка ввода пароля СУРД", "Ошибка", MB_OK);
        return;
        }
try  {PortValue = StrToInt(edtPort->Text.Trim());}
        catch(...){
        Application->MessageBox("Ошибка ввода порта ethrernet", "Ошибка", MB_OK);
        return;
        }
const AnsiString ip = medtIP->Text.Trim();
if(!IPDATA::checkAdressIP(ip)){
        Application->MessageBox("Ошибка ввода IP адреса", "Ошибка", MB_OK);
        return;
        }
// init UDP server
FormMain->setActiveServerUDP(PortValue);//Активируем сервер
// init UPD client
FormMain->setActiveClientUDP(ip,PortValue);//Активируем клиента
// показать в шапке
setTextIP(" IP:"+ip+" PORT:"+IntToStr(PortValue)+" PASSW:"+IntToStr(PassValue));
// проверка пароля
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
FormDk->Caption = "ДК в группе "+txt;
}
//---------------------------------------------------------------------------
// вызов командной консоли
void __fastcall TFormDk::btnConsolClick(TObject *Sender)
{
FormConsole->Visible = true;
}
//---------------------------------------------------------------------------
// button active surd
void __fastcall TFormDk::btnSurdClick(TObject *Sender)
{
Undo_See_OFF();
tmrSURD->Enabled = btnSurd->Down; //включитьт таймер SURD
if(!btnSurd->Down){
        updateNetDk(pDateIp); // востановить IP адреса
        }
}
//---------------------------------------------------------------------------
// timer status SURD
void __fastcall TFormDk::tmrSURDTimer(TObject *Sender)
{
FormDk->tmrSURD->Enabled =false;
const AnsiString scmd("allpollingdk"); //"allpollingdk\r"
// вывести, что получили
bool send_succ = FormMain->Send_Data_UDP(scmd);
static WORD inpsk=0;
if (send_succ){
        Status("OK");
        FormDk->Memo4->Lines->Add("/*** SURD BEGIN "+IntToStr(++inpsk)+" ***/");
        AnsiString UDP_BUFF = FormMain->retStrUDP();
        FormDk->Memo4->Lines->Add(UDP_BUFF);
        }
        else{
        Status("Ошибка");
        }
if(btnSurd->Down)
        FormDk->tmrSURD->Enabled = true;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormDk::btnRestartClick(TObject *Sender)
{
// рестарт всех ДК
AnsiString ds = "Рестарт все ДК СУРД?\n";
if (Application->MessageBox(ds.c_str(),
        "Перевести в рестарт",
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
                MessageDlg("Неверный пароль проекта!", mtError,TMsgDlgButtons() << mbOK,0);
        }
        else{
        Status("Ошибка ответа. ");
        result = noAnswer;
        MessageDlg("Ошибка соединения!", mtError,TMsgDlgButtons() << mbOK,0);
        }
return result;
}
//---------------------------------------------------------------------------
