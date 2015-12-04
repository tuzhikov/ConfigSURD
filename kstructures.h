#ifndef kstructuresH
#define kstructuresH
//------------
 #pragma pack (1)
 //
 #define MaxWeeksPlans     16  //Число недельных планов
 #define MaxDaysPlans      16  //Число суточных планов
 #define MaxCalendar       32  //Число разбиений для суток

 #define MaxProgFase       8   //Максимальное число фаз в программа

 #define MaxTVP            2   //Максимальное число ТВП
 #define MaxDirects        16  //Максимальное число направлений
 #define MaxProgram        32  //Максимальное число программ
 #define MaxFase           16  //Максимальное число фаз
  //
 #define MaxMULBlocks      12  //Максимальное число блоков СУСО
 #define MaxChannels       14  //Число каналов в СУСО

 #define WeeksInYear       54
 #define MaxLightSlots     12  //Число слотов яркости в дневном плане
 #define MaxLightPlans     12  //Число планов яркости



 #define TaktsN            4        // число тактов в пром. фазе
 #define TaktsALL          5        // число тактов в фазе

 //////
 // спец-программы
 #define NO_PROG           -1
 #define SPEC_PROG_NO      0   //не спец-программа
 #define SPEC_PROG_YF      1   //ЖМ
 #define SPEC_PROG_OC      2   //OC
 #define SPEC_PROG_KK      3   //KK
 //////////////
 // св-ва фаз
 #define FAZA_PROP_FIKS    0   //фиксированная фаза
 #define FAZA_PROP_COMB    1   //комбинированная
 #define FAZA_PROP_TVP     2   //вызывная ТВП


/////////
// состояния направлений
typedef enum __STATES_LIGHT
{
	ALL_OFF       = 0x00,   // Все выключены
	GREEN         = 0x01,	// Зелёный
	GREEN_FLASH   = 0x02,	// Зелёный мигающий
	RED           = 0x03,   // Красный
	RED_YELLOW    = 0x04,   // Красный-жёлтый
	YELLOW        = 0x05,   // Жёлтый
	YELLOW_FLASH  = 0x06,	// Жёлтый мигающий
	RESERVED
} STATES_LIGHT;
 ////////////////
 const char* STATE_TXT[] =
{ "ALL_OFF", "GREEN", "GREEN_FLASH", "RED", "RED_YELLOW", "YELLOW", "YELLOW_FLASH"};

 // ПромТакты
 typedef unsigned char BYTE;
 typedef unsigned short WORD;
 typedef unsigned long DWORD;

 // наименование
#define P_ZD1     0
#define P_ZD2     1
#define P_KD      2


 struct  TPROMTAKT
 {
       BYTE Zd1;     // Время выполнения такта
       BYTE Zd2;
       BYTE KD;
 };
 ////  шаблон фазы
 #define SHABL_FAZA_DIR_RED     0
 #define SHABL_FAZA_DIR_GREEN   1


 struct TSHABLONFASA
 {
    BYTE  Direct[MaxDirects]; //Флаг активного направления в фазе
                               //              0x01-активное
                               //              0x0 -пассивное  (красный цвет)

 };
 // источники ТВП
 struct TVPSOURCE
 {
   BYTE      addr; //адрес светофорного объекта 0..11
   BYTE      pres; //0 - нет ТВП, 1,2 - первая\вторая кнопка
 };
 // Структура фазы в программе
 struct TFASA
 {
   BYTE      FasaProperty;        //  свойства фазы
   WORD      Tosn;                //  основное время
   BYTE      NumFasa;             //  номер шаблонной фазы
   TPROMTAKT prom[MaxDirects];    // пром такты для каждого напрвления
   //BYTE      TVP1;               // ТВП1 - адрес светофорного объекта 0..11
  // BYTE      TVP1_num;           // номер ТВП
                                // 0 - нет ТВП, 1,2 - первая\вторая кнопка
   //BYTE      TVP2;               // ТВП2
   //BYTE      TVP2_num;           //
   TVPSOURCE tvps[2];

 };
 // FasaProperty
 //Фиксированная -  0;
 //Комбинированная, 0x01
 //ТВП - 0x02

   //BYTE ActiveFase;          //Флаг активной фазы младший бит
                               //              0x01-активная
                               //              0x0 -пассивная  (красный цвет)
//Особенности активной фазы   ActiveFase=1 -зеленый цвет
//                                                   ActiveFase=0x02 -зеленый мигающий

//Для трамвая:                            ActiveFase=0x03 -левый поворот
//                                        ActiveFase=0x04 -прямо
//                                        ActiveFase=0x05 -правый поворот
//                    ActiveFase=0x06,0x07,0x08,0x09- комбинации (левый,прямо ,правый)
//                    ActiveFase=0x0A;  стоп для трамвая (неактивная фаза)


//Ks -контрольная сумма. Сначала устанавливаем  Ks=0xFF.
//Далее к этому значению прибавляем побайтно всю структуру для которой
//вычисляется контрольная сумма.
//    (исключая собственно Кs)

// Структура раскладки программ по времени суток
struct TCALENDARTIME
{
	BYTE   NumProgramWorks;  //  № программы   1-32
        BYTE   SpecProg;         // флаг и номер спец-программ
	DWORD  BeginTimeWorks;   //  Время начала работы в секундах от 00:00:00
} ;

typedef struct
 {
   BYTE            AmountCalendTime;          //кол-во отрезков
   TCALENDARTIME   CalendTime[ MaxCalendar ]; // Временная диапазон выполнения программы
} TCALENDAR;

typedef struct
 {
   BYTE     Calendar[7 ]; // номера(индексы) суточных планов из списка DaysPlans
                          // 0 - Вс, 6 - Сб
}TWEEKCALENDAR;
///
typedef struct
 {
   BYTE     YearCalendar[WeeksInYear]; // номера(индексы) недельных планов из списка WeeksCalendars
}TYEARCALENDAR;
///////////////////////////////////////////////
typedef struct
{
   BYTE   AmountFasa; 		   //Количество фаз в программе
   TFASA  fazas[MaxProgFase];
}TPROGRAM;

//Модули - Сигнальные группы
//MaxMULBlocks= Число чигнальных групп


  struct TONEMUL
  {
     //привязка силовых линий к направдениям
     // 0 - нет привязки
     //
     BYTE   direct1; //
     BYTE   direct2;
     //
     BYTE   walker1;
     BYTE   walker2;
     //
     BYTE   arrow1;
     BYTE   arrow2;

  } ;

  struct TMULS
  {
   TONEMUL    OneMUL[MaxMULBlocks];
  };
//……………………………………………………………
//Направления

#define DIRECT_TRANSP   0
#define DIRECT_PESH     1
#define DIRECT_ARROW    2
#define DIRECT_TRAMW    3


  struct TONEDIRECT
  {
    BYTE Type;                  //Тип направления Трансп=0 Пешеходн=1  Стрелка=2 Трамвай=3
  };


 struct TDIRECTS
 {
   TONEDIRECT  OneDirect  [ MaxDirects ];   // MaxDirects=32
 } ;
 ///
 struct TGUARD
 {
        // >0 - время между зелеными конфликтных направлений
        BYTE  ConfMatrix[MaxDirects][MaxDirects]; //
        BYTE  ConfMatrixFlag[MaxDirects][MaxDirects]; //  флаги
        //
        BYTE  red_min;   // минимальный
        BYTE  yellow;
        BYTE  redyellow;
        BYTE  greenflash;
        BYTE  green_min;
        WORD  faza_max;
        BYTE  green_fill;  //флаг заполнения пром. тактов 0-красным, 1 - зеленым
        ///
        BYTE  porog_green;
        BYTE  porog_red;
        //
        BYTE  kk_len;   //КК длительнсоть

 };
///////////////////////////////////////////////
 struct TLIGHT
 {
        BYTE  red;
        BYTE  yell;
        BYTE  green;
        DWORD  BeginTimeWorks;   //  Время начала работы в секундах от 00:00:00
 };
 struct TLIGHTPLAN
 {
       BYTE            AmountSlots;          //кол-во отрезков
       TLIGHT          slots[MaxLightSlots];
 };
 struct TLIGHTSTRUCT
 {
       TLIGHTPLAN  lightplans[MaxLightPlans]; //все планы яркости
       BYTE        year[MaxLightPlans];   // индексы планов ярксоти
       ///
       BYTE        lowlight; //«уменьшить яркость при разряде аккумулятора».
       BYTE        lightlevel;
       BYTE        vddoff; //напряжение отключения
       BYTE        vddon; //напряжение включение

 };

///////////////////////////////////////////////
// Структура проекта для ДК
struct TPROJECT
{
   WORD                 ProjectSize;	        // Размер проекта
   BYTE                 AmountDirects;	        // используемых направлений
   TDIRECTS             Directs;	        // Направления
   BYTE                 AmountMuls;             // кол-во СГ
   TMULS                Muls ;		        // МУЛЫ
   TSHABLONFASA         Fasa[MaxFase] ;         // Фазы - шаблоны
   TCALENDAR            DaysPlans[MaxDaysPlans];        // набор дневных планов
   TWEEKCALENDAR        WeeksPlans[MaxWeeksPlans];      // набор недельных планов
   TYEARCALENDAR        Year;                           // годовой план
   TPROGRAM             Program[ MaxProgram ];          // набор программ
   TGUARD               guard;                          // параметры безопасности
   TLIGHTSTRUCT         light;                          //параметры яркости
   unsigned long        CRC32;
}  ;

/////////


/////
#endif






