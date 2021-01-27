/**********************************************************************************************************************************
************************************** FILE NAME   :   GPIO.c:          ***********************************************************
****       General Purpose Input/Output ports
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <LPC214X.H>
#include "GPIO.h"
/**********************************************************************************************************************************
** Function name   : GpioInit
** Descriptions    : Initializes the GPIO	port
** parameters      : None
** Returned value  : None
***********************************************************************************************************************************/
void GpioInit(void)
{
  SCS = 0;			                                  // set GPIOx to use regular I/O 
	GpioSetDirection(GPIO0 ,OUTPUT ,13);
	GpioSetDirection(GPIO1 ,OUTPUT ,21);
}
/**********************************************************************************************************************************
** Function name   : GpioSetDirection
** Descriptions    : Individually controls the direction of each port pin.	
** parameters      : portnumber ->(GPIO0,or GPIO1) ,dir ->(INPUT or OUTPUT),bit(bit number)
** Returned value  : None
***********************************************************************************************************************************/
void GpioSetDirection(uint8_t portnumber,uint8_t dir,uint32_t bit)
{
	if(portnumber == 0)
	{
		 IODIR0 |= (dir << bit);                      //  This register individually controls the direction of port0 pin. 
	}
	else if(portnumber == 1)
	{
		 IODIR1 |= (dir << bit);                      //  This register individually controls the direction of port1 pin. 
	}
}
/**********************************************************************************************************************************
** Function name   : GpioSetBit
** Descriptions    : This Function controls the state of output pins.Writing ones produces HIgh at thecorresponding port pins
** parameters      : portnumber ->(GPIO0,or GPIO1) ,bit(bit number) 
** Returned value  : None
***********************************************************************************************************************************/
void GpioSetBit(uint8_t portnumber,uint32_t bit)
{
	if(portnumber == 0)
	{ 
		 IOSET0 |= (1 << bit);                        // This register controls the state of output pins            
	}
	else if(portnumber == 1)
	{
		 IOSET1 |= (1 << bit);                        // This register controls the state of output pins
	}
}
/**********************************************************************************************************************************
** Function name   : GpioClearBit
** Descriptions    : This Function controls the state of output pins.Writing ones produces LOW at the corresponding port pins
** parameters      : portnumber ->(GPIO0,or GPIO1) ,bit(bit number) 
** Returned value  : None
***********************************************************************************************************************************/	
void GpioClearBit(uint8_t portnumber,uint32_t bit)
{
	if(portnumber == 0)
	{
		 IOCLR0 |= (1 << bit);                       // This register controls the state of output pins
	}
	else if(portnumber == 1)
	{
		 IOCLR1 |= (1 << bit);                       // This register controls the state of output pins
	}
}
/**********************************************************************************************************************************
** Function name   : GpioGetBit
** Descriptions    : This Function read the data on the gpio port
** parameters      : portnumber ->(GPIO0,or GPIO1) ,bit(bit number) 
** Returned value  : status of the gpio pin
***********************************************************************************************************************************/	
uint32_t GpioGetBit(uint8_t portnumber, uint32_t bit)
{
	if(portnumber == 0)
	{
		 return (IOPIN0>> bit) & 1U;                 // read the current state of the port0 pins
	}
  else if(portnumber == 1)
	{
		 return (IOPIN1>> bit) & 1U;                 // read the current state of the port10 pins
	}
	return 0;
}
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
