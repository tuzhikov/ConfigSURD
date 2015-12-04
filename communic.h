/*----------------------------------------------------------------------------*/

#ifndef communicH
#define communicH
#include <vcl.h>
#include <vector.h>
#include <stdio.h>
#include "structures.h"

using namespace std;

//enum TYPE_IP{IP_LONG,MAC_LONG,END_LONG};

// хранение параметров связи по UDP
class IPDATA
{
std::vector<AnsiString> IP_PROJECT;
std::vector<AnsiString> MAC_PROJECT;
AnsiString BrIP;

int  PORT;
int  DELAY;

static bool checkIP(AnsiString ip); // IP: 169.254.016.001
bool checkMAC(AnsiString mac); // MAC: 00:1A:B6:00:64:00
AnsiString makeBroadcastIP(void);
public:
    IPDATA (
           const int port = 11990,
           const int delay = 1000,
           AnsiString ip = "169.254.016.001",
           AnsiString mac = "00:1A:B6:00:64:00"
           ):PORT(port),DELAY(delay){addOneIp(ip);addOneMac(mac);}
    static bool checkAdressIP(const AnsiString ip){return checkIP(ip);}
    inline int  getPort(void){return PORT;}
    inline void setPort(const int port){PORT = port;}
    inline int  getDelay(void){return DELAY;}
    inline void setDelay(const int delay){DELAY = delay;}
    // получить один IP MAC
    inline AnsiString getOneIp(const int iIp){
        if(iIp<IP_PROJECT.size())  return IP_PROJECT[iIp];
                                else return "";}
    inline AnsiString getOneMac(const int iMac){
        if(iMac<MAC_PROJECT.size())  return MAC_PROJECT[iMac];
                                else return "";}
    // установить IP MAC адресс
    inline bool setOneIp(const int inIp,AnsiString ip){
        if(!checkIP(ip))return false;
        if(inIp<IP_PROJECT.size()) IP_PROJECT[inIp] = ip.LowerCase();
                              else IP_PROJECT.push_back(ip.LowerCase());
        return true;
        }
    inline bool setOneMac(const int inMac,AnsiString mac){
        if(!checkMAC(mac))return false;
        if(inMac<MAC_PROJECT.size()) MAC_PROJECT[inMac] = mac.LowerCase();
                                else MAC_PROJECT.push_back(mac.LowerCase());
        return true;
        }
    // добавить один IP MAC
    inline void addOneIp(AnsiString ip){IP_PROJECT.push_back(ip);}
    inline void addOneMac(AnsiString mac){MAC_PROJECT.push_back(mac);}
    // удалить все IP MAC
    inline void removeIp(void){IP_PROJECT.clear();}
    inline void removeMac(void){MAC_PROJECT.clear();}
    // получить размер массива IP MAC
    inline int  getCountIp(void){return IP_PROJECT.size();}
    inline int  getCountMac(void){return MAC_PROJECT.size();}
    // вернуть широковещательный адресс
    // вернуть широковещательный адресс
    inline AnsiString retBroadcastIP(void){return makeBroadcastIP();}
    // копировать
    bool saveDateSurd(ExData::TSURD *psurd);
    //
    bool loadDateSurd(ExData::TPROJECT *pPrj);
};
/*----------------------------------------------------------------------------*/
extern IPDATA IpData;
/*----------------------------------------------------------------------------*/
#endif
