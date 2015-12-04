//---------------------------------------------------------------------------

#ifndef localH
#define localH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TButton *Button1;
        TButton *Button2;
        TListBox *ListBox1;
        TPanel *Panel2;
        TLabel *Label1;
        TComboBox *ComboBox1;
        TLabel *Label2;
        TComboBox *ComboBox2;
        TLabel *Label3;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TLabel *Label5;
        TComboBox *ComboBox5;
        TComboBox *ComboBox6;
        TLabel *Label6;
        TLabel *Label9;
        TLabel *Label4;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TPanel *Panel3;
        TListBox *ListBox2;
        TComboBox *ComboBox7;
        TShape *Shape3;
        TComboBox *ComboBox8;
        TComboBox *ComboBox9;
        TPanel *Panel4;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel7;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape4;
        TPanel *Panel8;
        TLabel *Label7;
        TLabel *Label8;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall ComboBox4Change(TObject *Sender);
        void __fastcall ComboBox5Change(TObject *Sender);
        void __fastcall ComboBox6Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall ComboBox7Change(TObject *Sender);
        void __fastcall ComboBox8Change(TObject *Sender);
        void __fastcall ComboBox9Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;

void Show_Form_Local();
//---------------------------------------------------------------------------
#endif
