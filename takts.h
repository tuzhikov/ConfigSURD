//---------------------------------------------------------------------------

#ifndef taktsH
#define taktsH
//---------------------------------------------------------------------------
#include "structures.h"
#include "progutil.h"

using namespace ExData;

namespace TAKTS
{
typedef struct __TAKT_PROP{
        STATES_LIGHT  col;
        BYTE          time;
        }TAKT_PROP;
/*----------------------------------------------------------------------------*/
typedef  TAKT_PROP      prom_takts_faz_type[MaxDirects][TaktsN];
typedef  STATES_LIGHT   osn_takts_faz_type[MaxDirects];
/*----------------------------------------------------------------------------*/
void initTAKTS(const TPROJECT  *proj,const TPROGRAMS *progs);
void Build_Takts(const int c_prog,
                 const int n_prog,
                 const int cur_faz,
                 const int next_faz);
/*----------------------------------------------------------------------------*/
extern int cur_prog;  ///текущая программа
extern   prom_takts_faz_type    prom_takts; // пром. такты одной фазы
extern   osn_takts_faz_type     osn_takt;   // основные такты  фазы
extern   int Tprom_len;
extern   int osn_takt_time;  //длина основного такта
}
#endif
