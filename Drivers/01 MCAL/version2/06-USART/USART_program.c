/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: USART           ****************/
/*************       Version: 2.00            ****************/
/*************************************************************/


#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_Manipulation.h"


#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

void (*USART1_CallBack)(void);
void (*USART2_CallBack)(void);
void (*USART6_CallBack)(void);

void USART_voidInit(USART_InitType *A_InitStruct,USART_ClockInitTypeDef *A_ClockInitStruct,UART_t USARTx)
{

	/*Equations to calculate BaudRate with Over Sampling 16 */
	u32 LOC_u64Mantissa = ( F_CPU ) / ( 16 * (A_InitStruct->BaudRate) ) ;

	u32 LOC_u64Fraction = ( ( ( F_CPU * 100 ) / ( 16 * (A_InitStruct->BaudRate) )  ) % 100 ) * 16 ;

	if( LOC_u64Fraction > 1500 ){ LOC_u64Mantissa += 1 ; LOC_u64Fraction  = 0 ; }


#if   USARTx==UART1
	/* Set the Baud Rate */
	USART_1 -> BRR = ( LOC_u64Mantissa << 4  ) | ( LOC_u64Fraction / 100 ) ;
	//USART_1->BRR = A_InitStruct->BaudRate;


	USART_1->CR1 = (A_InitStruct->Oversampling << USART_CR1_OVER8)    |
			(A_InitStruct->DataWidth <<USART_CR1_M)                  |
			(A_InitStruct->Parity_Enable <<USART_CR1_PCE)            |
			(A_InitStruct->Parity_Selection <<USART_CR1_PS)          ;

	switch (A_InitStruct->TransferDirection)
	{
	case USART_TX:               SET_BIT(USART_1->CR1, USART_CR1_TE); break;  /* send an idle frame before the first data frame. */
	case USART_RX:               SET_BIT(USART_1->CR1, USART_CR1_RE); break;
	case USART_TX_RX:            SET_BIT(USART_1->CR1, USART_CR1_TE);
	                             SET_BIT(USART_1->CR1, USART_CR1_RE); break;
	}

	USART_1->CR2 =  (A_InitStruct->StopBits<<USART_CR2_STOP)	         |
			(A_ClockInitStruct->ClockOutput <<USART_CR2_CLKEN)       |
			(A_ClockInitStruct->ClockPhase <<USART_CR2_CPHA)         |
			(A_ClockInitStruct->ClockPolarity <<USART_CR2_CPOL)      ;



	/* USART ENABLE     */
	SET_BIT(USART_1->CR1, USART_CR1_UE);

	USART_1->SR=0;

#endif

}


void USART_voidSendByte(UART_t USARTx,u8 Copy_u8Data)
{
#if   USARTx==UART1

	/* wait until transmission data is empty */
	while(GET_BIT(USART_1->SR, USART_SR_TXE) == 0);

	/* put data to data register this step will clear the TXE flag */
	USART_1->DR = Copy_u8Data;

	/* wait until transmission is complete */
	while(GET_BIT(USART_1->SR, USART_SR_TC) == 0);

	/* clear TC flag */
	CLEAR_BIT(USART_1->SR, USART_SR_TC);

#elif USARTx==UART2

	/* wait until transmission data is empty */
	while(GET_BIT(USART_2->SR, USART_SR_TXE) == 0);

	/* put data to data register this step will clear the TXE flag */
	USART_2->DR = Copy_u8Data;

	/* wait until transmission is complete */
	while(GET_BIT(USART_2->SR, USART_SR_TC) == 0);

	/* clear TC flag */
	CLEAR_BIT(USART_2->SR, USART_SR_TC);


#endif


}



void USART_voidSendString (UART_t USARTx, u8* A_ptru8String )
{
	/*Iterator to iterate over the string*/
	u8 local_u8Iterator =0;

	/*while the string is not End*/
	while (A_ptru8String[local_u8Iterator] != '\0')
	{
		/*send string byte by byte*/

        #if   USARTx==UART1
		USART_voidSendByte(UART1, A_ptru8String[local_u8Iterator]);
        #elif   USARTx==UART2
		USART_voidSendByte(UART2, A_ptru8String[local_u8Iterator]);
        #elif   USARTx==UART7
	    USART_voidSendByte(UART7, A_ptru8String[local_u8Iterator]);
        #endif
		local_u8Iterator++;
	}
}


u8   USART_u8ReadDataRegister(UART_t USARTx)
{
#if   USARTx==UART1
	   return USART_1 -> DR;
#elif   USARTx==UART2
	   return USART_2 -> DR;
#elif   USARTx==UART7
	   return USART_7 -> DR;
#endif

}


void USART_voidReceiveByteBlocking(UART_t USARTx, u8* Ptr_u8Data)
{

	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
#if   USARTx==UART1
		/* Wait until Reception is complete */
		while(!(GET_BIT(USART_1->SR, USART_SR_RXNE)));

		/* Store the Data to the Pointer */
		*(Ptr_u8Data) = USART_1->DR;

#elif   USARTx==UART2
		/* Wait until Reception is complete */
		while((GET_BIT(USART_2->SR, USART_SR_RXNE) )== 0);

		/* Store the Data to the Pointer */
		*(Ptr_u8Data) = USART_2->DR;
#endif
	}
	else
	{

	}

}



void USART_voidReceiveDataNonBlocking ( UART_t USARTx, u8* Ptr_u8Data )
{

	u32 loc_u8TimeOut = 0;
	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
		/* Wait until Reception is complete */
		while(((GET_BIT(USART_1->SR, USART_SR_RXNE) )== 0) && (loc_u8TimeOut < THRESHOLD_VALUE))
		{
			loc_u8TimeOut++;
		}

		if (loc_u8TimeOut==THRESHOLD_VALUE)
		{
			*(Ptr_u8Data) =255;
		}
		else
		{
			/* Store the Data to the Pointer */
			*(Ptr_u8Data) = USART_1->DR;
		}
	}
	else
	{

	}
}



void USART1_voidSetCallBack( void (*ptr) (void) )
{
	USART1_CallBack = ptr ;
}

void USART2_voidSetCallBack( void (*ptr) (void) )
{
	USART2_CallBack = ptr ;
}

void USART6_voidSetCallBack( void (*ptr) (void) )
{
	USART6_CallBack = ptr ;
}

void USART1_IRQHandler(void)
{
	USART_1 -> SR = 0 ;
	USART1_CallBack();
}

void USART2_IRQHandler(void)
{
	USART_2 -> SR = 0 ;
	USART2_CallBack();
}

void USART6_IRQHandler(void)
{
	USART_6 -> SR = 0 ;
	USART6_CallBack();
}
