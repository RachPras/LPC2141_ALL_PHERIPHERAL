/**********************************************************************************************************************************
************************************** FILE NAME   :   HARDWARE.c:         ***********************************************************
****        setup the CLK of the microcontroller, and Initializes the watchdog timer 
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <lpc214x.h>
#include "HARDWARE.h"
/**********************************************************************************************************************************
** Function name   : SystemInit
** Descriptions    : PLL0 has been setup with CCLK = 60Mhz,User may change it as needed
**                   The PLL output frequency PCLK = [(PLL_MVAL) × FOSC] or CCLK = FCCO / (2 × PLL_DVAL)
**                   FOSC -> is in the range of the crystsl connected to the target board (i.e -> 10 MHz to 25 MHz).
**                   FCCO -> is in the range of 156 MHz to 320 MHz.
** parameters      : None
** Returned value  : None
***********************************************************************************************************************************/
void SystemInit(void)
{
	PLL0CON    = PLL_EN;                      // PLL Enable
	PLL0CFG    = PLL_MVAL|PLL_DVAL;	          // MSEL  = 5 PLL Multiplier value. PSEL =2 PLL Divider value
	PLL0FEED   = 0xAA;                        // PLL Feed Register.
	PLL0FEED   = 0x55;                        // PLL Feed Register.
	while(!(PLL0STAT & PLL_LOCK));            // wait untill PLL is locked
	PLL0CON    = PLL_EN|PLL_CNCT;             // PLL Enable And connect 
	PLL0FEED   = 0xAA;                        // PLL Feed Register.
	PLL0FEED   = 0x55;                        // PLL Feed Register.
	VPBDIV     = VP_DIVAL;                    // Controls the rate of the VPB clock in relation to the processor clock
}
/**********************************************************************************************************************************
** Function name   : WatchdogInit
** Descriptions    : Wathdog initialisation(it is a piece of hardware it automatically reset the system,if th software hangs.)
** parameters      : None
** Returned value  : None
***********************************************************************************************************************************/
void WatchdogInit(void)
{
	WDMOD    = WDMOD_EN;                      // Watchdog Reset Mode: operate with the watchdog interrupt and WDRESET enabled.
	WDTC     = (WD_RST_TIME*WD_CLK_FRQ)/4;    // watchdog reset time = (1/SYS_CLK)*4*(required count) (1sec)
	WatchdogTrigger();
}
/**********************************************************************************************************************************
** Function name   : WatchdogTrigger
** Descriptions    : Feed the constant value 
** parameters      : None
** Returned value  : None
***********************************************************************************************************************************/
void WatchdogTrigger(void)
{
	WDFEED = 0xAA;                              // Start the watchdog by writing 0xAA followed by 0x55 to the WDFEED register.
	WDFEED = 0X55;
}


/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/

