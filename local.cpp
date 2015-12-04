//---------------------------------------------------------------------------

#include <vcl.h>
#include <list.h>
#pragma hdrstop

#include "local.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

  int cur_mul=0;
  int cur_tramv =0;
  TPROJECT   CM_PAP; //копия
  //
  list <BYTE> tram_napr_left;
  list <BYTE> tram_napr_centr;
  list <BYTE> tram_napr_right;



//---------------------------------------------------------------------------
AnsiString GET_TXT_NAPR(int napr_i)
{
        AnsiString s_add="";
        ///
        switch (CM_PAP.Directs.OneDirect[napr_i].Type)
           {
              case 0: {s_add = "транспорт"; break;}
              case 1: {s_add = "пешеход";   break;}
              case 2: {s_add = "поворот";   break;}
              case 3: {s_add = "реверс";   break;}
              case 4: {s_add = "трам-лево";   break;}
              case 5: {s_add = "трам-право";   break;}
              case 6: {s_add = "трам-прямо";   break;}

           }
        ///
        return (s_add);
}
//---------------------------------------------------------------------------
AnsiString GET_TXT_COLOR(int col)
{
        AnsiString s_add="";
        ///
        switch (col)
           {
              case 0: {s_add = "КРАСНЫЙ"; break;}
              case 1: {s_add = "ЗЕЛЕНЫЙ";   break;}
              case 2: {s_add = "ЖЕЛТЫЙ";   break;}
              case 3: {s_add = "трам-ЛЕВО";   break;}
              case 4: {s_add = "трам-НАПРАВО";   break;}
              case 5: {s_add = "трам-ПРЯМО";   break;}
              case 6: {s_add = "трам-СТОП";   break;}


           }
        ///
        return (s_add);
}
//---------------------------------------------------------------------------
void Post_Proc()
{

        Form6->ComboBox2->Enabled = Form6->ComboBox1->ItemIndex;
        Form6->ComboBox4->Enabled = Form6->ComboBox3->ItemIndex;
        Form6->ComboBox6->Enabled = Form6->ComboBox5->ItemIndex;


}
//---------------------------------------------------------------------------
void Post_Proc_Tram(TObject *Sender)
{
     TComboBox *comb = (TComboBox *)Sender;
     if (comb->ItemIndex==0)
      return;
     ////
     AnsiString s = comb->Text;
     if (!s.Pos("трам"))
       comb->ItemIndex=0;


}
//---------------------------------------------------------------------------
void Show_MUL()
{
        Form6->ComboBox1->ItemIndex = CM_PAP.Muls.OneMUL[cur_mul].red.napr;
        Form6->ComboBox2->ItemIndex = CM_PAP.Muls.OneMUL[cur_mul].red.color;
        //
        Form6->ComboBox3->ItemIndex = CM_PAP.Muls.OneMUL[cur_mul].yel.napr;
        Form6->ComboBox4->ItemIndex = CM_PAP.Muls.OneMUL[cur_mul].yel.color;
        //
        Form6->ComboBox5->ItemIndex = CM_PAP.Muls.OneMUL[cur_mul].green.napr;
        Form6->ComboBox6->ItemIndex = CM_PAP.Muls.OneMUL[cur_mul].green.color;
        ///
        Form6->ComboBox7->ItemIndex = CM_PAP.Muls.OneTRAMVAY[cur_tramv].left.napr;
        Form6->ComboBox9->ItemIndex = CM_PAP.Muls.OneTRAMVAY[cur_tramv].right.napr;
        Form6->ComboBox8->ItemIndex = CM_PAP.Muls.OneTRAMVAY[cur_tramv].center.napr;
        ///
        Post_Proc();


}
//---------------------------------------------------------------------------
void Show_Form_Local()
{
   AnsiString s;
   memcpy(&CM_PAP, &PAP, sizeof(PAP));
   //

   Form6->ListBox1->Clear();
   Form6->ListBox2->Clear();
   ///
   tram_napr_left.clear();
   tram_napr_right.clear();
   tram_napr_centr.clear();


   //int mul_n = CM_PAP.AmountMuls;
   int mul_n = MaxMULBlocks;
   for (int i=0; i< mul_n; i++)
        Form6->ListBox1->Items->Add(IntToStr(i+1));
   //
   for (int i=0; i< MaxTramvays; i++)
        Form6->ListBox2->Items->Add(IntToStr(i+1));

   //
   Form6->ComboBox1->Clear();
   Form6->ComboBox2->Clear();
   Form6->ComboBox3->Clear();
   Form6->ComboBox4->Clear();
   Form6->ComboBox5->Clear();
   Form6->ComboBox6->Clear();
   //
   Form6->ComboBox7->Clear();
   Form6->ComboBox8->Clear();
   Form6->ComboBox9->Clear();
   //Form6->ComboBox10->Clear();


   Form6->ComboBox1->Items->Add("НЕТ");
   Form6->ComboBox3->Items->Add("НЕТ");
   Form6->ComboBox5->Items->Add("НЕТ");
   //
   Form6->ComboBox7->Items->Add("НЕТ");
   Form6->ComboBox8->Items->Add("НЕТ");
   Form6->ComboBox9->Items->Add("НЕТ");



   //
   for (int i=0; i< CM_PAP.AmountDirects; i++)
   {
        s = GET_TXT_NAPR(i);
        Form6->ComboBox1->Items->Add(IntToStr(i+1) + " " + s );
        Form6->ComboBox3->Items->Add(IntToStr(i+1) + " " + s );
        Form6->ComboBox5->Items->Add(IntToStr(i+1) + " " + s );
        ///
        if (!s.Pos("трам"))
          s="";
        //  
        {

          Form6->ComboBox7->Items->Add(IntToStr(i+1) + " " + s );
          Form6->ComboBox8->Items->Add(IntToStr(i+1) + " " + s );
          Form6->ComboBox9->Items->Add(IntToStr(i+1) + " " + s );
        }
   }
   //
   for (int i=0; i< MUL_COLOR_COUNT; i++)
   {
        Form6->ComboBox2->Items->Add(" " + GET_TXT_COLOR(i) );
        Form6->ComboBox4->Items->Add(" " + GET_TXT_COLOR(i) );
        Form6->ComboBox6->Items->Add(" " + GET_TXT_COLOR(i) );

   }

   Form6->ListBox1->ItemIndex=cur_mul;
   Form6->ListBox2->ItemIndex=cur_tramv;

   //
   Show_MUL();
   ////
   Form6->BringToFront();
   Form6->Visible = true;
}
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button1Click(TObject *Sender)
{
        Form6->Visible = false;
        memcpy(&PAP.Muls, &CM_PAP.Muls, sizeof(TMULS));

}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
     Form6->Visible = false;        
}
//---------------------------------------------------------------------------


void __fastcall TForm6::ListBox1Click(TObject *Sender)
{
 //
        int i = Form6->ListBox1->ItemIndex;
        cur_mul = i;
        Show_MUL();

}
//---------------------------------------------------------------------------
void __fastcall TForm6::ComboBox1Change(TObject *Sender)
{
        CM_PAP.Muls.OneMUL[cur_mul].red.napr =  Form6->ComboBox1->ItemIndex;
        Post_Proc();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox2Change(TObject *Sender)
{
        CM_PAP.Muls.OneMUL[cur_mul].red.color =  Form6->ComboBox2->ItemIndex;
        Post_Proc();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox3Change(TObject *Sender)
{
     CM_PAP.Muls.OneMUL[cur_mul].yel.napr =  Form6->ComboBox3->ItemIndex;
        Post_Proc();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox4Change(TObject *Sender)
{
     CM_PAP.Muls.OneMUL[cur_mul].yel.color =  Form6->ComboBox4->ItemIndex;
        Post_Proc();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox5Change(TObject *Sender)
{
    CM_PAP.Muls.OneMUL[cur_mul].green.napr = Form6->ComboBox5->ItemIndex;
        Post_Proc();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox6Change(TObject *Sender)
{
    CM_PAP.Muls.OneMUL[cur_mul].green.color =  Form6->ComboBox6->ItemIndex;
        Post_Proc();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormCreate(TObject *Sender)
{
        ///
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ListBox2Click(TObject *Sender)
{
        int i = Form6->ListBox2->ItemIndex;
        cur_tramv = i;
        Show_MUL();

}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox7Change(TObject *Sender)
{
        //Post_Proc_Tram(Sender);
        int i_napr = Form6->ComboBox7->ItemIndex;
        if (i_napr==0)
          return;
        //
        if (CM_PAP.Directs.OneDirect[i_napr-1].Type==DIRECT_TRAM_L)
           CM_PAP.Muls.OneTRAMVAY[cur_tramv].left.napr =  Form6->ComboBox7->ItemIndex;
        Show_MUL();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox8Change(TObject *Sender)
{
        int i_napr = Form6->ComboBox8->ItemIndex;
        if (i_napr==0)
          return;
        //
        if (CM_PAP.Directs.OneDirect[i_napr-1].Type==DIRECT_TRAM_F)
                CM_PAP.Muls.OneTRAMVAY[cur_tramv].center.napr =  Form6->ComboBox8->ItemIndex;
        ///
        Show_MUL();
        //

}
//---------------------------------------------------------------------------
//
void __fastcall TForm6::ComboBox9Change(TObject *Sender)
{
        int i_napr = Form6->ComboBox9->ItemIndex;
        if (i_napr==0)
          return;
        //
        if (CM_PAP.Directs.OneDirect[i_napr-1].Type==DIRECT_TRAM_R)
                CM_PAP.Muls.OneTRAMVAY[cur_tramv].right.napr =  Form6->ComboBox9->ItemIndex;
        ///
        Show_MUL();
        //

}
//---------------------------------------------------------------------------


