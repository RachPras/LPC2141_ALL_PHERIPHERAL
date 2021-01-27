/**********************************************************************************************************************************
************************************** FILE NAME   :   PWM.c:         ***********************************************************
*******                               Pulse Width Modulator  
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "HARDWARE.h"
#include "PWM.h"

/**********************************************************************************************************************************
** Function name   : PWMInit
** Descriptions    : Initialise the PWM block
** parameters      : period -> (i.e frequency of the PWM)
** Returned value  : None
***********************************************************************************************************************************/	
void PWMInit(uint32_t period)
{
	PCON_PWM0;                                            // Power On PWM module
	PINSEL_PWM2;                           			          // Configure the necessary pin as a PWM
	PINSEL_PWM5;                           			          // Configure the necessary pin as a PWM
	PWMMR0 = (SYS_CLK) / ((PRESCALEVALUE+1) * period) ;   // Set PWM periof
	PWMPR  =  PRESCALEVALUE;                              // The PWMTC is incremented every PWMPR+1 cycles of PCLK
	PWMMCR = (PWM_MR1R);                                  // Reset PWMTC on PWMMR0 match
	PWMLER = (PWM_LATCH1 | PWM_LATCH2 | PWM_LATCH3 | 
						PWM_LATCH4 | PWM_LATCH5| PWM_LATCH6);       // update MR0,MR1,MR0,MR1,MR0,MR1
	PWMPCR = (PWMENA1 | PWMENA2 | PWMENA3 | 
						PWMENA4 | PWMENA5 | PWMENA6 );              // enable PWM output
	PWMTCR = (PWMCNT_RST) ;                               // Reset PWM TC & PR
	PWMTCR = (PWMCNT_EN | PWM_ENABLE);    	              // Enable counter      
}
/**********************************************************************************************************************************
** Function name   : GeneratePWM
** Descriptions    : Generate the PWM on the selected channel
** parameters      : pwmnumber ->PWM channel Number,dutycycle ->(dutycycle of the PWM Signal)
** Returned value  : None
***********************************************************************************************************************************/
void GeneratePWM(uint8_t pwmnumber ,uint32_t dutycycle)
{
	  if     (pwmnumber == 1)PWMMR1 =(PWMMR0 *dutycycle)/100;     // Set the dutycycle of PWM1
		else if(pwmnumber == 2)PWMMR2 =(PWMMR0 *dutycycle)/100;     // Set the dutycycle of PWM2
		else if(pwmnumber == 3)PWMMR3 =(PWMMR0 *dutycycle)/100;     // Set the dutycycle of PWM3
		else if(pwmnumber == 4)PWMMR4 =(PWMMR0 *dutycycle)/100;     // Set the dutycycle of PWM4  
		else if(pwmnumber == 5)PWMMR5 =(PWMMR0 *dutycycle)/100;     // Set the dutycycle of PWM5
    else if(pwmnumber == 6)PWMMR6 =(PWMMR0 *dutycycle)/100;     // Set the dutycycle of PWM6 		
}
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
