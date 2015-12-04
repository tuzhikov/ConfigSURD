#ifndef udzcgH
#define udzcgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <vector>
#include "structures.h"

//---------------------------------------------------------------------------
enum retANSWER{retOk,retError,retEmpty,retEnd};

class RetAnsSTR
{
AnsiString Str;
retANSWER Ret;
public:
    RetAnsSTR(AnsiString str,const retANSWER ret):Str(str),Ret(ret){}
    inline AnsiString getString(void){return Str;}
    inline retANSWER getAnswer(void){return Ret;}
    inline void setString(AnsiString str){Str = str;}
    inline void setAnswer(retANSWER ret){Ret = ret;}
};

class TFormUDZG : public TForm
{
__published:	// IDE-managed Components
        TComboBox *cbbOpr1;
        TComboBox *cbbOpr2;
        TPanel *pnlbut;
        TBevel *bvlTop;
        TLabel *lblText;
        TSpeedButton *btnPlus;
        TSpeedButton *btnMinus;
        TButton *btnOk;
        TButton *btnExit;
        TListBox *lstOut;
        TPanel *pnlresult;
        TComboBox *cbbResultSign;
        TComboBox *cbbResult;
        TCheckBox *chkResultInv;
        TPanel *pnl1;
        TComboBox *cbbBS;
        TComboBox *cbbB;
        TCheckBox *chkBInv;
        TPanel *Panel1;
        TComboBox *cbbAS;
        TComboBox *cbbA;
        TCheckBox *chkAInv;
        TPanel *Panel2;
        TComboBox *cbbCS;
        TComboBox *cbbC;
        TCheckBox *chkCInv;
        TLabel *lblrv;
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall btnPlusClick(TObject *Sender);
        void __fastcall btnMinusClick(TObject *Sender);
        void __fastcall btnOkClick(TObject *Sender);
        void __fastcall lstOutChange(TObject *Sender);
        void __fastcall cbColorChange(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall lstOutClick(TObject *Sender);
private:	// User declarations
        WORD CountCCG;
        WORD CountUDZCG;
        ExData::TEXPRESSIONS tempDate;
        TStringList *strCCG;
        TStringList *strUDZCG;
        TStringList *strClorCCG;
        TStringList *strClorUDZCG;
        TStringList *strLogical;

        std::vector<TCheckBox*> chesk;
        std::vector<TComboBox*> cmbDir;
        std::vector<TComboBox*> cmbClr;
        std::vector<TComboBox*> cbbOpr;

        void setListDirection(void);
        bool checkMaskUDZCG(void);
        void deleteMaskUDZCG(void);
        void deliteAllMaskUDZCG(void);
        bool saveMaskUDZCG(void);
        WORD checkAllParameter(void);
        RetAnsSTR checkDirectUDZCG(void);
        void showOnePrmComboBox(const int Index);
        RetAnsSTR showOnePrmOutList(const int Index);
        void showAllPrmOutList(void);
        void setStrCbCollor(const TComboBox *incb,const TComboBox *outcb);
public:		// User declarations
        __fastcall TFormUDZG(TComponent* Owner);
        void setVisibleDirection(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormUDZG *FormUDZG;
//---------------------------------------------------------------------------
#endif
