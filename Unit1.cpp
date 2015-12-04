/*----------------------------------------------------------------------------*/
#include <vcl.h>
#include <assert.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <limits.h>
#include <list.h>
#pragma  hdrstop
#include "Unit10.h"
#include "Unit1.h"
#include "structures.h"
#include "progutil.h"
#include "project.h"
#include "dayplans.h"
#include "weeksplans.h"
#include "year.h"
#include "local.h"
#include "guard.h"
#include "fazas.h"
#include "help_form.h"
#include "takts.h"
#include "Unit18.h"
#include "Unit21.h"
#include "Unit11.h"
#include "communic.h"
#include "crc32.h"
#include "Unit12.h"
#include "napr.h"
#include "udzcg.h"
/*----------------------------------------------------------------------------*/
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;

/*------------------------------------------------------------------------------
Глобальные
------------------------------------------------------------------------------*/
using namespace ExData;

TPROJECT   PAP;     //текущий проект для всех
TPROGRAMS  PAPROGS; //программы
// Для всех ДК проекта
TPROJECT   PAP_RINGS[N_DK];    //текущий проект
TPROGRAMS  PAPROGS_RINGS[N_DK];//программы

/*----------------------------------------------------------------------------*/
/* Callback functions*/
/*----------------------------------------------------------------------------*/
// клик по фазе
void __fastcall PanFazaClick(TObject *Sender)
{
FormMain->Show_Main_Form();
/*FormMain->showMainPhase();
FormMain->PaintForm();*/
}
/*----------------------------------------------------------------------------*/
// вызов панели направления
void __fastcall NaprClick(TObject *Sender)
{
//
}
/*----------------------------------------------------------------------------*/
// клик по таску
void __fastcall TaktsClick(TObject *Sender)
{
FormMain->showPhaseInfo();
}
/*----------------------------------------------------------------------------*/
/* Class TFormMain */
/*----------------------------------------------------------------------------*/
// проверка конфликтов в шаблонной фазе
// TRUE - есть конфликты
bool  TFormMain::Check_Confl_In_Sh_Faze(TPROJECT *PROJ)
{
for (int i_sh=0; i_sh< MaxFase; i_sh++)
        {
        for (int n1=0; n1< MaxDirects; n1++)
                if (PROJ->Fasa[i_sh].Direct[n1]){
                for(int n2=0; n2< MaxDirects; n2++)
                        {
                        if (PROJ->Fasa[i_sh].Direct[n2])
                                if (n1!=n2){
                                if (PROJ->guard.ConfMatrixFlag[n1][n2]){
                                        return(true);
                                        }
                                }
                        }
                }
        }
return(false);
}
/*----------------------------------------------------------------------------*/
void TFormMain::checkConflicts(TPROJECT *PROJ)
{
if (Check_Confl_In_Sh_Faze(PROJ)){
        MessageBox(0,"Ошибка проекта: матрица конфликтов не соответствует шаблонам фаз",
                "Отмена!!!",MB_YESNO);
        }
}
/*----------------------------------------------------------------------------*/
// копировать проект для сохранения в файл и загрузки в ДК
void TFormMain::makeProject(const int nCount)
{
/* вeсь проект */
memcpy(&PAP_RINGS[nCount],&PAP,sizeof(PAP));
/*программы*/
memcpy(&PAPROGS_RINGS[nCount],&PAPROGS,sizeof(PAPROGS));
// корректировка Тосн.
for(int i=0;i<PAP.Program.AmountFasa;i++)
        {
        PAP_RINGS[nCount].Program.fazas[i].Tosn = FormMain->retTosn(0,i);
        for(int j=0;j<MaxProgram;j++)
                PAPROGS_RINGS[nCount].Program[j].fazas[i].Tosn = FormMain->retTosn(0,i);
        }
PAP_RINGS[nCount].surd.ID_DK_CUR = 0;// всегда дял одного ДК, очередной костыль
makeCRCAllProject(&PAP_RINGS[nCount],&PAPROGS_RINGS[nCount]);
}
/*----------------------------------------------------------------------------*/
//собрать поект с контрольной суммой
void TFormMain::makeCRCAllProject(TPROJECT * const pPrj,TPROGRAMS * const pPRG)
{
// размеры структур
pPRG->ProgramsSize = sizeof(TPROGRAMS); //6921
pPrj->ProjectSize = sizeof(TPROJECT);   //51957
pPrj->comments.inner.preambule = 0xABBA;
//расчет контрольной суммы
pPRG->CRC32 = crc32_calc((unsigned char*)&PAPROGS,sizeof(TPROGRAMS)-sizeof(pPRG->CRC32));
pPrj->CRC32_programs = pPRG->CRC32;
pPrj->CRC32 = crc32_calc((unsigned char*)pPrj,sizeof(TPROJECT)-sizeof(pPrj->CRC32));
//3115988966
}
/*----------------------------------------------------------------------------*/
void TFormMain::saveProject(void)
{
AnsiString      file_s;
FILE            *in_file;

//информация о файле
FormMain->SaveDialog1->Filter = "SURD Binary files (*.surd)|*.SURD";
FormMain->SaveDialog1->DefaultExt = "suso";
//
if (FormMain->SaveDialog1->Execute()){
        //
        file_s = FormMain->SaveDialog1->FileName;
        VIS.file_name=file_s;
        in_file=fopen(file_s.c_str(),"wb");
        //
        for(int i=0; i< VIS.count_dk; i++)
                {
                makeCRCAllProject(&PAP,&PAPROGS);
                fwrite(&PAP, sizeof(PAP),1,in_file);
                fwrite(&PAPROGS, sizeof(PAPROGS),1,in_file);
                }
        //закрыть бинарный файл
        fclose(in_file);
        // изменения сохранены
        VIS.is_edit=false;
        RefreshAllForms();
        }
}
/*----------------------------------------------------------------------------*/
void TFormMain::openProject(void)
{
AnsiString      file_s;
FILE            *in_file;

char            buffData[sizeof(TPROJECT)+sizeof(TPROGRAMS)+(LenghIP*MAX_DK)+10];
char            *buf_read;
char            *pbuffData;
//
FormMain->OpenDialog1->Filter = "SURD Binary files (*.surd)|*.SURD";
//
if(FormMain->OpenDialog1->Execute()){
        file_s = FormMain->OpenDialog1->FileName;
        VIS.file_name=file_s;
        //
        in_file=fopen(file_s.c_str(),"rb");
        buf_read = buffData;
        int bytes_in=fread(buffData,1,sizeof(buffData),in_file);
        if(bytes_in<(sizeof(TPROJECT)+sizeof(TPROGRAMS))*N_DK){
                return; // ошибка по длине
                }
        pbuffData = buffData;
        VIS.count_dk = 0; // сбросс количество ДК
        for(int i=0; i< N_DK; i++)
                {
                memcpy(&PAP,pbuffData,sizeof(TPROJECT));      pbuffData+=sizeof(TPROJECT);
                memcpy(&PAPROGS,pbuffData,sizeof(TPROGRAMS)); pbuffData+=sizeof(TPROGRAMS);
                memcpy(&PAP_RINGS[i],&PAP, sizeof(TPROJECT));
                memcpy(&PAPROGS_RINGS[i],&PAPROGS,sizeof(TPROGRAMS));
                VIS.count_dk++;
                }
        ///////////////////////////////
        for (int i_dk=0; i_dk<N_DK; i_dk++)
                {
                if (PAP_RINGS[i_dk].comments.inner.preambule!=0xABBA){
                        memset(&PAP_RINGS[i_dk].comments.inner.in,0,sizeof(TCOMMENT_INNER2));
                        }
                }
        ///////////////////////////////
        memcpy(&PAP,    &PAP_RINGS[0],    sizeof(PAP)); // первый проект
        memcpy(&PAPROGS,&PAPROGS_RINGS[0],sizeof(PAPROGS)); // программы к проекту
        // установить параметры связи по ethernet
        IpData.loadDateSurd(&PAP);
        //
        fclose(in_file);
        RefreshAllForms();
        }//if end
//
VIS.cur_plan = 0; // просмотр с первого плана
setDayPlan(VIS.cur_plan);
//
ShowTitleText();
//
checkConflicts(&PAP);
FormPlansDay->saveTempStructure(&PAP); // нужно для инициализации временной структуры
}
/*----------------------------------------------------------------------------*/
void TFormMain::clearTosnPhase(TPROGRAM *pRrg)
{
for(int i=0;i<pRrg->AmountFasa;i++)
        {
        pRrg->fazas[i].Tosn = 0;
        }
}
/*----------------------------------------------------------------------------*/
// считаем основное время всех фаз
int TFormMain::countTimeAllPhase(const int curPlan)
{
const int timeMaxPhase = 1440; // 1440 минут в сутках
int timeEndPhase = 0,countTimePhase = 0;
const int maxPhase = PAP.DaysPlans[VIS.cur_prog].AmountCalendTime;
for(int i=0;i<maxPhase-1;i++)// считаем без последней фазы
        {
        //if(PAP.DaysPlans[curPlan].CalendTime[i+1].BeginTimeWorks){// это не последний интервал
          int tempTime;
          if((PAP.DaysPlans[curPlan].CalendTime[i+1].BeginTimeWorks==0)&&
                (i==maxPhase-2)){ // это последняя фаза вызывная Тосн=0
                tempTime = timeMaxPhase - countTimePhase;
                }else{
                tempTime =
                        PAP.DaysPlans[curPlan].CalendTime[i+1].BeginTimeWorks/60 -
                        PAP.DaysPlans[curPlan].CalendTime[i].BeginTimeWorks/60;
                }
                PAP.Program.fazas[i].Tosn = tempTime;
                if(PAP.Program.fazas[i].Tosn)PAP.Program.fazas[i].FasaProperty = PHASE_PROP_COMB;
                                        else PAP.Program.fazas[i].FasaProperty = PHASE_PROP_TVP;
                countTimePhase += tempTime;
        //        }
        //        else{
        //        timeEndPhase = PAP.Program.fazas[i].Tosn=timeMaxPhase - countTimePhase;
        //        }
        }
return timeEndPhase = PAP.Program.fazas[maxPhase-1].Tosn=timeMaxPhase - countTimePhase;// время последней фазы
}
/*----------------------------------------------------------------------------*/
// добавляет фазу в текущую программу
void TFormMain::addPhase(void)
{
list <TFASA> prog;prog.clear();
list <TFASA>:: iterator  prog_iter;
TFASA   one_f;

// перерасчет времени
DWORD timeEndPhase = countTimeAllPhase(VIS.cur_plan);
int maxPhase = PAP.Program.AmountFasa;
// формируем список предыдущих фаз
for (int i=0; i<maxPhase; i++)
        {
        PAP.Program.fazas[i].Tmin = PAP.guard.green_min;
        prog.push_back(PAP.Program.fazas[i]);
        }
//новая фаза
memset(&one_f,0,sizeof(TFASA));
one_f.Tosn = timeEndPhase;  // длительность расчетной последней фазы
one_f.Tmin = PAP.guard.green_min; // мин длительность зеленого
if(timeEndPhase)one_f.FasaProperty = PHASE_PROP_COMB;
           else one_f.FasaProperty = PHASE_PROP_TVP; // фазы только вызывные
prog.push_back(one_f);
// проверим на мак. фаз
maxPhase = prog.size();
if (maxPhase> MaxProgFase){
        return;
        }
//соберм все фазы
//memset(&PAP.Program,0,sizeof(PAP.Program));
clearTosnPhase(&PAP.Program);
int newLengh=0;
for( prog_iter=prog.begin(); prog_iter!=prog.end(); ++prog_iter)
        {
        memcpy(&(PAP.Program.fazas[newLengh]),&(*prog_iter) ,sizeof(TFASA));
        memcpy(&(PAPROGS.Program[VIS.cur_prog].fazas[newLengh]),&(*prog_iter) ,sizeof(TFASA));
        newLengh++;
        }
PAPROGS.Program[VIS.cur_prog].AmountFasa = newLengh;
PAP.Program.AmountFasa = newLengh;
}
/*----------------------------------------------------------------------------*/
// удаляем выбранную фазу
void TFormMain::removePhase(void)
{
// проверяем на последнюю
if(PAP.Program.AmountFasa < 2)return;
// всего фаз
const int CountLingh = PAP.Program.AmountFasa;
// собираем все
//memset(&PAP.Program,0,sizeof(PAP.Program));
clearTosnPhase(&PAP.Program);
// пересчет времени
countTimeAllPhase(VIS.cur_plan);
for(int i=0;i<CountLingh-1;i++)
        {
        memcpy(&(PAPROGS.Program[VIS.cur_prog].fazas[i]),
                &(PAP.Program.fazas[i]),sizeof(TFASA));
        }
PAP.Program.AmountFasa = CountLingh-1;
PAPROGS.Program[VIS.cur_prog].AmountFasa = CountLingh-1;
}
/*----------------------------------------------------------------------------*/
/*пересчет фаз при изменение врмени*/
void TFormMain::updateTimePhase(void)
{
// чистим структуру времени
clearTosnPhase(&PAP.Program);
// пересчет времени
countTimeAllPhase(VIS.cur_plan);
// всего фаз
const int CountLingh = PAP.Program.AmountFasa;
for(int i=0;i<CountLingh;i++)
        {
        memcpy(&(PAPROGS.Program[VIS.cur_prog].fazas[i]),&(PAP.Program.fazas[i]),sizeof(TFASA));
        }
// количество фаз в проете
PAP.Program.AmountFasa = CountLingh;
PAPROGS.Program[VIS.cur_prog].AmountFasa = CountLingh;
// обновим экран
Show_Main_Form();
}
/*----------------------------------------------------------------------------*/
void TFormMain::Copy_Cur_Prog(int cur_prog)
{
memcpy(&PAP.Program,&PAPROGS.Program[cur_prog], sizeof(TPROGRAM));
}
/*----------------------------------------------------------------------------*/
void TFormMain::newProject(void)
{

VIS.CUR_DK = 0;
VIS.count_dk = 1;
memset(&PAP,0,sizeof(PAP));
memset(&PAPROGS,0,sizeof(PAP));

PAP.AmountDirects=1;
PAP.AmountMuls=1;
//
PAP.guard.red_min=5;
PAP.guard.green_min=5;
PAP.guard.green_yellow=5;
PAP.guard.yellow_min=5;
PAP.guard.kk_len = 5;
PAP.guard.faza_max=1440;
        PAP.guard.yellow=0;
        PAP.guard.redyellow=0;
PAP.maxDK = 1;
PAP.guard.restart_interval = 5;
PAP.guard.restarts = 5;
PAP.guard.time_clear = 5;
PAP.guard.gpsON = 1;
//
PAP.jornal.power_on=1;
PAP.jornal.alarm = 1;
PAP.jornal.gmt = 3;
//
PAP.surd.Pass = 999999;
PAP.surd.PORT = 11990;
PAP.surd.TIMEOUT = 1000;
PAP.surd.TimeDelay = 100;
PAP.surd.Count = 5;
//
PAP.Fasa[0].Direct[0]=1;
// задаем одно направление
PAP.Directs.countDirectCCG  =1;

PAP.Directs.OneDirect[0].out.red[0].color  =MUL_RED;
PAP.Directs.OneDirect[0].out.red[0].group =1;
PAP.Directs.OneDirect[0].out.red[0].NumberDk = 0;

PAP.Directs.OneDirect[0].out.yel[0].color  =MUL_YELLOW;
PAP.Directs.OneDirect[0].out.yel[0].group =1;
PAP.Directs.OneDirect[0].out.yel[0].NumberDk = 0;

PAP.Directs.OneDirect[0].out.green[0].color=MUL_GREEN;
PAP.Directs.OneDirect[0].out.green[0].group =1;
PAP.Directs.OneDirect[0].out.green[0].NumberDk = 0;
// остальные направления ставим только цвет
for(int i=0;i< MaxDirects;i++) // все напрвления
        {
        for(int j=0;j<MAX_DK;j++)// все Дк
                {
                PAP.Directs.OneDirect[i].out.red[j].color=MUL_RED;
                PAP.Directs.OneDirect[i].out.yel[j].color=MUL_YELLOW;
                PAP.Directs.OneDirect[i].out.green[j].color=MUL_GREEN;
                }
        }
// добавление программы
PAP.Program.AmountFasa = 1;
PAP.Program.fazas[0].Tosn = 1440;
PAP.Program.fazas[0].Tmin = 5;
PAP.Program.fazas[0].FasaProperty = PHASE_PROP_COMB;
PAP.Program.fazas[0].NumFasa = 0;
// MaxCalendar
for (int i=0; i< MaxDaysPlans; i++)
        {
        PAP.DaysPlans[i].AmountCalendTime=1;
        }
VIS.cur_prog=0;
memcpy(&PAPROGS.Program[VIS.cur_prog],&PAP.Program, sizeof(TPROGRAM)); // проект в программы
}
/*----------------------------------------------------------------------------*/
void TFormMain::showTimePanel(void)
{
FormMain->cbbDayPlan->ItemIndex = VIS.cur_plan; // настройка для формы
// время начала фазы
const int tmpPhase = DPA->cur_faza;
DWORD time_i =PAP.DaysPlans[VIS.cur_plan].CalendTime[tmpPhase].BeginTimeWorks;
//TDateTime tdt = FormPlansDay->convertSecondsToTDT(time_i);
AnsiString strTime = FormPlansDay->convertSecondsToStr(time_i);
FormMain->pnlTimeStart->Caption = strTime; //tdt.TimeString();
// время окончание фазы
if(tmpPhase<PAP.DaysPlans[VIS.cur_plan].AmountCalendTime){
        time_i = PAP.DaysPlans[VIS.cur_plan].CalendTime[tmpPhase+1].BeginTimeWorks;
        }else{
        //tdt = 0;
        strTime = "";
        }
//tdt = FormPlansDay->convertSecondsToTDT(time_i);
strTime = FormPlansDay->convertSecondsToStr(time_i);
FormMain->pnlTimeEnd->Caption = strTime;//tdt.TimeString();
}
/*----------------------------------------------------------------------------*/
/**/
void TFormMain::showMainPhase(void)
{
int f_i = DPA->cur_faza;
FormMain->pnlPhasa->Caption = IntToStr(f_i+1); // показать номер выбранной фазы
showTimePanel();
}
//---------------------------------------------------------------------------
void TFormMain::showPhaseInfo(void)
{
//место то вывода окна
FormMain->PanelEdit->Left=
        DPA->pan_faza[DPA->cur_faza]->Left+DPA->select_takt->Left + DPA->select_takt->Width/2;
FormMain->PanelEdit->Top=
        DPA->pan_faza[DPA->cur_faza]->Top+DPA->select_takt->Top + DPA->select_takt->Height/2;

int n_i = DPA->cur_napr;
int f_i = DPA->cur_faza;
FormMain->PanelEdit->BringToFront();
FormMain->PanelFazaNum->Caption = IntToStr(f_i + 1);
FormMain->PanelNaprNum->Caption = IntToStr(n_i + 1);
// показать основное время
FormMain->Edit1->Text = IntToStr( DPA->proga->fazas[f_i].Tosn);
// показать доп.такты
FormMain->Edit2->Text = IntToStr( DPA->proga->fazas[f_i].prom[n_i].Zd1);
FormMain->Edit3->Text = IntToStr( DPA->proga->fazas[f_i].prom[n_i].Zd2);
FormMain->Edit6->Text = IntToStr( DPA->proga->fazas[f_i].prom[n_i].KD);
//номер шаблона фазы
int sh_faza = DPA->proga->fazas[f_i].NumFasa;
FormMain->ComboBoxNumFaza->ItemIndex = sh_faza;
//
FormMain->PanelEdit->Visible = true;
//Затенение неиспользуемых
if (DPA->project->Fasa[sh_faza].Direct[n_i]){
        FormMain->Edit2->Enabled = true;//_i].Zd1);
        FormMain->Edit3->Enabled = true;//[n_i].Zd2);
        FormMain->Edit6->Enabled = true;  ;//i].KD);
        }else{
        FormMain->Edit2->Enabled = false;//_i].Zd1);
        FormMain->Edit3->Enabled = false;//[n_i].Zd2);
        FormMain->Edit6->Enabled = false;  ;//i].KD);
        }
//
showMainPhase();
}
/*----------------------------------------------------------------------------*/
void TFormMain::Show_Main_Form(void)
{
// текущая программа
DPA->Paint(VIS.cur_prog);
// текущий суточный план
FormMain->cbbDayPlan->ItemIndex = VIS.cur_plan;//VIS.cur_prog;
// текущая фаза
showMainPhase();
}
/*----------------------------------------------------------------------------*/
// обновить все формы при изменении параметров проекта
void TFormMain::RefreshAllForms()
{
Show_Main_Form();
}
/*----------------------------------------------------------------------------*/
// конструктор
/*----------------------------------------------------------------------------*/
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
/*TPROJECT_DK testDk;
DWORD leng = sizeof(testDk);
if(leng); */
}
/*----------------------------------------------------------------------------*/
//Новый проект
void __fastcall TFormMain::on_NewFileClick(TObject *Sender)
{
newProject();
Show_Main_Form();
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
crc32_init();
getVersion();
VIS.file_name="";
ShowTitleText();
newProject();
// класс построения ленты времени
DPA = new DiagramPainter(FormMain,FormMain->ScrollBox1,&PAP,&PAPROGS);
DPA->Editable = true;
DPA->logic_struct = false;
DPA->cur_napr=0;
// callback init
DPA->faza_callback = TaktsClick;
DPA->napr_callback = NaprClick;
DPA->panfaza_callback = PanFazaClick;
// изменения в проекте
VIS.is_edit=false;
// init UDP server
const int port = IpData.getPort();
setActiveServerUDP(port);//Активируется сервер
// init UPD client
const AnsiString ip = IpData.getOneIp(0); // get ip default
setActiveClientUDP(ip,port);
//инит дневные планы
for (int i=0; i<MaxDaysPlans; i++)
        FormMain->cbbDayPlan->Items->Add(IntToStr(i+1));
FormMain->cbbDayPlan->ItemIndex = 0;
for (int i=0; i<MaxFase; i++)
        FormMain->ComboBoxNumFaza->Items->Add(IntToStr(i+1));
FormMain->ComboBoxNumFaza->ItemIndex = 0;
// перестоить форму
Show_Main_Form();
}
/*----------------------------------------------------------------------------*/
// разрушение формы.удаляем все
void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
delete DPA;
}
/*----------------------------------------------------------------------------*/
// закрыть панель настройки
void __fastcall TFormMain::Button3Click(TObject *Sender)
{
FormMain->PanelEdit->Visible = false;
}
/*----------------------------------------------------------------------------*/
// сохранить настройки с панели настройки
void __fastcall TFormMain::Button2Click(TObject *Sender)
{
int i_conv;
const int n_i = DPA->cur_napr;
const int f_i = DPA->cur_faza;
// показать  Тosn Тмин
DPA->proga->fazas[f_i].Tosn =  PAP.Program.fazas[f_i].Tosn;
DPA->proga->fazas[f_i].Tmin =  PAP.Program.fazas[f_i].Tmin;
// номер шаблона
const int tempPhase = FormMain->ComboBoxNumFaza->ItemIndex;
DPA->proga->fazas[f_i].NumFasa = tempPhase;
PAP.Program.fazas[f_i].NumFasa = tempPhase;
//
__try  {i_conv = StrToInt(FormMain->Edit2->Text);}
        __except(EXCEPTION_EXECUTE_HANDLER){i_conv = -1;}
if (i_conv>-1){
        DPA->proga->fazas[f_i].prom[n_i].Zd1 =  i_conv;
        PAP.Program.fazas[f_i].prom[n_i].Zd1 =  i_conv;
        }
//
__try  { i_conv = StrToInt(FormMain->Edit3->Text);}
        __except(EXCEPTION_EXECUTE_HANDLER)    { i_conv = -1;}
if (i_conv>-1){
        DPA->proga->fazas[f_i].prom[n_i].Zd2 = i_conv;
        PAP.Program.fazas[f_i].prom[n_i].Zd2 = i_conv;
        }
//
__try  { i_conv = StrToInt(FormMain->Edit6->Text);}
        __except(EXCEPTION_EXECUTE_HANDLER)    { i_conv = -1;}
if (i_conv>-1){
        DPA->proga->fazas[f_i].prom[n_i].KD = i_conv;
        PAP.Program.fazas[f_i].prom[n_i].KD = i_conv;
        }
//
FormMain->PanelEdit->Visible = false;
DPA->Paint();
}
/*----------------------------------------------------------------------------*/
// добавить фазу
void __fastcall TFormMain::btn_BtAddDirectionClick(TObject *Sender)
{
FormPlansDay->addDayPlans();
addPhase();
Show_Main_Form();
}
/*----------------------------------------------------------------------------*/
// убрать фазу
void __fastcall TFormMain::btn_BtRemoveDirectionClick(TObject *Sender)
{
// сначала чистим календарь ВАЖНО!!!
FormPlansDay->removeDayPlans();
//удаляем фазу
removePhase();
Show_Main_Form();
}
/*----------------------------------------------------------------------------*/
/*увеличить моштаб*/
void __fastcall TFormMain::btn_ZoomIncClick(TObject *Sender)
{
DPA->coeff_width*=1.2;
DPA->Paint();
}
/*----------------------------------------------------------------------------*/
/*уменьшить моштаб*/
void __fastcall TFormMain::btn_ZoomReduceClick(TObject *Sender)
{
DPA->coeff_width*=0.8;
DPA->Paint();
}
/*----------------------------------------------------------------------------*/
// вызов окна дневные планы
void __fastcall TFormMain::on_DSA_PlansClick(TObject *Sender)
{
FormPlansDay->showFormDaysPlans();
FormPlansDay->Visible = true;
}
/*----------------------------------------------------------------------------*/
// вызов окна настройки
void __fastcall TFormMain::on_SetupPrgClick(TObject *Sender)
{
FormProject->showFormProject();
}
/*----------------------------------------------------------------------------*/
// окно помощь
void __fastcall TFormMain::on_AboutClick(TObject *Sender)
{
FormHelp->VisibledHelp();
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::on_WeeklyPlansClick(TObject *Sender)
{
Show_Form_WeeksPlans();
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::on_AnnualPlanClick(TObject *Sender)
{
Show_Form_Year();
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::on_SafetyClick(TObject *Sender)
{
FormGuard->showFormGuard();
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::on_TemplatePhaseClick(TObject *Sender)
{
frPhaseTemplate->showFormPhase(&PAP);
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::on_OpenFileClick(TObject *Sender)
{
openProject();
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::on_SaveFileClick(TObject *Sender)
{
saveProject();
ShowTitleText();
}
/*----------------------------------------------------------------------------*/
// вызов окна направления
void __fastcall TFormMain::on_DirectClick(TObject *Sender)
{
frmDirection->ShowMainFormDirection(&PAP);
}
/*----------------------------------------------------------------------------*/
// событие при закрытии формы
void __fastcall TFormMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
int btn=mrNone;

if (VIS.is_edit)
        btn = MessageBox(0,"Проект не сохранен! Сохранить?","Сохранение",MB_YESNOCANCEL);
        if (btn==6){
                saveProject();
                }
        if (btn==2){
                CanClose=false;
                }
}
/*----------------------------------------------------------------------------*/
// для панели редактирования фазы
void __fastcall TFormMain::PanelEditMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
MouseDownPos.x = X;
MouseDownPos.y = Y;
DragEnabled = true;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::PanelEditMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
if  (DragEnabled){
        ((TPanel*)Sender)->Left = ((TPanel*)Sender)->Left + (X - MouseDownPos.x);
        ((TPanel*)Sender)->Top = ((TPanel*)Sender)->Top + (Y - MouseDownPos.y);
        };
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::PanelEditMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
DragEnabled=false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::IdUDPServerUDPRead(TObject *Sender,
      TStream *AData, TIdSocketHandle *ABinding)
{
    int len, pos;
    AnsiString sub_str = "SUCCESS:";
    char* szBuff = new char[ AData->Size+1 ];
    //--------обработка принятых данных----------
    memset( szBuff, 0, AData->Size+1 );
    AData->ReadBuffer( szBuff, AData->Size );
       AnsiString str = AnsiString (szBuff);
       len = str.Length();
       pos = str.Pos(sub_str);
       if (pos)
       {
          int i_end = pos + sub_str.Length();
          UDP_String = str.SubString(i_end, len - i_end+1);
          SUCC_FLAG=true;
       }
       else
       {
          UDP_String = str;
       }
       FormConsole->mmoOut->Lines->Add(str);
delete szBuff;
}
/*----------------------------------------------------------------------------*/
// true - OK
bool TFormMain::Send_Data_UDP(AnsiString s)
{
SUCC_FLAG=false;
UDP_String="";
FormMain->IdUDPClient->Send(s);

for (int i=0; i<50; i++)
        {
        if (SUCC_FLAG)
               break;
            ::Sleep(50);
        Application->ProcessMessages();
        }
return (SUCC_FLAG);
}
/*----------------------------------------------------------------------------*/
// true - ОК
bool TFormMain::Send_Packet_UDP(AnsiString s, int tryes)
{
for (int i=0; i< tryes; i++)
        {
        if (Send_Data_UDP(s))
                return (true);

        }
return (false);
}
/*----------------------------------------------------------------------------*/
// установить суточный план
void TFormMain::setDayPlan(const int inPlan)
{
if (VIS.cur_plan>=MaxDaysPlans)return;
VIS.cur_plan = inPlan;
//countTimeAllPhase(inPlan);
// update time phase
updateTimePhase();

}
/*----------------------------------------------------------------------------*/
// выбрать суточный план из  ComboBox
void __fastcall TFormMain::cbbDayPlanChange(TObject *Sender)
{
VIS.cur_plan = FormMain->cbbDayPlan->ItemIndex;
FormPlansDay->setCurrentPlan(VIS.cur_plan);
setDayPlan(VIS.cur_plan);
}
/*----------------------------------------------------------------------------*/
// выбрать следующий суточный план
void __fastcall TFormMain::btnPhaseAddClick(TObject *Sender)
{
if (VIS.cur_plan<MaxDaysPlans-1)
        VIS.cur_plan++;
FormPlansDay->setCurrentPlan(VIS.cur_plan);
setDayPlan(VIS.cur_plan);
}
/*----------------------------------------------------------------------------*/
// выбрать предыдущий суточный план
void __fastcall TFormMain::btnPhaseOldClick(TObject *Sender)
{
if (VIS.cur_plan)
        VIS.cur_plan--;
FormPlansDay->setCurrentPlan(VIS.cur_plan);
setDayPlan(VIS.cur_plan);
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btn_ButSetupClick(TObject *Sender)
{
FormProject->showFormProject();
frmDirection->Visible = false;
FormGuard->Visible = false;
FormPlansDay->Visible = false;
Form4->Visible = false;
Form5->Visible = false;
FormDk->Visible = false;
FormUDZG->Visible = false;
// выключаем сервера
//setActiveServer(false);
//setActiveClient(false);
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btn_DirectionClick(TObject *Sender)
{
frmDirection->ShowMainFormDirection(&PAP);
FormProject->Visible = false;
FormGuard->Visible = false;
FormProject->Visible = false;
FormPlansDay->Visible = false;
Form4->Visible = false;
Form5->Visible = false;
FormDk->Visible = false;
FormUDZG->Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btn_SafetyClick(TObject *Sender)
{
FormGuard->showFormGuard();
FormProject->Visible = false;
frmDirection->Visible = false;
FormProject->Visible = false;
FormPlansDay->Visible = false;
Form4->Visible = false;
Form5->Visible = false;
FormDk->Visible = false;
FormUDZG->Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btnPhaseClick(TObject *Sender)
{
frPhaseTemplate->showFormPhase(&PAP);
FormProject->Visible = false;
frmDirection->Visible = false;
FormGuard->Visible = false;
FormPlansDay->Visible = false;
Form4->Visible = false;
Form5->Visible = false;
FormDk->Visible = false;
FormUDZG->Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btnDayPlanClick(TObject *Sender)
{
FormPlansDay->showFormDaysPlans();
FormPlansDay->Visible = true;
FormProject->Visible = false;
frmDirection->Visible = false;
FormGuard->Visible = false;
FormProject->Visible = false;
Form4->Visible = false;
Form5->Visible = false;
FormDk->Visible = false;
FormUDZG->Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btnWeekPlanClick(TObject *Sender)
{
Show_Form_WeeksPlans();
FormProject->Visible = false;
frmDirection->Visible = false;
FormGuard->Visible = false;
FormProject->Visible = false;
FormPlansDay->Visible = false;
Form5->Visible = false;
FormDk->Visible = false;
FormUDZG->Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btnYearClick(TObject *Sender)
{
Show_Form_Year();
FormProject->Visible = false;
frmDirection->Visible = false;
FormGuard->Visible = false;
FormProject->Visible = false;
FormPlansDay->Visible = false;
Form4->Visible = false;
FormDk->Visible = false;
FormUDZG->Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btn_BtDkClick(TObject *Sender)
{
//FormProject->Visible = false;
FormDk->Enabled = true;
FormDk->updateNetDk(&IpData);
FormDk->Visible = true;
FormDk->BringToFront();
frmDirection->Visible = false;
FormGuard->Visible = false;
FormProject->Visible = false;
FormPlansDay->Visible = false;
Form4->Visible = false;
Form5->Visible = false;
FormUDZG->Visible = false;
}
/*----------------------------------------------------------------------------*//*----------------------------------------------------------------------------*/
void __fastcall TFormMain::on_DkClick(TObject *Sender)
{
FormDk->Visible = true;
FormDk->BringToFront();
}
/*----------------------------------------------------------------------------*/
void TFormMain::ShowTitleText(void)
{
FormMain->Caption =
        "Конфигуратор СУРД   v." +IntToStr(cur_version.Maj_Version)+
        "." + IntToStr(cur_version.Min_Version) + "."
        +IntToStr(cur_version.Revision) + " " +VIS.file_name;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::btnUDZClick(TObject *Sender)
{
FormUDZG->Visible = true;
FormUDZG->setVisibleDirection();
FormProject->Visible = false;
frmDirection->Visible = false;
FormGuard->Visible = false;
FormProject->Visible = false;
FormPlansDay->Visible = false;
Form4->Visible = false;
Form5->Visible = false;
FormDk->Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TFormMain::UDZCGClick(TObject *Sender)
{
FormUDZG->Visible = true;
FormUDZG->setVisibleDirection();
}
/*----------------------------------------------------------------------------*/
TPROJECT *TFormMain::retDataProject(void)const
{
return &PAP;
}
TPROGRAMS *TFormMain::retDataPrograms(void)const
{
return &PAPROGS;
}
/*----------------------------------------------------------------------------*/
void TFormMain::getVersion(void)
{
        AnsiString   s;
        DWORD  dw,b_size;
        void * p_buf;
        VS_FIXEDFILEINFO *pFileInfo;
        s = Application->ExeName;
        b_size = GetFileVersionInfoSize(s.c_str(),&dw);
        if (b_size){ // i can get the version of the file
                p_buf = malloc(b_size);
                GetFileVersionInfo(s.c_str(),dw,b_size,p_buf);
                if( VerQueryValue( p_buf, "\\", (LPVOID *) &pFileInfo, (PUINT)&b_size ) ){
                        cur_version.Maj_Version = HIWORD(pFileInfo->dwFileVersionMS);
                        cur_version.Min_Version = LOWORD(pFileInfo->dwFileVersionMS);
                        cur_version.Build = LOWORD(pFileInfo->dwProductVersionLS);
                        cur_version.Revision = HIWORD(pFileInfo->dwProductVersionLS);
                        }
                free(p_buf);
                }
}
/*----------------------------------------------------------------------------*/
// активируем UDP сервер
void TFormMain::setActiveServerUDP(const int port)
{
IdUDPServer->DefaultPort = port;
IdUDPServer->Active=true;
}
void TFormMain::setActiveServer(bool acv)
{
IdUDPServer->Active=acv;
}
/*----------------------------------------------------------------------------*/
// активируем UDP клиента
void TFormMain::setActiveClientUDP(const AnsiString ip,const int port)
{
// init UPD client
IdUDPClient->Host = ip;
IdUDPClient->Port = port;
IdUDPClient->Active=true;
}
void TFormMain::setActiveClient(bool acv)
{
IdUDPClient->Active=acv;
}
void TFormMain::setClientIP(const AnsiString ip)
{
IdUDPClient->Host = ip;
IdUDPClient->Active=true;
}

