//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit18.h"
#include "Unit1.h"
#include "communic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm18 *Form18;

//---------------------------------------------------------------------------
void Show_GroupBox()
{
        if (Form18->RadioButton1->Checked)
        {
            Form18->GroupBox1->Visible=false;
            Form18->GroupBox2->Visible=true;
        }
        else
        {
            Form18->GroupBox2->Visible=false;
            Form18->GroupBox1->Visible=true;
        }
}
//---------------------------------------------------------------------------
void  Show_Form18()
{
        AnsiString   s;
        ////////////////////
        Form18->RadioGroup1->ItemIndex = prog_info.com_n-1;
          //com_name = "COM" + IntToStr(prog_info.com_n);
        Form18->MaskEdit3->Text = IntToStr(prog_info.ip_time_out);
           //read_time_out_ip = prog_info.ip_time_out;
        //Form18->RadioButton2->Checked = prog_info.com_usb;
           //COM_TYP = prog_info.com_usb;
        Form18->CheckBox1->Checked = prog_info.is_usb;
          // IS_USB = prog_info.is_usb;
        if (prog_info.com_usb)
           { Form18->RadioButton2->Checked = true; Form18->RadioButton1->Checked = false;;}
           else
           { Form18->RadioButton1->Checked = true; Form18->RadioButton2->Checked = false;  }
        ///
        s = AnsiString(prog_info.ip_addr);
         Form18->MaskEdit1->Text = s;
        //memcpy(&prog_info.ip_addr[0],s.c_str(),s.Length());
        //
        s = IntToStr(prog_info.ip_port);
        Form18->Edit1->Text = s;
        //////////////////
        Show_GroupBox();
        /////
        Form18->GroupBox1->Refresh();
        Form18->GroupBox2->Refresh();
        //
        Form18->Visible = true;
        //
}
//---------------------------------------------------------------------------
__fastcall TForm18::TForm18(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//OK -сохранение
void __fastcall TForm18::Button1Click(TObject *Sender)
{
        AnsiString   s;
        int  i_conv, f_err(0);
        ///////////////
        //f_err = 0;
        //Init_Params();
        prog_info.com_n = Form18->RadioGroup1->ItemIndex +1;
          //com_name = "COM" + IntToStr(prog_info.com_n);
        prog_info.ip_time_out = StrToInt(Form18->MaskEdit3->Text.Trim());
           //read_time_out_ip = prog_info.ip_time_out;
        prog_info.com_usb = Form18->RadioButton2->Checked;
           COM_TYP = prog_info.com_usb;
        prog_info.is_usb = Form18->CheckBox1->Checked;
          // IS_USB = prog_info.is_usb;
        s = Form18->MaskEdit1->Text;
        memcpy(&prog_info.ip_addr[0],s.c_str(),s.Length());
        //
        __try  { i_conv = StrToInt(Form18->Edit1->Text);}
           __except(EXCEPTION_EXECUTE_HANDLER)    { i_conv = -1; f_err=1;}
        if (i_conv>-1)
           prog_info.ip_port = i_conv;
        //////////////////
        //сохраняем
        Save_INI_File();
        //////
        if (!f_err)
         Form18->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm18::Button2Click(TObject *Sender)
{
        ///////
        Form18->CheckBox1->Checked = false;
        Form18->Visible = false;
        //
}
//---------------------------------------------------------------------------
void __fastcall TForm18::RadioButton1Click(TObject *Sender)
{

        //Form18->GroupBox1->Visible=false;
        //Form18->GroupBox2->Visible=true;
        Show_GroupBox();



}
//---------------------------------------------------------------------------

void __fastcall TForm18::z(TObject *Sender)
{
        ///
        //
        //Form18->GroupBox2->Visible=false;
        //Form18->GroupBox1->Visible=true;
        Show_GroupBox();


}
//---------------------------------------------------------------------------

