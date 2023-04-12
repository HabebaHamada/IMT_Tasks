/**************************************************************
/                    Author : Habeba Hamada                    /
/                    LAYER  : MCAL                             /
/                    SWC    : RCC                              /
/                    Version: 1.00                             /
**************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"


#include"RCC_private.h"
#include"RCC_config.h"
#include"RCC_interface.h"


void RCC_voidSystemClockInit(void)
{

	/*       MCO1,MCO2 PreScaler cofiguratios  */

  	RCC->CFGR|=(MCO1_Prescaler<<MCO1PRE);
	RCC->CFGR|=(MCO2_Prescaler<<MCO2PRE);

	RCC->CFGR|=(MCO1_Clock_Source<<MCO1);
  	RCC->CFGR|=(MCO2_Clock_Source<<MCO2);


    /*        Clock Security System            */
  	RCC->CR|=(RCC_CLOCK_Security<<CSSON);

	/*        Clock Source Switch              */
  	RCC->CFGR|=(System_Clock_Source<<SW);

	/*        AHB PreScaler                    */
  	RCC->CFGR|=(RCC_AHB_PRESCALER<<HPRE);


	/*        APB1 PreScaler                   */
  	RCC->CFGR|=(RCC_APB1_PRESCALER<<PPRE1);

	/*        APB2 PreScaler                   */
  	RCC->CFGR|=(RCC_APB2_PRESCALER<<PPRE2);



	
	#if RCC_PLL_Mode==RCC_Enable

  	RCC->PLLCFGR=0;
  	RCC->PLLCFGR|=(PLL_InClk_Division_Factor<<PLLM);
  	RCC->PLLCFGR|=(PLL_VCO_Multiplication_Factor<<PLLN);
  	RCC->PLLCFGR|=(PLL_MainClk_Division_Factor<<PLLP);
  	RCC->PLLCFGR|=(PLL_Clk_Source<<PLLSRC);
  	RCC->PLLCFGR|=(PLL_USB_OTG_Division_Factor<<PLLQ);

	
  	RCC->CR|=(RCC_PLL_Mode<<PLLON);

	while(!GET_BIT(RCC->CR,PLLRDY));

	#endif
	
	#if RCC_HSEON_Mode==RCC_Enable

	/*           Clock By Pass Enable         */

  	RCC->CR|=(RCC_HSEYPASS<<HSEBYP);
  	RCC->CR|=(RCC_HSEON_Mode<<HSEON);

	while(!GET_BIT(RCC->CR,HSIRDY));

    #endif
	
	#if RCC_HSION_Mode==RCC_Enable
  	RCC->CR|=(RCC_HSION_Mode<<HSION);

	while(!GET_BIT(RCC->CR,HSERDY));

    #endif	
	
}
  
u8	RCC_u8PeripheralClockEnable(Bus_t RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral)
{
	u8 Local_u8Error=OK;
	if (RCC_u8CopyPeripheral<32)
	{
		switch(RCC_u8CopyBus)
		{
			case RCC_AHB1: SET_BIT(RCC->AHB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_AHB2: SET_BIT(RCC->AHB2ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB1: SET_BIT(RCC->APB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB2: SET_BIT(RCC->APB2ENR,RCC_u8CopyPeripheral);break;
			default : Local_u8Error =NOK;

			
		}
			
	}
	else Local_u8Error =NOK;

	return Local_u8Error;
}

u8	RCC_u8PeripheralClockDisable(Bus_t RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral)
{
	u8 Local_u8Error=OK;

	if (RCC_u8CopyPeripheral<32)
	{
		switch(RCC_u8CopyBus)
		{
			case RCC_AHB1: CLEAR_BIT(RCC->AHB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_AHB2: CLEAR_BIT(RCC->AHB2ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB1: CLEAR_BIT(RCC->APB1ENR,RCC_u8CopyPeripheral);break;
			case RCC_APB2: CLEAR_BIT(RCC->APB2ENR,RCC_u8CopyPeripheral);break;
			default : Local_u8Error =NOK;

			
    	}
	}
	else Local_u8Error =NOK;

		
	return Local_u8Error;
}

