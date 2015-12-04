//---------------------------------------------------------------------------

#ifndef progutilH
#define progutilH

#pragma pack (1)

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <math>

#include <Forms.hpp>
#include <Menus.hpp>
#include "structures.h"
#include "takts.h"

#define   t_prom_rect_size   200;  // ����� ������ � ��������

using namespace ExData;

const   int     ots_x    = 5;
const   int     ots_y    = 10; // ������ ������ � �������
const   int     tim_1    = 10; //����� � �������� 1 �������
const   int     height_1 = 30; // ������ �� ���������
const   int     ots_top  = 30;

// �������� ������ ��������
typedef struct __TAKT_PROP{
        STATES_LIGHT col;  // �������� ����������� �,�,�
        DWORD        time; // ����� ����
        }TAKT_PROP;
typedef  TAKT_PROP   takts_mas_type[MaxDirects][MaxProgFase][TaktsALL+1]; // ��� ��� �����������

// ������ �� ���-������ ���������
class DiagramPainter
{
        //AnsiString retConvertToTime(const int time);
public:
    Classes::TComponent*    _aowner; //�� ��� ������
    TWinControl*            _parent;
    TPROGRAM  *proga; // ��������� �� �������� � ������
    TPROJECT  *project;
    TPROGRAMS *programs;
    int curPrg; //������� ���������
    int cur_faza; //������� ���������� ���� �� ���������
    int cur_napr; //
    int cur_takt; //
    TImage  *select_takt;
    int  napr_n; //��-�� ����������� � �������
    int  faza_n; // ���-�� ���
    float     coeff_width;
    ////
    bool   Editable; //����������� �������������
    bool   logic_struct; //����������� ������ ���������� ���������
    //
    TPoint  MouseDownPos;
    bool   DragEnabled;
    //
    TPanel* pan;
    takts_mas_type  takts_mas;  // [MaxDirects][MaxProgFase][TaktsALL]
    takts_mas_type  takts_hint; // [MaxDirects][MaxProgFase][TaktsALL]
    takts_mas_type  takts_phase;  // [MaxDirects][MaxProgFase][TaktsALL]
    int    fazas_viz[MaxProgFase];
    TPanel *edit_mas[MaxDirects];   //������������ ������
    TImage *pan_arr[MaxDirects][MaxProgFase][TaktsALL]; // ��������� � ��������� takts_mas
    TPanel *pan_faza[MaxProgFase]; //������������ ������ ��� ��� ���������
    TPanel *pan_info;//���� ������ � ������������
    // call-back
    void __fastcall (*faza_callback)(TObject *Sender);
    void __fastcall (*napr_callback)(TObject *Sender);
    void __fastcall (*panfaza_callback)(TObject *Sender);
    DiagramPainter(Classes::TComponent* Aown, TWinControl* Parent,
                                TPROJECT * project_struct, TPROGRAMS *progs);
    ~DiagramPainter();
    void Paint();
    void Paint(int i_prog);// ���������� ������ ���������
    void Clear_Takts();
    void Build_Takts_NEW(void);
    int  Get_Next_Viz_Faz(int cur_faz_i);
    int  Paint_Time_Diag();
    void delete_panels();
    void delete_panels_tprom();
    int  SecToPix(int px);
    DWORD retTimeOsn(const int dir,const int phase){return takts_hint[dir][phase][0].time;}// � ��������� ����. - ��� �� ����� ���� � ����� ���. �����.
    DWORD retTimeOsnMax(const int dir,const int phase){return takts_phase[dir][phase][0].time;}
    ///   STATIC
    static AnsiString  Get_TXT_Napr_Type(DIR_TYPE  napr_typ, int  txt_type);
    static int Get_Tram_Num(TPROJECT *prj, int napr_i);
    static AnsiString  DiagramPainter::Get_Full_TXT_Napr(TPROJECT *prj, int napr_i);
    static AnsiString retConvertToTime(const int time);
    int Calc_Tc(int prog);
    void __fastcall AllClick(TObject *Sender);
    void __fastcall NaprClick(TObject *Sender);
    void __fastcall PanFazClick(TObject *Sender);

    //void Build_Takts();
    //int  Get_Red_Green_Type_Fasa(int i_napr, int i_faz);
    //void __fastcall TaktClick(TObject *Sender);
    //int Calculate_Tprom_max(int prog_num, int cur_faz, int next_faz);
    //int Calculate_Ex_Conf_Max(int prog_num, int n1, int cur_faz, int next_faz);
    //void __fastcall PanelFazaMouseDown(TObject *Sender,TMouseButton Button,
    //                                    TShiftState Shift, int X, int Y);
    //void __fastcall PanelFazaMouseMove(TObject *Sender, TShiftState Shift,int X, int Y);
    //void __fastcall PanelFazaMouseUp(TObject *Sender, TMouseButton Button,
    //                                    TShiftState Shift, int X, int Y);
};
//----------------------------------------------------------------------------//
#endif
