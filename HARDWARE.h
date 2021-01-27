/**********************************************************************************************************************************
************************************** FILE NAME   :   HARDWARE.h          *********************************************************
***********************************************************************************************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
/**********************************************************************************************************************************/
#define PWM_FRQ_HZ     1000                      // Feqency for the PWM Module 
#define SYS_CLK        60000000                  // Sytem clock frequency = 60MHz
/****************************************** PLL REGISTERS **************************************************************************/
#define PLL_EN         0x00000001                // PLL Enable  
#define PLL_CNCT       0x00000002                // PLL Connect
#define PLL_MVAL       0x00000004                // PLL Multiplier value. Supplies the value "M" in the PLL frequency calculations
#define PLL_DVAL       0x00000020                // PLL Divider value. Supplies the value "P" in the PLL frequency calculations.
#define PLL_LOCK       0X00000400                // Reflects the PLL Lock status. When zero, the PLL is not locked. When one, the PLL is locked onto the requested frequency.
#define VP_DIVAL       0x00000001                // Controls the rate of the VPB clock in relation to the processor clock.
/**************************** POWER CONTROL OF THE PERIPHERAL REGISTERS **************************************************************/
#define PCON_TIMR0     PCONP |= 0x00000002       // Timer/Counter 0 power/clock control bit.
#define PCON_TIMR1     PCONP |= 0x00000004       // Timer/Counter 1 power/clock control bit.
#define PCON_UART0     PCONP |= 0x00000008       // UART0 power/clock control bit.
#define PCON_UART1     PCONP |= 0x00000010       // UART1 power/clock control bit.
#define PCON_PWM0      PCONP |= 0x00000020       // PWM0 power/clock control bit.
#define PCON_I2C0      PCONP |= 0x00000080       // The I2C0 interface power/clock control bit.
#define PCON_SPI0      PCONP |= 0x00000100       // The SPI0 interface power/clock control bit.
#define PCON_RTC       PCONP |= 0x00000200       // The RTC power/clock control bit.
#define PCON_SPI1      PCONP |= 0x00000400       // The SSP interface power/clock control bit.
#define PCON_ADC0      PCONP |= 0x00001000       // A/D converter 0 (ADC0) power/clock control bit.
#define PCON_I2C1      PCONP |= 0x00080000       // The I2C1 interface power/clock control bit.
#define PCON_ADC1      PCONP |= 0x00100000       // A/D converter 1 (ADC1) power/clock control bit.
#define PCON_USB       PCONP |= 0x10000000       // USB power/clock control bit.
/**************************** WATCHDOG REGISTERS      ********************************************************************************/
#define WDMOD_EN       0x00000003                // Watchdog Reset Mode: operate with the watchdog interrupt and WDRESET enabled.
#define WD_RST_TIME    500                       // it denotes the watchdog reset time in msec
#define WD_CLK_FRQ     60000                     // watchdog clock frquency 
/**************************** VECTORED IRQ REGISTERS  ********************************************************************************/
#define VEC_IRQ_EN     0X00000020                // When 1, this vectored IRQ slot is enabled,
#define VEC_IRQ_TIM0   0X00000004                // When 1,Enable TIMER0 IRQ slot
#define VEC_IRQ_TIM1   0X00000005                // When 1,Enable TIMER1 IRQ slot
#define VEC_IRQ_UART0  0X00000006                // When 1,Enable UART0 IRQ slot
#define VEC_IRQ_UART1  0X00000007                // When 1,Enable UART1 IRQ slot
#define VEC_IRQ_PWM0   0X00000008                // When 1,Enable PWM0 IRQ slot
#define VEC_IRQ_I2C0   0X00000009                // When 1,Enable I2C0 IRQ slot
#define VEC_IRQ_SPI0   0X0000000A                // When 1,Enable SPI0 IRQ slot
#define VEC_IRQ_SPI1   0X0000000B                // When 1,Enable SPI1 IRQ slot
#define VEC_IRQ_PLL    0X0000000C                // When 1,Enable PLL IRQ slot
#define VEC_IRQ_RTC    0X0000000D                // When 1,Enable RTC IRQ slot
#define VEC_IRQ_EINT0  0X0000000E                // When 1,Enable EINT0 IRQ slot
#define VEC_IRQ_EINT1  0X0000000F                // When 1,Enable EINT1 IRQ slot
#define VEC_IRQ_EINT2  0X00000010                // When 1,Enable EINT2 IRQ slot
#define VEC_IRQ_EINT3  0X00000011                // When 1,Enable EINT3 IRQ slot
#define VEC_IRQ_AD0    0X00000012                // When 1,Enable AD0 IRQ slot
#define VEC_IRQ_I2C1   0X00000013                // When 1,Enable I2C1 IRQ slot
#define VEC_IRQ_BOD    0X00000014                // When 1,Enable BOD IRQ slot
#define VEC_IRQ_AD1    0X00000015                // When 1,Enable AD1 IRQ slot
#define VEC_IRQ_USB    0X00000016                // When 1,Enable USB IRQ slot
/**************************** INTERRUPT ENABLE REGISTERS  ****************************************************************************/	
#define TIM0_INT_EN    0X00000010               // When 1,Enable TIMER0  Interrupt
#define TIM1_INT_EN    0X00000020               // When 1,Enable TIMER1  Interrupt
#define UART0_INT_EN   0X00000040               // When 1,Enable UART0  Interrupt
#define UART1_INT_EN   0X00000080               // When 1,Enable UART1  Interrupt
#define PWM0_INT_EN    0X00000100               // When 1,Enable PWM0  Interrupt
#define I2C0_INT_EN    0X00000200               // When 1,Enable I2C0  Interrupt
#define SPI0_INT_EN    0X00000400               // When 1,Enable SPI0  Interrupt
#define SPI1_INT_EN    0X00000800               // When 1,Enable SPI1  Interrupt
#define PLL_INT_EN     0X00001000               // When 1,Enable PLL  Interrupt
#define RTC_INT_EN     0X00002000               // When 1,Enable RTC  Interrupt
#define EINT0_INT_EN   0X00004000               // When 1,Enable EINT0  Interrupt
#define EINT1_INT_EN   0X00008000               // When 1,Enable EINT1  Interrupt
#define EINT2_INT_EN   0X00010000               // When 1,Enable EINT2  Interrupt
#define EINT3_INT_EN   0X00020000               // When 1,Enable EINT3  Interrupt
#define AD0_INT_EN     0X00040000               // When 1,Enable AD0  Interrupt
#define I2C1_INT_EN    0X00080000               // When 1,Enable I2C1  Interrupt
#define BOD_INT_EN     0X00100000               // When 1,Enable BOD  Interrupt
#define AD1_INT_EN     0X00200000               // When 1,Enable AD1  Interrupt
#define USB_INT_EN     0X00400000               // When 1,Enable USB  Interrupt
/**********************************************************************************************************************************/
void SystemInit(void);
void WatchdogInit(void);
void WatchdogTrigger(void);
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
