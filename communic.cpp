/*----------------------------------------------------------------------------*/
#include "communic.h"
/*----------------------------------------------------------------------------*/
IPDATA IpData; // данные канала связи по ethernet
/*-----------------------------------------------------------------------------*
Class IPDATE
*-----------------------------------------------------------------------------*/
/*---------------- check IP adress--------------------------------------------*/
bool IPDATA ::checkIP(AnsiString ip) // IP: 169.254.016.001
        {
        const char *pIp = ip.c_str();
        int countPiont = 0,countDis = 0;
        for(int i=0;i<ip.Length();i++)
                {
                if((*pIp=='\0')||(*pIp=='\n'))break;
                if(*pIp=='.'){
                        if(countPiont++>3)return false; // точек больше трех
                        if(countDis!=3)return false; // цифр не три
                        countDis=0;
                        }else{
                        if((*pIp>='0')&&(*pIp<='9')){
                                if(++countDis>3)return false; // цифр больше трех
                                }else{
                                return false;}

                        }
                pIp++;
                }
        if((countPiont==3)&&(countDis==3))return true;
        return false;
        }
/*---------------- check MAC adress-------------------------------------------*/
bool IPDATA ::checkMAC(AnsiString mac) // MAC: 00:1A:B6:00:64:00
        {
        const char *pmac = mac.c_str();
        int countPiont = 0,countDis = 0;
        for(int i=0;i<mac.Length();i++)
                {
                if((*pmac=='\0')||(*pmac=='\n'))break;
                if(*pmac==':'){
                        if(countPiont++>5)return false; // больше пяти
                        if(countDis!=2)return false; // цифр не две
                        countDis=0;
                        }else{
                        if(
                          ((*pmac>='0')&&(*pmac<='9'))||
                          ((*pmac>='A')&&(*pmac<='F'))||
                          ((*pmac>='a')&&(*pmac<='f'))){
                                if(++countDis>2)return false; // цифр больше двух
                                }else{
                                return false;}

                        }
                pmac++;
                }
        if((countPiont==5)&&(countDis==2))return true;
        return false;
        }
/*-------------- copy date surd-----------------------------------------------*/
bool IPDATA ::saveDateSurd(ExData::TSURD *psurd)
{
//копируем MAC &IP в структуру проетка
for(int i=0;i<getCountMac();i++)
        {
        // IP adress
        memset(&psurd->ip[i],'\0',sizeof(psurd->ip[i]));
        memcpy(&psurd->ip[i],getOneIp(i).c_str(),getOneIp(i).Length());
        // MAC adress
        memset(&psurd->mac[i],'\0',sizeof(psurd->mac[i]));
        memcpy(&psurd->mac[i],getOneMac(i).c_str(),getOneMac(i).Length());
        }
return true;
}
// Из структуры проекта отображаем адреса mac &ip ----------------------------//
bool IPDATA ::loadDateSurd(ExData::TPROJECT *pPrj)
{
removeIp();
removeMac();
for(int i=0;i<pPrj->maxDK;i++)
        {
        AnsiString ip((char*)&pPrj->surd.ip[i],MAX_BYTE_IP);
        AnsiString mac((char*)&pPrj->surd.mac[i],MAX_BYTE_MAC);
        if(!setOneIp(i,ip))return false;
        if(!setOneMac(i,mac))return false;
        }
setPort(pPrj->surd.PORT);
setDelay(pPrj->surd.TIMEOUT);
return true;
}
// получить широквоещательный адресс
AnsiString IPDATA ::makeBroadcastIP(void)
{
AnsiString ip =  getOneIp(0);
int lengip = ip.Length();
char *pip = ip.c_str();

for(int i = lengip;;i--)
        {
        if(ip[i]=='.')break;
        ip.Delete(i,1);
        }
ip+="255";
return ip;
}

/*-----------------------------------------------------------------------------*
Class IPDATE END
*-----------------------------------------------------------------------------*/
