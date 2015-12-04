//---------------------------------------------------------------------------
// prog util
#include <typeinfo.h>
#include <map>


#pragma hdrstop

#include "progutil.h"
#include "structures.h"
#include "takts.h"
#include "Unit1.h"

#pragma package(smart_init)

using namespace std;

//---------------------------------------------------------------------------
int  DiagramPainter::Calc_Tc(int prog)
{
       int c_f, n_f;
       int faz_n;
       int tc=0;
       ///////////
       faz_n = PAPROGS.Program[curPrg].AmountFasa;
       ///
       for (c_f=0; c_f < faz_n; c_f++)
       {
          n_f = Get_Next_Viz_Faz(c_f);
          //
          TAKTS::Build_Takts(prog, prog, c_f, n_f);
          //
          tc+= TAKTS::osn_takt_time + TAKTS::Tprom_len;
          //
       }
       return (tc);
}
//------------------------------------------------------------------------------
// получить текстовое название типа направление
//0 - полные, 1- двухбуквенные обозначения
// - номер  направления - napr_n
AnsiString  DiagramPainter::Get_TXT_Napr_Type(DIR_TYPE  napr_typ, int  txt_type)
{
        AnsiString   s_add;
        /////////////////////  project
        s_add = "";
        if (txt_type == 0)
        switch (napr_typ)
           {
           case DIR_CCG: {s_add = "ССГ";break;}
           case DIR_UDZCG: {s_add = "УДЗСГ";break;}
           }
        /////
        if (txt_type == 1)
        switch (napr_typ)
           {
              case DIR_CCG: {s_add = "ссг-"; break;}
              case DIR_UDZCG: {s_add = "удзсг-"; break;}
           }
        /////
        return (s_add);

}
//------------------------------------------------------------------------------
// получить полное текствовое описание
AnsiString  DiagramPainter::Get_Full_TXT_Napr(TPROJECT *prj, int napr_i)
{
AnsiString   s_add;
DIR_TYPE  n_typ;
n_typ = prj->Directs.OneDirect[napr_i].Type;
s_add =  Get_TXT_Napr_Type(n_typ,0);
return(s_add);
}
/*------------------------------------------------------------------------------
конструктор
------------------------------------------------------------------------------*/
DiagramPainter::DiagramPainter(Classes::TComponent* Aown, TWinControl* Parent,
        TPROJECT * project_struct, TPROGRAMS *progs)
{
this->_aowner = Aown;
this->_parent = Parent;
this->programs = progs;
this->project = project_struct; // проетк
this->proga =(TPROGRAM*) &(project->Program); // программа из проетка
this->curPrg = 0;
this->faza_callback=NULL;
this->cur_faza=0;
this->panfaza_callback = NULL;
//чистим указатели панелей
for (int i=0 ; i < MaxDirects; i++)
        for (int ii=0; ii < MaxProgFase; ii++)
                for (int iii=0; iii < TaktsALL; iii++)
                        {
                        pan_arr[i][ii][iii]=NULL;
                        }
//чистим указатели панелей
for (int ii=0; ii < MaxProgFase; ii++)
        pan_faza[ii]=NULL;
//чистим указатели панелей
for (int i=0 ; i < MaxDirects; i++)
        edit_mas[i] = NULL;
//
pan_info=NULL;
Editable = false;
//
//coeff_width=0.512;
coeff_width = 0.8;
DragEnabled=false;
};
/*----------------------------------------------------------------------------*/
DiagramPainter::~DiagramPainter(void)
{
delete_panels();
}
//------------------------------------------------------------------------------
// удвляем все панели
void  DiagramPainter::delete_panels()
{
for (int i=0 ; i < MaxDirects; i++)
        {
        for (int ii=0; ii < MaxProgFase; ii++)
                {
                for(int iii=0; iii < TaktsALL; iii++)
                        {
                        if(pan_arr[i][ii][iii] ){
                                delete pan_arr[i][ii][iii];
                                pan_arr[i][ii][iii]=NULL;
                                }

                        }
                }
        }
for (int i=0; i < MaxProgFase; i++)
        {
        if  ( pan_faza[i] ){
                delete pan_faza[i];
                pan_faza[i]=NULL;
           }
        }
for (int i=0 ; i < MaxDirects; i++)
        {
        if (edit_mas[i] ){
                delete edit_mas[i];
                edit_mas[i] = NULL;
                }
        }
if (pan_info)
        delete pan_info;
}
//------------------------------------------------------------------------------
void  DiagramPainter::delete_panels_tprom()
{
}
//------------------------------------------------------------------------------
// рисуем ленту времени
void DiagramPainter::Paint()
{
delete_panels();   // удаляем панели
Build_Takts_NEW(); // строим такски
Paint_Time_Diag(); // создаем ленту времени
}
//------------------------------------------------------------------------------
// рисуем ленту времени контретной программы
void DiagramPainter::Paint(int i_prog)
{
this->curPrg = i_prog;
this->proga =(TPROGRAM*) &(programs->Program[i_prog]);
Paint();
}
//------------------------------------------------------------------------------
// очистим таски, то что надо рисовать
void DiagramPainter::Clear_Takts()
{
for (int i=0; i < MaxDirects; i++)
        for (int ii=0; ii < MaxProgFase; ii++)
                for (int iii=0; iii < TaktsALL; iii++)
                {
                takts_mas[i][ii][iii].col = 0;
                takts_mas[i][ii][iii].time = 0;
                }
}
//------------------------------------------------------------------------------
void __fastcall DiagramPainter::NaprClick(TObject *Sender)
{
TPanel *p_panel;

p_panel = ((TPanel *) Sender );
//
for (int i=0; i< MaxDirects; i++)
        {
        if (edit_mas[i])
                if (p_panel==edit_mas[i]){
                        this->cur_napr=i;
                        break;
                        }

        }
//
if (napr_callback)
        napr_callback(Sender);
}
//---------------------------------------------------------------------------
void __fastcall DiagramPainter::PanFazClick(TObject *Sender)
{
const TPanel *p_panel = ((TPanel *) Sender );

for (int i=0; i< MaxProgFase; i++)//MaxProgFase
        {
        if (pan_faza[i]){
                if (p_panel==pan_faza[i]){
                        this->cur_faza=i;
                        break;
                        }
                }
        }

if (panfaza_callback){
        panfaza_callback(Sender);
        }
}
//------------------------------------------------------------------------------
void __fastcall DiagramPainter::AllClick(TObject *Sender)
{
const TImage *p_image = ((TImage *) Sender );
bool b_find = false;

        for (int i=0 ; i < napr_n; i++)
        {
        for (int ii=0; ii < faza_n; ii++)
           {
           for (int iii = 0; iii < TaktsALL; iii++)
               {
               if (pan_arr[i][ii][iii])
                   if ((p_image == pan_arr[i][ii][iii])){
                        cur_faza = ii;
                        cur_takt = iii;
                        cur_napr = i;
                        select_takt = pan_arr[i][ii][iii];
                        b_find = true;
                        break;
                        }//if
               }//for iii
           if (b_find) break;
           }//for ii
        if (b_find) break;
        }//for i
//
if (faza_callback)
        faza_callback(Sender);
}
//------------------------------------------------------------------------------
int DiagramPainter::SecToPix(int px)
{
return (px *tim_1* coeff_width);
}
//------------------------------------------------------------------------------
AnsiString DiagramPainter::retConvertToTime(const int time)
{
const int hh = time/60;
const int mm = time%60;
AnsiString strHH,strMM;
if(hh<10)strHH = "0"+IntToStr(hh);
        else strHH = IntToStr(hh);
if(mm<10)strMM = "0"+IntToStr(mm);
        else strMM = IntToStr(mm);
return strHH+":"+strMM;
}
//------------------------------------------------------------------------------
//создает объекты и размещает их
int   DiagramPainter::Paint_Time_Diag()
{
int          i,ii,iii,time_i,wid_i,i_e, i_dif;
TColor       col, col1; //основной и дополнительный hex map
AnsiString   add_text, s;
int          f_i, n_i;
int          ta_i;
TRect        rct;

        //
        int     pos_x, pos_y;
        //
        //i - направление
        //ii - фаза
        //iii - такт
        ///time_i - время кумулятор
        //wid_i - ширина такта
        //
pos_x = 15;
pos_y = ots_y;
//
faza_n = proga->AmountFasa;
if (cur_faza>=faza_n)
        cur_faza=0;
// рисуем панель
pan_info = new TPanel(_aowner);
pan_info->Width = 100;
pan_info->Height = 100;
pan_info->Left = 10;
pan_info->Top = ots_top;
pan_info->BorderStyle = bsNone;
pan_info->Parent = _parent;

// строим панели фаз
for (i=0; i<faza_n; i++)
        {
        pan_faza[i] = new TPanel(_aowner);
        pan_faza[i]->Width = 100;
        pan_faza[i]->Height = 100;
        pan_faza[i]->Left = i*100;
        pan_faza[i]->Top = ots_top;
        pan_faza[i]->BorderStyle = bsNone;
        pan_faza[i]->Parent = _parent;
        pan_faza[i]->BevelOuter = bvNone;
        pan_faza[i]->OnClick = PanFazClick;
        pan_faza[i]->BevelInner=bvRaised;
        pan_faza[i]->BevelOuter=bvLowered;
        pan_faza[i]->Visible = true;
        }
///////////////////
time_i=0;
//////////////////////
pos_x = 0;
pos_y = ots_y;//SecToPix(height_1);
//
BYTE inxCCG = 1;
BYTE inxUDZCG = 1;
//
napr_n = project->AmountDirects;
// создаем информационные панели
for (int i=0 ; i < napr_n; i++)
        {
        edit_mas[i] = new TPanel(_aowner);
        edit_mas[i]->Width = t_prom_rect_size;
        edit_mas[i]->Height = height_1;
        edit_mas[i]->Left = pos_x;
        edit_mas[i]->Top = pos_y;
        edit_mas[i]->BorderStyle = bsSingle;
        edit_mas[i]->Parent = pan_info;
        edit_mas[i]->Hint = "Направление № " + IntToStr(i+1);
        //Get_TXT_Napr
        AnsiString textNp = Get_Full_TXT_Napr(project, i);
        if(textNp=="ССГ")
                edit_mas[i]->Caption = IntToStr(inxCCG++) + " " + textNp;
                else
                edit_mas[i]->Caption = IntToStr(inxUDZCG++) + " " + textNp;
        edit_mas[i]->Tag = i;
        edit_mas[i]->ShowHint = true;
        edit_mas[i]->OnClick = NaprClick;
        edit_mas[i]->Font->Style=edit_mas[i]->Font->Style << fsBold;
        edit_mas[i]->Font->Size=12;
        edit_mas[i]->Visible = true;
        pos_y=pos_y+ 2*height_1;;
        }
//
pan_info->Height = edit_mas[napr_n-1]->Top + edit_mas[napr_n-1]->Height + ots_y;
pan_info->Width = edit_mas[napr_n-1]->Left + edit_mas[napr_n-1]->Width ;
//
for (f_i=0; f_i < faza_n; f_i++)
        {
        pos_x = 0;
        pos_y = ots_y;
        //
        for (n_i=0 ; n_i < napr_n; n_i++)
             {
               iii = 0;
               ta_i = logic_struct ? 1 : TaktsALL;
               //
               for ( iii = 0; iii < ta_i; iii++)
               {
                 i_dif = takts_mas[n_i][f_i][iii].time;
                 if (takts_mas[n_i][f_i][iii].time == 0)
                    continue;
                 const int hint_time = takts_hint[n_i][f_i][iii].time; // время для hint
                 if (this->logic_struct)
                      takts_mas[n_i][f_i][iii].time=10;
                 wid_i=takts_mas[n_i][f_i][iii].time;
                 pan_arr[n_i][f_i][iii] = new TImage(_aowner);
                 pan_arr[n_i][f_i][iii]->Width= SecToPix(wid_i);
                 pan_arr[n_i][f_i][iii]->Height=height_1;
                 pan_arr[n_i][f_i][iii]->Parent = pan_faza[f_i];
                 pan_arr[n_i][f_i][iii]->Top=pos_y;
                 pan_arr[n_i][f_i][iii]->Left=pos_x;
                 pan_arr[n_i][f_i][iii]->Hint = retConvertToTime(hint_time)+" (час:мин)";//IntToStr(hint_time) + " min."; // показываем время
                 pan_arr[n_i][f_i][iii]->ShowHint = true;//!logic_struct;
                 //pan_arr[n_i][f_i][iii]->OnClick = AllClick;
                 pan_arr[n_i][f_i][iii]->Visible=true;
                 pan_arr[n_i][f_i][iii]->Tag = f_i*1000 + n_i*100 + iii;
                 //
                 if(this->project->Directs.OneDirect[n_i].Type==DIR_UDZCG){
                   takts_mas[n_i][f_i][iii].col = RED_YELLOW;
                   }else{
                   pan_arr[n_i][f_i][iii]->OnClick = AllClick;
                   }

                 /////////////
                 // рисуем
                 //смотрим цвет
                 col1 = clCream;
                 add_text="";
                 switch (takts_mas[n_i][f_i][iii].col)
                 {
                   case RED: { col=clRed; break; }
                   case YELLOW: { col=clYellow;  break; }
                   case GREEN: { col=clGreen; break;   }
                   case GREEN_RED:
                        {
                        if(this->project->guard.type_cycle){  //
                                col=clYellow;   break;
                                }else{
                                col=clGreen; col1 = clYellow;  break;
                                }
                        }
                   case RED_YELLOW:{col=clLtGray;break;}
                   //{ col=clRed; col1 = clYellow ;add_text="Ж"; break; }
                   //case 6: { col=clYellow; add_text="M";  break; }
                   //case 7: { col=clGreen; add_text="M"; break;  }

                 }
                 ///
                 if  (col1 == clCream)
                 {
                    pan_arr[n_i][f_i][iii]->Canvas->Brush->Color = col;
                    //

                    pan_arr[n_i][f_i][iii]->Canvas->Rectangle(0,0,
                                        pan_arr[n_i][f_i][iii]->Width,
                                        pan_arr[n_i][f_i][iii]->Height);
                     //
                     if (iii==0){
                        pan_arr[n_i][f_i][iii]->Canvas->Font->Color=clWhite;
                        AnsiString st = "Ф" +
                                IntToStr(proga->fazas[f_i].NumFasa+1);
                        int tx = pan_arr[n_i][f_i][iii]->Canvas->TextHeight(st);
                        int ty = pan_arr[n_i][f_i][iii]->Canvas->TextWidth(st);
                        //
                        pan_arr[n_i][f_i][iii]->Canvas->TextOutA(
                                (pan_arr[n_i][f_i][iii]->Width-tx)/2,
                                (pan_arr[n_i][f_i][iii]->Height-ty)/2,
                                   st);
                     }
                     //
                 }
                 else
                 {
                    pan_arr[n_i][f_i][iii]->Canvas->Brush->Color = col;
                    pan_arr[n_i][f_i][iii]->Canvas->Rectangle(0,0,
                                        pan_arr[n_i][f_i][iii]->Width,
                                        pan_arr[n_i][f_i][iii]->Height/2);
                    //
                    pan_arr[n_i][f_i][iii]->Canvas->Brush->Color = col1;

                    pan_arr[n_i][f_i][iii]->Canvas->Rectangle(
                                     0, pan_arr[n_i][f_i][iii]->Height/2,
                                        pan_arr[n_i][f_i][iii]->Width,
                                        pan_arr[n_i][f_i][iii]->Height  );
                    //


                 }

                 ////
                 time_i=time_i+wid_i;
                 pos_x=pos_x+wid_i*tim_1*coeff_width;
                 ///
                  //iii++;
               } //for iiii
               ////
               ////
               pos_y=pos_y+ 2*height_1;;
               pos_x=0;

           } //for n_i

        } //for f_i
//
n_i=0;
pos_x=pan_info->Left + pan_info->Width;  //предыдущая панелька
// двигаем панельки по горизонтали
for (f_i=0; f_i < faza_n; f_i++)
        {
        wid_i=0;  // время
        ta_i = logic_struct ? 1 : TaktsALL;
        for ( iii = 0; iii < ta_i; iii++)
                wid_i+=takts_mas[n_i][f_i][iii].time;
        //
        pan_faza[f_i]->Width = SecToPix(wid_i);
        pan_faza[f_i]->Left = pos_x;
        //
        pos_x+=SecToPix(wid_i);
        //
        pan_faza[f_i]->Height = pan_arr[napr_n-1][f_i][0]->Top +
                pan_arr[napr_n-1][f_i][0]->Height + ots_y;
        }
//
pan_faza[cur_faza]->Color = clDkGray;
return(0);
}
//------------------------------------------------------------------------------
// является ли данная фаза отображаемой
// i_prog - номер программы, i_por_faz - порядковый номер фазы в программе
bool  Is_Faz_Vis(int   i_por_faz)
{
        bool  ret_b;
        /////////////////////
        //ret_b = false;
        //
        //if (all_prog_visible) return (true);
        //
        //if ( progs_fazas_mas[i_prog][i_por_faz][1] >6)
           ret_b = true;
        ///////
        return (ret_b);

}
//------------------------------------------------------------------------------
// получает следующую видимую фазу для отображения на временной диаграмме
int  DiagramPainter::Get_Next_Viz_Faz(int cur_faz)
{
        int     i,ii, ret_i;
        ///////////
        ret_i = cur_faz;
        for (i = cur_faz + 1; i < proga->AmountFasa; i++)
        {
          if ( Is_Faz_Vis(i) )
          {
            ret_i = i;
            break;
          }//if
        }//for
        ///////////////
        if (ret_i == cur_faz)
        {
             for (i = 0; i < cur_faz; i++)
             {
                if ( Is_Faz_Vis(i) )
                {
                  ret_i = i;
                  break;
                }//if
             }//for

        }// if ret_i
        /////////////////////
        return (ret_i);


}
//------------------------------------------------------------------------------
// построение используя общюю бибилиотеку TAKTS
void DiagramPainter::Build_Takts_NEW(void)
{
int cur_faz=0, next_faz;     // номера фаз
int prog_faz_n = proga->AmountFasa;  // кол-во фаз в проге всего
//
napr_n = project->AmountDirects;
//
Clear_Takts();
//
TAKTS::initTAKTS(project,programs);
TAKTS::cur_prog = curPrg;
//
while (cur_faz < prog_faz_n)
        {
        next_faz = Get_Next_Viz_Faz(cur_faz); //следующая фаза
        //
        TAKTS::Build_Takts(curPrg,curPrg, cur_faz, next_faz);//такты для одной фазы
        // копируем массивы
        for (int i_napr = 0; i_napr < napr_n; i_napr ++)
                {
                takts_mas[i_napr][cur_faz][0].col= TAKTS::osn_takt[i_napr];
                // уменьшаем основной такт для просмотра
                takts_phase[i_napr][cur_faz][0].time = TAKTS::osn_takt_time;
                const int time = sqrt(TAKTS::osn_takt_time*3);
                takts_mas[i_napr][cur_faz][0].time = time;
                // обрабатываем вызывную фазу
                if(time==0)takts_mas[i_napr][cur_faz][0].time = sqrt(180.0);
                // время отображающее в hint
                takts_hint[i_napr][cur_faz][0].time = TAKTS::osn_takt_time;
                //
                for (int iii=0; iii<TaktsN; iii++)
                        {
                        takts_mas[i_napr][cur_faz][1+iii].col
                                = TAKTS::prom_takts[i_napr][iii].col;
                        const int time = sqrt(TAKTS::prom_takts[i_napr][iii].time*3);
                        takts_mas[i_napr][cur_faz][1+iii].time = time;
                        // hint
                        takts_hint[i_napr][cur_faz][1+iii].time
                                = TAKTS::prom_takts[i_napr][iii].time;
                        // из основного времени вычесть пром. такты
                        if(takts_hint[i_napr][cur_faz][0].time>TAKTS::prom_takts[i_napr][iii].time)
                                takts_hint[i_napr][cur_faz][0].time -= TAKTS::prom_takts[i_napr][iii].time;
                                else
                                takts_hint[i_napr][cur_faz][0].time = TAKTS::prom_takts[i_napr][iii].time -
                                                                      takts_hint[i_napr][cur_faz][0].time;
                        }
                }
        cur_faz++;
        }
}
//------------------------------------------------------------------------------
