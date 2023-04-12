/***************************************************************
/                    Author : Habeba Hamada                    /
/                    LAYER  : MCAL                             /
/                    SWC    : RCC                              /
/                    Version: 1.00                             /
**************************************************************/


#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* options : RCC_Disable                                                                                   */
/*           RCC_Enable                                                                               */
#define RCC_HSION_Mode         RCC_Enable
#define RCC_HSEON_Mode         RCC_Enable
#define RCC_PLL_Mode           RCC_Disable


/* options : RCC_Disable                                                                                   */
/*           RCC_Enable                                                                                  */
#define RCC_HSEYPASS             RCC_Disable

/* Clock Security System PIN configuration as it is set and cleared by software to enable clk security system*/
/* options : DetectorOFF                                                                           */
/*           DetectorON                                                                            */
    
#define RCC_CLOCK_Security        DetectorON

   
 /* Note: you can choose any number from 000010 to 111111 */
#define PLL_InClk_Division_Factor           0b000010

 /* Note: you can choose any number from 011000000 to 110110000 */
#define PLL_VCO_Multiplication_Factor       0b011000000

 /* Note: you can choose any number from 00 to 11 */
#define PLL_MainClk_Division_Factor         0b01

 /* Note: you can choose any number from 0010 to 1111 */
#define PLL_USB_OTG_Division_Factor         0b0010



/* options : HSIClk                                                                                   */
/*           HSEClk                                                                              */
#define PLL_Clk_Source            HSIClk

/* options : RCC_HSI,
	         RCC_HSE,
	         RCC_PLL
*/
#define System_Clock_Source       RCC_HSI

/* options
 *  AHB_NO,
	AHB_PRE_2,
	AHB_PRE_4,
	AHB_PRE_8,
	AHB_PRE_16,
	AHB_PRE_64,
	AHB_PRE_128,
	AHB_PRE_256,
	AHB_PRE_512,
	AHB_Default,   */

#define RCC_AHB_PRESCALER     AHB_Default


/*Options
 *  APB_NO,
	APB_PRE_2,
	APB_PRE_4,
	APB_PRE_8,
	APB_PRE_16,
	APB_Default,

*/
#define RCC_APB1_PRESCALER    APB_PRE_16                    /*Shoudn't excced 84 MHZ*/
#define RCC_APB2_PRESCALER    APB_Default                   /*Shoudn't excced 42 MHZ*/

/*Options MCO1_HSI,
	      MCO1_LSE,
	      MCO1_HSE,
	      MCO1_PLL,
	      MCO1_Default = MCO1_HSI

*/
#define MCO1_Clock_Source   MCO1_Default

/*Options MCO2_SYSCLK,
	      MCO2_PLLI2S,
	      MCO2_HSE,
	      MCO2_PLL,
	      MCO2_Default = MCO2_SYSCLK

*/

#define MCO2_Clock_Source   MCO2_Default

/*Options     No_Division,
	          Division_By_2,
	          Division_By_3,
	          Division_By_4,
              Division_By_5
*/
#define MCO1_Prescaler   Division_By_2
#define MCO2_Prescaler   Division_By_2

#endif
