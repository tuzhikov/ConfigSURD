//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "fazas.h"
#include "Unit1.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrPhaseTemplate *frPhaseTemplate;

/*----------------------------------------------------------------------------*/
__fastcall TfrPhaseTemplate::TfrPhaseTemplate(TComponent* Owner)
        : TForm(Owner)
{
}
/*----------------------------------------------------------------------------*/
/*Создать таблицу*/
void __fastcall TfrPhaseTemplate::FormCreate(TObject *Sender)
{
StringGrid1->ColCount = MaxFase+1;
StringGrid1->ColWidths[0] = 100;
for (int i=1; i< MaxFase+1; i++)
        StringGrid1->ColWidths[i] = 40;
StringGrid1->Cells[0][0] = " Напр / Фазы";
}
/*показать фазы в таблице*/
void TfrPhaseTemplate::showPhases(void)
{
int maxDirectionsCCG = tempProject.Directs.countDirectCCG;
// задаем строки
frPhaseTemplate->StringGrid1->RowCount = maxDirectionsCCG+1;
// устанавливаем мак фазы
for (int i=0; i<MaxProgFase; i++)
        frPhaseTemplate->StringGrid1->Cells[i+1][0] = IntToStr(i+1);
// устанавливаем активные направления
for (int i=0; i<maxDirectionsCCG; i++)
        frPhaseTemplate->StringGrid1->Cells[0][i+1] = IntToStr(i+1);
}
/*показать форму на главном окне*/
void TfrPhaseTemplate::showFormPhase(const ExData::TPROJECT *pPrj)
{
memcpy(&tempProject,pPrj, sizeof(tempProject));
showPhases();
frPhaseTemplate->Visible =true;
frPhaseTemplate->BringToFront();
}
/*----------------------------------------------------------------------------*/
void __fastcall TfrPhaseTemplate::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
if ((ACol > 0)&&(ARow > 0)){
        if(tempProject.Fasa[ACol-1].Direct[ARow-1]==0){
                StringGrid1->Canvas->Brush->Color = clRed;
                StringGrid1->Canvas->Rectangle(Rect);
                }
        if(tempProject.Fasa[ACol-1].Direct[ARow-1]){
                StringGrid1->Canvas->Brush->Color = clGreen;
                StringGrid1->Canvas->Rectangle(Rect);
                }
        }
}
/*----------------------------------------------------------------------------*/
void __fastcall TfrPhaseTemplate::btnCloseClick(TObject *Sender)
{
Visible = false;
}
/*----------------------------------------------------------------------------*/
void __fastcall TfrPhaseTemplate::btnSaveClick(TObject *Sender)
{
int btn=mrNone;

if (FormMain->Check_Confl_In_Sh_Faze(&tempProject)){ // проверка из unit 1
        btn = MessageBox(0,"Ошибка проекта: матрица конфликтов не соответствует шаблонам фаз",
                        "Отменено!!!",MB_YESNO);
        if (btn==6){
                return;}
        if (btn==7){
                return;}
        }
// внешние переменные
ExData::TPROJECT *prj = FormMain->retDataProject();
memcpy(&prj->Fasa, &tempProject.Fasa, sizeof(tempProject.Fasa));
FormMain->retVIS()->is_edit=true;
FormMain->RefreshAllForms();
}
/*----------------------------------------------------------------------------*/
void __fastcall TfrPhaseTemplate::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
tempProject.Fasa[ACol-1].Direct[ARow-1]=
                !tempProject.Fasa[ACol-1].Direct[ARow-1];
StringGrid1->Refresh();
}
/*----------------------------------------------------------------------------*/
