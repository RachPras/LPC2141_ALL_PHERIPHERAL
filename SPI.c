/**********************************************************************************************************************************
************************************** FILE NAME   :   SPI .c:         ***********************************************************
****   Serial pheripheral interface : is a full duplex serial interfaces. ***************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "HARDWARE.h"
#include "SPI.h"
#include "GPIO.h"
/**********************************************************************************************************************************
** Function name   : SPIInit
** Descriptions    : Initializes the SPI 	
** parameters      : portnumber ->(SPI0 or SPI1)
** Returned value  : None
***********************************************************************************************************************************/
void SPIInit(uint8_t portnumber)
{
	if(portnumber == 0)
	{
		PINSEL_SPI0_CS;                                    		// chip select configure as gpio pn
		PINSEL_SPI0_MOSI;                                  		// 
		PINSEL_SPI0_MISO;                                 		//
		PINSEL_SPI0_SCLK;                                  		//
		S0SPCR  = (SPI_CR_8BIT | SPI_CR_CPHA_FCLK |
							 SPI_CR_CPOL_AH | SPI_CR_MSTR|
            	 SPI_CR_MSBF);                           		// SPI Master mode, 8-bit data, SPI0 mode 
		S0SPCCR = SPI_CCR;                                 		// Even number, minimum value 8, pre scalar for SPI Clock =60Mhz/16
	  GpioSetDirection(GPIO0,OUTPUT,7);                    	// Set chip select direction as output
	}
	else if(portnumber == 1)
	{
		PINSEL_SPI1_CS;                                    		// select as a gpio pin P0.20
		PINSEL_SPI1_MOSI;                                 	  //
		PINSEL_SPI1_MISO;                                  		//
		PINSEL_SPI1_SCLK;                                  		//
		SSPCR0  = (SSP_CR0_DSS_16BIT | SSP_CR0_FRP_SPI|
		           SSP_CR0_CPOL_FCLK | SSP_CR0_CPHA_HBF | 
		           SSP_CR0_SCR);                           		// SPI Master mode, 8-bit data, SPI0 mode /
		SSPCR1  = (SSP_CR1_LBM_DIS | SSP_CR1_SSE_EN|
		           SSP_CR1_MSTR);                         
		SSPCPSR =  SSP_CPSR_CPSDVSR;                       		//  Clock =PCLK / (SSP_CPSR_CPSDVSR * [SSP_CR0_SCR+1]).
  	GpioSetDirection(GPIO0,OUTPUT,20);                	  //  Set chip select direction as output
	}
} 
/**********************************************************************************************************************************
** Function name   : SPISendData
** Descriptions    : send the data throug SPI (Master out slave in pin)	
** parameters      : portnumber(spi channel),blocksize(No .of byte to be sent),uint8_t(data packets)
** Returned value  : None
***********************************************************************************************************************************/
void SPISendData(uint8_t portnumber,uint32_t blocksize ,uint16_t *txdata)
{
	if(portnumber == 0)
	{
		while(blocksize != 0)
		{
			S0SPDR = *txdata;                         	            // Load data to be written into the data register
			while ((S0SPSR & SPI_CR_SPIE) == 0 );                   // Wait till data transmission is completed 
			txdata++;
			blocksize--;
		}
	}
	else if(portnumber == 1)
	{                      
		while(blocksize != 0)
		{
			SSPDR = *txdata;                         	               // Load data to be written into the data register
			while ( (SSPSR & (SSP_SR_TNF|SSP_SR_BSY))!= SSP_SR_TNF); // Wait till data transmission is completed
			txdata++;
			blocksize--;
		}
	}
}
/**********************************************************************************************************************************
** Function name   : SPIReceiveData
** Descriptions    : receviethe data from SPI (Master in slave out pin)	
** parameters      :  portnumber(spi channel),blocksize(No .o fbyte to be received )
** Returned value  : None
***********************************************************************************************************************************/
void SPIReceiveData(uint8_t portnumber, uint32_t blocksize,uint16_t *rxdata)
{
	if(portnumber == 0)
	{
		while(blocksize != 0)
		{
			while((S0SPSR & SPI_CR_SPIE) == 0);     	                // Wait till data transmission is completed 
	   *rxdata = S0SPDR;                              	          // store the data
			rxdata++;
			blocksize--;
		}
	}
	else if(portnumber == 1)
	{
		while(blocksize != 0)
		{
			 while ( (SSPSR & (SSP_SR_RNE|SSP_SR_BSY)) != SSP_SR_RNE ); // Wait until the Busy bit is cleared 
		   *rxdata = SSPDR;                         	                // store the data
			 rxdata++;
			 blocksize--;
		}
	}
}
/**********************************************************************************************************************************
** Function name   : ReadEncoder
** Descriptions    : This Function is used for read the encoder value in MASTER-CONTROLLER Project
**                   IC -AS048A(High-Resolution Position Sensor-bit rotary position  sensor),SPI interface
**                   Choose suitable SPI port according to your design (SPI0 allow to send 8 to 11 bit of data 
**                   at a time).For using SPI1/SSP you would send 16 bit of data at a time.
** parameters      : None
** Returned value  : Encoder Value
***********************************************************************************************************************************/
uint16_t ReadEncoder()
{
	uint16_t en_txdata[1] = {0XFFFF};
	uint16_t en_rxdata[1],Encoder =0;
	SPISendData(SPI1,1 ,(uint16_t*)en_txdata);                           //  Read Angle
	SPIReceiveData(SPI1,1 ,(uint16_t*)en_rxdata);                 
	Encoder = (en_rxdata[0]& 0x3FFF);
	return Encoder;
}

/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
