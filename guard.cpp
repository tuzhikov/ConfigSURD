//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "guard.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TFormGuard *FormGuard;

//---------------------------------------------------------------------------
void TFormGuard::showGuard(void)
{
const int napr_i = CG_PAP.Directs.countDirectCCG;
// задаем таблицу флагов
FormGuard->StringGrid1->ColCount = napr_i+1;
FormGuard->StringGrid1->RowCount = napr_i+1;
//  задаем таблицу времен
FormGuard->StringGrid2->ColCount = napr_i+1;
FormGuard->StringGrid2->RowCount = napr_i+1;

// заполнение таблиц флагов и времен
for (int i=0; i<napr_i; i++)
        {
        FormGuard->StringGrid1->Cells[i+1][0] = IntToStr(i+1);
        FormGuard->StringGrid1->Cells[0][i+1] = IntToStr(i+1);
        //
        FormGuard->StringGrid2->Cells[i+1][0] = IntToStr(i+1);
        FormGuard->StringGrid2->Cells[0][i+1] = IntToStr(i+1);
        }
// матрица конфликтов
for (int x=0; x<napr_i; x++)
        for (int y=0; y<napr_i; y++)
                {
                int flag = CG_PAP.guard.ConfMatrixFlag[x][y];
                if (flag)
                        FormGuard->StringGrid2->Cells[y+1][x+1]
                                =IntToStr(CG_PAP.guard.ConfMatrix[x][y]);
                        else
                        FormGuard->StringGrid2->Cells[y+1][x+1] = "";
                }
// мин красный
FormGuard->edtMinRed->Text = IntToStr(CG_PAP.guard.red_min);
// мин. желтый
FormGuard->edtMinYellow->Text = IntToStr(CG_PAP.guard.yellow_min);
// мин. зеленый
FormGuard->edtMinGreen->Text = IntToStr(CG_PAP.guard.green_min);
// мин. КК
FormGuard->edtKK->Text = IntToStr(CG_PAP.guard.kk_len);
// time VPU
FormGuard->edtTimeStDelayVPU->Value = CG_PAP.guard.TimeVPU;
//заполнение
FormGuard->cbbFilling->ItemIndex = CG_PAP.guard.green_fill;
//пом такт
FormGuard->cbbTypeTP->ItemIndex = CG_PAP.guard.type_cycle;
FormGuard->edtDelayTP->Text = IntToStr(CG_PAP.guard.green_yellow);
//
FormGuard->Edit8->Text = IntToStr(CG_PAP.guard.restart_interval);
FormGuard->Edit9->Text = IntToStr(CG_PAP.guard.restarts);
FormGuard->Edit10->Text = IntToStr(CG_PAP.guard.time_clear);
}

//---------------------------------------------------------------------------
__fastcall TFormGuard::TFormGuard(TComponent* Owner)
        : TForm(Owner),cur_col(0),cur_row(0)
{
}
//---------------------------------------------------------------------------
void TFormGuard::showFormGuard(void)
{
memcpy(&CG_PAP, &PAP, sizeof(PAP));
showGuard();
FormGuard->Visible = true;
FormGuard->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::btnSaveClick(TObject *Sender)
{
int btn=mrNone;
if (FormMain->Check_Confl_In_Sh_Faze(&CG_PAP)){
        btn = MessageBox(0,"Ошибка проекта: матрица конфликтов не соответствует шаблонам фаз",
                  "Отменено!!!", MB_YESNO);
        if (btn==6){
                }
        if (btn==7){
                return;
                }
        }
// save parametrs
int i_conv;
// устанавливаем мин времена.
/*
if(TryStrToInt(edtMinRed->Text, i_conv))
        if(i_conv<=sizeof(CG_PAP.guard.red_min)*0xFF)CG_PAP.guard.red_min = i_conv; // время мин. красного
                else Application->MessageBox(
                AnsiString("параметр больше"+IntToStr(sizeof(CG_PAP.guard.red_min)*0xFF)).c_str(),
                "Ошибка", MB_OK);
                */
const __int64 MAX_GREEN = 2<<((sizeof(CG_PAP.guard.green_min)*8)-1);
if(TryStrToInt(edtMinGreen->Text, i_conv))
        if(i_conv<MAX_GREEN)
                CG_PAP.guard.yellow_min = CG_PAP.guard.red_min = CG_PAP.guard.green_min = i_conv; // время мин. зеленый
                else
                Application->MessageBox(
                        AnsiString("Параметр больше "+IntToStr(MAX_GREEN)).c_str(),
                        "Ошибка", MB_OK);
/*
if(TryStrToInt(edtMinYellow->Text, i_conv))
        if(i_conv<=sizeof(CG_PAP.guard.yellow_min)*0xFF)CG_PAP.guard.yellow_min = i_conv; // время мин. зеленый
                else Application->MessageBox(
                AnsiString("параметр больше"+IntToStr(sizeof(CG_PAP.guard.yellow_min)*0xFF)).c_str(),
                "Ошибка", MB_OK);
                */
const DWORD MAX_LENG_KK = 2<<((sizeof(CG_PAP.guard.kk_len)*8)-1);
if(TryStrToInt(edtKK->Text, i_conv))
        if(i_conv<MAX_LENG_KK)CG_PAP.guard.kk_len = i_conv;
                else Application->MessageBox(
                                AnsiString("Параметр больше "+IntToStr(MAX_LENG_KK)).c_str(),
                                "Ошибка", MB_OK);
// время включения ВПУ
CG_PAP.guard.TimeVPU =  edtTimeStDelayVPU->Value;
//
CG_PAP.guard.green_fill = cbbFilling->ItemIndex;// заполнение красный\зеленый
// для пром. тактов
CG_PAP.guard.type_cycle = cbbTypeTP->ItemIndex; // тип пром. такта
if(TryStrToInt(edtDelayTP->Text, i_conv))
        CG_PAP.guard.green_yellow = i_conv; // время про. такта
//защитные интервалы систтемы
if(TryStrToInt(Edit8->Text, i_conv))
        CG_PAP.guard.restart_interval = i_conv; // интервал перезапуска ДК
if(TryStrToInt(Edit9->Text, i_conv))
        CG_PAP.guard.restarts = i_conv;         // количество попыток перезапуска
if(TryStrToInt(Edit10->Text, i_conv))
        CG_PAP.guard.time_clear = i_conv;       // время очистки аварий
// tables directions guarding
int napr_i = CG_PAP.Directs.countDirectCCG;
for(int ix=0; ix< napr_i; ix++)
        {
        for (int iy=0; iy< napr_i; iy++)
                {
                if(ix!=iy)
                        if(CG_PAP.guard.ConfMatrixFlag[ix][iy])
                                if(TryStrToInt(StringGrid2->Cells[iy+1][ix+1],i_conv)){
                                        if (i_conv>255) i_conv=255;
                                        CG_PAP.guard.ConfMatrix[ix][iy] = i_conv;
                                        }
                }
        }
memcpy(&PAP.guard, &CG_PAP.guard, sizeof(TGUARD));
showGuard();
FormMain->RefreshAllForms();
FormMain->retVIS()->is_edit=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::btnCloseClick(TObject *Sender)
{
Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::StringGrid1SetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{

        //
        int i_conv;
        ////////
        if (ACol == ARow)
            return;
        //String s = Value;
        __try  { i_conv = StrToInt(Value);}
           __except(EXCEPTION_EXECUTE_HANDLER)    { i_conv = -1;}
        //
        if (i_conv>-1)
        {
          CG_PAP.guard.ConfMatrix[ARow-1][ACol-1] = i_conv;
          CG_PAP.guard.ConfMatrix[ACol-1][ARow-1] = i_conv;
          //
          showGuard();
        }


}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
        if ((ACol>0) && (ARow>0))
        {
            if (ACol==ARow)
            {
              StringGrid1->Canvas->Brush->Color=clGray;
              StringGrid1->Canvas->Rectangle(Rect);
            }
            else
            {
                if (CG_PAP.guard.ConfMatrixFlag[ARow-1][ACol-1])
                {
                StringGrid1->Canvas->Brush->Color=clRed;
                StringGrid1->Canvas->Rectangle(Rect);
                }
            }
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
if (ACol!=ARow){
        cur_col = ACol;
        cur_row = ARow;
        CG_PAP.guard.ConfMatrixFlag[ARow-1][ACol-1] =
                                !CG_PAP.guard.ConfMatrixFlag[ARow-1][ACol-1];
        }
showGuard();
StringGrid1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::StringGrid2DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
if ((ACol>0) && (ARow>0)){
        if (ACol==ARow){
                StringGrid2->Canvas->Brush->Color=clGray;
                StringGrid2->Canvas->Rectangle(Rect);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::StringGrid2KeyPress(TObject *Sender, char &Key)
{
if (cur_col!=cur_row)// хотел отработать клавишу <enret>
        if (CG_PAP.guard.ConfMatrixFlag[cur_row-1][cur_col-1]){
                if (!isdigit(Key))
                        if (Key!='\b')
                                Key=0;
                }
}
//---------------------------------------------------------------------------
void __fastcall TFormGuard::StringGrid2SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
if (ACol!=ARow)
        if (CG_PAP.guard.ConfMatrixFlag[ARow-1][ACol-1]){
                cur_col = ACol;
                cur_row = ARow;
                }else{
                CanSelect=false;
                }
}
//---------------------------------------------------------------------------

