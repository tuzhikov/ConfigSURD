//---------------------------------------------------------------------------

#ifndef Unit12H
#define Unit12H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormConsole : public TForm
{
__published:	// IDE-managed Components
        TEdit *edtCommand;
        TMemo *mmoOut;
        TButton *btnSend;
        TComboBox *cbbTemplateCmd;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall btnSendClick(TObject *Sender);
        void __fastcall cbbTemplateCmdChange(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TFormConsole(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConsole *FormConsole;
//---------------------------------------------------------------------------
#endif
