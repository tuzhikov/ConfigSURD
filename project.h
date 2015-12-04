//---------------------------------------------------------------------------

#ifndef projectH
#define projectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------

enum TError{erPortETH,erDelayETH,erTimeSURD,erCuontSURD,erPassSURD,erEnd};
class TFormProject : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TMemo *Memo1;
        TTabSheet *TabSheet2;
        TPanel *Panel1;
        TTabSheet *TabSheet3;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TTabSheet *TabSheet4;
        TLabel *Label2;
        TTrackBar *TrackBar1;
        TPanel *Panel2;
        TLabel *Label3;
        TPanel *Panel4;
        TGroupBox *GroupBox1;
        TComboBox *ComboBoxDK;
        TLabel *Label1;
        TStringGrid *StringGridDK;
        TGroupBox *grp1;
        TCSpinEdit *edtTimeSt;
        TLabel *lbl2;
        TLabel *lbl3;
        TCSpinEdit *edtTimeCN;
        TCheckBox *chkGPS;
        TBevel *bvl1;
        TLabel *lblPORT;
        TEdit *EditPort;
        TLabel *lblPass;
        TMaskEdit *medtPass;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ComboBoxDKChange(TObject *Sender);
private:	// User declarations
        bool changeData;
        BYTE tmpMAxDK;
        void BuildTableIP(const int RowCount);
        void messageError(TError err);
public:		// User declarations
        __fastcall TFormProject(TComponent* Owner);
        void showFormProject(void);
        bool retChangeData(void){ // קעוםטו פכאדא סמ סבנמסמל
                bool tmp = changeData; changeData = false;return tmp;}
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProject *FormProject;

#endif
