//---------------------------------------------------------------------------

#ifndef Unit10H
#define Unit10H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ToolWin.hpp>
#include <Mask.hpp>
#include "communic.h"
#include "structures.h"

// размер данных пакета
#define PACK_LEN    512

using namespace std;
enum c{anOk,anError,noAnswer};
/*----------------------------------------------------------------------------*/
// данные дл€ загрузки в контрллер
class TDateDk
{
std::vector<ExData::TPROJECT_DK*> DateAllDk;
const ExData::TPROJECT *pPrj;

void rebuildProjectLoad(const int nDk)
{
memcpy(&DateAllDk[nDk]->surd,&pPrj->surd,sizeof(ExData::TSURD));
DateAllDk[nDk]->surd.ID_DK_CUR = nDk;
memcpy(&DateAllDk[nDk]->jornal,&pPrj->jornal,sizeof(ExData::TJORNAL));
memcpy(&DateAllDk[nDk]->comments,&pPrj->comments,sizeof(ExData::TCOMMENT_EX));
memcpy(&DateAllDk[nDk]->maxDK,&pPrj->maxDK,sizeof(BYTE));
memcpy(&DateAllDk[nDk]->guard,&pPrj->guard,sizeof(ExData::TGUARD));
memcpy(&DateAllDk[nDk]->Program,&pPrj->Program,sizeof(ExData::TPROGRAM ));
memcpy(&DateAllDk[nDk]->Year,&pPrj->Year,sizeof(ExData::TYEARCALENDAR));
for(int i=0;i<MaxWeeksPlans;i++)
        memcpy(&DateAllDk[nDk]->WeeksPlans[i],&pPrj->WeeksPlans[i],sizeof(ExData::TWEEKCALENDAR));
for(int i=0;i<MaxDaysPlans;i++)
        memcpy(&DateAllDk[nDk]->DaysPlans[i],&pPrj->DaysPlans[i],sizeof(ExData::TCALENDAR));
for(int i=0;i<MaxFase;i++)
        {
        memcpy(&DateAllDk[nDk]->Fasa[i],&pPrj->Fasa[i],sizeof(ExData::TSHABLONFASA));
        }
memcpy(&DateAllDk[nDk]->AmountMuls,&pPrj->AmountMuls,sizeof(BYTE));
memcpy(&DateAllDk[nDk]->ExpUDZ,&pPrj->ExpUDZ,sizeof(ExData::TEXPRESSIONS));
// задать направлени€
memset(&DateAllDk[nDk]->Directs,0,sizeof(ExData::TDIRECTS_DK));
DateAllDk[nDk]->Directs.countDirectCCG = pPrj->Directs.countDirectCCG;
for(int i=0;i<pPrj->AmountDirects;i++) // max 70 direct in project
        {
        DateAllDk[nDk]->Directs.OneDirect[i].Type = pPrj->Directs.OneDirect[i].Type;
        for(int j=0;j<pPrj->maxDK;j++)
            {
            //red
            if((pPrj->Directs.OneDirect[i].out.red[j].NumberDk==nDk)
                &&(pPrj->Directs.OneDirect[i].out.red[j].group!=0)){
                memcpy(&DateAllDk[nDk]->Directs.OneDirect[i].out.red,
                    &pPrj->Directs.OneDirect[i].out.red[j],sizeof(ExData::TNAPROUT));
                }
            //yellow
            if((pPrj->Directs.OneDirect[i].out.yel[j].NumberDk==nDk)
                &&(pPrj->Directs.OneDirect[i].out.yel[j].group!=0)){
                memcpy(&DateAllDk[nDk]->Directs.OneDirect[i].out.yellow,
                    &pPrj->Directs.OneDirect[i].out.yel[j],sizeof(ExData::TNAPROUT));
                }
            //green
            if((pPrj->Directs.OneDirect[i].out.green[j].NumberDk==nDk)
                &&(pPrj->Directs.OneDirect[i].out.green[j].group!=0)){
                memcpy(&DateAllDk[nDk]->Directs.OneDirect[i].out.green,
                    &pPrj->Directs.OneDirect[i].out.green[j],sizeof(ExData::TNAPROUT));
                }
            }
        }
DateAllDk[nDk]->AmountDirects = pPrj->AmountDirects;
DateAllDk[nDk]->ProjectSize = pPrj->ProjectSize;
}
public:
        TDateDk(const ExData::TPROJECT *pR):pPrj(pR)
                {
                for(int i=0;i<pPrj->maxDK;i++)
                        {
                        DateAllDk.push_back(new ExData::TPROJECT_DK);
                        rebuildProjectLoad(i);
                        //const ExData::TPROJECT_DK *pP =  retDatePrj(i);
                        //pP = 0;
                        }
                }
        ~TDateDk()
                {
                for(int i=0;i<pPrj->maxDK;i++)
                        delete DateAllDk[i];
                DateAllDk.clear();
                }
        // вернуть указатель на проект закрузки в ƒ 
        const ExData::TPROJECT_DK* retDatePrj(const int nDk)
                {
                if(nDk<DateAllDk.size()){
                        DateAllDk[nDk]->surd.ID_DK_CUR = nDk;
                        return DateAllDk[nDk];
                        }
                return 0;
                }
};
//---------------------------------------------------------------------------
class TFormDk : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TButton *btnExit;
        TPanel *Panel2;
        TButton *btnUpLoad;
        TButton *btnLoad;
        TMemo *mmoConsole;
        TLabel *Label4;
        TEdit *Edit2;
        TLabel *Label5;
        TPanel *Panel6;
        TStringGrid *StringGridJor;
        TListBox *ListBox1;
        TLabel *Label6;
        TListBox *ListBox2;
        TMemo *Memo2;
        TLabel *Label7;
        TLabel *Label8;
        TButton *btnDump;
        TLabel *Label9;
        TMemo *Memo3;
        TToolBar *ToolBar1;
        TSpeedButton *btnLook;
        TSpeedButton *btnTestOn;
        TLabel *Label10;
        TSplitter *Splitter1;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TSpeedButton *btnTestOff;
        TButton *btnChannelOn;
        TButton *btnChannelOff;
        TTimer *Timer1;
        TEdit *edtLog;
        TButton *btnClean;
        TMemo *mmoRed;
        TMemo *mmoYellow;
        TMemo *mmoGreen;
        TTabSheet *TabSheet5;
        TEdit *Edit3;
        TButton *btnTimeSyn;
        TButton *btnSeeTime;
        TLabel *Label1;
        TPanel *pnlmodesurd;
        TLabel *Label2;
        TPanel *pnlstsurd;
        TLabel *Label3;
        TPanel *pnlphase;
        TLabel *Label15;
        TPanel *pnlStat;
        TLabel *Label17;
        TPanel *pnlsource;
        TButton *btnReadJornal;
        TTabSheet *TabSheet6;
        TButton *btnExport;
        TTimer *Timer2;
        TProgressBar *ProgressBar1;
        TLabel *Label18;
        TButton *btnStopReadJornal;
        TTimer *Timer3;
        TEdit *Edit4;
        TLabel *Label19;
        TLabel *Label20;
        TEdit *Edit5;
        TDateTimePicker *DateTimePicker1;
        TButton *btnSetTime;
        TMemo *Memo4;
        TButton *btnClearFlash;
        TPanel *Panel11;
        TButton *btnInfoDk;
        TSplitter *Splitter2;
        TPanel *Panel8;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TButton *ButtonOS;
        TButton *ButtonOSUrg;
        TButton *ButtonRUN;
        TMaskEdit *medtIP;
        TEdit *edtPassword;
        TComboBox *cbbDk;
        TLabel *Label16;
        TLabel *Label21;
        TLabel *Label22;
        TButton *btnDkDefault;
        TCheckBox *chkNet;
        TButton *btnNet;
        TEdit *edtPort;
        TLabel *lblPort;
        TSpeedButton *btnSurd;
        TButton *btnConsol;
        TTimer *tmrSURD;
        TPanel *pnlTime;
        TLabel *lblTime;
        TPanel *pnlnet;
        TLabel *lblnet;
        TButton *btnRestart;
        TButton *btnMultiTime;
        TButton *btnSyncAllDk;
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall btnLoadClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btnTestOnClick(TObject *Sender);
        void __fastcall btnTestOffClick(TObject *Sender);
        void __fastcall btnChannelOnClick(TObject *Sender);
        void __fastcall btnChannelOffClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall btnLookClick(TObject *Sender);
        void __fastcall btnDumpClick(TObject *Sender);
        void __fastcall btnCleanClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormHide(TObject *Sender);
        void __fastcall btnTimeSynClick(TObject *Sender);
        void __fastcall btnSeeTimeClick(TObject *Sender);
        void __fastcall btnStopReadJornalClick(TObject *Sender);
        void __fastcall btnReadJornalClick(TObject *Sender);
        void __fastcall btnInfoDkClick(TObject *Sender);
        void __fastcall btnUpLoadClick(TObject *Sender);
        void __fastcall btnExportClick(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
        void __fastcall btnSetTimeClick(TObject *Sender);
        void __fastcall btnClearFlashClick(TObject *Sender);
        void __fastcall btnDkDefaultClick(TObject *Sender);
        void __fastcall cbbDkChange(TObject *Sender);
        void __fastcall ButtonOSClick(TObject *Sender);
        void __fastcall ButtonOSUrgClick(TObject *Sender);
        void __fastcall chkNetClick(TObject *Sender);
        void __fastcall btnNetClick(TObject *Sender);
        void __fastcall btnConsolClick(TObject *Sender);
        void __fastcall tmrSURDTimer(TObject *Sender);
        void __fastcall btnSurdClick(TObject *Sender);
        void __fastcall ButtonRUNClick(TObject *Sender);
        void __fastcall btnRestartClick(TObject *Sender);
        void __fastcall btnMultiTimeClick(TObject *Sender);
        void __fastcall btnSyncAllDkClick(TObject *Sender);
private:	// User declarations
        AnsiString textCurrentIP;
        AnsiString CurrentIP;
        IPDATA *pDateIp;
        void cpyStructure(const int);
        void ManualNetParametrs(bool fCheck);
        void setTextIP(const AnsiString txt);
        void sendMultiCommand(AnsiString cmd);
        AnsiString getDateTime(TDateTime &newTime);
public:		// User declarations
        __fastcall TFormDk(TComponent* Owner);
        void updateNetDk(IPDATA *);
        AnsiString getTextIP(void){return textCurrentIP;}
        BYTE checkPasswordSURD_OK(void);
        void ChangeDk(const int NumberDk);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDk *FormDk;
//---------------------------------------------------------------------------
#endif
