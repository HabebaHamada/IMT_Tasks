/**************************************************************
/                    Author : Habeba Hamada                    /
/                    LAYER  : MCAL                             /
/                    SWC    : RCC                              /
/                    Version: 1.00                             /
**************************************************************/

#ifndef		RCC_INTERFACE_H_
#define		RCC_INTERFACE_H_

typedef enum{
	RCC_AHB1,
	RCC_AHB2,
	RCC_APB1,
	RCC_APB2,
}Bus_t;

typedef enum{  
        RCC_GPIOA,
		RCC_GPIOB,
		RCC_GPIOC,
		RCC_GPIOD,
		RCC_GPIOE,
		RCC_GPIOH=7,
		RCC_CRC =12,
		RCC_DMA1=21,
		RCC_DMA2,
		RCC_OTGFS=7,
		RCC_TIM2=0,
		RCC_TIM3,
		RCC_TIM4,
		RCC_TIM5,
		RCC_WWDG=11,
		RCC_SPI2=14,
		RCC_SPI3,
		RCC_USART2=17,
		RCC_I2C1=21,
		RCC_I2C2,
		RCC_I2C3,
		RCC_PWR=28,
		RCC_TIM1=0,
		RCC_USART1=4,
		RCC_USART6,
		RCC_ADC1=8,
		RCC_SDIO=11,
		RCC_SPI1,
		RCC_SPI4,
		RCC_SYSCFG,
		RCC_TIM9=16,
		RCC_TIM10,
		RCC_TIM11,
}Peripherals_t;

void	RCC_voidSystemClockInit(void);

/*
 * Name       : RCC_u8PeripheralClockEnable
 * RETURN TYPE: u8
 * ARGUMENTS  : RCC_u8CopyBus : Bus_t
 * 			    RCC_u8CopyPer : Peripherals_t
 * DESCRIPTION: enable peripheral clock
 */
u8	RCC_u8PeripheralClockEnable(Bus_t RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral);

/*
 * Name       : RCC_u8PeripheralClockEnable
 * RETURN TYPE: u8
 * ARGUMENTS  : RCC_u8CopyBus : Bus_t
 * 			    RCC_u8CopyPer : Peripherals_t
 * DESCRIPTION: disable peripheral clock
 */
u8	RCC_u8PeripheralClockDisable(Bus_t RCC_u8CopyBus,Peripherals_t RCC_u8CopyPeripheral);

#endif
