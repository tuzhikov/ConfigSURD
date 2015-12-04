//---------------------------------------------------------------------------

#include <vcl.h>
#include <list.h>
#pragma hdrstop

#include "napr.h"
#include "Unit1.h"
#include "project.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDirection *frmDirection;
/*----------------------------------------------------------------------------*/
/*Конструктор формы*/
/*----------------------------------------------------------------------------*/
__fastcall TfrmDirection::TfrmDirection(TComponent* Owner)
        : TForm(Owner),
        strClorCCG(new TStringList()),
        strClorUDZCG(new TStringList()),
        strCCG(new TStringList()),
        strUDZCG(new TStringList()),
        curDirect(0)
{
// init list box color
strClorCCG->Add("К");
strClorCCG->Add("Ж");
strClorCCG->Add("З");
strClorUDZCG->Add("П");
strClorUDZCG->Add("Н");
strClorUDZCG->Add("Ф");
// init red
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[0]->cdPort = cbbGroupR1;
visDirectionRed[0]->cdCol = cbbCollorR1;
visDirectionRed[0]->cdDk = cbbDkR1;
visDirectionRed[0]->chkCtn = chkR1;
visDirectionRed[0]->round = shpR1;
visDirectionRed[0]->text = lblR1;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[1]->cdPort = cbbGroupR2;
visDirectionRed[1]->cdCol = cbbCollorR2;
visDirectionRed[1]->cdDk = cbbDkR2;
visDirectionRed[1]->chkCtn = chkR2;
visDirectionRed[1]->round = shpR2;
visDirectionRed[1]->text = lblR2;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[2]->cdPort = cbbGroupR3;
visDirectionRed[2]->cdCol = cbbCollorR3;
visDirectionRed[2]->cdDk = cbbDkR3;
visDirectionRed[2]->chkCtn = chkR3;
visDirectionRed[2]->round = shpR3;
visDirectionRed[2]->text = lblR3;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[3]->cdPort = cbbGroupR4;
visDirectionRed[3]->cdCol = cbbCollorR4;
visDirectionRed[3]->cdDk = cbbDkR4;
visDirectionRed[3]->chkCtn = chkR4;
visDirectionRed[3]->round = shpR4;
visDirectionRed[3]->text = lblR4;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[4]->cdPort = cbbGroupR5;
visDirectionRed[4]->cdCol = cbbCollorR5;
visDirectionRed[4]->cdDk = cbbDkR5;
visDirectionRed[4]->chkCtn = chkR5;
visDirectionRed[4]->round = shpR5;
visDirectionRed[4]->text = lblR5;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[5]->cdPort = cbbGroupR6;
visDirectionRed[5]->cdCol = cbbCollorR6;
visDirectionRed[5]->cdDk = cbbDkR6;
visDirectionRed[5]->chkCtn = chkR6;
visDirectionRed[5]->round = shpR6;
visDirectionRed[5]->text = lblR6;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[6]->cdPort = cbbGroupR7;
visDirectionRed[6]->cdCol = cbbCollorR7;
visDirectionRed[6]->cdDk = cbbDkR7;
visDirectionRed[6]->chkCtn = chkR7;
visDirectionRed[6]->round = shpR7;
visDirectionRed[6]->text = lblR7;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[7]->cdPort = cbbGroupR8;
visDirectionRed[7]->cdCol = cbbCollorR8;
visDirectionRed[7]->cdDk = cbbDkR8;
visDirectionRed[7]->chkCtn = chkR8;
visDirectionRed[7]->round = shpR8;
visDirectionRed[7]->text = lblR8;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[8]->cdPort = cbbGroupR12;
visDirectionRed[8]->cdCol = cbbCollorR12;
visDirectionRed[8]->cdDk = cbbDkR12;
visDirectionRed[8]->chkCtn = chkR12;
visDirectionRed[8]->round = shpR9;
visDirectionRed[8]->text = lblR9;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[9]->cdPort = cbbGroupR22;
visDirectionRed[9]->cdCol = cbbCollorR22;
visDirectionRed[9]->cdDk = cbbDkR22;
visDirectionRed[9]->chkCtn = chkR22;
visDirectionRed[9]->round = shpR10;
visDirectionRed[9]->text = lblR10;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[10]->cdPort = cbbGroupR32;
visDirectionRed[10]->cdCol = cbbCollorR32;
visDirectionRed[10]->cdDk = cbbDkR32;
visDirectionRed[10]->chkCtn = chkR32;
visDirectionRed[10]->round = shpR11;
visDirectionRed[10]->text = lblR11;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[11]->cdPort = cbbGroupR42;
visDirectionRed[11]->cdCol = cbbCollorR42;
visDirectionRed[11]->cdDk = cbbDkR42;
visDirectionRed[11]->chkCtn = chkR42;
visDirectionRed[11]->round = shpR12;
visDirectionRed[11]->text = lblR12;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[12]->cdPort = cbbGroupR52;
visDirectionRed[12]->cdCol = cbbCollorR52;
visDirectionRed[12]->cdDk = cbbDkR52;
visDirectionRed[12]->chkCtn = chkR52;
visDirectionRed[12]->round = shpR13;
visDirectionRed[12]->text = lblR13;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[13]->cdPort = cbbGroupR62;
visDirectionRed[13]->cdCol = cbbCollorR62;
visDirectionRed[13]->cdDk = cbbDkR62;
visDirectionRed[13]->chkCtn = chkR62;
visDirectionRed[13]->round = shpR14;
visDirectionRed[13]->text = lblR14;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[14]->cdPort = cbbGroupR72;
visDirectionRed[14]->cdCol = cbbCollorR72;
visDirectionRed[14]->cdDk = cbbDkR72;
visDirectionRed[14]->chkCtn = chkR72;
visDirectionRed[14]->round = shpR15;
visDirectionRed[14]->text = lblR15;
visDirectionRed.push_back(new TVisualDirection());
visDirectionRed[15]->cdPort = cbbGroupR82;
visDirectionRed[15]->cdCol = cbbCollorR82;
visDirectionRed[15]->cdDk = cbbDkR82;
visDirectionRed[15]->chkCtn = chkR82;
visDirectionRed[15]->round = shpR16;
visDirectionRed[15]->text = lblR16;
// init yellow
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[0]->cdPort = cbbGroupY11;
visDirectionYellow[0]->cdCol = cbbCollorY11;
visDirectionYellow[0]->cdDk = cbbDkY11;
visDirectionYellow[0]->chkCtn = chkY11;
visDirectionYellow[0]->round = shpY1;
visDirectionYellow[0]->text = lblY1;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[1]->cdPort = cbbGroupY21;
visDirectionYellow[1]->cdCol = cbbCollorY21;
visDirectionYellow[1]->cdDk = cbbDkY21;
visDirectionYellow[1]->chkCtn = chkY21;
visDirectionYellow[1]->round = shpY2;
visDirectionYellow[1]->text = lblY2;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[2]->cdPort = cbbGroupY31;
visDirectionYellow[2]->cdCol = cbbCollorY31;
visDirectionYellow[2]->cdDk = cbbDkY31;
visDirectionYellow[2]->chkCtn = chkY31;
visDirectionYellow[2]->round = shpY3;
visDirectionYellow[2]->text = lblY3;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[3]->cdPort = cbbGroupY41;
visDirectionYellow[3]->cdCol = cbbCollorY41;
visDirectionYellow[3]->cdDk = cbbDkY41;
visDirectionYellow[3]->chkCtn = chkY41;
visDirectionYellow[3]->round = shpY4;
visDirectionYellow[3]->text = lblY4;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[4]->cdPort = cbbGroupY51;
visDirectionYellow[4]->cdCol = cbbCollorY51;
visDirectionYellow[4]->cdDk = cbbDkY51;
visDirectionYellow[4]->chkCtn = chkY51;
visDirectionYellow[4]->round = shpY5;
visDirectionYellow[4]->text = lblY5;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[5]->cdPort = cbbGroupY61;
visDirectionYellow[5]->cdCol = cbbCollorY61;
visDirectionYellow[5]->cdDk = cbbDkY61;
visDirectionYellow[5]->chkCtn = chkY61;
visDirectionYellow[5]->round = shpY6;
visDirectionYellow[5]->text = lblY6;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[6]->cdPort = cbbGroupY71;
visDirectionYellow[6]->cdCol = cbbCollorY71;
visDirectionYellow[6]->cdDk = cbbDkY71;
visDirectionYellow[6]->chkCtn = chkY71;
visDirectionYellow[6]->round = shpY7;
visDirectionYellow[6]->text = lblY7;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[7]->cdPort = cbbGroupY81;
visDirectionYellow[7]->cdCol = cbbCollorY81;
visDirectionYellow[7]->cdDk = cbbDkY81;
visDirectionYellow[7]->chkCtn = chkY81;
visDirectionYellow[7]->round = shpY8;
visDirectionYellow[7]->text = lblY8;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[8]->cdPort = cbbGroupY12;
visDirectionYellow[8]->cdCol = cbbCollorY12;
visDirectionYellow[8]->cdDk = cbbDkY12;
visDirectionYellow[8]->chkCtn = chkY12;
visDirectionYellow[8]->round = shpY9;
visDirectionYellow[8]->text = lblY9;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[9]->cdPort = cbbGroupY22;
visDirectionYellow[9]->cdCol = cbbCollorY22;
visDirectionYellow[9]->cdDk = cbbDkY22;
visDirectionYellow[9]->chkCtn = chkY22;
visDirectionYellow[9]->round = shpY10;
visDirectionYellow[9]->text = lblY10;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[10]->cdPort = cbbGroupY32;
visDirectionYellow[10]->cdCol = cbbCollorY32;
visDirectionYellow[10]->cdDk = cbbDkY32;
visDirectionYellow[10]->chkCtn = chkY32;
visDirectionYellow[10]->round = shpY11;
visDirectionYellow[10]->text = lblY11;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[11]->cdPort = cbbGroupY42;
visDirectionYellow[11]->cdCol = cbbCollorY42;
visDirectionYellow[11]->cdDk = cbbDkY42;
visDirectionYellow[11]->chkCtn = chkY42;
visDirectionYellow[11]->round = shpY12;
visDirectionYellow[11]->text = lblY12;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[12]->cdPort = cbbGroupY52;
visDirectionYellow[12]->cdCol = cbbCollorY52;
visDirectionYellow[12]->cdDk = cbbDkY52;
visDirectionYellow[12]->chkCtn = chkY52;
visDirectionYellow[12]->round = shpY13;
visDirectionYellow[12]->text = lblY13;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[13]->cdPort = cbbGroupY62;
visDirectionYellow[13]->cdCol = cbbCollorY62;
visDirectionYellow[13]->cdDk = cbbDkY62;
visDirectionYellow[13]->chkCtn = chkY62;
visDirectionYellow[13]->round = shpY14;
visDirectionYellow[13]->text = lblY14;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[14]->cdPort = cbbGroupY72;
visDirectionYellow[14]->cdCol = cbbCollorY72;
visDirectionYellow[14]->cdDk = cbbDkY72;
visDirectionYellow[14]->chkCtn = chkY72;
visDirectionYellow[14]->round = shpY15;
visDirectionYellow[14]->text = lblY15;
visDirectionYellow.push_back(new TVisualDirection());
visDirectionYellow[15]->cdPort = cbbGroupY82;
visDirectionYellow[15]->cdCol = cbbCollorY82;
visDirectionYellow[15]->cdDk = cbbDkY82;
visDirectionYellow[15]->chkCtn = chkY82;
visDirectionYellow[15]->round = shpY16;
visDirectionYellow[15]->text = lblY16;
// init green
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[0]->cdPort = cbbGroupG11;
visDirectionGreen[0]->cdCol = cbbCollorG11;
visDirectionGreen[0]->cdDk = cbbDkG11;
visDirectionGreen[0]->chkCtn = chkG11;
visDirectionGreen[0]->round = shpG1;
visDirectionGreen[0]->text = lblG1;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[1]->cdPort = cbbGroupG21;
visDirectionGreen[1]->cdCol = cbbCollorG21;
visDirectionGreen[1]->cdDk = cbbDkG21;
visDirectionGreen[1]->chkCtn = chkG21;
visDirectionGreen[1]->round = shpG2;
visDirectionGreen[1]->text = lblG2;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[2]->cdPort = cbbGroupG31;
visDirectionGreen[2]->cdCol = cbbCollorG31;
visDirectionGreen[2]->cdDk = cbbDkG31;
visDirectionGreen[2]->chkCtn = chkG31;
visDirectionGreen[2]->round = shpG3;
visDirectionGreen[2]->text = lblG3;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[3]->cdPort = cbbGroupG41;
visDirectionGreen[3]->cdCol = cbbCollorG41;
visDirectionGreen[3]->cdDk = cbbDkG41;
visDirectionGreen[3]->chkCtn = chkG41;
visDirectionGreen[3]->round = shpG4;
visDirectionGreen[3]->text = lblG4;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[4]->cdPort = cbbGroupG51;
visDirectionGreen[4]->cdCol = cbbCollorG51;
visDirectionGreen[4]->cdDk = cbbDkG51;
visDirectionGreen[4]->chkCtn = chkG51;
visDirectionGreen[4]->round = shpG5;
visDirectionGreen[4]->text = lblG5;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[5]->cdPort = cbbGroupG61;
visDirectionGreen[5]->cdCol = cbbCollorG61;
visDirectionGreen[5]->cdDk = cbbDkG61;
visDirectionGreen[5]->chkCtn = chkG61;
visDirectionGreen[5]->round = shpG6;
visDirectionGreen[5]->text = lblG6;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[6]->cdPort = cbbGroupG71;
visDirectionGreen[6]->cdCol = cbbCollorG71;
visDirectionGreen[6]->cdDk = cbbDkG71;
visDirectionGreen[6]->chkCtn = chkG71;
visDirectionGreen[6]->round = shpG7;
visDirectionGreen[6]->text = lblG7;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[7]->cdPort = cbbGroupG81;
visDirectionGreen[7]->cdCol = cbbCollorG81;
visDirectionGreen[7]->cdDk = cbbDkG81;
visDirectionGreen[7]->chkCtn = chkG81;
visDirectionGreen[7]->round = shpG8;
visDirectionGreen[7]->text = lblG8;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[8]->cdPort = cbbGroupG12;
visDirectionGreen[8]->cdCol = cbbCollorG12;
visDirectionGreen[8]->cdDk = cbbDkG12;
visDirectionGreen[8]->chkCtn = chkG12;
visDirectionGreen[8]->round = shpG9;
visDirectionGreen[8]->text = lblG9;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[9]->cdPort = cbbGroupG22;
visDirectionGreen[9]->cdCol = cbbCollorG22;
visDirectionGreen[9]->cdDk = cbbDkG22;
visDirectionGreen[9]->chkCtn = chkG22;
visDirectionGreen[9]->round = shpG10;
visDirectionGreen[9]->text = lblG10;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[10]->cdPort = cbbGroupG32;
visDirectionGreen[10]->cdCol = cbbCollorG32;
visDirectionGreen[10]->cdDk = cbbDkG32;
visDirectionGreen[10]->chkCtn = chkG32;
visDirectionGreen[10]->round = shpG11;
visDirectionGreen[10]->text = lblG11;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[11]->cdPort = cbbGroupG42;
visDirectionGreen[11]->cdCol = cbbCollorG42;
visDirectionGreen[11]->cdDk = cbbDkG42;
visDirectionGreen[11]->chkCtn = chkG42;
visDirectionGreen[11]->round = shpG12;
visDirectionGreen[11]->text = lblG12;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[12]->cdPort = cbbGroupG52;
visDirectionGreen[12]->cdCol = cbbCollorG52;
visDirectionGreen[12]->cdDk = cbbDkG52;
visDirectionGreen[12]->chkCtn = chkG52;
visDirectionGreen[12]->round = shpG13;
visDirectionGreen[12]->text = lblG13;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[13]->cdPort = cbbGroupG62;
visDirectionGreen[13]->cdCol = cbbCollorG62;
visDirectionGreen[13]->cdDk = cbbDkG62;
visDirectionGreen[13]->chkCtn = chkG62;
visDirectionGreen[13]->round = shpG14;
visDirectionGreen[13]->text = lblG14;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[14]->cdPort = cbbGroupG72;
visDirectionGreen[14]->cdCol = cbbCollorG72;
visDirectionGreen[14]->cdDk = cbbDkG72;
visDirectionGreen[14]->chkCtn = chkG72;
visDirectionGreen[14]->round = shpG15;
visDirectionGreen[14]->text = lblG15;
visDirectionGreen.push_back(new TVisualDirection());
visDirectionGreen[15]->cdPort = cbbGroupG82;
visDirectionGreen[15]->cdCol = cbbCollorG82;
visDirectionGreen[15]->cdDk = cbbDkG82;
visDirectionGreen[15]->chkCtn = chkG82;
visDirectionGreen[15]->round = shpG16;
visDirectionGreen[15]->text = lblG16;
// задаем события для компанентов
for (int i=0;i<visDirectionRed.size();i++)
        {
        //red
        // clear
        visDirectionRed[i]->cdPort->ItemIndex = 0;
        visDirectionRed[i]->cdCol->ItemIndex = 0;
        visDirectionRed[i]->cdDk->ItemIndex = 0;
        visDirectionRed[i]->chkCtn->Checked = false;
        visDirectionRed[i]->chkCtn->Visible = false;
        // events
        visDirectionRed[i]->cdPort->OnChange = cbbChangePORT;
        visDirectionRed[i]->cdCol->OnChange = cbbChangeCOLOR;
        visDirectionRed[i]->cdDk->OnChange = cbbChangeDK;
        visDirectionRed[i]->chkCtn->OnClick = cbClickCONTR;
        //setup tag
        visDirectionRed[i]->cdPort->Tag = i;
        visDirectionRed[i]->cdCol->Tag=i;
        visDirectionRed[i]->cdDk->Tag=i;
        visDirectionRed[i]->chkCtn->Tag=i;
        //yellow
        // clear
        visDirectionYellow[i]->cdPort->ItemIndex = 0;
        visDirectionYellow[i]->cdCol->ItemIndex = 0;
        visDirectionYellow[i]->cdDk->ItemIndex = 0;
        visDirectionYellow[i]->chkCtn->Checked = false;
        visDirectionYellow[i]->chkCtn->Visible = false;
        // events
        visDirectionYellow[i]->cdPort->OnChange = cbbChangePORT;
        visDirectionYellow[i]->cdCol->OnChange = cbbChangeCOLOR;
        visDirectionYellow[i]->cdDk->OnChange = cbbChangeDK;
        visDirectionYellow[i]->chkCtn->OnClick = cbClickCONTR;
        //setup tag
        visDirectionYellow[i]->cdPort->Tag = i+YEL_IN;
        visDirectionYellow[i]->cdCol->Tag=i+YEL_IN;
        visDirectionYellow[i]->cdDk->Tag=i+YEL_IN;
        visDirectionYellow[i]->chkCtn->Tag=i+YEL_IN;
        //green
        // clear
        visDirectionGreen[i]->cdPort->ItemIndex = 0;
        visDirectionGreen[i]->cdCol->ItemIndex = 0;
        visDirectionGreen[i]->cdDk->ItemIndex = 0;
        visDirectionGreen[i]->chkCtn->Checked = false;
        visDirectionGreen[i]->chkCtn->Visible = false;
        // events
        visDirectionGreen[i]->cdPort->OnChange = cbbChangePORT;
        visDirectionGreen[i]->cdCol->OnChange = cbbChangeCOLOR;
        visDirectionGreen[i]->cdDk->OnChange = cbbChangeDK;
        visDirectionGreen[i]->chkCtn->OnClick = cbClickCONTR;
        //setup tag
        visDirectionGreen[i]->cdPort->Tag = i+GREN_IN;
        visDirectionGreen[i]->cdCol->Tag=i+GREN_IN;
        visDirectionGreen[i]->cdDk->Tag=i+GREN_IN;
        visDirectionGreen[i]->chkCtn->Tag=i+GREN_IN;
        }
}
/*----------------------------------------------------------------------------*/
void __fastcall TfrmDirection::FormCreate(TObject *Sender)
{
StatusBar("Направление.");
showNumPort(MaxMULBlocks);
showTypeDir(false);                       
frmDirection->lstPanelPlus->Clear() ;
for (int i=0; i< ExData::DIR_COUNT; i++)
        frmDirection->lstPanelPlus->Items->Add(DiagramPainter::Get_TXT_Napr_Type(i,0));
}
/*----------------------------------------------------------------------------*/
// сохранить в временную структуру проекта
/*----------------------------------------------------------------------------*/
void TfrmDirection::addListDirection(void)
{
vector<TONEDIRECT> tmpDirCCG;
vector<TONEDIRECT> tmpDirUDZCG;

//задать начальные значения
for(int i=0;i<MAX_DK;i++)
        {
        tempOneDirection.out.red[i].color=MUL_RED;
        tempOneDirection.out.yel[i].color=MUL_YELLOW;
        tempOneDirection.out.green[i].color=MUL_GREEN;
        }
//новое направление UDZCG сохраняем вконце списка
if(tempOneDirection.Type!=DIR_CCG){// новое направление УДЗСГ
  memcpy(&tempPrg.Directs.OneDirect[tempPrg.AmountDirects-1],&tempOneDirection,
                sizeof(tempOneDirection));
  }
//новое направление СCG сохраняем до направлений UDZCG
if(tempOneDirection.Type==DIR_CCG){
  // разбиваем по направлениям
  for(int i=0;i<tempPrg.AmountDirects-1;i++)// без нового направления
        {
        if(tempPrg.Directs.OneDirect[i].Type==DIR_CCG){
                tmpDirCCG.push_back(tempPrg.Directs.OneDirect[i]);
                }
        if(tempPrg.Directs.OneDirect[i].Type!=DIR_CCG){
                tmpDirUDZCG.push_back(tempPrg.Directs.OneDirect[i]);
                }
        }
  // сохраняем новое направление
  tmpDirCCG.push_back(tempOneDirection);
  const WORD lengCCG = tmpDirCCG.size();
  tempPrg.Directs.countDirectCCG = 0;
  // save direction CCG
  for(int i=0;i<lengCCG;i++)
        {
        memcpy(&tempPrg.Directs.OneDirect[i],&tmpDirCCG[i],sizeof(tempOneDirection));
        tempPrg.Directs.countDirectCCG++;
        }
  // save direction UDZCG
  const WORD lengUDZCG = tmpDirUDZCG.size();
  for(int i=0;i<lengUDZCG;i++)
        {
        memcpy(&tempPrg.Directs.OneDirect[lengCCG+i],&tmpDirUDZCG[i],sizeof(tempOneDirection));
        }
  }
}
/*----------------------------------------------------------------------------*/
// показать направления в List
/*----------------------------------------------------------------------------*/
// собрать лист напралений
void TfrmDirection::setListDirection(void)
{
int currentDir = tempPrg.AmountDirects, countCCG=1,countUDZCG=1;
strCCG->Clear();
strUDZCG->Clear();
tempPrg.Directs.countDirectCCG = 0;
for (int i=0; i<currentDir; i++)
        {
        if(tempPrg.Directs.OneDirect[i].Type!=DIR_CCG){
          strUDZCG->Add(IntToStr(countUDZCG++) + ". " +
             DiagramPainter::Get_Full_TXT_Napr(&tempPrg, i));
          }
        if(tempPrg.Directs.OneDirect[i].Type==DIR_CCG){
          strCCG->Add(IntToStr(countCCG++) + ". " +
             DiagramPainter::Get_Full_TXT_Napr(&tempPrg, i));
          tempPrg.Directs.countDirectCCG++; //количество направлений CCG
          }
        }
}
/*----------------------------------------------------------------------------*/
// отобразить лист напралений
void TfrmDirection::showListDirection(void)
{
setListDirection();
frmDirection->lstOut->Clear();
frmDirection->lstOut->Items->AddStrings(strCCG);
frmDirection->lstOut->Items->AddStrings(strUDZCG);
frmDirection->lstOut->ItemIndex = curDirect;
// выбрать экран направления перезапись данных в отображении направления
DIR_TYPE tempTypDir = tempPrg.Directs.OneDirect[curDirect].Type;
if(tempTypDir==DIR_CCG){
        showTypeDir(false);
        }
if(tempTypDir==DIR_UDZCG){
        showTypeDir(true);
        }
// показать данные выбранного направлении
showParametrOneDirectoin(curDirect);
}
/*----------------------------------------------------------------------------*/
// очистить данные при изменении ДК
void TfrmDirection::clearDataofChange(TPROJECT *prg)
{
for(int i=0;i<prg->AmountDirects;i++)
        {
        for(int j=0;j<MAX_DK;j++)
                {
                //red
                prg->Directs.OneDirect[i].out.red[j].NumberDk=0;
                prg->Directs.OneDirect[i].out.red[j].control =0;
                prg->Directs.OneDirect[i].out.red[j].group   =0;
                prg->Directs.OneDirect[i].out.red[j].color   =MUL_RED;
                //yellow
                prg->Directs.OneDirect[i].out.yel[j].NumberDk=0;
                prg->Directs.OneDirect[i].out.yel[j].control =0;
                prg->Directs.OneDirect[i].out.yel[j].group   =0;
                prg->Directs.OneDirect[i].out.yel[j].color   =MUL_YELLOW;
                //green
                prg->Directs.OneDirect[i].out.green[j].NumberDk=0;
                prg->Directs.OneDirect[i].out.green[j].control =0;
                prg->Directs.OneDirect[i].out.green[j].group   =0;
                prg->Directs.OneDirect[i].out.green[j].color   =MUL_GREEN;
                }
        }
}
/*----------------------------------------------------------------------------*/
// показать окно с главной формы
void TfrmDirection::ShowMainFormDirection(TPROJECT *prg)
{
if(FormProject->retChangeData())clearDataofChange(prg);
memcpy(&tempPrg, prg, sizeof(tempPrg));
frmDirection->Visible = true;
showNumDk(prg->maxDK); // задать количество ДК
showListDirection();   // показать список направлений
BringToFront();
}
/*----------------------------------------------------------------------------*/
// вывести сообщение в StatusBar
void TfrmDirection::StatusBar(AnsiString txt)
{
frmDirection->StatusBar1->SimpleText=txt;
}
/*----------------------------------------------------------------------------*/
// Установить мак. ДК в проекте
// maxNumber - максимальное число ДК в  проете
void TfrmDirection::showNumDk(const int maxNumber)
{
for(int i=0;i<visDirectionRed.size();i++)
        {
        visDirectionRed[i]->cdDk->Items->Clear();
        visDirectionYellow[i]->cdDk->Items->Clear();
        visDirectionGreen[i]->cdDk->Items->Clear();
        for(int n=0;n<maxNumber;n++)
                {
                visDirectionRed[i]->cdDk->Items->Add(IntToStr(n+1));
                visDirectionYellow[i]->cdDk->Items->Add(IntToStr(n+1));
                visDirectionGreen[i]->cdDk->Items->Add(IntToStr(n+1));
                }
        visDirectionRed[i]->cdDk->ItemIndex=0;
        visDirectionYellow[i]->cdDk->ItemIndex=0;
        visDirectionGreen[i]->cdDk->ItemIndex=0;
        }
}
/*----------------------------------------------------------------------------*/
/* ComboBox задат тип для выбранного направления*/
void TfrmDirection::showTypeDir(const bool type)
{
for(int i=0;i<visDirectionRed.size();i++)
        {
        visDirectionRed[i]->cdCol->Items->Clear();
        visDirectionYellow[i]->cdCol->Items->Clear();
        visDirectionGreen[i]->cdCol->Items->Clear();
        if(type){
                visDirectionRed[i]->cdCol->Items->AddStrings(strClorUDZCG);
                visDirectionRed[i]->round->Visible = false;
                visDirectionRed[i]->text->Visible = true;
                visDirectionYellow[i]->cdCol->Items->AddStrings(strClorUDZCG);
                visDirectionYellow[i]->round->Visible = false;
                visDirectionYellow[i]->text->Visible = true;
                visDirectionGreen[i]->cdCol->Items->AddStrings(strClorUDZCG);
                visDirectionGreen[i]->round->Visible = false;
                visDirectionGreen[i]->text->Visible = true;
                // checrk alarm
                visDirectionRed[i]->chkCtn->Visible = false;
                visDirectionGreen[i]->chkCtn->Visible = false;
                }else{
                visDirectionRed[i]->cdCol->Items->AddStrings(strClorCCG);
                visDirectionRed[i]->round->Visible = true;
                visDirectionRed[i]->text->Visible = false;
                visDirectionYellow[i]->cdCol->Items->AddStrings(strClorCCG);
                visDirectionYellow[i]->round->Visible = true;
                visDirectionYellow[i]->text->Visible = false;
                visDirectionGreen[i]->cdCol->Items->AddStrings(strClorCCG);
                visDirectionGreen[i]->round->Visible = true;
                visDirectionGreen[i]->text->Visible = false;
                // check alarm
                visDirectionRed[i]->chkCtn->Visible = true;
                visDirectionGreen[i]->chkCtn->Visible = true;
                }
        visDirectionRed[i]->cdCol->ItemIndex=0;
        visDirectionYellow[i]->cdCol->ItemIndex=0;
        visDirectionGreen[i]->cdCol->ItemIndex=0;
        }
}
/*----------------------------------------------------------------------------*/
/*задать количество выходов в combobox*/
void TfrmDirection::showNumPort(const int maxNumBlock)
{
for(int i=0;i<visDirectionRed.size();i++)
        {
        visDirectionRed[i]->cdPort->Items->Clear();
        visDirectionRed[i]->cdPort->Items->Add("НЕТ");
        visDirectionRed[i]->cdPort->ItemIndex = 0;
        visDirectionYellow[i]->cdPort->Items->Clear();
        visDirectionYellow[i]->cdPort->Items->Add("НЕТ");
        visDirectionYellow[i]->cdPort->ItemIndex = 0;
        visDirectionGreen[i]->cdPort->Items->Clear();
        visDirectionGreen[i]->cdPort->Items->Add("НЕТ");
        visDirectionGreen[i]->cdPort->ItemIndex = 0;
        for(int n=0;n<maxNumBlock;n++)
                {
                visDirectionRed[i]->cdPort->Items->Add(IntToStr(n+1));
                visDirectionYellow[i]->cdPort->Items->Add(IntToStr(n+1));
                visDirectionGreen[i]->cdPort->Items->Add(IntToStr(n+1));
                }
        }
}
/*----------------------------------------------------------------------------*/
/*Кнопка Добавить наравление в проекта*/
void __fastcall TfrmDirection::btnPlusClick(TObject *Sender)
{
frmDirection->pnlPlus->Visible = true;
frmDirection->lstPanelPlus->ItemIndex=0;
}
/* Кнопка Удалить направление из проекта*/
void __fastcall TfrmDirection::BitBtn2Click(TObject *Sender)
{
if (tempPrg.AmountDirects>1){
        tempPrg.AmountDirects--;
        }
showListDirection();
}
/*----------------------------------------------------------------------------*/
// Добавить направление в проект "тип направления"
void __fastcall TfrmDirection::Panel5Click(TObject *Sender)
{
if (tempPrg.AmountDirects++<MaxDirects){
        tempOneDirection.Type = frmDirection->lstPanelPlus->ItemIndex;
        addListDirection();
        }
showListDirection();
frmDirection->pnlPlus->Visible = false;
}
/*----------------------------------------------------------------------------*/
/* Отмена скрываем окно тип направления*/
void __fastcall TfrmDirection::Panel6Click(TObject *Sender)
{
frmDirection->pnlPlus->Visible = false;
}
/*----------------------------------------------------------------------------*/
/* выбор направления из lstOut*/
void __fastcall TfrmDirection::lstOutClick(TObject *Sender)
{
curDirect = frmDirection->lstOut->ItemIndex; // выбрали направление
showListDirection();
}
/*----------------------------------------------------------------------------*/
/*закрыть окно основное*/
void __fastcall TfrmDirection::btnCloseClick(TObject *Sender)
{
frmDirection->Visible = false;
}
/*----------------------------------------------------------------------------*/
/*сохранить данные направлений в основной проект*/
void __fastcall TfrmDirection::btnOkClick(TObject *Sender)
{
memcpy(&PAP.Directs, &tempPrg.Directs, sizeof(PAP.Directs));
PAP.AmountDirects = tempPrg.AmountDirects;
FormMain->retDPA()->Paint();// рисуем ленту времени
FormMain->retVIS()->is_edit=true;
}
/*----------------------------------------------------------------------------*/
 // обработчик для comboBox Port общий
void __fastcall TfrmDirection::cbbChangePORT(TObject *Sender)
{
TComboBox *cmb=dynamic_cast<TComboBox*>(Sender);
if(cmb){
        if(checkSructParametrGroup(cmb)){
                setParametrOneDirectoin(curDirect);  // новые данные
                }else{
                showParametrOneDirectoin(curDirect); // восстанавливаем старые данные
                }
        }else{
        StatusBar("не мое событие <cbbChangePORT>");
        }
}
/*----------------------------------------------------------------------------*/
 // обработчик для comboBox COLOR общий
void __fastcall TfrmDirection::cbbChangeCOLOR(TObject *Sender)
{
TComboBox *cmb=dynamic_cast<TComboBox*>(Sender);
if(cmb){
        if(checkSructParametrColor(cmb)){
                setParametrOneDirectoin(curDirect);  // новые данные
                }else{
                showParametrOneDirectoin(curDirect);  // восстанавливаем старые данные
                }
        }else{
        StatusBar("не мое событие <cbbChangeCOLOR>");
        }
}
/*----------------------------------------------------------------------------*/
 // обработчик для comboBox DK общий
void __fastcall TfrmDirection::cbbChangeDK(TObject *Sender)
{
TComboBox *cmb=dynamic_cast<TComboBox*>(Sender);
if(cmb){
        if(checkSructParametrDK(cmb)){
                setParametrOneDirectoin(curDirect);  // новые данные
                }else{
                showParametrOneDirectoin(curDirect); // восстанавливаем старые данные
                }
        }else{
        StatusBar("не мое событие <cbbChangeDK>");
        }
}
/*----------------------------------------------------------------------------*/
 // обработчик для checkbox CONTROL общий
void __fastcall TfrmDirection::cbClickCONTR(TObject *Sender)
{
TCheckBox*chb=dynamic_cast<TCheckBox*>(Sender);
if(chb){
        setParametrOneDirectoin(curDirect);
        }else{
        StatusBar("не мое событие <cbbChangeDK>");
        }
}
/*----------------------------------------------------------------------------*/
void __fastcall TfrmDirection::FormDestroy(TObject *Sender)
{
delete strCCG;
delete strUDZCG;
delete strClorCCG;
delete strClorUDZCG;
if(!visDirectionRed.empty()){
  for(int i=0;i<visDirectionRed.size();i++)
        {
        delete visDirectionRed[i];
        }
  }
if(!visDirectionYellow.empty()){
  for(int i=0;i<visDirectionYellow.size();i++)
        {
        delete visDirectionYellow[i];
        }
  }
if(!visDirectionGreen.empty()){
  for(int i=0;i<visDirectionGreen.size();i++)
        {
        delete visDirectionGreen[i];
        }
  }
visDirectionRed.clear();
visDirectionYellow.clear();
visDirectionGreen.clear();
}
/*----------------------------------------------------------------------------*/
// сохранить установленные параметры текущего направления в структуру временную
bool TfrmDirection::setParametrOneDirectoin(const int currentDirection)
{
if(currentDirection>tempPrg.AmountDirects)return false; // нет в проекте такого направления


// сохраняем текущее направление в временную структуру
// red
const int maxDkR = visDirectionRed.size();
for(int i=0;i<maxDkR;i++)
        {
        int indexDk=visDirectionRed[i]->cdDk->ItemIndex;
        int indexPort = visDirectionRed[i]->cdPort->ItemIndex;
        int indexColor = visDirectionRed[i]->cdCol->ItemIndex;
        bool chStat = visDirectionRed[i]->chkCtn->Checked;
        tempPrg.Directs.OneDirect[currentDirection].out.red[i].NumberDk = indexDk;
        tempPrg.Directs.OneDirect[currentDirection].out.red[i].control = chStat;
        tempPrg.Directs.OneDirect[currentDirection].out.red[i].group = indexPort;
        tempPrg.Directs.OneDirect[currentDirection].out.red[i].color = indexColor;
        }
// yellow
const int maxDkY = visDirectionYellow.size();
for(int i=0;i<maxDkY;i++)
        {
        int indexDk=visDirectionYellow[i]->cdDk->ItemIndex;
        int indexPort = visDirectionYellow[i]->cdPort->ItemIndex;
        int indexColor = visDirectionYellow[i]->cdCol->ItemIndex;
        bool chStat = visDirectionYellow[i]->chkCtn->Checked;
        tempPrg.Directs.OneDirect[currentDirection].out.yel[i].NumberDk = indexDk;
        tempPrg.Directs.OneDirect[currentDirection].out.yel[i].control = chStat;
        tempPrg.Directs.OneDirect[currentDirection].out.yel[i].group = indexPort;
        tempPrg.Directs.OneDirect[currentDirection].out.yel[i].color = indexColor;
        }
//grren
const int maxDkG = visDirectionGreen.size();
for(int i=0;i<maxDkG;i++)
        {
        int indexDk=visDirectionGreen[i]->cdDk->ItemIndex;
        int indexPort = visDirectionGreen[i]->cdPort->ItemIndex;
        int indexColor = visDirectionGreen[i]->cdCol->ItemIndex;
        bool chStat = visDirectionGreen[i]->chkCtn->Checked;
        tempPrg.Directs.OneDirect[currentDirection].out.green[i].NumberDk = indexDk;
        tempPrg.Directs.OneDirect[currentDirection].out.green[i].control = chStat;
        tempPrg.Directs.OneDirect[currentDirection].out.green[i].group = indexPort;
        tempPrg.Directs.OneDirect[currentDirection].out.green[i].color = indexColor;
        }
return true;
}
// проверить данные в структуре для вывода в на форму
bool TfrmDirection::checkDataToShow(const int currentDirection)
{
// red
for(int i=0;i<visDirectionRed.size();i++)
        {
        int MaxDk = visDirectionRed[i]->cdDk->Items->Count;
        if(MaxDk<tempPrg.Directs.OneDirect[currentDirection].out.red[i].NumberDk)return false;
        int MaxPort = visDirectionRed[i]->cdPort->Items->Count;
        if(MaxPort<tempPrg.Directs.OneDirect[currentDirection].out.red[i].group)return false;
        int MaxCol = visDirectionRed[i]->cdCol->Items->Count;
        if(MaxCol<tempPrg.Directs.OneDirect[currentDirection].out.red[i].color)return false;
        }
// yellow
for(int i=0;i<visDirectionYellow.size();i++)
        {
        int MaxDk = visDirectionYellow[i]->cdDk->Items->Count;
        if(MaxDk<tempPrg.Directs.OneDirect[currentDirection].out.red[i].NumberDk)return false;
        int MaxPort = visDirectionYellow[i]->cdPort->Items->Count;
        if(MaxPort<tempPrg.Directs.OneDirect[currentDirection].out.red[i].group)return false;
        int MaxCol = visDirectionYellow[i]->cdCol->Items->Count;
        if(MaxCol<tempPrg.Directs.OneDirect[currentDirection].out.red[i].color)return false;
        }
//grren
for(int i=0;i<visDirectionGreen.size();i++)
        {
        int MaxDk = visDirectionGreen[i]->cdDk->Items->Count;
        if(MaxDk<tempPrg.Directs.OneDirect[currentDirection].out.red[i].NumberDk)return false;
        int MaxPort = visDirectionGreen[i]->cdPort->Items->Count;
        if(MaxPort<tempPrg.Directs.OneDirect[currentDirection].out.red[i].group)return false;
        int MaxCol = visDirectionGreen[i]->cdCol->Items->Count;
        if(MaxCol<tempPrg.Directs.OneDirect[currentDirection].out.red[i].color)return false;
        }

return true;
}
// получить установленные параметры текущего направления из структуры временной
bool TfrmDirection::showParametrOneDirectoin(const int currentDirection)
{
if(currentDirection>tempPrg.AmountDirects)return false; // нет в проекте такого направления
// проверяем
if(!checkDataToShow(currentDirection))return false;
// отображаем  текущее направление из временнуй структуры на форму
// red
for(int i=0;i<visDirectionRed.size();i++)
        {
        visDirectionRed[i]->cdDk->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.red[i].NumberDk;
        visDirectionRed[i]->cdPort->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.red[i].group;
        visDirectionRed[i]->cdCol->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.red[i].color;
        bool check = tempPrg.Directs.OneDirect[currentDirection].out.red[i].control;
        visDirectionRed[i]->chkCtn->Perform(BM_SETCHECK,check,0);
        }
// yellow
for(int i=0;i<visDirectionYellow.size();i++)
        {
        visDirectionYellow[i]->cdDk->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.yel[i].NumberDk;
        visDirectionYellow[i]->cdPort->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.yel[i].group;
        visDirectionYellow[i]->cdCol->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.yel[i].color;
        bool check = tempPrg.Directs.OneDirect[currentDirection].out.yel[i].control;
        visDirectionYellow[i]->chkCtn->Perform(BM_SETCHECK,check,0);
        }
//grren
for(int i=0;i<visDirectionGreen.size();i++)
        {
        visDirectionGreen[i]->cdDk->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.green[i].NumberDk;
        visDirectionGreen[i]->cdPort->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.green[i].group;
        visDirectionGreen[i]->cdCol->ItemIndex =
                tempPrg.Directs.OneDirect[currentDirection].out.green[i].color;
        bool check = tempPrg.Directs.OneDirect[currentDirection].out.green[i].control;
        visDirectionGreen[i]->chkCtn->Perform(BM_SETCHECK,check,0);
        }
return true;
}
// проерить конфликты по свем направлениям
bool TfrmDirection::checkOneSructParametr(const WORD Group,const WORD Color,const WORD Dk)
{
for(int In=0;In<tempPrg.AmountDirects;In++)
        {
        for(int i=0;i<visDirectionRed.size();i++)// проверяем все формы их  не должно быть больше 32
                {
                //red
                if(tempPrg.Directs.OneDirect[In].out.red[i].NumberDk==Dk){
                        if(tempPrg.Directs.OneDirect[In].out.red[i].group==0)continue;
                        if(tempPrg.Directs.OneDirect[In].out.red[i].group==Group){
                                if(tempPrg.Directs.OneDirect[In].out.red[i].color==Color)
                                        return false;
                                }
                        }
                //yellow
                if(tempPrg.Directs.OneDirect[In].out.yel[i].NumberDk==Dk){
                        if(tempPrg.Directs.OneDirect[In].out.yel[i].group==0)continue;
                        if(tempPrg.Directs.OneDirect[In].out.yel[i].group==Group){
                                if(tempPrg.Directs.OneDirect[In].out.yel[i].color==Color)
                                        return false;
                                }
                        }
                //green
                if(tempPrg.Directs.OneDirect[In].out.green[i].NumberDk==Dk){
                        if(tempPrg.Directs.OneDirect[In].out.green[i].group==0)continue;
                        if(tempPrg.Directs.OneDirect[In].out.green[i].group==Group){
                                if(tempPrg.Directs.OneDirect[In].out.green[i].color==Color)
                                        return false;
                                }
                        }
                }
        }
return true;
}
// возрат текущего номера Дк
int TfrmDirection::getDk(const int tag)
{
if(tag<YEL_IN)  return visDirectionRed[tag]->cdDk->ItemIndex;
if(tag<GREN_IN) return visDirectionYellow[tag-YEL_IN]->cdDk->ItemIndex;
                return visDirectionGreen[tag-GREN_IN]->cdDk->ItemIndex;
}
// возрат текущего номера группы
int TfrmDirection::getGroup(const int tag)
{
if(tag<YEL_IN)  return visDirectionRed[tag]->cdPort->ItemIndex;
if(tag<GREN_IN) return visDirectionYellow[tag-YEL_IN]->cdPort->ItemIndex;
                return visDirectionGreen[tag-GREN_IN]->cdPort->ItemIndex;
}
// возрат текущего номера цвета
int TfrmDirection::getColor(const int tag)
{
if(tag<YEL_IN)  return visDirectionRed[tag]->cdCol->ItemIndex;
if(tag<GREN_IN) return visDirectionYellow[tag-YEL_IN]->cdCol->ItemIndex;
                return visDirectionGreen[tag-GREN_IN]->cdCol->ItemIndex;

}
// return false - есть конфликт проверяем Дк
bool TfrmDirection::checkSructParametrDK(const TComboBox *cmb)
{
const WORD Dk = cmb->ItemIndex;
const WORD Color = getColor(cmb->Tag);
const WORD Group = getGroup(cmb->Tag);
return checkOneSructParametr(Group,Color,Dk);
}
// return false - есть конфликт проверяем Группу
bool TfrmDirection::checkSructParametrGroup(const TComboBox *cmb)
{
const WORD Group= cmb->ItemIndex;
const WORD Color = getColor(cmb->Tag);
const WORD Dk = getDk(cmb->Tag);
return checkOneSructParametr(Group,Color,Dk);
}
// return false - есть конфликт проверяем цвет //BYTE col = visDirectionGreen[i],visDirectionYellow[i],visDirectionRed[i]
bool TfrmDirection::checkSructParametrColor(const TComboBox *cmb)
{
const WORD Color = cmb->ItemIndex;
const WORD Group = getGroup(cmb->Tag);
const WORD Dk = getDk(cmb->Tag);
return checkOneSructParametr(Group,Color,Dk);
}
