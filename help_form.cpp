//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "help_form.h"
#include "Unit1.h"
#include "crc32.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormHelp *FormHelp;
//---------------------------------------------------------------------------
__fastcall TFormHelp::TFormHelp(TComponent* Owner)
        : TForm(Owner)
{

FormHelp->lblVer->Caption =
        IntToStr(FormMain->retVersion()->Maj_Version) + "."
        + IntToStr(FormMain->retVersion()->Min_Version) + "."
        + IntToStr(FormMain->retVersion()->Revision)+ "."
        + IntToStr(FormMain->retVersion()->Build) + " "
        //+ FormMain->retVIS()->file_name+ " " 
        + AnsiString(__DATE__);
}
//---------------------------------------------------------------------------
void __fastcall TFormHelp::Button1Click(TObject *Sender)
{
FormHelp->Visible = false;
}
//---------------------------------------------------------------------------
void TFormHelp::VisibledHelp(void)
{
FormHelp->Visible = true;
FormMain->makeProject(0); // собрать проект для отображение CRC32
__int64 CRC32 = PAP_RINGS[0].CRC32;
lblIDP->Caption = "IDP_SURD: " +IntToStr(CRC32);
}
