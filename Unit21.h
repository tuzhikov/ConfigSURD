//---------------------------------------------------------------------------

#ifndef Unit21H
#define Unit21H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm21 : public TForm
{
__published:	// IDE-managed Components
        TRadioGroup *RadioGroup1;
        TEdit *Edit1;
        TLabel *Label2;
        TButton *Button1;
        TButton *Button2;
        TEdit *Edit2;
        TUpDown *UpDown1;
        TLabel *Label3;
        TBevel *Bevel1;
        TLabel *Label1;
        TEdit *Edit3;
        TUpDown *UpDown2;
        TBevel *Bevel2;
        TLabel *Label4;
        TMemo *Memo1;
        TLabel *Label5;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm21(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm21 *Form21;
//---------------------------------------------------------------------------
#endif
