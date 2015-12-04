//---------------------------------------------------------------------------

#ifndef help_formH
#define help_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormHelp : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TLabel *Label1;
        TLabel *lblVer;
        TLabel *lblIDP;
        TBevel *bvl;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormHelp(TComponent* Owner);
        void VisibledHelp(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHelp *FormHelp;
//---------------------------------------------------------------------------
#endif
