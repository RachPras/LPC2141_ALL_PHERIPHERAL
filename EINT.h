/**********************************************************************************************************************************
************************************** FILE NAME   :   EINT.h          ***********************************************************
***********************************************************************************************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "Hardware.h"
/************************* PIN SELECT REGISTERS  ***********************************************************************************/
//#define PIN_EINT0          PINSEL0 |= 0X0000000C       // P0.1   EINT0
  #define PIN_EINT0          PINSEL1 |= 0X00000001       // P0.16  EINT0
	#define PIN_EINT1          PINSEL0 |= 0X000000C0       // P0.3   EINT1
//#define PIN_EINT1          PINSEL0 |= 0X20000000       // P0.14  EINT0
//#define PIN_EINT2          PINSEL0 |= 0X0000C000       // P0.7   EINT2
  #define PIN_EINT2          PINSEL0 |= 0X80000000       // P0.15  EINT2	
//#define PIN_EINT3          PINSEL0 |= 0X000C0000       // P0.9   EINT3
  #define PIN_EINT3          PINSEL1 |= 0X00000300       // P0.20  EINT3
/***************************** EXTERNAL INTERRUPT REGISTERS**************************************************************************/	
#define  EXTMODE0_LVL        0X00000000                  // Level-sensitivity is selected for EINT0.
#define  EXTMODE0_EDG        0X00000001                  // EINT0 is edge sensitive.
#define  EXTMODE1_LVL        0X00000000                  // Level-sensitivity is selected for EINT1.
#define  EXTMODE1_EDG        0X00000002                  // EINT1 is edge sensitive
#define  EXTMODE2_LVL        0X00000000                  // Level-sensitivity is selected for EINT2.
#define  EXTMODE2_EDG        0X00000004                  // EINT2 is edge sensitive.
#define  EXTMODE3_LVL        0X00000000                  // Level-sensitivity is selected for EINT3.
#define  EXTMODE3_EDG        0X00000008                  // EINT3 is edge sensitive.
#define EXTPOLAR0_FE         0X000000000                 // EINT0 is low-active or falling-edge sensitive (depending on EXTMODE0).
#define EXTPOLAR0_RE         0X000000001                 // EINT0 is high-active or rising-edge sensitive (depending on EXTMODE0).
#define EXTPOLAR1_FE         0X000000000                 // EINT1 is low-active or falling-edge sensitive (depending on EXTMODE1).
#define EXTPOLAR1_RE         0X000000002                 // EINT1 is high-active or rising-edge sensitive (depending on EXTMODE1).
#define EXTPOLAR2_FE         0X000000000                 // EINT2 is low-active or falling-edge sensitive (depending on EXTMODE2).
#define EXTPOLAR2_RE         0X000000004                 // EINT2 is high-active or rising-edge sensitive (depending on EXTMODE2).
#define EXTPOLAR3_FE         0X000000000                 // EINT3 is low-active or falling-edge sensitive (depending on EXTMODE3).
#define EXTPOLAR3_RE         0X000000008                 // EINT3 is high-active or rising-edge sensitive (depending on EXTMODE3).
#define CLR_EINT0            0x00000001                  // This bit is cleared by writing a one to it,
#define CLR_EINT1            0x00000002                  // This bit is cleared by writing a one to it,
#define CLR_EINT2            0x00000004                  // This bit is cleared by writing a one to it,
#define CLR_EINT3            0x00000008                  // This bit is cleared by writing a one to it,
/************************************************************************************************************************************/
void EINTInit(uint8_t );
__irq void EINT0ISR(void);
__irq void EINT1ISR(void);
__irq void EINT2ISR(void);
__irq void EINT3ISR(void);
	
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
