//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop
#include "dayplans.h"
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPlansDay *FormPlansDay;

/*----------------------------------------------------------------------------*/
__fastcall TFormPlansDay::TFormPlansDay(TComponent* Owner)
        : TForm(Owner),currentPlan(0),currentTimeSlot(0)
{
// ������ ������� ��� ������
dtpDateTime->Format = "HH:mm";
}
//---------------------------------------------------------------------------
void __fastcall TFormPlansDay::FormCreate(TObject *Sender)
{
FormPlansDay->StringGrid->Cells[0][0] = " � ����";
FormPlansDay->StringGrid->Cells[1][0] = " ����� ������";
FormPlansDay->StringGrid->ColWidths[0] = 150;
FormPlansDay->StringGrid->ColWidths[1] = 190;
FormPlansDay->StringGrid->Cells[0][1] = "1";
FormPlansDay->StringGrid->Cells[1][1] = "00:00";
showFormDaysPlans();
}
/*������������� ����� � ������ TDT*/
TDateTime  TFormPlansDay::convertSecondsToTDT(const DWORD begintime)
{
TDateTime  tdt;
WORD hh,mm,ss,ms;

hh = begintime / 3600;
mm = (begintime - hh*3600) / 60;
//ss = begintime % 60;
ss = 0;
ms = 0;
tdt = EncodeTime(hh,mm,ss,ms);
return (tdt);
}
/*�������� ����� � ������� AnsiString*/
AnsiString  TFormPlansDay::convertSecondsToStr(const DWORD begintime)
{
const WORD hh = begintime / 3600;
const WORD mm = (begintime - hh*3600) / 60;
AnsiString strHH, strMM;
if(hh<10)strHH = "0"+IntToStr(hh);
        else strHH = IntToStr(hh);
if(mm<10)strMM = "0"+IntToStr(mm);
        else strMM = IntToStr(mm);
return strHH+":"+strMM;
}
/*----------------------------------------------------------------------------*/
void TFormPlansDay::showTime(void)
{
BYTE p_i, s_i;
p_i =tempPrj.DaysPlans[currentPlan].CalendTime[currentTimeSlot].NumProgramWorks;
s_i =tempPrj.DaysPlans[currentPlan].CalendTime[currentTimeSlot].SpecProg;

TDateTime tdt;
DWORD  time_i;
time_i =tempPrj.DaysPlans[currentPlan].CalendTime[currentTimeSlot].BeginTimeWorks;
tdt = convertSecondsToTDT(time_i);
FormPlansDay->dtpDateTime->Time = tdt;
}
void TFormPlansDay::saveTempStructure(const ExData::TPROJECT *pPrj)
{
memcpy(&tempPrj,pPrj, sizeof(tempPrj));
}
//---------------------------------------------------------------------------
// ��������� �� ��������� ������ � �������� �����
void TFormPlansDay::showFormDaysPlans(void)
{
//memcpy(&tempPrj, &PAP, sizeof(PAP));
saveTempStructure(&PAP);
ListBox->ItemIndex=currentPlan;
StringGrid->Refresh();
showDayPlan(currentPlan);
BringToFront();
}
//---------------------------------------------------------------------------
// �������� ������ ���� ������ �������
void TFormPlansDay::showDayPlan(const int planDey)
{
int time_n = tempPrj.DaysPlans[planDey].AmountCalendTime; // ������� ���
FormPlansDay->StringGrid->RowCount =time_n +1;

for (int i=0; i<time_n; i++)
        {
        if(!i)continue;// �������� ��� 1 �����������
        FormPlansDay->StringGrid->Cells[0][i+1] = IntToStr(i+1);
        const int p_i = tempPrj.DaysPlans[planDey].CalendTime[i].BeginTimeWorks;
        //TDateTime  tdt = convertSecondsToTDT(p_i);
        //AnsiString time = TimeToStr(tdt);
        const AnsiString time = convertSecondsToStr(p_i);
        FormPlansDay->StringGrid->Cells[1][i+1] = time;//TimeToStr(tdt);
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormPlansDay::btnExitClick(TObject *Sender)
{
Visible = false;
}
//---------------------------------------------------------------------------
// ��������� �� ������ �����
bool TFormPlansDay::checkAllTime(void)
{
bool res=false;
for(int i_plan=0; i_plan<MaxDaysPlans; i_plan++)
        {
        const int countCalendar = tempPrj.DaysPlans[i_plan].AmountCalendTime;
        for(int i=1; i< countCalendar; i++)
                {
                if((tempPrj.DaysPlans[i_plan].CalendTime[i].BeginTimeWorks==0)
                        &&(i==countCalendar-1)){continue;} // �������� ��������� ���� �������� �� ����������
                if(tempPrj.DaysPlans[i_plan].CalendTime[i].BeginTimeWorks<
                                tempPrj.DaysPlans[i_plan].CalendTime[i-1].BeginTimeWorks){
                        res=true;
                        break;
                        }
                }
        }
return(res);
}
//---------------------------------------------------------------------------
// ������ ��������� �������
void TFormPlansDay::correctAllTime(void)
{
for (int i_plan=0;i_plan<MaxDaysPlans;i_plan++)
        for (int i=1;i<tempPrj.DaysPlans[i_plan].AmountCalendTime;i++)
                if(tempPrj.DaysPlans[i_plan].CalendTime[i].BeginTimeWorks<
                                        tempPrj.DaysPlans[i_plan].CalendTime[i-1].BeginTimeWorks){
                        tempPrj.DaysPlans[i_plan].CalendTime[i].BeginTimeWorks =
                                        tempPrj.DaysPlans[i_plan].CalendTime[i-1].BeginTimeWorks;
                        }
}
//---------------------------------------------------------------------------
void TFormPlansDay::forPlusandMinusBut(void)
{
int btn=mrNone;
// ��������� �����
if (checkAllTime())
        btn = MessageDlg("������������ �����. ���������������?",mtError, mbOKCancel,0);
        else{
        memcpy(&PAP.DaysPlans, &tempPrj.DaysPlans, sizeof(TCALENDAR)*MaxDaysPlans); // �������� ��� �������
        }
if(btn==mrOk){
        correctAllTime();
        showDayPlan(currentPlan);// ���������� ��������� ��������
        }
FormMain->retVIS()->is_edit=true;
}
/*save parametrs--------------------------------------------------------------*/
void __fastcall TFormPlansDay::btnOkClick(TObject *Sender)
{
forPlusandMinusBut();
FormMain->updateTimePhase();// �� ������� �����
}
/*---------------------------------------------------------------------------*/
void TFormPlansDay::setCurrentPlan(const int crPlan)
{
currentPlan = crPlan;
// �������� ������� �����
showDayPlan(currentPlan);
//���������� ���� �� ������� ����
FormMain->setDayPlan(currentPlan);
// ���������� ����� ����� �� listbox
FormPlansDay->ListBox->ItemIndex=currentPlan;
FormPlansDay->ListBox->Font->Color = clBlue;
}
//---------------------------------------------------------------------------
void __fastcall TFormPlansDay::ListBoxClick(TObject *Sender)
{
const int i = FormPlansDay->ListBox->ItemIndex;
setCurrentPlan(i);
forPlusandMinusBut();
FormMain->updateTimePhase();
}
//---------------------------------------------------------------------------
// ����� ��
void __fastcall TFormPlansDay::StringGridSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
if (ARow)
        currentTimeSlot = ARow-1;
// ���������� ������ �����
if(currentTimeSlot)
        showTime();

}
//---------------------------------------------------------------------------
void __fastcall TFormPlansDay::dtpDateTimeChange(TObject *Sender)
{
TDateTime  tdt = FormPlansDay->dtpDateTime->Time;
AnsiString s = TimeToStr(tdt);
tdt = tdt - floor(tdt); //��������� ������ ����� ���
WORD hh,mm,ss,ms;
int sec_begin;
DecodeTime(tdt, hh,mm,ss,ms);
sec_begin = hh*3600 + mm*60; // ������ ���� � ������
tempPrj.DaysPlans[currentPlan].CalendTime[currentTimeSlot].BeginTimeWorks = sec_begin;
showDayPlan(currentPlan);
}
//---------------------------------------------------------------------------
// �������
void TFormPlansDay::removeDayPlans(void)
{
for(int i=0;i<MaxDaysPlans;i++)
        {
        if(tempPrj.DaysPlans[i].AmountCalendTime>1){
                tempPrj.DaysPlans[i].AmountCalendTime--;
                //
                tempPrj.DaysPlans[i].CalendTime[tempPrj.DaysPlans[i].AmountCalendTime].BeginTimeWorks = 0;
                }
        showDayPlan(i);
        }
forPlusandMinusBut();// save struct
}
// �������� ------------------------------------------------------------------//
void TFormPlansDay::addDayPlans(void)
{
for(int i=0;i<MaxDaysPlans;i++)
        {
        if (tempPrj.DaysPlans[i].AmountCalendTime < MaxCalendar){
                int i_n = ++tempPrj.DaysPlans[i].AmountCalendTime;
                tempPrj.DaysPlans[i].CalendTime[i_n-1].BeginTimeWorks=
                                tempPrj.DaysPlans[i].CalendTime[i_n-2].BeginTimeWorks+2700;
                showDayPlan(i);
                }
        }
forPlusandMinusBut(); // save struct
}
