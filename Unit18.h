//---------------------------------------------------------------------------

#ifndef Unit18H
#define Unit18H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>

 void  Show_Form18();
//---------------------------------------------------------------------------
class TForm18 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TMaskEdit *MaskEdit1;
        TLabel *Label2;
        TLabel *Label3;
        TMaskEdit *MaskEdit3;
        TEdit *Edit1;
        TGroupBox *GroupBox2;
        TRadioGroup *RadioGroup1;
        TCheckBox *CheckBox1;
        TLabel *Label4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall z(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm18(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm18 *Form18;
//---------------------------------------------------------------------------
#endif
