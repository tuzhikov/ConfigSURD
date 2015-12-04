//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit12.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConsole *FormConsole;
//---------------------------------------------------------------------------
__fastcall TFormConsole::TFormConsole(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormConsole::btnSendClick(TObject *Sender)
{
FormMain->IdUDPClient->Send(FormConsole->edtCommand->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormConsole::cbbTemplateCmdChange(TObject *Sender)
{
FormConsole->edtCommand->Text= FormConsole->cbbTemplateCmd->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormConsole::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
// key "enter" down
if (Key==13){
        FormMain->IdUDPClient->Send(FormConsole->edtCommand->Text);
        }
}
//---------------------------------------------------------------------------

