//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "project.h"
#include "Unit1.h"
#include "communic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormProject *FormProject;

//----------------------------------------------------------------------------//
__fastcall TFormProject::TFormProject(TComponent* Owner)
        : TForm(Owner)
{
}
//----------------------------------------------------------------------------//
void TFormProject::messageError(TError err)
{
if(err>=erEnd){
        Application->MessageBox("������ ����������", "������", MB_OK);
        return;
        }
TStringList *str = new TStringList();
str->Add("������ ����� ����� ethrernet");
str->Add("������ ����� �������� ethrernet");
str->Add("������ ����� ������� ����");
str->Add("������ ����� ���������� ����");
str->Add("������ ����� ������ ����");
char  *strError = str[0][err].c_str();
Application->MessageBox(strError, "������", MB_OK);
delete str;
}
//----------------------------------------------------------------------------//
/*���������� �����*/
void TFormProject::showFormProject(void)
{
// �������� �������
AnsiString   str;
ExData::TPROJECT *prj = FormMain->retDataProject();
str = AnsiString::AnsiString((const char *)&prj->comments.comment); // ����������
FormProject->Memo1->Text = str;
FormProject->CheckBox1->Checked = prj->jornal.power_on;
FormProject->CheckBox2->Checked = prj->jornal.power_off;
FormProject->CheckBox5->Checked = prj->jornal.faz;
FormProject->CheckBox6->Checked = prj->jornal.alarm;
FormProject->TrackBar1->Position = prj->jornal.gmt;
FormProject->Panel2->Caption = IntToStr(prj->jornal.gmt);
FormProject->edtTimeSt->Text = IntToStr(prj->surd.TimeDelay);
FormProject->edtTimeCN->Text = IntToStr(prj->surd.Count);
FormProject->medtPass->Text = IntToStr(prj->surd.Pass);
FormProject->ComboBoxDK->ItemIndex = prj->maxDK-1;
FormProject->chkGPS->Checked = prj->guard.gpsON;
//��������� �����
IpData.loadDateSurd(prj);
BuildTableIP(prj->maxDK);
tmpMAxDK = prj->maxDK;
//FormProject->MaskEditTime->Text = IntToStr(IpData.getDelay());// ����� �������� �� IP
FormProject->EditPort->Text = IntToStr(IpData.getPort());
FormProject->Visible=true; // ��������
//
BringToFront();
}
//----------------------------------------------------------------------------//
void __fastcall TFormProject::Button2Click(TObject *Sender)
{
Visible = false;
// �������� �������
// init UDP server
const int port = IpData.getPort();
FormMain->setActiveServerUDP(port);//���������� ������
// init UPD client
const AnsiString ip = IpData.getOneIp(0); // get ip default
FormMain->setActiveClientUDP(ip,port);//���������� �������
}
//----------------------------------------------------------------------------//
/*Button Save*/
void __fastcall TFormProject::Button1Click(TObject *Sender)
{
ExData::TPROJECT *prj = FormMain->retDataProject();
// save max DK
if(prj->maxDK!=tmpMAxDK){      // ��������� � ���������� ��
        prj->maxDK = tmpMAxDK; // set max Dk in project
        changeData = true;
        }
// ��������� ��������� IP
DWORD TempValue;
// eth port
try  {TempValue = StrToInt(EditPort->Text.Trim());}
        catch(...){messageError(erPortETH);return;}
IpData.setPort(TempValue);
prj->surd.PORT = IpData.getPort();
//time ��� ����� �� ���������� � ������� �� ��������� 1000��.
IpData.setDelay(1000);
prj->surd.TIMEOUT = 1000;
// ������ IP
IpData.removeIp();  // ������ ������ IP
IpData.removeMac(); // ������ ������ MAC
for(int i=0;i<prj->maxDK;i++)
        {
        AnsiString ip = StringGridDK->Cells[1][i+1];
        AnsiString mac = StringGridDK->Cells[2][i+1];
        // check ip
        if(!IpData.setOneIp(i,ip)){
                AnsiString err = "IP ����� ����� �������! ����� ��:" + IntToStr(i+1);
                Application->MessageBox((char*)err.c_str(), "������", MB_OK);
                return;
                }
        // check mac
        if(!IpData.setOneMac(i,mac)){
                AnsiString err = "MAC ����� ����� �������! ����� ��:" + IntToStr(i+1);
                Application->MessageBox((char*)err.c_str(), "������", MB_OK);
                return;
                }
        }
// �������� �� ��������� IP&MAC �������
for(int i=0;i<prj->maxDK;i++)
        {
        AnsiString ip = IpData.getOneIp(i);
        AnsiString mac = IpData.getOneMac(i);
        for(int j=0;j<IpData.getCountIp();j++)
                {
                if(i==j)continue;
                if(ip==IpData.getOneIp(j)){
                        AnsiString err = "IP ������ �����! ����� ��:"
                                        + IntToStr(i+1)+" = ����� ��:" + IntToStr(j+1);
                        Application->MessageBox((char*)err.c_str(), "������", MB_OK);
                        return;
                        }
                // mac
                if(mac==IpData.getOneMac(j)){
                        AnsiString err = "MAC ������ �����! ����� ��:"
                                        + IntToStr(i+1)+" = ����� ��:" + IntToStr(j+1);
                        Application->MessageBox((char*)err.c_str(), "������", MB_OK);
                        return;
                        }
                }
        }
// save MAC &IP to structure
IpData.saveDateSurd(&prj->surd);
// text
AnsiString com = Memo1->Text;
if (com.Length()>MaxTextLen_Ex)com.SetLength(MaxTextLen_Ex);
strcpy(prj->comments.comment,com.c_str());
prj->jornal.power_on =  CheckBox1->Checked;
prj->jornal.power_off = CheckBox2->Checked;
prj->jornal.faz =       CheckBox5->Checked;
prj->jornal.alarm =     CheckBox6->Checked;
prj->guard.gpsON =      chkGPS->Checked;  
prj->jornal.gmt = TrackBar1->Position;
try  {TempValue = StrToInt(edtTimeSt->Text.Trim());}
        catch(...){messageError(erTimeSURD);return;}
prj->surd.TimeDelay = TempValue;
try {TempValue = StrToInt(edtTimeCN->Text.Trim());}
        catch(...){messageError(erCuontSURD);return;}
prj->surd.Count = TempValue;
try {TempValue = StrToInt(medtPass->Text.Trim());}
        catch(...){messageError(erPassSURD);return;}
prj->surd.Pass = TempValue;
// �������� ����
FormMain->RefreshAllForms();
}
//----------------------------------------------------------------------------//
void __fastcall TFormProject::TrackBar1Change(TObject *Sender)
{
Panel2->Caption = IntToStr(TrackBar1->Position);
}
//----------------------------------------------------------------------------//
void __fastcall TFormProject::FormCreate(TObject *Sender)
{
StringGridDK->Cells[0][0] = "�� ID";
StringGridDK->Cells[1][0] = "IP �����";
StringGridDK->Cells[2][0] = "MAC �����";
StringGridDK->ColWidths[0] = 100;
StringGridDK->ColWidths[1] = 150;
StringGridDK->ColWidths[2] = 150;
}
//----------------------------------------------------------------------------//
void __fastcall TFormProject::ComboBoxDKChange(TObject *Sender)
{
tmpMAxDK = ComboBoxDK->ItemIndex+1;
BuildTableIP(tmpMAxDK);
}
//----------------------------------------------------------------------------//
// �������� IP ���� �� ����, ��������� �������    build a table
void TFormProject::BuildTableIP(const int RowCount)
{
// ������ �������
StringGridDK->RowCount = RowCount+1;
for (int i=0;i<RowCount;i++)
        {
        StringGridDK->Cells[0][i+1] = i+1;
        if(IpData.getOneIp(i)=="")
                        IpData.addOneIp("169.254.016.001");// �������� ip
        StringGridDK->Cells[1][i+1] = IpData.getOneIp(i).Trim();
        // MAC adress
        if(IpData.getOneMac(i)=="")
                        IpData.addOneMac("00:1A:B6:00:64:00");// �������� mac
        StringGridDK->Cells[2][i+1] = IpData.getOneMac(i).Trim();
        }
}
// 0000;1;_
// 000000;1;_
//----------------------------------------------------------------------------//

