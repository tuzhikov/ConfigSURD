//---------------------------------------------------------------------------

#ifndef dayplansH
#define dayplansH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include "structures.h"
//---------------------------------------------------------------------------
class TFormPlansDay : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid;
        TPanel *pnlBut;
        TButton *btnOk;
        TButton *btnExit;
        TListBox *ListBox;
        TPanel *pnlPlan;
        TToolBar *ToolBar2;
        TDateTimePicker *dtpDateTime;
        TSplitter *Splitter4;
        TLabel *Label1;
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall btnOkClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ListBoxClick(TObject *Sender);
        void __fastcall StringGridSelectCell(TObject *Sender, int ACol,
                                int ARow, bool &CanSelect);
        void __fastcall dtpDateTimeChange(TObject *Sender);
private:	// User declarations
        int  currentPlan;    // текущий выбранный план
        int  currentTimeSlot;// текущие время фазы
        ExData::TPROJECT tempPrj;
        bool checkAllTime(void);
        void correctAllTime(void);
        void showDayPlan(const int planDey);
        void showTime(void);
        void forPlusandMinusBut(void);
public:		// User declarations
        __fastcall TFormPlansDay(TComponent* Owner);
        void showFormDaysPlans(void);
        void saveTempStructure(const ExData::TPROJECT *pPrj); // это костыль который надо убрать при закрытом окне нет инициализации
        void addDayPlans(void);
        void removeDayPlans(void);
        TDateTime convertSecondsToTDT(const DWORD begintime);
        AnsiString convertSecondsToStr(const DWORD begintime);
        int retCurrentPlan(void){return currentPlan;}
        void setCurrentPlan(const int crPlan);
        const int getCurrentPlan(void){return currentPlan;}
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPlansDay *FormPlansDay;
//---------------------------------------------------------------------------
#endif
