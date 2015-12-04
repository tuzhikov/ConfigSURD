/*----------------------------------------------------------------------------*/
#ifndef fazasH
#define fazasH
/*----------------------------------------------------------------------------*/
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "structures.h"
/*----------------------------------------------------------------------------*/
class TfrPhaseTemplate : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TStringGrid *StringGrid1;
        TButton *btnClose;
        TButton *btnSave;
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
private:	// User declarations
        ExData::TPROJECT   tempProject; // храним временно
        void showPhases(void);
public:		// User declarations
        __fastcall TfrPhaseTemplate(TComponent* Owner);
        void showFormPhase(const ExData::TPROJECT *pPrj);
};
/*----------------------------------------------------------------------------*/
extern PACKAGE TfrPhaseTemplate *frPhaseTemplate;

/*----------------------------------------------------------------------------*/
#endif
