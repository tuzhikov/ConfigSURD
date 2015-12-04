//---------------------------------------------------------------------------

#ifndef guardH
#define guardH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include "structures.h"
//---------------------------------------------------------------------------
class TFormGuard : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TButton *btnSave;
        TButton *btnClose;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TStringGrid *StringGrid1;
        TTabSheet *TabSheet2;
        TStringGrid *StringGrid2;
        TTabSheet *TabSheet3;
        TPanel *Panel2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *lbl1;
        TEdit *edtMinRed;
        TEdit *edtMinYellow;
        TEdit *Edit4;
        TEdit *edtMinGreen;
        TEdit *edtMaxTimeManual;
        TEdit *edtTimeClear;
        TComboBox *cbbFilling;
        TPanel *pnl1;
        TLabel *lbl4;
        TLabel *lbl5;
        TEdit *edtDelayTP;
        TComboBox *cbbTypeTP;
        TTabSheet *TabSheet4;
        TLabel *Label13;
        TLabel *Label16;
        TLabel *Label17;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TEdit *edtKK;
        TLabel *lbl2;
        TLabel *lbl3;
        TBevel *bvl1;
        void __fastcall btnSaveClick(TObject *Sender);
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall StringGrid1SetEditText(TObject *Sender, int ACol,
          int ARow, const AnsiString Value);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid2DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall StringGrid2KeyPress(TObject *Sender, char &Key);
        void __fastcall StringGrid2SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        
private:	// User declarations
        ExData::TPROJECT   CG_PAP; //копия
        int cur_col;
        int cur_row;
        /*---------------------*/
        void showGuard(void);
public:		// User declarations
        __fastcall TFormGuard(TComponent* Owner);
        void showFormGuard(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGuard *FormGuard;

#endif
