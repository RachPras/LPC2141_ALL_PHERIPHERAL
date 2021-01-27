/**********************************************************************************************************************************
************************************** FILE NAME   :   PWM.h:          ***********************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "Hardware.h"
/***********************************************************************************************************************************/
enum 
{
	PWM1 = 1,
	PWM2 = 2,
	PWM3 = 3,
	PWM4 = 4,
	PWM5 = 5,
	PWM6 = 6,
};
/************************* PIN SELECT REGISTERS  ***********************************************************************************/
#define PINSEL_PWM1        PINSEL0 |= 0X00000002   // P0.0  PWM1 
#define PINSEL_PWM2    		 PINSEL0 |= 0X00008000   // P0.7 PWM2 
#define PINSEL_PWM3        PINSEL0 |= 0X00000008   // P0.1  PWM3
#define PINSEL_PWM4        PINSEL0 |= 0X00020000   // P0.8  PWM4
#define PINSEL_PWM5        PINSEL1 |= 0X00000400   // P0.21 PWM5
#define PINSEL_PWM6        PINSEL0 |= 0X00080000   // P0.9  PWM6
/**********************  PWM REGISTERS      ***********************************************************************************/
#define PRESCALEVALUE      0                       // The PWMTC is incremented every PWMPR+1 cycles of PCLK. 
#define PWMCNT_EN          0X00000001              // When one, the PWM Timer Counter and PWM Prescale Counter are enabled for counting
#define PWMCNT_RST         0X00000002              // When one, the PWM Timer Counter and the PWM Prescale Counter are synchronously reset on the nextpositive edge of PCLK.
#define PWM_ENABLE         0X00000008              // When one, PWM mode is enabled. PWM
#define PWM_MR0I           0X00000001              // Interrupt on PWMMR0
#define PWM_MR0R           0X00000002              // Reset on PWMMR0
#define PWM_MR0S           0X00000004              // Stop on PWMMR0
#define PWM_MR1I           0X00000008              // Interrupt on PWMMR1
#define PWM_MR1R           0X00000010              // Reset on PWMMR1
#define PWM_MR1S           0X00000020              // Stop on PWMMR1
#define PWM_MR2I           0X00000040              // Interrupt on PWMMR2
#define PWM_MR2R           0X00000080              // Reset on PWMMR2
#define PWM_MR2S           0X00000100              // Stop on PWMMR2
#define PWM_MR3I           0X00000200              // Interrupt on PWMMR3
#define PWM_MR3R           0X00000400              // Reset on PWMMR3
#define PWM_MR3S           0X00000800              // Stop on PWMMR3
#define PWM_MR4I           0X00001000              // Interrupt on PWMMR4
#define PWM_MR4R           0X00002000              // Reset on PWMMR4
#define PWM_MR4S           0X00004000              // Stop on PWMMR4
#define PWM_MR5I           0X00008000              // Interrupt on PWMMR5
#define PWM_MR5R           0X00010000              // Reset on PWMMR5
#define PWM_MR5S           0X00020000              // Stop on PWMMR5
#define PWM_MR6I           0X00040000              // Interrupt on PWMMR6
#define PWM_MR6R           0X00080000              // Reset on PWMMR6
#define PWM_MR6S           0X00100000              // Stop on PWMMR6
#define PWMSEL2            0x00000004              // Selects double edge controlled mode for the PWM2 output.
#define PWMSEL3            0x00000008              // Selects double edge controlled mode for the PWM3 output.
#define PWMSEL4            0x00000010              // Selects double edge controlled mode for the PWM4 output.
#define PWMSEL5            0x00000020              // Selects double edge controlled mode for the PWM5 output.
#define PWMSEL6            0x00000040              // Selects double edge controlled mode for the PWM6 output.
#define PWMENA1            0x00000200              // The PWM1 output enabled.
#define PWMENA2            0x00000400              // The PWM2 output enabled.
#define PWMENA3            0x00000800              // The PWM3 output enabled.
#define PWMENA4            0x00001000              // The PWM4 output enabled.
#define PWMENA5            0x00002000              // The PWM5 output enabled.
#define PWMENA6            0x00004000              // The PWM6 output enabled.
#define PWM_LATCH1         0X00000001              // The PWM1 Latch enabled.
#define PWM_LATCH2         0X00000002              // The PWM2 Latch enabled.
#define PWM_LATCH3         0X00000004              // The PWM3 Latch enabled.
#define PWM_LATCH4         0X00000008              // The PWM4 Latch enabled.
#define PWM_LATCH5         0X00000010              // The PWM5 Latch enabled.
#define PWM_LATCH6         0X00000020              // The PWM6 Latch enabled.
/**********************************************************************************************************************************/
void PWMPinConfig(void);
void PWMInit(uint32_t );
void GeneratePWM(uint8_t ,uint32_t );
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
