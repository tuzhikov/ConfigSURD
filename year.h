//---------------------------------------------------------------------------

#ifndef yearH
#define yearH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TPanel *Panel1;
        TButton *Button1;
        TButton *Button2;
        TStringGrid *StringGrid1;
        TPanel *Panel2;
        TComboBox *ComboBox1;
        TPanel *Panel3;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TButton *Button3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;

void Show_Form_Year();
//---------------------------------------------------------------------------
#endif
