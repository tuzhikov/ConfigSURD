//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frame_dk.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrame3 *Frame3;
//---------------------------------------------------------------------------
__fastcall TFrame3::TFrame3(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrame3::Button1Click(TObject *Sender)
{
        Frame3->Color= clRed;        
}
//---------------------------------------------------------------------------

