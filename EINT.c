/**********************************************************************************************************************************
************************************** FILE NAME   :   EINT.c:          ***********************************************************
***          EINT the level or edge on that pin will set its interrupt flag in this register
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <LPC214X.H>
#include "HARDWARE.h"
#include "EINT.h"
/************************************  Global variables **************************************************************************/
int volatile EInt0_Count	=	0,EInt1_Count	=	0,EInt2_Count	=	0,EInt3_Count	=	0; // register awakes whemn interrupts occured
/**********************************************************************************************************************************
** Function name   : EINTInit
** Descriptions    : Initializes the External interrupt pins and register		
** parameters      : eintnumber -> external interrupt number
** Returned value  : None
***********************************************************************************************************************************/
void EINTInit(uint8_t eintnumber)
{
	switch(eintnumber)
	{
		case 0:
			EXTMODE  |= EXTMODE0_EDG;										     // Edge sensitive mode on EINT1
			EXTPOLAR |= EXTPOLAR0_FE;									       // Falling Edge Sensitive
			PIN_EINT0;													             // Enable EINT1 on P0.15
			VICVectCntl5 |= VEC_IRQ_EN | VEC_IRQ_EINT0;			 // Use VIC0 for EINT1 ; 15 is index of EINT2
			VICVectAddr5 |= (unsigned long) EINT0ISR;		     // Set Interrupt Vec Addr in VIC0
			VICIntEnable |= EINT0_INT_EN;								     // Enable EINT0
		break;
		case 1:
			EXTMODE  |= EXTMODE1_EDG;										     // Edge sensitive mode on EINT1
			EXTPOLAR |= EXTPOLAR1_FE;									       // Falling Edge Sensitive
			PIN_EINT1;													             // Enable EINT1 on P0.15
			VICVectCntl6 |= VEC_IRQ_EN | VEC_IRQ_EINT1;			 // Use VIC0 for EINT1 ; 15 is index of EINT2
			VICVectAddr6 |= (unsigned long) EINT1ISR;		     // Set Interrupt Vec Addr in VIC0
			VICIntEnable |= EINT1_INT_EN;								     // Enable EINT0
		break;
		case 2:
			EXTMODE  |= EXTMODE2_EDG;										     // Edge sensitive mode on EINT1
			EXTPOLAR |= EXTPOLAR2_FE;									       // Falling Edge Sensitive
			PIN_EINT2;													             // Enable EINT1 on P0.15
			VICVectCntl7 |= VEC_IRQ_EN | VEC_IRQ_EINT2;			 // Use VIC0 for EINT1 ; 15 is index of EINT2
			VICVectAddr7 |= (unsigned long) EINT2ISR;		     // Set Interrupt Vec Addr in VIC0
			VICIntEnable |= EINT2_INT_EN;								     // Enable EINT0
		break;
		case 3:
			EXTMODE  |= EXTMODE3_EDG;										     // Edge sensitive mode on EINT1
			EXTPOLAR |= EXTPOLAR3_FE;									       // Falling Edge Sensitive
			PIN_EINT3;													             // Enable EINT1 on P0.15
			VICVectCntl8 |= VEC_IRQ_EN | VEC_IRQ_EINT3;			 // Use VIC0 for EINT1 ; 15 is index of EINT2
			VICVectAddr8 |= (unsigned long) EINT3ISR;		     // Set Interrupt Vec Addr in VIC0
			VICIntEnable |= EINT3_INT_EN;								     // Enable EINT0
		break;
			
	}
}
/**********************************************************************************************************************************
** Function name   : EINT0ISR
** Descriptions    : EIN0 Interrupt Sub-Routine	
** parameters      : None( 
** Returned value  : None
***********************************************************************************************************************************/
__irq void EINT0ISR(void)
{
	++EInt0_Count;
	EXTINT |= CLR_EINT0;
	VICVectAddr = 0;
}
/**********************************************************************************************************************************
** Function name   : EINT1ISR
** Descriptions    : EIN1 Interrupt Sub-Routine	
** parameters      : None( 
** Returned value  : None
***********************************************************************************************************************************/
__irq void EINT1ISR(void)
{
	++EInt1_Count;
	EXTINT |= CLR_EINT1;
	VICVectAddr = 0;
}
/**********************************************************************************************************************************
** Function name   : EINT2ISR
** Descriptions    : EIN2 Interrupt Sub-Routine	
** parameters      : None( 
** Returned value  : None
***********************************************************************************************************************************/
__irq void EINT2ISR(void)
{
	++EInt2_Count;
	EXTINT |= CLR_EINT2;
	VICVectAddr = 0;
}
/**********************************************************************************************************************************
** Function name   : EINT3ISR
** Descriptions    : EIN3 Interrupt Sub-Routine	
** parameters      : None( 
** Returned value  : None
***********************************************************************************************************************************/
__irq void EINT3ISR(void)
{
	++EInt3_Count;
	EXTINT |= CLR_EINT3;
	VICVectAddr = 0;
}


/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
