#ifndef kstructuresH
#define kstructuresH
//------------
 #pragma pack (1)
 //
 #define MaxWeeksPlans     16  //����� ��������� ������
 #define MaxDaysPlans      16  //����� �������� ������
 #define MaxCalendar       32  //����� ��������� ��� �����

 #define MaxProgFase       8   //������������ ����� ��� � ���������

 #define MaxTVP            2   //������������ ����� ���
 #define MaxDirects        16  //������������ ����� �����������
 #define MaxProgram        32  //������������ ����� ��������
 #define MaxFase           16  //������������ ����� ���
  //
 #define MaxMULBlocks      12  //������������ ����� ������ ����
 #define MaxChannels       14  //����� ������� � ����

 #define WeeksInYear       54
 #define MaxLightSlots     12  //����� ������ ������� � ������� �����
 #define MaxLightPlans     12  //����� ������ �������



 #define TaktsN            4        // ����� ������ � ����. ����
 #define TaktsALL          5        // ����� ������ � ����

 //////
 // ����-���������
 #define NO_PROG           -1
 #define SPEC_PROG_NO      0   //�� ����-���������
 #define SPEC_PROG_YF      1   //��
 #define SPEC_PROG_OC      2   //OC
 #define SPEC_PROG_KK      3   //KK
 //////////////
 // ��-�� ���
 #define FAZA_PROP_FIKS    0   //������������� ����
 #define FAZA_PROP_COMB    1   //���������������
 #define FAZA_PROP_TVP     2   //�������� ���


/////////
// ��������� �����������
typedef enum __STATES_LIGHT
{
	ALL_OFF       = 0x00,   // ��� ���������
	GREEN         = 0x01,	// ������
	GREEN_FLASH   = 0x02,	// ������ ��������
	RED           = 0x03,   // �������
	RED_YELLOW    = 0x04,   // �������-�����
	YELLOW        = 0x05,   // Ƹ����
	YELLOW_FLASH  = 0x06,	// Ƹ���� ��������
	RESERVED
} STATES_LIGHT;
 ////////////////
 const char* STATE_TXT[] =
{ "ALL_OFF", "GREEN", "GREEN_FLASH", "RED", "RED_YELLOW", "YELLOW", "YELLOW_FLASH"};

 // ���������
 typedef unsigned char BYTE;
 typedef unsigned short WORD;
 typedef unsigned long DWORD;

 // ������������
#define P_ZD1     0
#define P_ZD2     1
#define P_KD      2


 struct  TPROMTAKT
 {
       BYTE Zd1;     // ����� ���������� �����
       BYTE Zd2;
       BYTE KD;
 };
 ////  ������ ����
 #define SHABL_FAZA_DIR_RED     0
 #define SHABL_FAZA_DIR_GREEN   1


 struct TSHABLONFASA
 {
    BYTE  Direct[MaxDirects]; //���� ��������� ����������� � ����
                               //              0x01-��������
                               //              0x0 -���������  (������� ����)

 };
 // ��������� ���
 struct TVPSOURCE
 {
   BYTE      addr; //����� ������������ ������� 0..11
   BYTE      pres; //0 - ��� ���, 1,2 - ������\������ ������
 };
 // ��������� ���� � ���������
 struct TFASA
 {
   BYTE      FasaProperty;        //  �������� ����
   WORD      Tosn;                //  �������� �����
   BYTE      NumFasa;             //  ����� ��������� ����
   TPROMTAKT prom[MaxDirects];    // ���� ����� ��� ������� ����������
   //BYTE      TVP1;               // ���1 - ����� ������������ ������� 0..11
  // BYTE      TVP1_num;           // ����� ���
                                // 0 - ��� ���, 1,2 - ������\������ ������
   //BYTE      TVP2;               // ���2
   //BYTE      TVP2_num;           //
   TVPSOURCE tvps[2];

 };
 // FasaProperty
 //������������� -  0;
 //���������������, 0x01
 //��� - 0x02

   //BYTE ActiveFase;          //���� �������� ���� ������� ���
                               //              0x01-��������
                               //              0x0 -���������  (������� ����)
//����������� �������� ����   ActiveFase=1 -������� ����
//                                                   ActiveFase=0x02 -������� ��������

//��� �������:                            ActiveFase=0x03 -����� �������
//                                        ActiveFase=0x04 -�����
//                                        ActiveFase=0x05 -������ �������
//                    ActiveFase=0x06,0x07,0x08,0x09- ���������� (�����,����� ,������)
//                    ActiveFase=0x0A;  ���� ��� ������� (���������� ����)


//Ks -����������� �����. ������� �������������  Ks=0xFF.
//����� � ����� �������� ���������� �������� ��� ��������� ��� �������
//����������� ����������� �����.
//    (�������� ���������� �s)

// ��������� ��������� �������� �� ������� �����
struct TCALENDARTIME
{
	BYTE   NumProgramWorks;  //  � ���������   1-32
        BYTE   SpecProg;         // ���� � ����� ����-��������
	DWORD  BeginTimeWorks;   //  ����� ������ ������ � �������� �� 00:00:00
} ;

typedef struct
 {
   BYTE            AmountCalendTime;          //���-�� ��������
   TCALENDARTIME   CalendTime[ MaxCalendar ]; // ��������� �������� ���������� ���������
} TCALENDAR;

typedef struct
 {
   BYTE     Calendar[7 ]; // ������(�������) �������� ������ �� ������ DaysPlans
                          // 0 - ��, 6 - ��
}TWEEKCALENDAR;
///
typedef struct
 {
   BYTE     YearCalendar[WeeksInYear]; // ������(�������) ��������� ������ �� ������ WeeksCalendars
}TYEARCALENDAR;
///////////////////////////////////////////////
typedef struct
{
   BYTE   AmountFasa; 		   //���������� ��� � ���������
   TFASA  fazas[MaxProgFase];
}TPROGRAM;

//������ - ���������� ������
//MaxMULBlocks= ����� ���������� �����


  struct TONEMUL
  {
     //�������� ������� ����� � ������������
     // 0 - ��� ��������
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
//�����������������������
//�����������

#define DIRECT_TRANSP   0
#define DIRECT_PESH     1
#define DIRECT_ARROW    2
#define DIRECT_TRAMW    3


  struct TONEDIRECT
  {
    BYTE Type;                  //��� ����������� ������=0 ��������=1  �������=2 �������=3
  };


 struct TDIRECTS
 {
   TONEDIRECT  OneDirect  [ MaxDirects ];   // MaxDirects=32
 } ;
 ///
 struct TGUARD
 {
        // >0 - ����� ����� �������� ����������� �����������
        BYTE  ConfMatrix[MaxDirects][MaxDirects]; //
        BYTE  ConfMatrixFlag[MaxDirects][MaxDirects]; //  �����
        //
        BYTE  red_min;   // �����������
        BYTE  yellow;
        BYTE  redyellow;
        BYTE  greenflash;
        BYTE  green_min;
        WORD  faza_max;
        BYTE  green_fill;  //���� ���������� ����. ������ 0-�������, 1 - �������
        ///
        BYTE  porog_green;
        BYTE  porog_red;
        //
        BYTE  kk_len;   //�� ������������

 };
///////////////////////////////////////////////
 struct TLIGHT
 {
        BYTE  red;
        BYTE  yell;
        BYTE  green;
        DWORD  BeginTimeWorks;   //  ����� ������ ������ � �������� �� 00:00:00
 };
 struct TLIGHTPLAN
 {
       BYTE            AmountSlots;          //���-�� ��������
       TLIGHT          slots[MaxLightSlots];
 };
 struct TLIGHTSTRUCT
 {
       TLIGHTPLAN  lightplans[MaxLightPlans]; //��� ����� �������
       BYTE        year[MaxLightPlans];   // ������� ������ �������
       ///
       BYTE        lowlight; //���������� ������� ��� ������� ������������.
       BYTE        lightlevel;
       BYTE        vddoff; //���������� ����������
       BYTE        vddon; //���������� ���������

 };

///////////////////////////////////////////////
// ��������� ������� ��� ��
struct TPROJECT
{
   WORD                 ProjectSize;	        // ������ �������
   BYTE                 AmountDirects;	        // ������������ �����������
   TDIRECTS             Directs;	        // �����������
   BYTE                 AmountMuls;             // ���-�� ��
   TMULS                Muls ;		        // ����
   TSHABLONFASA         Fasa[MaxFase] ;         // ���� - �������
   TCALENDAR            DaysPlans[MaxDaysPlans];        // ����� ������� ������
   TWEEKCALENDAR        WeeksPlans[MaxWeeksPlans];      // ����� ��������� ������
   TYEARCALENDAR        Year;                           // ������� ����
   TPROGRAM             Program[ MaxProgram ];          // ����� ��������
   TGUARD               guard;                          // ��������� ������������
   TLIGHTSTRUCT         light;                          //��������� �������
   unsigned long        CRC32;
}  ;

/////////


/////
#endif






