/**********************************************************************************************************************************
************************************** FILE NAME   :   SPI.h          ***********************************************************
***********************************************************************************************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "Hardware.h"
/***********************************************************************************************************************************/
#define SPI0                 0
#define SPI1                 1
/**********************  PIN SELECT REGISTERS     ***********************************************************************************/
#define PINSEL_SPI0_CS      PINSEL0 |= 0X00000000          // P0.7 SPI0 CS(select as gpio)
#define PINSEL_SPI0_MOSI    PINSEL0 |= 0X00001000          // P0.6 SPI0 MOSI
#define PINSEL_SPI0_MISO    PINSEL0 |= 0X00000400          // P0.5 SPI0 MISO
#define PINSEL_SPI0_SCLK    PINSEL0 |= 0X00000100          // P0.4 SPI0 SCK
#define PINSEL_SPI1_CS      PINSEL1 |= 0X00000000          // P0.20 SPI1 CS
#define PINSEL_SPI1_MOSI    PINSEL1 |= 0X00000080          // P0.19 SPI1 MOSI
#define PINSEL_SPI1_MISO    PINSEL1 |= 0X00000020          // P0.18 SPI1 MISO
#define PINSEL_SPI1_SCLK    PINSEL1 |= 0X00000008          // P0.17 SPI1 SCK
/************************* SPI  REGISTERS**************************************************************************/
#define SPI_CR_8BIT         0X00000000                     // The SPI controller sends and receives 8 bits of data per transfer.
#define SPI_CR_11BIT        0X00000002                     // The SPI controller sends and receives the number of bits selected by bits 11:8.
#define SPI_CR_CPHA_FCLK    0X00000000                     // Data is sampled on the first clock edge of 
#define SPI_CR_CPHA_SCLK    0X00000004                     // Data is sampled on the Scond clock edge of SCK
#define SPI_CR_CPOL_AH      0X00000000                     // SCK is active high.
#define SPI_CR_CPOL_AL      0X00000008                     // SCK is active LOW.
#define SPI_CR_MSTR         0X00000020                     // The SPI operates in Master mode.
#define SPI_CR_SLAV         0X00000000                     // The SPI operates in Slave mode.
#define SPI_CR_LSBF         0X00000040                     // SPI data is transferred LSB (bit 0) first.
#define SPI_CR_MSBF         0X00000000                     // SPI data is transferred MSB(bit 0) first.
#define SPI_CR_SPIE         0X00000080                     // A hardware interrupt is generated each time the SPIF or MODF bits are activated

#define SPI_SR_ABRT         0X00000008                     // Slave abort. When 1, this bit indicates that a slave abort has occurred.
#define SPI_SR_MODF         0X00000010                     // when 1, this bit indicates that a Mode fault error has occurred.
#define SPI_SR_ROVR         0X00000020                     // Read overrun. When 1, this bit indicates that a read overrun has occurred.
#define SPI_SR_WCOL         0X00000040                     // When 1, this bit indicates that a write collisionhas occurred.
#define SPI_SR_SPIF         0X00000080                     //  When 1, this bit indicates a SPI data transfer is complete.
#define SPI_CCR             0X00000010                     // The value of this register must always be an even number
                                                           // The value of the register must also always be greater than or equal to 8.
																													 // The SPI0 rate may be calculated as: PCLK / SPCCR0 value
/************************* SSP  REGISTERS**************************************************************************/
#define SSP_CR0_DSS_4BIT   0X00000003                      // Data Size Select,4 bit transfer 
#define SSP_CR0_DSS_8BIT   0X00000007                      // Data Size Select,8 bit transfer
#define SSP_CR0_DSS_16BIT  0X0000000F                      // Data Size Select,16 bit transfer
#define SSP_CR0_FRP_SPI    0X00000000                      // Frame Format,SPI 
#define SSP_CR0_FRP_SSI    0X00000010                      // Frame Format,SSI
#define SSP_CR0_CPOL_FCLK  0X00000000                      // Clock Out Polarity..SSP controller captures serial data on the first clock transition of the frame
#define SSP_CR0_CPOL_SCLK  0X00000040                      // Clock Out Polarity..SSP controller captures serial data on the Second clock transition of the frame
#define SSP_CR0_CPHA_HBF   0X00000080                      // Clock Out Phase. This bit is only used in SPI mode. SSP controller maintains the bus clock HIGH between frames.
#define SSP_CR0_CPHA_LBF   0X00000000                      // Clock Out Phase. This bit is only used in SPI mode. SSP controller maintains the bus clock low between frames.
#define SSP_CR0_SCR        0X00000100                      // Serial Clock Rate..the bit frequency is PCLK / (CPSDVSR * [SCR+1]).

#define SSP_CR1_LBM_EN     0X00000001                      // Loop Back Mode enabled
#define SSP_CR1_LBM_DIS    0X00000000                      // .During normal operation.
#define SSP_CR1_SSE_EN     0X00000002                      // The SSP controller will interact with other devices on the serial bus.                  
#define SSP_CR1_SSE_DIS    0X00000000                      // The SSP controller is disabled.
#define SSP_CR1_MSTR       0X00000000                      // This bit can only be written when the SSE bit is 0.MASTER MODE
#define SSP_CR1_SLAV       0X00000004                      // This bit can only be written when the SSE bit is 0.SLAVE MODE  

#define SSP_SR_TFE         0X00000001                      // Transmit FIFO Empty. This bit is 1 is the Transmit FIFO is empty
#define SSP_SR_TNF         0X00000002                      // Transmit FIFO Not Full. This bit is 0 if the Tx FIFO is full, 1 if not
#define SSP_SR_RNE         0X00000004                      // Receive FIFO Not Empty. This bit is 0 if the Receive FIFO is empty, 1 if not.
#define SSP_SR_RFF         0X00000008                      // Receive FIFO Full. This bit is 1 if the Receive FIFO is full, 0 if not.
#define SSP_SR_BSY         0X00000010                      // Busy. This bit is 0 if the SSP controller is idle
#define SSP_CPSR_CPSDVSR   0x00000008                      // This even value between 2 and 254
/**********************************************************************************************************************************/
void   SPIInit        (uint8_t);
void   SPISendData    (uint8_t,uint32_t  ,uint16_t *);
void   SPIReceiveData (uint8_t,uint32_t , uint16_t *);
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
