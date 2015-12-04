//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>

#include "structures.h"
#include "progutil.h"

#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <limits.h>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdUDPServer.hpp>


#pragma pack (1)
// structure type version program
typedef struct
  {
    WORD Maj_Version;
    WORD Min_Version;
    WORD Build;
    WORD Revision;

  }TCurVerion;
// structure
typedef struct
{
     int    maxDk;    // максимальное Дк в проекте
     int    CUR_DK;   //текущее кольцо(ДК)
     int    count_dk; //кол-во колец
     int    cur_prog;
     int    cur_plan;
     bool   is_edit;
     AnsiString file_name;
}__VIS;
/*----------------------------------------------------------------------------*/
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *on_SetupPrg;
        TMenuItem *on_DSA_Plans;
        TMenuItem *on_WeeklyPlans;
        TMenuItem *on_AnnualPlan;
        TMenuItem *on_Safety;
        TMenuItem *N10;
        TMenuItem *on_About;
        TMenuItem *on_NewFile;
        TToolBar *ToolBar1;
        TStatusBar *StatusBar1;
        TScrollBox *ScrollBox1;
        TPanel *PanelEdit;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit2;
        TEdit *Edit3;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label6;
        TLabel *Label5;
        TEdit *Edit6;
        TLabel *Label7;
        TBitBtn *btn_BtAddDirection;
        TSplitter *Splitter1;
        TBitBtn *btn_BtRemoveDirection;
        TLabel *Label8;
        TComboBox *ComboBoxNumFaza;
        TBitBtn *btn_ZoomInc;
        TSplitter *Splitter2;
        TSplitter *Splitter3;
        TBitBtn *btn_ZoomReduce;
        TPanel *PanelFazaNum;
        TPanel *PanelNaprNum;
        TSplitter *Splitter4;
        TPanel *Panel4;
        TMenuItem *on_TemplatePhase;
        TMenuItem *on_OpenFile;
        TMenuItem *on_SaveFile;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TSplitter *Splitter5;
        TToolBar *ToolBar2;
        TPanel *pnlPhasa;
        TSplitter *Splitter8;
        TSplitter *Splitter6;
        TIdUDPServer *IdUDPServer;
        TIdUDPClient *IdUDPClient;
        TComboBox *cbbDayPlan;
        TButton *btnPhaseAdd;
        TButton *btnPhaseOld;
        TToolBar *ToolBar3;
        TBitBtn *btn_ButSetup;
        TSplitter *Splitter7;
        TBitBtn *btn_Direction;
        TSplitter *Splitter9;
        TSplitter *Splitter10;
        TSplitter *Splitter11;
        TSplitter *Splitter12;
        TBitBtn *btn_Safety;
        TBitBtn *btnDayPlan;
        TBitBtn *btnWeekPlan;
        TBitBtn *btnYear;
        TSplitter *Splitter13;
        TBitBtn *btn_BtDk;
        TBitBtn *btnPhase;
        TSplitter *Splitter14;
        TMenuItem *on_Direct;
        TMenuItem *on_Dk;
        //TPanel *Panel1;
        TSplitter *Splitter17;
        TSplitter *Splitter15;
        TSplitter *Splitter18;
        TPanel *Panel8;
        TPanel *Panel9;
        TSplitter *Splitter19;
        TPanel *pnlTimeEnd;
        TPanel *pnlTimeStart;
        TSplitter *Splitter16;
        TButton *btnUDZ;
        TSplitter *spl1;
        TMenuItem *UDZCG;
        void __fastcall on_NewFileClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall btn_BtAddDirectionClick(TObject *Sender);
        void __fastcall btn_BtRemoveDirectionClick(TObject *Sender);
        void __fastcall btn_ZoomIncClick(TObject *Sender);
        void __fastcall on_SetupPrgClick(TObject *Sender);
        void __fastcall btn_ZoomReduceClick(TObject *Sender);
        void __fastcall on_DSA_PlansClick(TObject *Sender);
        void __fastcall on_AboutClick(TObject *Sender);
        void __fastcall on_WeeklyPlansClick(TObject *Sender);
        void __fastcall on_AnnualPlanClick(TObject *Sender);
        void __fastcall on_SafetyClick(TObject *Sender);
        void __fastcall on_TemplatePhaseClick(TObject *Sender);
        void __fastcall on_OpenFileClick(TObject *Sender);
        void __fastcall on_SaveFileClick(TObject *Sender);
        void __fastcall on_DirectClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall PanelEditMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall PanelEditMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall PanelEditMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall IdUDPServerUDPRead(TObject *Sender,
          TStream *AData, TIdSocketHandle *ABinding);
        void __fastcall cbbDayPlanChange(TObject *Sender);
        void __fastcall btnPhaseAddClick(TObject *Sender);
        void __fastcall btnPhaseOldClick(TObject *Sender);
        void __fastcall btn_ButSetupClick(TObject *Sender);
        void __fastcall btn_DirectionClick(TObject *Sender);
        void __fastcall btn_SafetyClick(TObject *Sender);
        void __fastcall btnPhaseClick(TObject *Sender);
        void __fastcall btnDayPlanClick(TObject *Sender);
        void __fastcall btnWeekPlanClick(TObject *Sender);
        void __fastcall btnYearClick(TObject *Sender);
        void __fastcall btn_BtDkClick(TObject *Sender);
        void __fastcall on_DkClick(TObject *Sender);
        void __fastcall btnUDZClick(TObject *Sender);
        void __fastcall UDZCGClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
        static const BYTE LenghIP = 16;
        bool DragEnabled;
        DiagramPainter   *DPA;// Отрисовка редактируемой программы
        TPoint  MouseDownPos;
        TCurVerion  cur_version;
        __VIS       VIS; // инфа о состоянии редактора
        //for UDP
        bool SUCC_FLAG;
        AnsiString UDP_String;
        /*functions*/
        void ShowTitleText(void);
        void getVersion(void);
        void newProject(void);
        void saveProject(void);
        void openProject(void);
        void checkConflicts(TPROJECT *PROJ);
        void clearTosnPhase(TPROGRAM *pRrg);
        int countTimeAllPhase(const int curPlan);
        void addPhase(void);
        void removePhase(void);
        void Copy_Cur_Prog(int cur_prog);
        void showTimePanel(void);
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
        TPROJECT *retDataProject(void)const;
        TPROGRAMS *retDataPrograms(void)const;
        void showMainPhase(void);
        void showPhaseInfo(void);
        void Show_Main_Form(void);
        void setDayPlan(const int inPlan);
        void RefreshAllForms(void);
        void updateTimePhase(void);
        bool Check_Confl_In_Sh_Faze(TPROJECT *PROJ);
        void setActiveServerUDP(const int port);
        void setActiveServer(bool acv);
        void setActiveClientUDP(const AnsiString ip,const int port);
        void setClientIP(const AnsiString ip);
        void setActiveClient(bool acv);
        bool Send_Data_UDP(AnsiString s);
        bool Send_Packet_UDP(AnsiString s, int tryes);
        const DiagramPainter *retDPA(void){return DPA;}
        const AnsiString retStrUDP(void){return UDP_String;}
        void clearStrUDP(void){UDP_String = "";}
        const TCurVerion *retVersion(void){return &cur_version;}
        __VIS *retVIS(void){return &VIS;}
        void PaintForm(void){DPA->Paint();}
        DWORD retTosn(const int dir,const int phase){return DPA->retTimeOsn(dir,phase);}  //retTimeOsnMax
        DWORD retTosnGlb(const int dir,const int phase){return DPA->retTimeOsnMax(dir,phase);}
        void makeProject(const int nCount);
        void makeCRCAllProject(TPROJECT * const pPrj,TPROGRAMS * const pPRG);
};
/*----------------------------------------------------------------------------*/
extern PACKAGE TFormMain *FormMain;
/*----------------------------------------------------------------------------*/
extern   TPROJECT   PAP;
extern   TPROGRAMS  PAPROGS; //программы
// хранение колец
extern TPROJECT   PAP_RINGS[N_DK];     //текущий проект
extern TPROGRAMS  PAPROGS_RINGS[N_DK]; //программы
/*----------------------------------------------------------------------------*/
#endif
