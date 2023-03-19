/*********************************************************************************/
/* Author    : Habeba Hamada                                                       */
/* Version   : V1                                                                  */
/* Date      : 18 Mar 2023                                                         */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

#include "GPIO_interface.h"

// pwm signal is at edge aligned mode

void  PWM_voidSetPinDirection(u8 Copy_u8tim, u8 Copy_u8ch){
switch (Copy_u8tim)
    {
         /*** TIM1 ***/
     case TIM1:
     if (Copy_u8ch == CH1)
	{ 
	//GPIO_A->CRH&=~0x0000000F;
    //GPIO_A->CRH|= 0x0000000B; 	/* PA8: alternate func. output */

    TIM1_CCER |= 1<<0; /* CC1P = 0, CC1E = 1 */
	TIM1_BDTR |=0x8000;						
	TIM1_CCMR1&=~0x00FF;
	TIM1_CCMR1|= 0x0068;  /* OC1M=PWM mode 1, OC1PE=1 */  
	TIM1_CR1  |= 1<<7;	/* Auto reload preload enable */
	
	TIM1_PSC = PSC_TIM1;	
	TIM1_ARR = ARR_TIM1;	
	
	TIM1_EGR |= 1; /* UG = 1 (generate update) */
	TIM1_CR1 |= 0x01; /* timer enable (CEN = 1) */
    }
	
    else if (Copy_u8ch == CH2)
		
    { 
	//GPIO_A->CRH&=~0x000000F0;
  //GPIO_A->CRH|= 0x000000B0; 	/* PA9: alternate func. output */

    TIM1_CCER |= 1<<4; /* CC2P = 0, CC2E = 1 */
	TIM1_BDTR |=0x8000;
	TIM1_CCMR1&=~0xFF00;
	TIM1_CCMR1 |= 0x6800;  /* OC2M=PWM1, OC2PE=1 */  
	TIM1_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM1_PSC = PSC_TIM1;	
	TIM1_ARR = ARR_TIM1;	
	
	TIM1_EGR |= 1; /* UG = 1 (generate update) */
	TIM1_CR1 |= 0x01; /* timer enable (CEN = 1) */
    }
						
	else if (Copy_u8ch == CH3)
    { 
	//GPIO_A->CRH&=~0x00000F00;
    //GPIO_A->CRH|= 0x00000B00; 	/* PA10: alternate func. output */

    TIM1_CCER |= 1<<8; /* CC3P = 0, CC3E = 1 */
	TIM1_BDTR |=0x8000;
	TIM1_CCMR2&=~0x00FF;
	TIM1_CCMR2 |= 0x0068;  /* OC3M=PWM1, OC3PE=1 */  
	TIM1_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM1_PSC = PSC_TIM1;	
	TIM1_ARR = ARR_TIM1;	
	
	TIM1_EGR |= 1; /* UG = 1 (generate update) */
	TIM1_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
	else if (Copy_u8ch == CH4)
     { 
	//GPIO_A->CRH&=~0x0000F000;
    //GPIO_A->CRH|= 0x0000B000; 	/* PA11: alternate func. output */

    TIM1_CCER |= 1<<12; /* CC4P = 0, CC4E = 1 */
	TIM1_BDTR |=0x8000;
	TIM1_CCMR2&=~0xFF00;
	TIM1_CCMR2 |= 0x6800;  /* OC4M=PWM1, OC4PE=1 */  
	TIM1_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM1_PSC = PSC_TIM1;	
	TIM1_ARR = ARR_TIM1;	
	
	TIM1_EGR |= 1; /* UG = 1 (generate update) */
	TIM1_CR1 |= 0x01; /* timer enable (CEN = 1) */
    }
    break;

    /*** TIM2 ***/

    case TIM2:
    if (Copy_u8ch == CH1)
  
	{ 
	//GPIO_A->CRL&=~0x0000000F;
    //GPIO_A->CRL|= 0x0000000B; 	/* PA0: alternate func. output */

    TIM2_CCER |= 1<<0; /* CC1P = 0, CC1E = 1 */
	TIM2_CCMR1&=~0x00FF;
	TIM2_CCMR1 |= 0x0068;  /* OC1M=PWM1, OC1PE=1 */  
	TIM2_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM2_PSC = PSC_TIM2;	
	TIM2_ARR = ARR_TIM2;	
	
	TIM2_EGR |= 1; /* UG = 1 (generate update) */
	TIM2_CR1 |= 0x01; /* timer enable (CEN = 1) */
    }
    else if (Copy_u8ch == CH2)
            { 
	GPIO_A->CRL&=~0x000000F0;
  GPIO_A->CRL|= 0x000000B0; 	/* PA1: alternate func. output */

 
  TIM2_CCER |= 1<<4; /* CC2P = 0, CC2E = 1 */
	TIM2_CCMR1&=~0xFF00;
	TIM2_CCMR1 |= 0x6800;  /* OC2M=PWM1, OC2PE=1 */  
	TIM2_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM2_PSC = PSC_TIM2;	
	TIM2_ARR = ARR_TIM2;	
	
	TIM2_EGR |= 1; /* UG = 1 (generate update) */
	TIM2_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
						
						else if (Copy_u8ch == CH3)
            { 
	GPIO_A->CRL&=~0x00000F00;
  GPIO_A->CRL|= 0x00000B00; 	/* PA2: alternate func. output */

  TIM2_CCER |= 1<<8; /* CC3P = 0, CC3E = 1 */
	TIM2_CCMR2&=~0x00FF;
	TIM2_CCMR2 |= 0x0068;  /* OC3M=PWM1, OC3PE=1 */  
	TIM2_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM2_PSC = PSC_TIM2;	
	TIM2_ARR = ARR_TIM2;	
	
	TIM2_EGR |= 1; /* UG = 1 (generate update) */
	TIM2_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
						else if (Copy_u8ch == CH4)
            { 
	GPIO_A->CRL&=~0x0000F000;
  GPIO_A->CRL|= 0x0000B000; 	/* PA3: alternate func. output */

  TIM2_CCER |= 1<<12; /* CC4P = 0, CC4E = 1 */
	TIM2_CCMR2&=~0xFF00;
	TIM2_CCMR2 |= 0x6800;  /* OC4M=PWM1, OC4PE=1 */  
	TIM2_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM2_PSC = PSC_TIM2;	
	TIM2_ARR = ARR_TIM2;	
	
	TIM2_EGR |= 1; /* UG = 1 (generate update) */
	TIM2_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
            break;

         /*** TIM3 ***/

        case TIM3:
            if (Copy_u8ch == CH1)
  
						{ 
	GPIO_A->CRL&=~0x0F000000;
  GPIO_A->CRL|= 0x0B000000; 	/* PA6: alternate func. output */

  TIM3_CCER |= 1<<0; /* CC1P = 0, CC1E = 1 */
	TIM3_CCMR1&=~0x00FF;
	TIM3_CCMR1 |= 0x0068;  /* OC1M=PWM1, OC1PE=1 */  
	TIM3_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM3_PSC = PSC_TIM3;	
	TIM3_ARR = ARR_TIM3;	
	
	TIM3_EGR |= 1; /* UG = 1 (generate update) */
	TIM3_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
            else if (Copy_u8ch == CH2)
            { 
	GPIO_A->CRL&=~0xF0000000;
  GPIO_A->CRL|= 0xB0000000; 	/* PA7: alternate func. output */

  TIM3_CCER |= 1<<4; /* CC2P = 0, CC2E = 1 */
	TIM3_CCMR1&=~0xFF00;
	TIM3_CCMR1 |= 0x6800;  /* OC2M=PWM1, OC2PE=1 */  
	TIM3_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM3_PSC = PSC_TIM3;	
	TIM3_ARR = ARR_TIM3;	
	
	TIM3_EGR |= 1; /* UG = 1 (generate update) */
	TIM3_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
						
						else if (Copy_u8ch == CH3)
            { 
	GPIO_B->CRL&=~0x0000000F;
  GPIO_B->CRL|= 0x0000000B; 	/* PB0: alternate func. output */

  TIM3_CCER |= 1<<8; /* CC3P = 0, CC3E = 1 */
	TIM3_CCMR2&=~0x00FF;
	TIM3_CCMR2 |= 0x0068;  /* OC3M=PWM1, OC3PE=1 */  
	TIM3_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM3_PSC = PSC_TIM3;	
	TIM3_ARR = ARR_TIM3;	
	
	TIM3_EGR |= 1; /* UG = 1 (generate update) */
	TIM3_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
						else if (Copy_u8ch == CH4)
            { 
	GPIO_B->CRL&=~0x000000F0;
  GPIO_B->CRL|= 0x000000B0; 	/* PB1: alternate func. output */

  TIM3_CCER |= 1<<12; /* CC4P = 0, CC4E = 1 */
	TIM3_CCMR2&=~0xFF00;
	TIM3_CCMR2 |= 0x6800;  /* OC4M=PWM1, OC4PE=1 */  
	TIM3_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM3_PSC = PSC_TIM3;	
	TIM3_ARR = ARR_TIM3;	
	
	TIM3_EGR |= 1; /* UG = 1 (generate update) */
	TIM3_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
            break;
         /*** TIM4 ***/

        case TIM4:
            if (Copy_u8ch == CH1)
  
						{ 
	GPIO_B->CRL&=~0x0F000000;
  GPIO_B->CRL|= 0x0B000000; 	/* PB6: alternate func. output */

  TIM4_CCER |= 1<<0; /* CC1P = 0, CC1E = 1 */
	TIM4_CCMR1&=~0x00FF;
	TIM4_CCMR1 |= 0x0068;  /* OC1M=PWM1, OC1PE=1 */  
	TIM4_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM4_PSC = PSC_TIM4;	
	TIM4_ARR = ARR_TIM4;	
	
	TIM4_EGR |= 1; /* UG = 1 (generate update) */
	TIM4_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
            else if (Copy_u8ch == CH2)
            { 
	GPIO_B->CRL&=~0xF0000000;
  GPIO_B->CRL|= 0xB0000000; 	/* PB7: alternate func. output */

  TIM4_CCER |= 1<<4; /* CC2P = 0, CC2E = 1 */
	TIM4_CCMR1&=~0xFF00;
	TIM4_CCMR1 |= 0x6800;  /* OC2M=PWM1, OC2PE=1 */  
	TIM4_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM4_PSC = PSC_TIM4;	
	TIM4_ARR = ARR_TIM4;	
	
	TIM4_EGR |= 1; /* UG = 1 (generate update) */
	TIM4_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
						
						else if (Copy_u8ch == CH3)
            { 
	GPIO_B->CRH&=~0x0000000F;
  GPIO_B->CRH|= 0x0000000B; 	/* PB8: alternate func. output */

  TIM4_CCER |= 1<<8; /* CC3P = 0, CC3E = 1 */
	TIM4_CCMR2&=~0x00FF;
	TIM4_CCMR2 |= 0x0068;  /* OC3M=PWM1, OC3PE=1 */  
	TIM4_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM4_PSC = PSC_TIM4;	
	TIM4_ARR = ARR_TIM4;	
	
	TIM4_EGR |= 1; /* UG = 1 (generate update) */
	TIM4_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
						else if (Copy_u8ch == CH4)
            { 
	GPIO_B->CRH&=~0x000000F0;
  GPIO_B->CRH|= 0x000000B0; 	/* PB9: alternate func. output */

  TIM4_CCER |= 1<<12; /* CC4P = 0, CC4E = 1 */
	TIM4_CCMR2&=~0xFF00;
	TIM4_CCMR2 |= 0x6800;  /* OC4M=PWM1, OC4PE=1 */  
	TIM4_CR1 |= 1<<7;	/* Auto reload preload enable*/
	
	TIM4_PSC = PSC_TIM4;	
	TIM4_ARR = ARR_TIM4;	
	
	TIM4_EGR |= 1; /* UG = 1 (generate update) */
	TIM4_CR1 |= 0x01; /* timer enable (CEN = 1) */
            }
            break;

				default:       break;
    }



}

void  PWM_voidWrite(u8 Copy_u8tim, u8 Copy_u8ch,u16 Copy_u16dutyCycle){

	switch (Copy_u8tim)
    {
         /*** TIM1 ***/

        case TIM1:
            if (Copy_u8ch == CH1)
             	TIM1_CCR1 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH2)
             	TIM1_CCR2 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH3)
             	TIM1_CCR3 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH4)
             	TIM1_CCR4 = Copy_u16dutyCycle;	
          break;
					/*** TIM2 ***/
	
				case TIM2:
            if (Copy_u8ch == CH1)
             	TIM2_CCR1 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH2)
             	TIM2_CCR2 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH3)
             	TIM2_CCR3 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH4)
             	TIM2_CCR4 = Copy_u16dutyCycle;	
          break;
				/*** TIM3 ***/
				
				case TIM3:
            if (Copy_u8ch == CH1)
             	TIM3_CCR1 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH2)
             	TIM3_CCR2 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH3)
             	TIM3_CCR3 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH4)
             	TIM3_CCR4 = Copy_u16dutyCycle;	
          break;
         /*** TIM4 ***/

				case TIM4:
            if (Copy_u8ch == CH1)
             	TIM4_CCR1 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH2)
             	TIM4_CCR2 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH3)
             	TIM4_CCR3 = Copy_u16dutyCycle;	
						else if (Copy_u8ch == CH4)
             	TIM4_CCR4 = Copy_u16dutyCycle;	
          break;
						
				default: break;

		}

}