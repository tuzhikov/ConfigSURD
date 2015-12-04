//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "udzcg.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUDZG *FormUDZG;
typedef enum{cbRES,cbA,cbB,cbC,cbAS,cbBS,cbCS,END_cb}TYPE_OP;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TFormUDZG::TFormUDZG(TComponent* Owner)
        : TForm(Owner),
        strCCG(new TStringList()),
        strUDZCG(new TStringList()),
        strClorCCG(new TStringList()),
        strClorUDZCG(new TStringList()),
        strLogical(new TStringList())
{
FormUDZG->Visible = false;
cbbResult->Tag = cbRES;
cbbA->Tag = cbA;
cbbAS->Tag = cbAS;
cbbB->Tag = cbB;
cbbBS->Tag = cbBS;
cbbC->Tag = cbC;
cbbCS->Tag = cbCS;
// текст для логических операций
strLogical->Add("    И");
strLogical->Add("  ИЛИ");
strLogical->Add("  И-НЕ");
strLogical->Add("ИЛИ-НЕ");
cbbOpr1->Items->AddStrings(strLogical);
cbbOpr1->ItemIndex = 0;
cbbOpr2->Items->AddStrings(strLogical);
cbbOpr2->ItemIndex = 0;
strClorCCG->Add("К");
strClorCCG->Add("Ж");
strClorCCG->Add("З");
strClorCCG->Add("1");
strClorCCG->Add("0");
strClorUDZCG->Add("П");
strClorUDZCG->Add("Н");
strClorUDZCG->Add("Ф");
cbbResultSign->Items->AddStrings(strClorUDZCG);
cbbResultSign->ItemIndex = 0;
strClorUDZCG->Add("1");
strClorUDZCG->Add("0");
setVisibleDirection();
// указатели на форме
chesk.push_back(chkAInv);
chesk.push_back(chkBInv);
chesk.push_back(chkCInv);
cmbDir.push_back(cbbA);
cmbDir.push_back(cbbB);
cmbDir.push_back(cbbC);
cmbClr.push_back(cbbAS);
cmbClr.push_back(cbbBS);
cmbClr.push_back(cbbCS);
cbbOpr.push_back(cbbOpr1);
cbbOpr.push_back(cbbOpr2);
memset(&tempDate,0,sizeof(tempDate));
}
/*собрать лист напралений ----------------------------------------------------*/
void TFormUDZG::setListDirection(void)
{
ExData::TPROJECT *prj = FormMain->retDataProject();
int currentDir = prj->AmountDirects, countCCG=1,countUDZCG=1;
strCCG->Clear();
strUDZCG->Clear();
for (int i=0; i<currentDir; i++)
        {
        if(prj->Directs.OneDirect[i].Type!=DIR_CCG){
          strUDZCG->Add(IntToStr(countUDZCG++) + ". " +
             DiagramPainter::Get_Full_TXT_Napr(prj, i));
          }
        if(prj->Directs.OneDirect[i].Type==DIR_CCG){
          strCCG->Add(IntToStr(countCCG++) + ". " +
             DiagramPainter::Get_Full_TXT_Napr(prj, i));
          }
        }
}
// отобразить направления в comboboxs-----------------------------------------//
void TFormUDZG::setVisibleDirection(void)
{
// построить список всех направлений
setListDirection();
// отобразить
cbbResult->Clear();
if(strUDZCG->Count){
        cbbResult->Items->AddStrings(strUDZCG);
        cbbResult->ItemIndex = 0;
        }
cbbA->Clear();
cbbA->Items->AddStrings(strCCG);
cbbA->Items->AddStrings(strUDZCG);
cbbA->ItemIndex = 0;
cbbB->Clear();
cbbB->Items->AddStrings(strCCG);
cbbB->Items->AddStrings(strUDZCG);
cbbB->ItemIndex = 0;
cbbC->Clear();
cbbC->Items->AddStrings(strCCG);
cbbC->Items->AddStrings(strUDZCG);
cbbC->ItemIndex = 0;
// установить цвета
setStrCbCollor(cbbA,cbbAS);
setStrCbCollor(cbbB,cbbBS);
setStrCbCollor(cbbC,cbbCS);
// отобразить все маски listbox
showAllPrmOutList();
BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TFormUDZG::btnExitClick(TObject *Sender)
{
FormUDZG->Visible = false;
}
//---------------------------------------------------------------------------
// очичтить всю структуру
void TFormUDZG::deliteAllMaskUDZCG(void)
{
memset(&tempDate,0,sizeof(tempDate)); //
memset(&PAP.ExpUDZ,0,sizeof(PAP.ExpUDZ));
}
//---------------------------------------------------------------------------
// удалить один элемент из структуры с очисткой элемента
void TFormUDZG::deleteMaskUDZCG(void)
{
if(tempDate.Count>=MAX_UDZCG)return;

tempDate.Expression[tempDate.Count].logic[0] = 0;
tempDate.Expression[tempDate.Count].logic[1] = 0;
tempDate.Expression[tempDate.Count].result.NotAcv = 0;
tempDate.Expression[tempDate.Count].result.NumberDir = 0;
tempDate.Expression[tempDate.Count].result.TypeCol = 0;
for(int i=0;i<MAX_OPERAND;i++)
        {
        tempDate.Expression[tempDate.Count].operand[i].NotAcv = 0;
        tempDate.Expression[tempDate.Count].operand[i].NumberDir = 0;
        tempDate.Expression[tempDate.Count].operand[i].TypeCol = 0;
        }
if(tempDate.Count)tempDate.Count--;
}
/* сохранить элемент в структуру ---------------------------------------------*/
bool TFormUDZG::saveMaskUDZCG(void)
{
const int index = tempDate.Count;
if(cbbOpr1->ItemIndex<END_LOGIC_OP){
        tempDate.Expression[index].logic[0] = cbbOpr1->ItemIndex;
        tempDate.Expression[index].logic[1] = cbbOpr2->ItemIndex;
        } else return false;
tempDate.Expression[index].result.NotAcv =  chkResultInv->Checked;
tempDate.Expression[index].result.NumberDir = strCCG->Count+cbbResult->ItemIndex;
tempDate.Expression[index].result.TypeCol = cbbResultSign->ItemIndex;
tempDate.Expression[index].result.TypeDir = DIR_UDZCG;
for(int i=0;i<MAX_OPERAND;i++)
        {
        tempDate.Expression[index].operand[i].NotAcv = chesk[i]->Checked;
        tempDate.Expression[index].operand[i].NumberDir = cmbDir[i]->ItemIndex;
        if(cmbDir[i]->ItemIndex<strCCG->Count){
                tempDate.Expression[index].operand[i].TypeDir = DIR_CCG;
                }else{
                tempDate.Expression[index].operand[i].TypeDir = DIR_UDZCG;
                }
        tempDate.Expression[index].operand[i].TypeCol = cmbClr[i]->ItemIndex;

        }
if(tempDate.Count<MAX_UDZCG)tempDate.Count++;
return true;
}
/* проверить и сохранить устанавливаемую маску из ComboBox -------------------*/
bool TFormUDZG::checkMaskUDZCG(void)
{
// проверяем строку ввода
if(cbbResult->Text==cbbA->Text){
        if(cbbResultSign->Text==cbbAS->Text)return false;
        }
        else
        if(cbbResult->Text==cbbB->Text){
                if(cbbResultSign->Text==cbbBS->Text)return false;
                }
                else
                if(cbbResult->Text==cbbC->Text){
                        if(cbbResultSign->Text==cbbCS->Text)return false;
                        }
// проверка на повторение заданных направлений
const int countCCG = strCCG->Count;  // количество активных направлений ССГ

for(int In=0;In<tempDate.Count;In++) //active direction
        {
        if(tempDate.Expression[In].result.NumberDir-countCCG==cbbResult->ItemIndex){ // проверяем все направления с новым
                if(tempDate.Expression[In].result.TypeCol== cbbResultSign->ItemIndex)return false;
                }
        }
// save line mask
saveMaskUDZCG();
return true;
}
/* проверка на созданные направленя УДЗ в логическом выражении ---------------*/
RetAnsSTR TFormUDZG::checkDirectUDZCG(void)
{
RetAnsSTR ret("ОК",retOk);
bool result[MAX_OPERAND] = {false};
const int countCCG = strCCG->Count;  // количество активных направлений ССГ

// все операнды в лог. выражении
for(int i=0;i<MAX_OPERAND;i++)
        {
        if(cmbDir[i]->ItemIndex>=countCCG){// направление УДЗСГ проверить задано ли зарание
                if(cmbClr[i]->ItemIndex>=MUL_COLOR_COUNT) continue; // выход
                result[i] = true; // надо проверить
                for(int In=0;In<tempDate.Count;In++)// все заданые активные направления
                        {
                        if(tempDate.Expression[In].result.NumberDir==cmbDir[i]->ItemIndex){
                                if(tempDate.Expression[In].result.TypeCol == cmbClr[i]->ItemIndex){
                                        // задано
                                        result[i] = false;
                                        }
                                }
                        }
                }
        if(result[i]){ // ошибка выходим
                ret.setString("Операнд: №"+IntToStr(i+1)+" не определен!");
                ret.setAnswer(retError);
                break;
                }
        }
return ret;
}
/* add list ------------------------------------------------------------------*/
void __fastcall TFormUDZG::btnPlusClick(TObject *Sender)
{
AnsiString out;

if(!cbbResult->Items->Count){
        Application->MessageBox("Нет направлений УДЗСГ!", "Ошибка", MB_OK);
        return;
        }
// не заданы направления УДЗСГ
RetAnsSTR rets = checkDirectUDZCG();
if(rets.getAnswer()!=retOk){
          Application->MessageBox(rets.getString().c_str(), "Ошибка", MB_OK);
          return;
          }
// установка одиниковых направлений
if(!checkMaskUDZCG()){
        Application->MessageBox("Неправильно установили направление УДЗСГ!", "Ошибка", MB_OK);
        return;
        }
if(lstOut->Items->Count>=MAX_UDZCG){ // MAX_UDZCG из модуля structures.h
        Application->MessageBox("Превышен предел условий!", "Ошибка", MB_OK);
        return;
        }
RetAnsSTR ret = showOnePrmOutList(tempDate.Count-1); // собираем сообщения текст для вывода
if(ret.getAnswer()!=retOk){
          Application->MessageBox("Ошибка в структуре данных проекта!", "Ошибка", MB_OK);
          return;
          }
lstOut->Items->Add(ret.getString());
}
/*----------------------------------------------------------------------------*/
//remove list
void __fastcall TFormUDZG::btnMinusClick(TObject *Sender)
{
int index = lstOut->Items->Count; // сколько строк?
if(index){lstOut->Items->Delete(index-1);}
deleteMaskUDZCG();
}
/*----------------------------------------------------------------------------*/
// сохраняем в основной проект
void __fastcall TFormUDZG::btnOkClick(TObject *Sender)
{
memcpy(&PAP.ExpUDZ,&tempDate,sizeof(PAP.ExpUDZ));
// сохраним состояние направлений для текущей сесии
CountCCG = strCCG->Count;
CountUDZCG = strUDZCG->Count;
}
/*----------------------------------------------------------------------------*/
/*Отображает цвета направлений ComboBoxColor */
void TFormUDZG::setStrCbCollor(const TComboBox *incb,const TComboBox *outcb)
{
if(incb->ItemIndex<strCCG->Count){
        outcb->Clear();
        outcb->Items->AddStrings(strClorCCG);
        }
        else{
        outcb->Clear();
        outcb->Items->AddStrings(strClorUDZCG);
        }
outcb->ItemIndex = 0;
}
/*событие по всем ComboBoxs выбора направлений */
void __fastcall TFormUDZG::lstOutChange(TObject *Sender)
{
if(((TComboBox*)Sender)->Tag==cbA){
        setStrCbCollor((TComboBox*)Sender,cbbAS);
        }
if(((TComboBox*)Sender)->Tag==cbB){
        setStrCbCollor((TComboBox*)Sender,cbbBS);
        }
if(((TComboBox*)Sender)->Tag==cbC){
        setStrCbCollor((TComboBox*)Sender,cbbCS);
        }
}
/*----------------------------------------------------------------------------*/
/*событие по всем ComboBoxs выбора цвета */
void __fastcall TFormUDZG::cbColorChange(TObject *Sender)
{
if(((TComboBox*)Sender)->ItemIndex<MUL_COLOR_COUNT){
        if(((TComboBox*)Sender)->Tag==cbAS) cbbA->Enabled=true;
        if(((TComboBox*)Sender)->Tag==cbBS) cbbB->Enabled=true;
        if(((TComboBox*)Sender)->Tag==cbCS) cbbC->Enabled=true;
        }else{
        if(((TComboBox*)Sender)->Tag==cbAS) cbbA->Enabled=false;
        if(((TComboBox*)Sender)->Tag==cbBS) cbbB->Enabled=false;
        if(((TComboBox*)Sender)->Tag==cbCS) cbbC->Enabled=false;
        }
}
/*frees memory----------------------------------------------------------------*/
void __fastcall TFormUDZG::FormDestroy(TObject *Sender)
{
delete strCCG;
delete strUDZCG;
delete strClorCCG;
delete strClorUDZCG;
delete strLogical;
}
/*проверить возможность вывода данных на GUI ---------------------------------*/
WORD TFormUDZG::checkAllParameter(void)
{
if(!tempDate.Count)return retEmpty; // не задано ни одной маски

for(int In=0;In<tempDate.Count;In++)
        {
        // проверка структуры логических операций
        for(int i=0;i<MAX_OPERATION;i++)
                if(tempDate.Expression[In].logic[i]>=END_LOGIC_OP)return retError;

        // проверка структуры операндов
        for(int i=0;i<MAX_OPERAND;i++)
                {
                if(tempDate.Expression[In].operand[i].NumberDir>=cmbDir[i]->Items->Count)return retError;
                if(tempDate.Expression[In].operand[i].TypeCol>=cmbClr[i]->Items->Count)return retError;
                }
        //проверка структуры результатов
        if(tempDate.Expression[In].result.NumberDir-strCCG->Count >=cbbResult->Items->Count)return retError;
        if(tempDate.Expression[In].result.TypeCol >=cbbResultSign->Items->Count)return retError;
        }
return retOk;
}
/*Отобразить выбранные параметры из структуры в ComboBox----------------------*/
void TFormUDZG::showOnePrmComboBox(const int Index)
{
if(checkAllParameter()==retError){
  Application->MessageBox("Ошибки в структуре данных!", "Ошибка", MB_OK);
  }
if(Index<tempDate.Count){
  // показать операции
  for(int i=0;i<cbbOpr.size();i++)
        cbbOpr[i]->ItemIndex  = tempDate.Expression[Index].logic[i];
  // отобразить результат
  chkResultInv->Checked    = (bool)tempDate.Expression[Index].result.NotAcv;
  cbbResult->ItemIndex     = tempDate.Expression[Index].result.NumberDir - strCCG->Count;
  cbbResultSign->ItemIndex = tempDate.Expression[Index].result.TypeCol;
  // отобразить операнды
  for(int i=0;i<MAX_OPERAND;i++)
        {
        chesk[i]->Checked  = (bool)tempDate.Expression[Index].operand[i].NotAcv; // call event click
        cmbDir[i]->ItemIndex = tempDate.Expression[Index].operand[i].NumberDir;
        cmbClr[i]->ItemIndex = tempDate.Expression[Index].operand[i].TypeCol;
        if(cmbClr[i]->ItemIndex<MUL_COLOR_COUNT)cmbDir[i]->Enabled = true;
                                           else cmbDir[i]->Enabled = false;
        }
  }else{
  Application->MessageBox("Нет записи в структуре данных!", "Ошибка", MB_OK);
  }
}
/*Собрать стоку для отображения в OutList структуры MASK----------------------*/
/*
return Структура RET_ANSWER
Index - номер записи в структуре данных  для отправки (сейчас мах 64)
*/
RetAnsSTR TFormUDZG::showOnePrmOutList(const int Index)
{
RetAnsSTR ret("",retError);
AnsiString OutStr;
vector<AnsiString>const strTmp;
const int countCCG = strCCG->Count;  // количество активных направлений ССГ
const int countUDZCG = strUDZCG->Count; // количество активных направлений УДЗСГ
const int countClrCCG = strClorCCG->Count;//
const int countClrUDZCG = strClorUDZCG->Count;

if(tempDate.Count>Index){ // проверка на активное направление
        // Собираем результат
        int NumberDir = tempDate.Expression[Index].result.NumberDir-countCCG; // все ССГ убрать
        int inTypeClr = tempDate.Expression[Index].result.TypeCol;
        if((NumberDir>=0)&&(NumberDir<countUDZCG)&&
                (inTypeClr<countClrUDZCG)&&(inTypeClr>=0)){
                OutStr = "("+strUDZCG[0][NumberDir]+"-";  //
                if(tempDate.Expression[Index].result.NotAcv)OutStr+="!";
                OutStr+= strClorUDZCG[0][inTypeClr]+") =";
                }else{
                return ret;
                }
        strTmp.push_back(OutStr);
        // Собираем операнды
        for(int i=0;i<MAX_OPERAND;i++) // все условия
                {
                OutStr = "";
                int TypeDir  = tempDate.Expression[Index].operand[i].TypeDir;
                int inTypeClr = tempDate.Expression[Index].operand[i].TypeCol;
                if(TypeDir==DIR_CCG){// направление ССГ
                        int NumberDir   = tempDate.Expression[Index].operand[i].NumberDir;
                        if((NumberDir<countCCG)&&(inTypeClr<countClrCCG)){
                                OutStr = "("+strCCG[0][NumberDir]+"-";
                                if(tempDate.Expression[Index].operand[i].NotAcv)OutStr+="!";
                                OutStr+= strClorCCG[0][inTypeClr]+")";
                                }else{
                                return ret;
                                }
                        }else{ // направление УДЗСГ
                        int NumberDir   = tempDate.Expression[Index].operand[i].NumberDir-countCCG;
                        if((NumberDir<countUDZCG)&&(inTypeClr<countClrUDZCG)){
                                OutStr = "("+strUDZCG[0][NumberDir]+"-";
                                if(tempDate.Expression[Index].operand[i].NotAcv)OutStr+="!";
                                OutStr+= strClorUDZCG[0][inTypeClr]+")";
                                }else{
                                return ret;
                                }
                        }
                if(i<MAX_OPERATION){
                        int inlogOp = tempDate.Expression[Index].logic[i];
                        AnsiString tsr = strLogical[0][inlogOp];
                        OutStr+=tsr.Trim();
                        }
                strTmp.push_back(OutStr);
                }
        }else{
        return ret;
        }
// собираем весь текст сообщения
OutStr = IntToStr(Index+1)+".";
for(int i=0;i<strTmp.size();i++)
        {
        OutStr+=strTmp[i];
        }
ret.setString(OutStr);
ret.setAnswer(retOk);
return ret;
}

/*Отобразить параметры в OutList из структуры MASK только при открытии окна УДЗCГ*/
void TFormUDZG::showAllPrmOutList(void)
{
ExData::TPROJECT *prj = FormMain->retDataProject();
ExData::TEXPRESSIONS *tMask = &(prj->ExpUDZ);
memcpy(&tempDate,tMask,sizeof(tempDate));


if(checkAllParameter()==retError){
  Application->MessageBox("Ошибки в структуре данных! Необходимо пересоздать.", "Ошибка", MB_OK);
  deliteAllMaskUDZCG();
  }
// сотавляем новый список
lstOut->Items->Clear();
for(int In=0;In<tempDate.Count;In++)
        {
        RetAnsSTR ret = showOnePrmOutList(In);
        if(ret.getAnswer()!=retOk){
          Application->MessageBox("Ошибка в структуре данных проекта УДЗСГ!Необходимо пересоздать УДЗСГ.", "Ошибка", MB_OK);
          deliteAllMaskUDZCG(); // чистим структуру
          return;
          }
        lstOut->Items->Add(ret.getString());
        }
}
/*выбрали операцию в OutList, можно показать в ComboBox'S --------------------*/
void __fastcall TFormUDZG::lstOutClick(TObject *Sender)
{
showOnePrmComboBox(FormUDZG->lstOut->ItemIndex);
}
/*----------------------------------------------------------------------------*/




