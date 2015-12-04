//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "weeksplans.h"
#include "progutil.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

   TPROJECT   CW_PAP; //копия
   int   cur_wplan=0;

//---------------------------------------------------------------------------
void Show_WeekPlan()
{
        int i;
        //
        i = CW_PAP.WeeksPlans[cur_wplan].Calendar[0];
        Form4->ComboBox1->ItemIndex = i;
        //
        i = CW_PAP.WeeksPlans[cur_wplan].Calendar[1];
        Form4->ComboBox2->ItemIndex = i;
        //
        i = CW_PAP.WeeksPlans[cur_wplan].Calendar[2];
        Form4->ComboBox3->ItemIndex = i;
        //
        i = CW_PAP.WeeksPlans[cur_wplan].Calendar[3];
        Form4->ComboBox4->ItemIndex = i;
        //
        i = CW_PAP.WeeksPlans[cur_wplan].Calendar[4];
        Form4->ComboBox5->ItemIndex = i;
        //
        i = CW_PAP.WeeksPlans[cur_wplan].Calendar[5];
        Form4->ComboBox6->ItemIndex = i;
        //
        i = CW_PAP.WeeksPlans[cur_wplan].Calendar[6];
        Form4->ComboBox7->ItemIndex = i;
        //

}
//---------------------------------------------------------------------------
void Show_Form_WeeksPlans()
{
        memcpy(&CW_PAP, &PAP, sizeof(PAP));
        //
        Form4->ListBox1->ItemIndex=cur_wplan;
        //Form4->StringGrid1->Refresh();
        //
        Show_WeekPlan();
        //
        Form4->BringToFront();
        Form4->Visible = true;
        //



}
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender)
{
        Form4->Visible =false;
        memcpy(&PAP.WeeksPlans, &CW_PAP.WeeksPlans, sizeof(TWEEKCALENDAR)*MaxWeeksPlans);
        //
        FormMain->retVIS()->is_edit=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button4Click(TObject *Sender)
{
        Form4->Visible =false;

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
        ///
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
        
        for (int i=0; i< MaxDaysPlans; i++)
        {
                Form4->ComboBox1->Items->Add(IntToStr(i+1));
                Form4->ComboBox2->Items->Add(IntToStr(i+1));
                Form4->ComboBox3->Items->Add(IntToStr(i+1));
                Form4->ComboBox4->Items->Add(IntToStr(i+1));
                Form4->ComboBox5->Items->Add(IntToStr(i+1));
                Form4->ComboBox6->Items->Add(IntToStr(i+1));
                Form4->ComboBox7->Items->Add(IntToStr(i+1));

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ListBox1Click(TObject *Sender)
{
//
        int i = this->ListBox1->ItemIndex;
        cur_wplan = i;
        Show_WeekPlan();

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
        //
        int i = this->ComboBox1->ItemIndex;
        CW_PAP.WeeksPlans[cur_wplan].Calendar[0] = i;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox2Change(TObject *Sender)
{
        int i = this->ComboBox2->ItemIndex;
        CW_PAP.WeeksPlans[cur_wplan].Calendar[1] = i;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox3Change(TObject *Sender)
{
      int i = this->ComboBox3->ItemIndex;
        CW_PAP.WeeksPlans[cur_wplan].Calendar[2] = i;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox4Change(TObject *Sender)
{
      int i = this->ComboBox4->ItemIndex;
        CW_PAP.WeeksPlans[cur_wplan].Calendar[3] = i;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox5Change(TObject *Sender)
{
      int i = this->ComboBox5->ItemIndex;
        CW_PAP.WeeksPlans[cur_wplan].Calendar[4] = i;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox6Change(TObject *Sender)
{
int i = this->ComboBox6->ItemIndex;
        CW_PAP.WeeksPlans[cur_wplan].Calendar[5] = i;

}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox7Change(TObject *Sender)
{
     int i = this->ComboBox7->ItemIndex;
        CW_PAP.WeeksPlans[cur_wplan].Calendar[6] = i;

}
//---------------------------------------------------------------------------

