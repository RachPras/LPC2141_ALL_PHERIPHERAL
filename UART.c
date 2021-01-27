/**********************************************************************************************************************************
************************************** FILE NAME   :   UART.c         *************************************************************
*****       Universal Asynchronous Receiver/Transmitter used for serial communication   
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <lpc214x.h>
#include "HARDWARE.h"
#include "UART.h"
/**********************************************************************************************************************************/
uint8_t  uirb = 0;                             		 // gloabal register awakes when receive interrupt occured.
uint32_t uicnt = 0; 
/**********************************************************************************************************************************
** Function name   : UARTInit
** Descriptions    : Initializes the UART0 and set the baudrate 	
** parameters      : portnumber i.e UART channel(UART0 or UART1),baudrate-> rate at which the data transferd bts/sec(i.e 9600,115200)
** Returned value  : None
***********************************************************************************************************************************/
void UARTInit(uint8_t portnumber, uint32_t baudrate )
{
	unsigned int   Fdiv;
	if(portnumber == 0 )
	{
		PINSEL_UART0_TXD;                           		 // configure pin as  UART0_TXD
		PINSEL_UART0_RXD;                           		 // configure pin as  UART0_RXD
		PCON_UART0;                                 		 // UART0 power/clock control bit.
		U0LCR    = UART_WRD_LEN | UART_DLAB_ACC;				 // 8 bits, no Parity, 1 Stop bit 
		Fdiv     = (SYS_CLK / 16 )/ baudrate ;	    		 // baud rate 
		U0DLM    = Fdiv / 256;							        		 // determines the baud rate of the UART0.
		U0DLL    = Fdiv % 256;                      		 // determines the baud rate of the UART0.
		U0LCR    = UART_WRD_LEN;		                		 // DLAB = 0 
		U0FCR    =(UART_FIFO_EN | UART_RXFIFO_EN |
							 UART_TXFIFO_EN);		               		 // Enable and reset TX and RX FIFO.

			#ifdef UART0_RX_INT_DISABLE                 	 // if UART0 interrupt is required,enable the macro  
				U0IER         =  UART_RX_INT;              	 // Enable RBR interrupt
				VICVectAddr1 |= (unsigned long)Uart0ISR;
				VICVectCntl1 |= VEC_IRQ_EN | VEC_IRQ_UART0;
				VICIntEnable |= UART0_INT_EN;                
			#endif  
	}
	else if(portnumber == 1 )
	{
		PINSEL_UART1_TXD;                            		 // configure pin as  UART1_TXD
		PINSEL_UART1_RXD;                            		 // configure pin as  UART1_RXD
		PCON_UART1;                                  		 // UART0 power/clock control bit.
		U1LCR    = UART_WRD_LEN | UART_DLAB_ACC;		 		 // 8 bits, no Parity, 1 Stop bit
		Fdiv     = (SYS_CLK / 16 )/ baudrate ;	     		 // baud rate 
		U1DLM    = Fdiv / 256;							
		U1DLL    = Fdiv % 256;
		U1LCR    = UART_WRD_LEN;		                 		 // DLAB = 0 
		U1FCR    = (UART_FIFO_EN | UART_RXFIFO_EN |
							  UART_TXFIFO_EN);		             		 // Enable and reset TX and RX FIFO. 
	 
			#ifdef UART1_RX_INT_DISABLE                    // if UART0 interrupt is required,enable the macro    
				U0IER         =  UART_RX_INT;                // Enable RBR interrupt
				VICVectAddr2 |= (unsigned long)Uart1ISR;
				VICVectCntl2 |= VEC_IRQ_EN | VEC_IRQ_UART1;
				VICIntEnable |= UART1_INT_EN;                
      #endif   
	}
}
/**********************************************************************************************************************************
** Function name   : Uart0ISR
** Descriptions    : UART0 Interrupt Sub-Routine	
** parameters      : None(
** Returned value  : None
***********************************************************************************************************************************/
__irq void Uart0ISR(void)
{
	uint32_t regVal;
  regVal = U0IIR;                            // clear interrupt
	uicnt++;
  uirb   = U0RBR;                            // received data
  U0IIR  = regVal;
  VICVectAddr = 0x0;
}
/**********************************************************************************************************************************
** Function name   : Uart1ISR
** Descriptions    : UART1 Interrupt Sub-Routine	
** parameters      : None 
** Returned value  : None
***********************************************************************************************************************************/
__irq void Uart1ISR(void)
{
	uint32_t regVal;
  regVal = U1IIR;                              // clear interrupt
	uicnt++;
  uirb   = U1RBR;                              // received data
	U0IIR  = regVal;
  VICVectAddr = 0x0;
}
/**********************************************************************************************************************************
** Function name   : UARTSendByte
** Descriptions    : Send a the byte to transmit via the serial output pin, TXD.	
** parameters      : portnumber->UART channel(UART0 or UART1), byte->transmitted data)
** Returned value  : None
***********************************************************************************************************************************/
void UARTSendByte(uint8_t portnumber,uint8_t byte)
{
	if(portnumber == 0 )
	{
		while (!(U0LSR & UART_LSR_THRE));                 // wait untill valid data
		U0THR = byte;                                     // The byte will be sent through the Tx line
	}
	if(portnumber == 1 )
	{
		while (!(U1LSR & UART_LSR_THRE));                 // wait untill valid data
		U1THR = byte;                                     // The byte will be sent through the Tx line
	}  
}
/**********************************************************************************************************************************
** Function name   : UARTSend
** Descriptions    : Send a block of data to the UART port based on the data length		
** parameters      : portnumber -> UART channel(UART0 or UART1), length ->number of bytes of data, data->(transmitted character)
** Returned value  : None
***********************************************************************************************************************************/
void UARTSend(uint8_t portnumber, uint32_t length,uint8_t *data)
{
	unsigned char txdata;
	if(portnumber == 0)
	{
		while (length > 0U)
		{
			while (!(U0LSR & UART_LSR_THRE));                // wait untill valid data
			txdata = *data;
			U0THR  = txdata ;                                // The byte will be sent through the Tx line
			data++;
			length--;
		}
	}
	else if(portnumber == 1)
	{
		while (length > 0U)
		{
			while (!(U1LSR & UART_LSR_THRE));                // wait untill valid data
			txdata = *data;
			U1THR  = txdata ;                                // The byte will be sent through the Tx line
			data++;
			length--;
		}
	}
}
/**********************************************************************************************************************************
** Function name   : fputc
** Descriptions    : Place your implementation of fputc here e.g. write a character to the UART,for using "printf function"	
** parameters      : ch, 
** Returned value  : None
***********************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	while (!(U0LSR & UART_LSR_THRE));                     // wait untill valid data
	U0THR = ch;                                           // The byte will be sent through the Tx line
  return ch;
}
/**********************************************************************************************************************************
** Function name   : UARTReceiveByte
** Descriptions    : Receive a byte of data From the serial output pin, TXD.	
** parameters      : portnumber->UART channel(UART0 or UART1)
** Returned value  : received byte
***********************************************************************************************************************************/
uint8_t UARTReceiveByte(uint8_t portnumber)
{
	if(portnumber == 0)
	{
		while((U0LSR & UART_LSR_RDR) == 0U);               // wait untill valid data
		return (U0RBR & (unsigned int)0x000000FFU);        // The byte will be receive through the Tx line
	}
	else if(portnumber == 1)
	{
		while((U1LSR & UART_LSR_RDR) == 0U);               // wait untill valid data
		return (U1RBR & (unsigned int)0x000000FFU);        // The byte will be receive through the Tx line
	}
	return 0;
}
/**********************************************************************************************************************************
** Function name   : UARtReceive
** Descriptions    : Receive the block of data From the UART port	
** parameters      : portnumber->UART channel(UART0 or UART1), length->number of bytes of data, data->(received character)
** Returned value  : None
***********************************************************************************************************************************/
void UARtReceive(uint8_t portnumber,uint32_t length, uint8_t * data)
{
	if(portnumber == 0)
	{
		while (length > 0U)
		{ 
			while ((U0LSR & UART_LSR_RDR) == 0U) ;                 // wait untill valid data
			*data = (U0RBR & (unsigned int)0x000000FFU);           // The byte will be receive through the Tx line
			data++;
			length--;
		}
	}
	else if(portnumber == 1)
	{
		while (length > 0U)
		{ 
			while ((U1LSR & UART_LSR_RDR) == 0U) ;                // wait untill valid data
			*data = (U1RBR & (unsigned int)0x000000FFU);          // The byte will be receive through the Tx line
			data++;
			length--;
		}
	}
}     
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
