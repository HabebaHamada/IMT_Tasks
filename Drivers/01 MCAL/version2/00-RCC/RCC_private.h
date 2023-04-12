/**************************************************************
/                    Author : Habeba Hamada                    /
/                    LAYER  : MCAL                             /
/                    SWC    : RCC                              /
/                    Version: 1.00                             /
**************************************************************/

#ifndef		RCC_PRIVATE_H_
#define		RCC_PRIVATE_H_


#define RCC_BASE_ADD                (u32)(0x40023800)


typedef struct
{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 reserved1 ;
	u32 reserved2 ;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 reserved3 ;
	u32 reserved4 ;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 reserved5 ;
	u32 reserved6 ;
	u32 APB1ENR;
	u32 APB2ENR;
}RCC_t;


#define RCC  ((volatile RCC_t*)(RCC_BASE_ADD))



typedef enum
{
	HSION,
	HSIRDY,
	HSITIRM = 3,
	HSICAL  = 8,
	HSEON   = 16,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON   = 24,
	PLLRDY,
	PLLI2SON,
	PLLI2SRDY
}RCC_CR_t;


typedef enum
{
	PLLM,
	PLLN   = 6,
	PLLP   = 16,
	PLLSRC = 22,
	PLLQ   = 24
}RCC_PLLCFGR_t;


typedef enum
{
	SW,
	SWS      = 2,
	HPRE     = 4,
	PPRE1    = 10,
	PPRE2    = 13,
	RTCPRE   = 16,
	MCO1     = 21,
	I2SSRC   = 23,
	MCO1PRE,
	MCO2PRE  = 27,
	MCO2     = 30
}RCC_CFGR_t;


/****************************************/

typedef enum
{
	RCC_HSI,
	RCC_HSE,
	RCC_PLL
}SysClk;


typedef enum
{
	APB_NO,
	APB_PRE_2   = 4,
	APB_PRE_4,
	APB_PRE_8,
	APB_PRE_16,
	APB_Default = 0,
}APB_Prescaler;



typedef enum
{
	AHB_NO,
	AHB_PRE_2    = 8,
	AHB_PRE_4,
	AHB_PRE_8,
	AHB_PRE_16,
	AHB_PRE_64,
	AHB_PRE_128,
	AHB_PRE_256,
	AHB_PRE_512,
	AHB_Default  = 0,
}AHB_PreScaler;


typedef enum
{
	MCO1_HSI,
	MCO1_LSE,
	MCO1_HSE,
	MCO1_PLL,
	MCO1_Default = MCO1_HSI
}MCO1_Source;


typedef enum
{
	MCO2_SYSCLK,
	MCO2_PLLI2S,
	MCO2_HSE,
	MCO2_PLL,
	MCO2_Default = MCO2_SYSCLK
}MCO2_Source;

typedef enum
{
	No_Division,
	Division_By_2,
	Division_By_3,
	Division_By_4,
	Division_By_5
}MCO_Div;


typedef enum
{
	PLLP_2,
	PLLP_4,
	PLLP_6,
	PLLP_8,
}RCC_PLL_Div;


typedef enum
{
	HSIClk,
	HSEClk,
}RCC_PLL_CLKSource;


typedef enum
{
	DetectorOFF,
	DetectorON,
}RCC_CLK_Security;



/****************************************************************************/

#define RCC_Enable              1
#define RCC_Disable             0





#endif
