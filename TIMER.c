/**********************************************************************************************************************************
************************************** FILE NAME   :   TIMER.c:         ***********************************************************
****   Two 32-bit timers/external event counters (with four capture and four compare channels each), and watchdog. ****************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "HARDWARE.h"
#include "TIMER.h"
/**************************************GLobal variables ******************************************************************************/
uint32_t  Check = 0;                         // global register increment when interrupts occured
/**********************************************************************************************************************************
** Function name   : Timer0Init
** Descriptions    : Initializes the Timer0 it generates the interrupt when MR matches TC  	
** parameters      : None
** Returned value  : None
***********************************************************************************************************************************/
void Timer0Init(void)
{
	T0CTCR        = 0x00000000;	                 // reset timer 
	T0PR          = TIM0_PR_VAL;                 // prescaler value
	T0MR0         = TIM0_MR_VAL;                 // Zero Indexed Count - hence subtracting 1
	T0MCR         = TIM_MROI | TIM_MROR;         // Set bit0 & bit1 to High which is to : Interrupt & Reset TC on MR0  
	VICVectAddr4 |= (unsigned )T0ISR;     			 // Pointer Interrupt Function (ISR)
	VICVectCntl4 |= VEC_IRQ_EN | VEC_IRQ_TIM0; 	 // 0x20 (i.e bit5 = 1) -> to enable Vectored IRQ slot 0x4 (bit[4:0]) -> this the source number - here its timer0 which has VIC channel mask 
	VICIntEnable |= TIM0_INT_EN;                 // Enable timer0 int
	T0TCR         = TIM_CNTRST;          		     // Reset Timer
	T0TCR         = TIM_CNTEN;                   // Enable Timer
}
/**********************************************************************************************************************************
** Function name   : T0ISR
** Descriptions    : Timer0Interrupt service routine  	
** parameters      : None
** Returned value  : None
***********************************************************************************************************************************/
__irq void T0ISR(void)
{
	long int regVal;
	regVal = T0IR; 											         // Read current IR value clear the interrupt register
	Check++;
	T0IR = regVal; 											         // Write back to IR to clear Interrupt Flag
	VICVectAddr = 0x0; 									         // This is to signal end of interrupt execution
}
/**********************************************************************************************************************************
** Function name   : DelayMsec
** Descriptions    : generating delay	
** parameters      : msec(delay count)
** Returned value  : None
***********************************************************************************************************************************/
void Delay_msec(uint32_t msec)
{
	while(Check < msec);                      
	Check = 0; 
}
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/

