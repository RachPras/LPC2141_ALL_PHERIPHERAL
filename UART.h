/**********************************************************************************************************************************
************************************** FILE NAME   :   UART.h          ***********************************************************
***********************************************************************************************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "Hardware.h"
/***********************************************************************************************************************************/
#define UART0     0
#define UART1     1
#define UART0_RX_INT_ENABLE   
#define UART1_RX_INT_ENABLE  
/**********************  PIN SELECT REGISTERS     ***********************************************************************************/
#define PINSEL_UART0_TXD    PINSEL0 |= 0X00000001       // P0.0 UART0 (TXD)
#define PINSEL_UART0_RXD    PINSEL0 |= 0X00000004       // P0.1 UART0 (RXD)
#define PINSEL_UART1_TXD    PINSEL0 |= 0X00010000       // P0.8 UART1 (TXD)
#define PINSEL_UART1_RXD    PINSEL0 |= 0X00040000       // P0.9 UART1 (RXD)
/************************* UART REGISTERS**************************************************************************/
#define  UART_WRD_LEN      0X00000003                   // 8 bit character length
#define  UART_DLAB_ACC     0X00000080                   // Enable access to Divisor Latches.
#define  UART_FIFO_EN      0X00000001                   // Active high enable for both UART0 Rx and TX
#define  UART_RXFIFO_EN    0X00000002                   // will clear all bytes in UART0 Rx FIFO and reset the pointer logic
#define  UART_TXFIFO_EN    0X00000002                   // will clear all bytes in UART0 Tx FIFO and reset the pointer logic
#define  UART_LSR_RDR		   0x00000001                   // Receiver Data Ready
#define  UART_LSR_OE		   0x00000002                   // Overrun error status
#define  UART_LSR_PE		   0x00000004                   // Parity error status
#define  UART_LSR_FE		   0x00000008                   // Framing error status
#define  UART_LSR_BI		   0x00000010                   // Break interrupt status
#define  UART_LSR_THRE	   0x00000020                   // THRE is set immediately upon detection of an empty UART0 THR
#define  UART_RX_INT 	     0x00000001                   // enables the Receive Data Available interrupt
#define  UART_TX_INT 	     0x00000002                   // enables the THRE interrupt for UART0
/***********************************************************************************************************************************/
void           UARTInit       (uint8_t,uint32_t);
void           UARTSend       (uint8_t,uint32_t ,uint8_t*);
void           UARTSendByte   (uint8_t,uint8_t);
uint8_t        UARTReceiveByte(uint8_t);
void           UARtReceive    (uint8_t,uint32_t , uint8_t*);
__irq void     Uart0ISR       (void);
__irq void     Uart1ISR       (void);


/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/

