//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "year.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;

   int cur_week=0;
   TPROJECT   CY_PAP; //копия

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void Check_Year_Plan()
{
        AnsiString s;
        int i_conv;
        /////
        for (int i=0; i<WeeksInYear; i++)
        {
          s = Form5->StringGrid1->Cells[1][i+1];
          if (TryStrToInt(s,i_conv))
             if ((i_conv>0) && (i_conv<=MaxWeeksPlans))
                CY_PAP.Year.YearCalendar[i] = i_conv-1;

        }
        //
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void Show_Year()
{
      //Form5->ListBox1->ItemIndex = cur_week;
      //Form5->ComboBox1->ItemIndex =
      //    CY_PAP.Year.YearCalendar[cur_week];
      ///
      for (int i=0; i<WeeksInYear; i++)
        {
          Form5->StringGrid1->Cells[1][i+1] = CY_PAP.Year.YearCalendar[i]+1;
        }
        ///



}
//---------------------------------------------------------------------------

void Show_Form_Year()
{
        memcpy(&CY_PAP, &PAP, sizeof(PAP));
        //
        Form5->BringToFront();
        Show_Year();
        //Form5->ListBox1->ItemIndex=cur_week;
        Form5->Visible = true;
}
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)
{
        for (int i=0; i< WeeksInYear; i++)
        {
           Form5->ComboBox1->Items->Add(IntToStr(i+1));
           Form5->ComboBox2->Items->Add(IntToStr(i+1));
        }
        ///
        for (int i=0; i< MaxWeeksPlans; i++)
          Form5->ComboBox3->Items->Add(IntToStr(i+1));
        ///
        Form5->ComboBox1->ItemIndex=0;
        Form5->ComboBox2->ItemIndex=5;
        Form5->ComboBox3->ItemIndex = 0;

        Show_Year();
        //////
        Form5->StringGrid1->RowCount = WeeksInYear+1;
        Form5->StringGrid1->ColCount = 2;
        Form5->StringGrid1->Cells[0][0] = "№ недели";
        Form5->StringGrid1->Cells[1][0] = "Нед. план";

        Form5->StringGrid1->ColWidths[0] = 150;
        Form5->StringGrid1->ColWidths[1] = 100;

        //Form5->StringGrid1->RowHeights[0]=30;
        //Form5->StringGrid1->RowHeights[1]=30;
        //
        for (int i=0; i<WeeksInYear; i++)
        {
          Form5->StringGrid1->Cells[0][i+1] = IntToStr(i+1);
          Form5->StringGrid1->RowHeights[i] = 25;
        }
        ///


}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
        Check_Year_Plan();
        Show_Year();
        //Form5->Visible = false;
        memcpy(&PAP.Year, &CY_PAP.Year, sizeof(TYEARCALENDAR));
        //
        FormMain->retVIS()->is_edit=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
        Form5->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBox1Change(TObject *Sender)
{
         //CY_PAP.Year.YearCalendar[cur_week] =
         //   Form5->ComboBox1->ItemIndex ;
         //
         Show_Year();

}
//---------------------------------------------------------------------------


void __fastcall TForm5::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
        ///
        Check_Year_Plan();
        cur_week = ACol-1;

        Show_Year();
}
//---------------------------------------------------------------------------
//Установить
void __fastcall TForm5::Button3Click(TObject *Sender)
{
        int i,i1,i2, zn;
        ///
        i1 = Form5->ComboBox1->ItemIndex;
        i2 = Form5->ComboBox2->ItemIndex;
        zn = Form5->ComboBox3->ItemIndex;
        //
        if (i2<i1)
        {
          i=i2; i2=i1; i1=i;
        }
        ///
        for (i=i1; i<=i2; i++)
        {
          CY_PAP.Year.YearCalendar[i]=zn;

        }
        //
        Show_Year();

}
//---------------------------------------------------------------------------

