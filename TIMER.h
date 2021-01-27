/**********************************************************************************************************************************
************************************** FILE NAME   :   TIMER.h:          ***********************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "Hardware.h"
/**********************  PIN SELECT REGISTERS     ***********************************************************************************/
  #define PINSEL_CAP0_0        PINSEL0 |= 0X00000020       // P0.2   CAP0.0 
//#define PINSEL_CAP0_0        PINSEL0 |= 0X00002000       // P0.22  CAP0.0  
//#define PINSEL_CAP0_0        PINSEL0 |= 0X30000000       // P0.30  CAP0.0  
  #define PINSEL_CAP0_1        PINSEL0 |= 0X00000200       // P0.4   CAP0.1 
  #define PINSEL_CAP0_2        PINSEL0 |= 0X00002000       // P0.6   CAP0.2
//#define PINSEL_CAP0_2        PINSEL1 |= 0X00000003       // P0.16  CAP0.2
//#define PINSEL_CAP0_2        PINSEL1 |= 0X02000000       // P0.28  CAP0.2
  #define PINSEL_CAP0_3        PINSEL1 |= 0X08000000       // P0.29  CAP0.3
  #define PINSEL_CAP1_0        PINSEL0 |= 0X00200000       // P0.10  CAP1.0 
  #define PINSEL_CAP1_1        PINSEL0 |= 0X00800000       // P0.11  CAP1.1
  #define PINSEL_CAP1_2        PINSEL1 |= 0X00000004       // P0.17  CAP1.2
//#define PINSEL_CAP1_2        PINSEL1 |= 0X000000C0       // P0.19  CAP1.2
  #define PINSEL_CAP1_3        PINSEL1 |= 0X00000010       // P0.18  CAP1.3
//#define PINSEL_CAP1_3        PINSEL1 |= 0X00000C00       // P0.21  CAP1.3
  #define PINSEL_MAT0_0        PINSEL0 |= 0X00000080       // P0.3  MAT0.0
//#define PINSEL_MAT0_0        PINSEL1 |= 0X00003000       // P0.22 MAT0.0
  #define PINSEL_MAT0_1        PINSEL0 |= 0X00000800       // P0.5  MAT0.1
  #define PINSEL_MAT0_2        PINSEL1 |= 0X00000002       // P0.16 MAT0.2
//#define PINSEL_MAT0_2        PINSEL1 |= 0X03000000       // P0.28 MAT0.2
	#define PINSEL_MAT0_3        PINSEL1 |= 0X0C000000       // P0.29 MAT0.3
  #define PINSEL_MAT1_0        PINSEL0 |= 0X02000000       // P0.12  MAT1.0
  #define PINSEL_MAT1_1        PINSEL0 |= 0X08000000       // P0.13  MAT1.1
	#define PINSEL_MAT1_2        PINSEL1 |= 0X0000000C       // P0.17  MAT1.2
//#define PINSEL_MAT1_2        PINSEL1 |= 0X00000040       // P0.19  MAT1.2
	#define PINSEL_MAT1_3        PINSEL1 |= 0X00000030       // P0.18  MAT1.3
//#define PINSEL_MAT1_3        PINSEL1 |= 0X00000100       // P0.20  MAT1.3
/***************************** TIMER/COUNTER REGISTERS**************************************************************************/
#define TIM0_PR_VAL            60                          // Every PCLK TC wiil incremented
#define TIM0_MR_VAL            1000                        //  When TC matches MR value event occurs
#define TIM_CNTEN              0X00000001                  // When one, the Timer Counter and Prescale Counter are enabled for counting 
#define TIM_CNTRST             0X00000002                  // When one, the Timer Counter and the Prescale Counterare synchronously reset
#define TIM_TIM_MOD            0X00000000                  // Timer Mode: every rising PCLK edge  
#define TIM_CAP_MOD            0X00000001                  // Counter Mode: TC is incremented on rising edges on the CAP input selected by bits 3:2.
#define TIM_INSEL_CAP0         0X00000000                  // CAPn.0 (CAP0.0 for TIMER0 and CAP1.0 for TIMER1)
#define TIM_INSEL_CAP1         0X00000004                  // CAPn.1 (CAP0.1 for TIMER0 and CAP1.1 for TIMER1)
#define TIM_INSEL_CAP2         0X00000008                  // CAPn.0 (CAP0.0 for TIMER0 and CAP1.0 for TIMER1)
#define TIM_INSEL_CAP3         0X0000000C                  // CAPn.1 (CAP0.1 for TIMER0 and CAP1.1 for TIMER1)
#define TIM_MROI               0X00000001                  // Interrupt on MR0:
#define TIM_MROR               0X00000002                  // Reset on MR0:
#define TIM_MROS               0X00000004                  // Stop on MR0:
#define TIM_MR1I               0X00000008                  // Interrupt on MR1:
#define TIM_MR1R               0X00000010                  // Reset on MR1:
#define TIM_MR1S               0X00000020                  // Stop on MR1:
#define TIM_MR2I               0X00000040                  // Interrupt on MR2:
#define TIM_MR2R               0X00000080                  // Reset on MR2:
#define TIM_MR2S               0X00000100                  // Stop on MR2:
#define TIM_MR3I               0X00000200                  // Interrupt on MR3:
#define TIM_MR3R               0X00000400                  // Reset on MR3:
#define TIM_MR3S               0X00000800                  // Stop on MR3:
#define TIM_CAP0RE             0X00000001                  // Capture on CAPn.0 rising edge
#define TIM_CAP0FE             0X00000002                  // Capture on CAPn.0 falling edge:
#define TIM_CAP0I              0X00000004                  // Interrupt on CAPn.0 event:
#define TIM_CAP1RE             0X00000008                  // Capture on CAPn.1 rising edge
#define TIM_CAP1FE             0X00000010                  // Capture on CAPn.1 falling edge:
#define TIM_CAP1I              0X00000020                  // Interrupt on CAPn.1 event:
#define TIM_CAP2RE             0X00000040                  // Capture on CAPn.2 rising edge
#define TIM_CAP2FE             0X00000080                  // Capture on CAPn.2 falling edge:
#define TIM_CAP2I              0X00000100                  // Interrupt on CAPn.2 event:
#define TIM_CAP3RE             0X00000200                  // Capture on CAPn.3 rising edge
#define TIM_CAP3FE             0X00000400                  // Capture on CAPn.3 falling edge:
#define TIM_CAP3I              0X00000800                  // Interrupt on CAPn.3 event:
#define TIM_EM0                0X00000001                  // External Match 0.
#define TIM_EM1                0X00000002                  // External Match 0.
#define TIM_EM2                0X00000004                  // External Match 0.
#define TIM_EM3                0X00000008                  // External Match 0.
#define TIM_EMC0_DN            0X00000000                  // External Match Control 0.Do Nothing.
#define TIM_EMC0_CLR           0X00000010                  // External Match Control 0.Clear the corresponding External Match bit/output
#define TIM_EMC0_SET           0X00000020                  // External Match Control 0.Set the corresponding External Match bit/output to 1
#define TIM_EMC0_TOG           0X00000030                  // External Match Control 0.Toggle the corresponding External Match bit/output.
#define TIM_EMC1_DN            0X00000000                  // External Match Control 1.Do Nothing.
#define TIM_EMC1_CLR           0X00000040                  // External Match Control 1.Clear the corresponding External Match bit/output 
#define TIM_EMC1_SET           0X00000080                  // External Match Control 1.Set the corresponding External Match bit/output to 1
#define TIM_EMC1_TOG           0X000000C0                  // External Match Control 1 Toggle the corresponding External Match bit/output.
#define TIM_EMC2_DN            0X00000000                  // External Match Control 2.Do Nothing.
#define TIM_EMC2_CLR           0X00000100                  // External Match Control 2.Clear the corresponding External Match bit/output 
#define TIM_EMC2_SET           0X00000200                  // External Match Control 2.Set the corresponding External Match bit/output to 1
#define TIM_EMC2_TOG           0X00000300                  // External Match Control 2.Toggle the corresponding External Match bit/output.
#define TIM_EMC3_DN            0X00000000                  // External Match Control 3.Do Nothing.
#define TIM_EMC3_CLR           0X00000400                  // External Match Control 3.Clear the corresponding External Match bit/output 
#define TIM_EMC3_SET           0X00000800                  // External Match Control 3.Set the corresponding External Match bit/output to 1
#define TIM_EMC3_TOG           0X00000C00                  // External Match Control Toggle the corresponding External Match bit/output.
/***********************************************************************************************************************************/
void       Delay_msec   (uint32_t);
void       Timer0Init  (void);
__irq void T0ISR       (void);

void Timer1CaptureInit(void);
__irq void timer1ISR(void);
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/

