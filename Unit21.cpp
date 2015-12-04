//---------------------------------------------------------------------------
//
#include <vcl.h>
#pragma hdrstop

#include "Unit21.h"
#include "Unit1.h"
#include "Unit18.h"
#include "Unit11.h"
#include "communic.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm21 *Form21;

  char  buf21[32];
  extern char        buf_synt[65000]; //выгрузка программ
  char               buf_diff[10000];
  int b_s_all;
//---------------------------------------------------------------------------
// Выдать текстовое значение программы 1..32, ЖМ, ОС, КК
AnsiString  Get_TXT_Prog_Name(int   i_prog)
{
        AnsiString   s_prog;
        //////////
        s_prog = IntToStr(i_prog +1);
        //
        if (i_prog > 33)
        {
           switch (i_prog)
           {
            case 50: {s_prog = "ЖМ"; break;}
            case 51: {s_prog = "ОС"; break;}
            case 52: {s_prog = "КК"; break;}
           }//switch
        }
        /////
        return (s_prog);

}
//---------------------------------------------------------------------------
AnsiString  Get_Bits(unsigned char ch)
{
        AnsiString  s;
        unsigned char  b=1;
        ////////////////
        s = "";
        for (int i=0; i<8; i++)
        {
          if (ch & b) s =s + "1";
          else   s = s + "0";
          //
          b=b*2;
        }
        //
        return (s);

}
//---------------------------------------------------------------------------
__fastcall TForm21::TForm21(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
//
void __fastcall TForm21::Button1Click(TObject *Sender)
{
        int     i, err, w_r_err, i_ret, i_prog, i_day,iw;
        int     try_i, ret_i, packs_send;
        int     i_op, time_out, ret_Check_Ans;
        AnsiString   s,s1, s_time, s_ans, s_mul;
        TDateTime  now;
        WORD    dif_w;
        ////////////
        err = 0;
        w_r_err = 1;
        b_s_all = 0;
        //
        //com_name = "COM" + IntToStr(Form18->RadioGroup1->ItemIndex + 1);
        //
        Form21->Edit1->Text = "";
        //Open_COM(9600);
        DBG_Write("Try Connect",0,'c');
        i_ret = Connect_DK();
        //
        now = Now();
        s_time = " [ "+TimeToStr(now) + " ]";
        //
        if (!i_ret)
        {
           //
           i = Form21->RadioGroup1->ItemIndex;
           switch (i)
           {
              case 0: {i_op = DEF_COMM_GM; break;}
              case 1: {i_op = DEF_COMM_OS; break;}
              case 2: {i_op = DEF_COMM_UNDO; break;}
              case 3: {i_op = DEF_COMM_START_PROG; break;}
              case 4: {i_op = DEF_COMM_SYNH; break;}
              case 5: {i_op = DEF_COMM_LOAD_PROG; break;}
              case 6: {i_op = DEF_COMM_LOAD_DAY; break;}
              case 7: {i_op = DEF_COMM_SEE_MGR; break;}
              case 8:{i_op = DEF_COMM_START_FASE; break;}
              case 9:{i_op = DEF_COMM_SEE_SOST; break;}
              case 10:{i_op = DEF_COMM_SEE_CURRENT; break;}

           }
           ///

           b_s_all = 0;
           //////
           //Save_To_Project();
           //
           i_prog = Form21->UpDown1->Position;
           i_day = Form21->UpDown2->Position;
           //

           while (Create_Paket(i_op, i_prog, i_day) && w_r_err)
           {
               ret_i = -1;
               //
               for (try_i=0; try_i<3; try_i++)
               {
                  memset (buf_ans,0,100);
                  memset (buf_synt,0,100);
                  //buf_synt
                  if (prog_info.com_usb == 0)
                  {
                    DBG_Write(buf_paket,buf_paket_n,'h');
                    Write_Data(h_com_port, buf_paket, buf_paket_n, buf_paket_n * 2);
                    time_out = prog_info.ip_time_out;
                    //////
                    //if (IS_USB)
                      buf_ans_n=Read_Data(h_com_port, buf_ans, prog_info.ip_time_out, prog_info.ip_time_out);
                      DBG_Write(buf_ans,buf_ans_n,'h' );
                    // else
                    //  Read_Data(h_com_port, buf_ans, time_out, time_out);
                  }//if (COM_TYP == 0)
                  ///
                  if (prog_info.com_usb == 1)
                   {
                      DBG_Write(buf_paket,buf_paket_n,'h');
                      buf_ans_n = Write_Read_IP(buf_paket,buf_ans,buf_paket_n,prog_info.ip_time_out);
                      DBG_Write(buf_ans, buf_ans_n, 'h');
                   }// ==1
                  ///

                  //
                  ret_Check_Ans = Check_Ans(i_op);
                  if (ret_Check_Ans==DEF_COMM_STATUS_OK)  //если прошел ответ - запоминаем, с какого раза
                  {
                  ret_i = try_i;

                    if (i_op == DEF_COMM_SEE_MGR)
                    {
                      s1 = Get_Bits(buf_synt[0]) + " ";
                      s1 =s1+ Get_Bits(buf_synt[1]) + " ";
                      s1 =s1+ Get_Bits(buf_synt[2]) + " ";
                      //memset(buf21,0,20);
                      //BinToHex(buf_synt,buf21,3);
                      //s1 = AnsiString(buf21);
                      s = s1 + " " + s;
                    }
                    ///
                   if (i_op == DEF_COMM_SEE_SOST)
                    {
                      int i_pr = answer_dk.CurrentProgram;
                      int i_faz = answer_dk.CurrentFasa;
                      //
                      s = " Программа = " + Get_TXT_Prog_Name(i_pr);
                      if (i_pr<33) s  = s +  ", фаза = " + IntToStr(i_faz +1);
                      //
                    }
                    ///
                    if (i_op == DEF_COMM_SEE_CURRENT)
                    {
                      Form21->Memo1->Clear();
                      //if (answer_dk.Teaching) Form33->Memo1->Lines->Add("Идет обучение");
                      for (int i_mul=0; i_mul<8; i_mul++)
                      {
                        s_mul ="МУЛ№" + IntToStr(i_mul+1)+ ". ";
                        //
                        for (int i_ch=0; i_ch<6; i_ch++)
                        {
                          dif_w = answer_dk.MulCurrents[6*i_mul + i_ch];
                          iw=dif_w;
                          s_mul = s_mul + IntToStr(iw) + "; ";
                        }
                        //
                        Form21->Memo1->Lines->Add(s_mul);
                      }//for i_mul
                      //
                      if (answer_dk.FaultMul==0) Form21->Memo1->Lines->Add("----------");
                      else
                      {
                        Form21->Memo1->Lines->Add("Сбой: ");
                        Form21->Memo1->Lines->Add("МУЛ № " + IntToStr(answer_dk.FaultMul));
                        Form21->Memo1->Lines->Add("Канал № " + IntToStr(answer_dk.FaultChannel));

                      }


                      //int i_pr = answer_dk.CurrentProgram;
                      //int i_faz = answer_dk.CurrentFasa;
                      //
                      //s = " Программа = " + Get_TXT_Prog_Name(i_pr);
                      //if (i_pr<33) s  = s +  ", фаза = " + IntToStr(i_faz +1);
                      //
                      //Form33->Visible = true;
                    }
                    ///

                    //
                    Form21->Edit1->Text = "Операция № " + IntToStr(i_op -1) + " - ОК!   " + s + s_time;
                    break;
                  }//if
               }//for
               /////////////////
               if (ret_i !=-1)  //пакет прошел
               {
                 err = 1;
                 packs_send++;

               }//<>100
               else
               {
                   // пакет не прошел с 3-х попыток
                   err = 0;
                   //
                   switch (ret_Check_Ans)
                   {
                     case DEF_COMM_STATUS_NOT_OK : {s_ans="Запрос не принят"; break;}
                     case DEF_COMM_STATUS_ANSWER_BAD : {s_ans="Некорректный ответ"; break;}
                     case DEF_COMM_STATUS_NO_ANSWER : {s_ans="Нет ответа"; break;}
                   }
                   //s_ans =
                   Form21->Edit1->Text = "Операция № " + IntToStr(i_op -1) + " - ОШИБКА!   " + s + " " + s_ans;
                   break;
               }
           } // while
           /////////
           //Dis_Connect_DK();
        }//if !ret - соединились
        else
        {
           //now = Now();
           //s = TimeToStr(now);
           Form21->Edit1->Text = "НЕТ соединения!!!   " + s_time;
           DBG_Write("No Connect",0,'c');
        }
        //////
        Dis_Connect_DK();
        //Close_COM();

        ///////////

}
//---------------------------------------------------------------------------

void __fastcall TForm21::Button2Click(TObject *Sender)
{
        ////////////
        Form21->Visible = false;
        //        
}
//---------------------------------------------------------------------------

