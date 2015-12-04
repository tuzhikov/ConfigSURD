//---------------------------------------------------------------------------

#pragma hdrstop

#include "takts.h"
#include "Unit1.h"
#include "structures.h"
#pragma  package(smart_init)
//---------------------------------------------------------------------------
namespace TAKTS
{
const TPROJECT  *project;
const TPROGRAMS *programs;
int       napr_n;    //���-�� �����������
int       cur_prog;  //������� ���������

prom_takts_faz_type     prom_takts;     // ����. ����� ����� ����
osn_takts_faz_type      osn_takt;       // �������� �����  ����
int                     osn_takt_time;  //����� ��������� �����
int                     Tprom_len;      // ����������������� ����. ���� ������������
                                        // � ������� Build_Takts

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void initTAKTS(const TPROJECT  *proj,const TPROGRAMS *progs)
{
project = proj;
programs = progs;
napr_n = project->AmountDirects;
}
//------------------------------------------------------------------------------
// ��������� ������ ��������� ���� � ��������� � ���� � ���������
// 2 ��������
// 1) �������� ��������� � cur_faz - ����� � ���
// 2) ��� ��������� cur_faz - ����� ��������� ����
static int Get_SH_FAZ(int c_prog, int cur_faz)
{
    int sh_faza=0;
    ///
    if (c_prog!=NO_PROG)
       sh_faza = programs->Program[c_prog].fazas[cur_faz].NumFasa;
    else
       sh_faza = cur_faz;
    ////
    return(sh_faza);
}
//------------------------------------------------------------------------------

// ������� ��� ������� ���� - �������(0) ��� �������(1)
// i_faz - ����� ���� � ������� ���������
static int  Get_Red_Green_Type_Fasa(int c_prog, int i_napr, int i_faz)
{
        int sh_faza = Get_SH_FAZ(c_prog, i_faz);
        // ����� ��������� ���� ��
        //sh_faza = project->Program[cur_prog].fazas[i_faz].NumFasa;
        if (project->Fasa[sh_faza].Direct[i_napr])
          return 1;
        else
          return 0;
        ///

}
//
//------------------------------------------------------------------------------
// ��������� �������� ����������� ����. ������
static int GET_P(int c_prog, int c_napr, int cur_faz, BYTE prom_param)
{
      int ret_i=0;
      ////
      if (c_prog!=NO_PROG)
      {
         switch (prom_param)
         {
          case P_ZD1:
            ret_i = programs->Program[c_prog].fazas[cur_faz].prom[c_napr].Zd1;
            break;
          ///
          case P_ZD2:
            ret_i = programs->Program[c_prog].fazas[cur_faz].prom[c_napr].Zd2;
            break;
          ///
          case P_KD:
            ret_i = programs->Program[c_prog].fazas[cur_faz].prom[c_napr].KD;
            break;
          ///

         }
      }
      ////
      return (ret_i);

}
//------------------------------------------------------------------------------
static int GET_Tosn(int c_prog, int cur_faz)
{
     int ret_i=0;
     ///
     if (c_prog!=NO_PROG)
     {
         ret_i = programs->Program[c_prog].fazas[cur_faz].Tosn;
     }
     //
     return (ret_i);

}
//------------------------------------------------------------------------------
// ��������� ������������ ����� ��� �������� ����� ������
// cur_faz - ���������� ����� ���� � ���������
static int Calculate_Tprom_max(int c_prog, int n_prog, int cur_faz, int next_faz)
{
        int     i, ret_i, prom_i, prom_max, i_napr;
        int     per_faz;   //������� ����� ������
        int     cur_faz_sh, next_faz_sh; // ������ ��������� ����

        ////////////////
        cur_faz_sh = Get_SH_FAZ(c_prog, cur_faz);
        next_faz_sh = Get_SH_FAZ(n_prog, next_faz);
        //
        ret_i = 0;
        prom_max = 0;
        ////////////////////////
        // 1) ������� ����� �� ������ ���������
        ///////////// cur_prog
        // �� ���� ������������
        for (i_napr = 0; i_napr < napr_n; i_napr ++)
        {
          //per_faz = napr_faz[i_napr][cur_faz] - napr_faz[i_napr][next_faz];
          per_faz = Get_Red_Green_Type_Fasa(c_prog,i_napr, cur_faz) -
                    Get_Red_Green_Type_Fasa(n_prog,i_napr, next_faz);
          prom_i = 0;
          // ������ ��������
          // 1-0=1  - ������� �� �������� � ��������
          // 0-1=-1 - ������� �� �������� � ��������
          // 0-0=0  , 1-1 = 0 - ��� ��������� ��������� �����
          //////////////////
          // ������� �-�  , ����� ��+�+�
           if (per_faz == 1)
           {
              if (project->Directs.OneDirect[i_napr].Type==DIR_CCG)
              {
                    prom_i = GET_P(c_prog, i_napr, cur_faz, P_ZD2) +
                             //proga->fazas[cur_faz].prom[i_napr].Zd2 +
                       project->guard.green_yellow +
                       project->guard.yellow +
                                GET_P(c_prog, i_napr, cur_faz, P_KD);
                       //proga->fazas[cur_faz].prom[i_napr].KD ;
              }
              else
              {
                    prom_i = GET_P(c_prog, i_napr, cur_faz, P_ZD2) +
                             //proga->fazas[cur_faz].prom[i_napr].Zd2 +
                             GET_P(c_prog, i_napr, cur_faz, P_KD)+
                             project->guard.green_yellow;

              }
              //
           }//if per ==1
           /////
           // ������� �-� , ����� ��+�
           if (per_faz == -1)
           {
              if (project->Directs.OneDirect[i_napr].Type==DIR_CCG)
              {
                    prom_i = GET_P(n_prog, i_napr, next_faz, P_ZD1) +
                             //GET_P(c_prog, i_napr, cur_faz, P_KD) +
                             //proga->fazas[cur_faz].prom[i_napr].Zd1 +
                             project->guard.redyellow;
              }
              else
              {
                    prom_i = GET_P(n_prog, i_napr, next_faz, P_ZD1);
                             //proga->fazas[cur_faz].prom[i_napr].Zd1;

              }
              //
           }//if per ==1
           /////
           // ������� �-� , �-�
           if (per_faz == 0)
           {

           }//if per ==0
           /////



           /////
           if (prom_i > prom_max)
              prom_max = prom_i;

        }//for i_napr
        //////////////////////////////////
        //////////////////////////////////
        // 2) ������� ����� �� ������� �����������
        int n1,n2;
        int prom_max_confl=0;
        prom_i=0;
        //����������� 1� 2 ���
        for (n1 = 0; n1 < napr_n; n1 ++)
        {
          if (project->Fasa[cur_faz_sh].Direct[n1]==SHABL_FAZA_DIR_GREEN)
            for (n2 = 0; n2 < napr_n; n2 ++)
            {
               if (project->Fasa[next_faz_sh].Direct[n2]==SHABL_FAZA_DIR_GREEN)
               if (project->guard.ConfMatrixFlag[n1][n2])
               {
                   //���� �������� �����������
                   prom_i =  GET_P(c_prog, n1, cur_faz, P_ZD2) +
                             //proga->fazas[cur_faz].prom[n1].Zd2 +
                             project->guard.green_yellow +
                             GET_P(n_prog, n2, next_faz, P_ZD1) +
                             //proga->fazas[next_faz].prom[n2].Zd1 +
                             project->guard.ConfMatrix[n1][n2];
                   ///
                   if (prom_i > prom_max)
                        prom_max = prom_i;
               }
            }//for n2
        }//for n1
        /////////////////
        ret_i = prom_max;
        //
        return (ret_i);

}
//------------------------------------------------------------------------------
// ���������� ������������ ������������ ���������=Conf+Zd1
// cur_faz - ���������� ����� ���� � ���������
// n1 - ����������� ��� �������� ��������� ����������� ��������
static int Calculate_Ex_Conf_Max(int c_prog, int n_prog, int n1, int cur_faz, int next_faz)
{
        int n2;
        int prom_max_confl=0;
        int prom_i=0;
        int prom_max=0;
        int cur_faz_sh, next_faz_sh; // ������ ��������� ����
        //TPROGRAM*    proga;
         ////
        //proga = &(project->Program[prog_num]);
        //
        cur_faz_sh = Get_SH_FAZ(c_prog,cur_faz);//proga->fazas[cur_faz].NumFasa;
        next_faz_sh = Get_SH_FAZ(n_prog,next_faz);// proga->fazas[next_faz].NumFasa;
         //����������� 1� 2 ���
          if (project->Fasa[cur_faz_sh].Direct[n1]==SHABL_FAZA_DIR_GREEN)
            for (n2 = 0; n2 < napr_n; n2 ++)
            {
               if (project->Fasa[next_faz_sh].Direct[n2]==SHABL_FAZA_DIR_GREEN)
               if (project->guard.ConfMatrixFlag[n1][n2])
               {
                   //���� �������� �����������
                   prom_i =  //GET_P(c_prog, n2, cur_faz, P_ZD1) +
                             GET_P(n_prog, n2, next_faz, P_ZD1) +

                             //proga->fazas[next_faz].prom[n2].Zd1 +
                             project->guard.ConfMatrix[n1][n2];
                   ///
                   if (prom_i > prom_max)
                        prom_max = prom_i;
               }
            }//for n2
        /////////////////
        return (prom_max);

}
//------------------------------------------------------------------------------
// ������� ������� ������
static void Clear_Takts()
{
for (int i=0;i< MaxDirects; i++)
        {
        osn_takt[i] = ALL_OFF;
        for (int j=0;j < TaktsN;j++)
                {
                prom_takts[i][j].col = 0;
                prom_takts[i][j].time = 0;
                }
        }
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// ���������� ������� ������ ��� ����� ���� :
// c_prog - ������� ���������
// n_prog - ��������� ��������� ����
void Build_Takts(const int c_prog,
                 const int n_prog,
                 const int cur_faz,
                 const int next_faz)
{
        //int     i,ii, i_napr;
        //int     per_faz;               // ������� ����� ������
        //int     prom_i;                // ����� �������� ������
                                       // (��� ���������� ������������� ��������� �������)
        //int     prom_max;              // �������� �����.����
        int     ex_conf;               // �������� ������������ ��������� �� Zd1
        bool    trans_napr;            // �������� �� ������ ����������� ������������
        int     cur_faz_typ, nex_faz_typ;
        //
        int Ytakt , Rtakt, GFtakt,RYtakt,Gtakt  ;    // �������� ����.������ � ��������
        //
        Clear_Takts();
        //
        Ytakt=project->guard.yellow;
        GFtakt=project->guard.green_yellow;
        RYtakt=project->guard.redyellow;

               const int prom_max = Calculate_Tprom_max(c_prog, n_prog, cur_faz, next_faz);
               Tprom_len = prom_max;
               // �� ���� ������������
               for (int i_napr = 0; i_napr < napr_n; i_napr ++)
               {
                    cur_faz_typ = Get_Red_Green_Type_Fasa(c_prog, i_napr, cur_faz);
                    nex_faz_typ = Get_Red_Green_Type_Fasa(n_prog, i_napr, next_faz);
                    //
                    const int per_faz = cur_faz_typ - nex_faz_typ;
                    //
                    if ( project->Directs.OneDirect[i_napr].Type == DIR_CCG)
                          trans_napr = true;
                        else
                          trans_napr = false;
                    // ������� �-�  , ����� ��+�+�
                    if (per_faz == 1)
                    {

                       osn_takt[i_napr] = GREEN;  //���� - �������
                       osn_takt_time = GET_Tosn(c_prog, cur_faz);
                             //GET_P(c_prog, i_napr, cur_faz, P_ZD1)
                             //proga->fazas[cur_faz].Tosn;
                       /////
                       ex_conf = Calculate_Ex_Conf_Max(c_prog, n_prog, i_napr, cur_faz,next_faz );
                       //////////////////////////////
                       if (trans_napr)
                       if (project->guard.green_fill)
                       {
                          // ���������� ������ �������
                          Rtakt = ex_conf - Ytakt;
                          if (Rtakt<0) Rtakt=0;
                          //
                          Gtakt = prom_max - Rtakt- Ytakt - GFtakt;
                          if (Gtakt<0) Gtakt=0;
                          //
                          int pt_i=0;  //����� ����.�����
                          if (Gtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Gtakt;
                            pt_i++;
                          }
                          ///
                          if (GFtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN_RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = GFtakt;
                            pt_i++;
                          }
                          ///
                          if (Ytakt)
                          {
                            prom_takts[i_napr][pt_i].col = YELLOW;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Ytakt;
                            pt_i++;
                          }
                          ///
                          if (Rtakt)
                          {
                            prom_takts[i_napr][pt_i].col = RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Rtakt;
                            pt_i++;
                          }
                          ///
                       }
                       /////////////
                       /////////////
                       if (trans_napr)
                       if (project->guard.green_fill==0)
                       {
                          // ���������� ������ �������
                          //
                          Gtakt =  GET_P(c_prog, i_napr, cur_faz, P_ZD2);
                                   // proga->fazas[cur_faz].prom[i_napr].Zd2;
                          //
                          Rtakt = prom_max-Ytakt-GFtakt-Gtakt;
                          //if (Rtakt<0) Rtakt=0;

                          //prom_max - Rtakt- Ytakt - GFtakt;
                          //if (Gtakt<0) Gtakt=0;
                          //
                          int pt_i=0;  //����� ����.�����
                          if (Gtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Gtakt;
                            pt_i++;
                          }
                          ///
                          if (GFtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN_RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = GFtakt;
                            pt_i++;
                          }
                          ///
                          if (Ytakt)
                          {
                            prom_takts[i_napr][pt_i].col = YELLOW;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Ytakt;
                            pt_i++;
                          }
                          ///
                          if (Rtakt)
                          {
                            prom_takts[i_napr][pt_i].col = RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Rtakt;
                            pt_i++;
                          }
                          ///
                       }
                       /////////////
                       /////////////
                       // �� ������������ �����������
                       if (!trans_napr)
                       if (project->guard.green_fill)
                       {
                          // ���������� ������ �������
                          Rtakt = ex_conf;// - Ytakt;
                          if (Rtakt<0) Rtakt=0;
                          //
                          Gtakt = prom_max - Rtakt- GFtakt;
                          if (Gtakt<0) Gtakt=0;
                          //
                          int pt_i=0;  //����� ����.�����
                          if (Gtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Gtakt;
                            pt_i++;
                          }
                          ///
                          if (GFtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN_RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = GFtakt;
                            pt_i++;
                          }
                          ///
                          if (Rtakt)
                          {
                            prom_takts[i_napr][pt_i].col = RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Rtakt;
                            pt_i++;
                          }
                          ///
                       }
                       /////////////
                       /////////////
                       // �� ������������ �����������
                       if (!trans_napr)
                       if (project->guard.green_fill==0)
                       {
                          // ���������� ������ �������
                          //
                          Gtakt = GET_P(c_prog, i_napr, cur_faz, P_ZD2);
                                //proga->fazas[cur_faz].prom[i_napr].Zd2;
                          //
                          Rtakt = prom_max-GFtakt-Gtakt;
                          if (Rtakt<0) Rtakt=0;

                          //prom_max - Rtakt- Ytakt - GFtakt;
                          //if (Gtakt<0) Gtakt=0;
                          //
                          int pt_i=0;  //����� ����.�����
                          if (Gtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Gtakt;
                            pt_i++;
                          }
                          ///
                          if (GFtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN_RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = GFtakt;
                            pt_i++;
                          }
                          ///
                          if (Rtakt)
                          {
                            prom_takts[i_napr][pt_i].col = RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Rtakt;
                            pt_i++;
                          }
                          ///
                       }
                       /////////////
                       /////////////


                    }//if per ==1
                    //////////////////////////////////////////
                    /////////////////////////////////////////
                    // ������� �-�  , ����� ��+�
                    if (per_faz == -1)
                    {
                         osn_takt[i_napr] = RED;  //���� - �������
                         osn_takt_time =
                                GET_Tosn(c_prog,cur_faz);
                                //proga->fazas[cur_faz].Tosn;
                         Gtakt =  GET_P(n_prog, i_napr, next_faz, P_ZD1);// +

                       ////////////
                       ////////////
                       // ������������
                       if (trans_napr)
                       {

                                    //GET_P(c_prog, i_napr, cur_faz, P_ZD1);
                                   //proga->fazas[cur_faz].prom[i_napr].Zd1;
                          //
                          Rtakt = prom_max - Gtakt - RYtakt;
                          if (Rtakt<0) Rtakt=0;
                          //
                          int pt_i=0;  //����� ����.�����
                          if (Rtakt)
                          {
                            prom_takts[i_napr][pt_i].col = RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Rtakt;
                            pt_i++;
                          }
                          ///
                          if (RYtakt)
                          {
                            prom_takts[i_napr][pt_i].col = RED_YELLOW;  //���� - �������
                            prom_takts[i_napr][pt_i].time = RYtakt;
                            pt_i++;
                          }
                          ///
                          if (Gtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Gtakt;
                            pt_i++;
                          }
                          ///
                       }
                       /////////////
                       /////////////
                       // ������������, �������
                       if (!trans_napr)
                       {
                          //Gtakt = GET_P(n_prog, i_napr, next_faz, P_ZD1);
                                   //proga->fazas[cur_faz].prom[i_napr].Zd1;
                          //
                          Rtakt = prom_max - Gtakt;
                          if (Rtakt<0) Rtakt=0;
                          //
                          int pt_i=0;  //����� ����.�����
                          if (Rtakt)
                          {
                            prom_takts[i_napr][pt_i].col = RED;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Rtakt;
                            pt_i++;
                          }
                          ///
                          if (Gtakt)
                          {
                            prom_takts[i_napr][pt_i].col = GREEN;  //���� - �������
                            prom_takts[i_napr][pt_i].time = Gtakt;
                            pt_i++;
                          }
                          ///
                       }
                       /////////////
                       /////////////


                    }//if per ==-1
                    //////////////////////////////////////////
                    /////////////////////////////////////////
                    // ����������� ������� �-� ���  �-�
                    if (per_faz == 0)
                    {
                         if (Get_Red_Green_Type_Fasa(c_prog, i_napr, cur_faz))
                         {
                            osn_takt[i_napr] = GREEN;
                            prom_takts[i_napr][0].col = GREEN;  //���� - �������
                            prom_takts[i_napr][0].time = prom_max;
                         }
                         else
                         {
                            osn_takt[i_napr] = RED;
                            prom_takts[i_napr][0].col = RED;  //���� - �������
                            prom_takts[i_napr][0].time = prom_max;
                         }
                    osn_takt_time = GET_Tosn(c_prog,cur_faz);
                    }//if per == 0
               }// end for i_napr
}
//------------------------------------------------------------------------------
}//namespace


