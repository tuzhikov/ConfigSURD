//---------------------------------------------------------------------------

#ifndef weeksplansH
#define weeksplansH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TPanel *Panel1;
        TButton *Button3;
        TButton *Button4;
        TListBox *ListBox1;
        TLabel *Label1;
        TComboBox *ComboBox1;
        TPanel *Panel2;
        TLabel *Label2;
        TComboBox *ComboBox2;
        TLabel *Label3;
        TComboBox *ComboBox3;
        TLabel *Label4;
        TComboBox *ComboBox4;
        TLabel *Label5;
        TComboBox *ComboBox5;
        TLabel *Label6;
        TComboBox *ComboBox6;
        TLabel *Label7;
        TComboBox *ComboBox7;
        TLabel *Label8;
        TLabel *Label9;
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall ComboBox4Change(TObject *Sender);
        void __fastcall ComboBox5Change(TObject *Sender);
        void __fastcall ComboBox6Change(TObject *Sender);
        void __fastcall ComboBox7Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;

void Show_Form_WeeksPlans();
//---------------------------------------------------------------------------
#endif
