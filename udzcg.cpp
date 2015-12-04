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
// ����� ��� ���������� ��������
strLogical->Add("    �");
strLogical->Add("  ���");
strLogical->Add("  �-��");
strLogical->Add("���-��");
cbbOpr1->Items->AddStrings(strLogical);
cbbOpr1->ItemIndex = 0;
cbbOpr2->Items->AddStrings(strLogical);
cbbOpr2->ItemIndex = 0;
strClorCCG->Add("�");
strClorCCG->Add("�");
strClorCCG->Add("�");
strClorCCG->Add("1");
strClorCCG->Add("0");
strClorUDZCG->Add("�");
strClorUDZCG->Add("�");
strClorUDZCG->Add("�");
cbbResultSign->Items->AddStrings(strClorUDZCG);
cbbResultSign->ItemIndex = 0;
strClorUDZCG->Add("1");
strClorUDZCG->Add("0");
setVisibleDirection();
// ��������� �� �����
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
/*������� ���� ���������� ----------------------------------------------------*/
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
// ���������� ����������� � comboboxs-----------------------------------------//
void TFormUDZG::setVisibleDirection(void)
{
// ��������� ������ ���� �����������
setListDirection();
// ����������
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
// ���������� �����
setStrCbCollor(cbbA,cbbAS);
setStrCbCollor(cbbB,cbbBS);
setStrCbCollor(cbbC,cbbCS);
// ���������� ��� ����� listbox
showAllPrmOutList();
BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TFormUDZG::btnExitClick(TObject *Sender)
{
FormUDZG->Visible = false;
}
//---------------------------------------------------------------------------
// �������� ��� ���������
void TFormUDZG::deliteAllMaskUDZCG(void)
{
memset(&tempDate,0,sizeof(tempDate)); //
memset(&PAP.ExpUDZ,0,sizeof(PAP.ExpUDZ));
}
//---------------------------------------------------------------------------
// ������� ���� ������� �� ��������� � �������� ��������
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
/* ��������� ������� � ��������� ---------------------------------------------*/
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
/* ��������� � ��������� ��������������� ����� �� ComboBox -------------------*/
bool TFormUDZG::checkMaskUDZCG(void)
{
// ��������� ������ �����
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
// �������� �� ���������� �������� �����������
const int countCCG = strCCG->Count;  // ���������� �������� ����������� ���

for(int In=0;In<tempDate.Count;In++) //active direction
        {
        if(tempDate.Expression[In].result.NumberDir-countCCG==cbbResult->ItemIndex){ // ��������� ��� ����������� � �����
                if(tempDate.Expression[In].result.TypeCol== cbbResultSign->ItemIndex)return false;
                }
        }
// save line mask
saveMaskUDZCG();
return true;
}
/* �������� �� ��������� ���������� ��� � ���������� ��������� ---------------*/
RetAnsSTR TFormUDZG::checkDirectUDZCG(void)
{
RetAnsSTR ret("��",retOk);
bool result[MAX_OPERAND] = {false};
const int countCCG = strCCG->Count;  // ���������� �������� ����������� ���

// ��� �������� � ���. ���������
for(int i=0;i<MAX_OPERAND;i++)
        {
        if(cmbDir[i]->ItemIndex>=countCCG){// ����������� ����� ��������� ������ �� �������
                if(cmbClr[i]->ItemIndex>=MUL_COLOR_COUNT) continue; // �����
                result[i] = true; // ���� ���������
                for(int In=0;In<tempDate.Count;In++)// ��� ������� �������� �����������
                        {
                        if(tempDate.Expression[In].result.NumberDir==cmbDir[i]->ItemIndex){
                                if(tempDate.Expression[In].result.TypeCol == cmbClr[i]->ItemIndex){
                                        // ������
                                        result[i] = false;
                                        }
                                }
                        }
                }
        if(result[i]){ // ������ �������
                ret.setString("�������: �"+IntToStr(i+1)+" �� ���������!");
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
        Application->MessageBox("��� ����������� �����!", "������", MB_OK);
        return;
        }
// �� ������ ����������� �����
RetAnsSTR rets = checkDirectUDZCG();
if(rets.getAnswer()!=retOk){
          Application->MessageBox(rets.getString().c_str(), "������", MB_OK);
          return;
          }
// ��������� ���������� �����������
if(!checkMaskUDZCG()){
        Application->MessageBox("����������� ���������� ����������� �����!", "������", MB_OK);
        return;
        }
if(lstOut->Items->Count>=MAX_UDZCG){ // MAX_UDZCG �� ������ structures.h
        Application->MessageBox("�������� ������ �������!", "������", MB_OK);
        return;
        }
RetAnsSTR ret = showOnePrmOutList(tempDate.Count-1); // �������� ��������� ����� ��� ������
if(ret.getAnswer()!=retOk){
          Application->MessageBox("������ � ��������� ������ �������!", "������", MB_OK);
          return;
          }
lstOut->Items->Add(ret.getString());
}
/*----------------------------------------------------------------------------*/
//remove list
void __fastcall TFormUDZG::btnMinusClick(TObject *Sender)
{
int index = lstOut->Items->Count; // ������� �����?
if(index){lstOut->Items->Delete(index-1);}
deleteMaskUDZCG();
}
/*----------------------------------------------------------------------------*/
// ��������� � �������� ������
void __fastcall TFormUDZG::btnOkClick(TObject *Sender)
{
memcpy(&PAP.ExpUDZ,&tempDate,sizeof(PAP.ExpUDZ));
// �������� ��������� ����������� ��� ������� �����
CountCCG = strCCG->Count;
CountUDZCG = strUDZCG->Count;
}
/*----------------------------------------------------------------------------*/
/*���������� ����� ����������� ComboBoxColor */
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
/*������� �� ���� ComboBoxs ������ ����������� */
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
/*������� �� ���� ComboBoxs ������ ����� */
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
/*��������� ����������� ������ ������ �� GUI ---------------------------------*/
WORD TFormUDZG::checkAllParameter(void)
{
if(!tempDate.Count)return retEmpty; // �� ������ �� ����� �����

for(int In=0;In<tempDate.Count;In++)
        {
        // �������� ��������� ���������� ��������
        for(int i=0;i<MAX_OPERATION;i++)
                if(tempDate.Expression[In].logic[i]>=END_LOGIC_OP)return retError;

        // �������� ��������� ���������
        for(int i=0;i<MAX_OPERAND;i++)
                {
                if(tempDate.Expression[In].operand[i].NumberDir>=cmbDir[i]->Items->Count)return retError;
                if(tempDate.Expression[In].operand[i].TypeCol>=cmbClr[i]->Items->Count)return retError;
                }
        //�������� ��������� �����������
        if(tempDate.Expression[In].result.NumberDir-strCCG->Count >=cbbResult->Items->Count)return retError;
        if(tempDate.Expression[In].result.TypeCol >=cbbResultSign->Items->Count)return retError;
        }
return retOk;
}
/*���������� ��������� ��������� �� ��������� � ComboBox----------------------*/
void TFormUDZG::showOnePrmComboBox(const int Index)
{
if(checkAllParameter()==retError){
  Application->MessageBox("������ � ��������� ������!", "������", MB_OK);
  }
if(Index<tempDate.Count){
  // �������� ��������
  for(int i=0;i<cbbOpr.size();i++)
        cbbOpr[i]->ItemIndex  = tempDate.Expression[Index].logic[i];
  // ���������� ���������
  chkResultInv->Checked    = (bool)tempDate.Expression[Index].result.NotAcv;
  cbbResult->ItemIndex     = tempDate.Expression[Index].result.NumberDir - strCCG->Count;
  cbbResultSign->ItemIndex = tempDate.Expression[Index].result.TypeCol;
  // ���������� ��������
  for(int i=0;i<MAX_OPERAND;i++)
        {
        chesk[i]->Checked  = (bool)tempDate.Expression[Index].operand[i].NotAcv; // call event click
        cmbDir[i]->ItemIndex = tempDate.Expression[Index].operand[i].NumberDir;
        cmbClr[i]->ItemIndex = tempDate.Expression[Index].operand[i].TypeCol;
        if(cmbClr[i]->ItemIndex<MUL_COLOR_COUNT)cmbDir[i]->Enabled = true;
                                           else cmbDir[i]->Enabled = false;
        }
  }else{
  Application->MessageBox("��� ������ � ��������� ������!", "������", MB_OK);
  }
}
/*������� ����� ��� ����������� � OutList ��������� MASK----------------------*/
/*
return ��������� RET_ANSWER
Index - ����� ������ � ��������� ������  ��� �������� (������ ��� 64)
*/
RetAnsSTR TFormUDZG::showOnePrmOutList(const int Index)
{
RetAnsSTR ret("",retError);
AnsiString OutStr;
vector<AnsiString>const strTmp;
const int countCCG = strCCG->Count;  // ���������� �������� ����������� ���
const int countUDZCG = strUDZCG->Count; // ���������� �������� ����������� �����
const int countClrCCG = strClorCCG->Count;//
const int countClrUDZCG = strClorUDZCG->Count;

if(tempDate.Count>Index){ // �������� �� �������� �����������
        // �������� ���������
        int NumberDir = tempDate.Expression[Index].result.NumberDir-countCCG; // ��� ��� ������
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
        // �������� ��������
        for(int i=0;i<MAX_OPERAND;i++) // ��� �������
                {
                OutStr = "";
                int TypeDir  = tempDate.Expression[Index].operand[i].TypeDir;
                int inTypeClr = tempDate.Expression[Index].operand[i].TypeCol;
                if(TypeDir==DIR_CCG){// ����������� ���
                        int NumberDir   = tempDate.Expression[Index].operand[i].NumberDir;
                        if((NumberDir<countCCG)&&(inTypeClr<countClrCCG)){
                                OutStr = "("+strCCG[0][NumberDir]+"-";
                                if(tempDate.Expression[Index].operand[i].NotAcv)OutStr+="!";
                                OutStr+= strClorCCG[0][inTypeClr]+")";
                                }else{
                                return ret;
                                }
                        }else{ // ����������� �����
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
// �������� ���� ����� ���������
OutStr = IntToStr(Index+1)+".";
for(int i=0;i<strTmp.size();i++)
        {
        OutStr+=strTmp[i];
        }
ret.setString(OutStr);
ret.setAnswer(retOk);
return ret;
}

/*���������� ��������� � OutList �� ��������� MASK ������ ��� �������� ���� ���C�*/
void TFormUDZG::showAllPrmOutList(void)
{
ExData::TPROJECT *prj = FormMain->retDataProject();
ExData::TEXPRESSIONS *tMask = &(prj->ExpUDZ);
memcpy(&tempDate,tMask,sizeof(tempDate));


if(checkAllParameter()==retError){
  Application->MessageBox("������ � ��������� ������! ���������� �����������.", "������", MB_OK);
  deliteAllMaskUDZCG();
  }
// ��������� ����� ������
lstOut->Items->Clear();
for(int In=0;In<tempDate.Count;In++)
        {
        RetAnsSTR ret = showOnePrmOutList(In);
        if(ret.getAnswer()!=retOk){
          Application->MessageBox("������ � ��������� ������ ������� �����!���������� ����������� �����.", "������", MB_OK);
          deliteAllMaskUDZCG(); // ������ ���������
          return;
          }
        lstOut->Items->Add(ret.getString());
        }
}
/*������� �������� � OutList, ����� �������� � ComboBox'S --------------------*/
void __fastcall TFormUDZG::lstOutClick(TObject *Sender)
{
showOnePrmComboBox(FormUDZG->lstOut->ItemIndex);
}
/*----------------------------------------------------------------------------*/




