/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: LED          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"


#include "../../01-MCAL/02-GPIO/GPIO_interface.h"

#include "LED_interface.h"


void LED_Status(LED_Object Copy_LED,u8 Copy_u8LED_Status)
{
	GPIO_SetPinValue(Copy_LED.LED_Pin, Copy_LED.LED_Port,(Copy_u8LED_Status) ^ (Copy_LED.Connection_Type));
	
}

void LED_Toggle(LED_Object Copy_LED)
{
	static u8 X=0;
	GPIO_SetPinValue(Copy_LED.LED_Pin, Copy_LED.LED_Port,X);
}
