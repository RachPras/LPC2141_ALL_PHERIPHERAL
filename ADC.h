/**********************************************************************************************************************************
************************************** FILE NAME   :   ADC.h          ***********************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "Hardware.h"
/***********************************************************************************************************************************/ enum
{
	ADC_CH0 = 0,
	ADC_CH1 = 1,
	ADC_CH2 = 2,
	ADC_CH3 = 3,
	ADC_CH4 = 4,
	ADC_CH5 = 5,
	ADC_CH6 = 6,
	ADC_CH7 = 7,
};
/***********************************************************************************************************************************/
#define ADC0                 0
#define ADC1                 1
/****************************** PIN SELECT REGISTERS *******************************************************************************/
#define PIN_ADC0_1           PINSEL1 |= 0X01000000       // P0.28  AD0.1
#define PIN_ADC0_2           PINSEL1 |= 0X04000000       // P0.29  AD0.2
#define PIN_ADC0_3           PINSEL1 |= 0X10000000       // P0.30  AD0.3
#define PIN_ADC0_4           PINSEL1 |= 0X00040000       // P0.25  AD0.4
#define PIN_ADC0_6           PINSEL0 |= 0X00000300       // P0.4   AD0.6
#define PIN_ADC0_7           PINSEL0 |= 0X00000C00       // P0.5   AD0.7
/**********************************************************************************************************************************/
/************************     Available on LPC2144/6/8.    ************************************************************************/
/**********************************************************************************************************************************/
#define PIN_ADC1_0           PINSEL0 |= 0X00003000        // P0.6   AD1.0
#define PIN_ADC1_1           PINSEL0 |= 0X00030000        // P0.8   AD1.1
#define PIN_ADC1_2           PINSEL0 |= 0X00300000        // P0.10  AD1.2
#define PIN_ADC1_3           PINSEL0 |= 0X03000000        // P0.12  AD1.3
#define PIN_ADC1_4           PINSEL0 |= 0X0C000000        // P0.13  AD1.4
#define PIN_ADC1_5           PINSEL0 |= 0XC0000000        // P0.15  AD1.5
#define PIN_ADC1_6           PINSEL1 |= 0X00000800        // P0.21  AD1.6
#define PIN_ADC1_7           PINSEL1 |= 0X00001000        // P0.22  AD1.7
/****************************** ADC REGISRERSS *******************************************************************************/
#define ADC_SEL_CH0          0X00000001                   // For Selecting adc channel_0   
#define ADC_SEL_CH1          0X00000002                   // For Selecting adc channel_1
#define ADC_SEL_CH2          0X00000004                   // For Selecting adc channel_2
#define ADC_SEL_CH3          0X00000008                   // For Selecting adc channel_3
#define ADC_SEL_CH4          0X00000010                   // For Selecting adc channel_4
#define ADC_SEL_CH5          0X00000020                   // For Selecting adc channel_5
#define ADC_SEL_CH6          0X00000040                   // For Selecting adc channel_6
#define ADC_SEL_CH7          0X00000080                   // For Selecting adc channel_7
#define ADC_CONV_DONE        0X80000000                   // ADC conversion done bit
#define ADC_CONV_DONE_CH0    0X00000001                   // ADC channel_0 conersion done
#define ADC_CONV_DONE_CH1    0X00000002                   // ADC channel_1 conersion done
#define ADC_CONV_DONE_CH2    0X00000004                   // ADC channel_2 conersion done
#define ADC_CONV_DONE_CH3    0X00000008                   // ADC channel_3 conersion done
#define ADC_CONV_DONE_CH4    0X00000010                   // ADC channel_4 conersion done
#define ADC_CONV_DONE_CH5    0X00000020                   // ADC channel_5 conersion done
#define ADC_CONV_DONE_CH6    0X00000040                   // ADC channel_6 conersion done
#define ADC_CONV_DONE_CH7    0X00000080                   // ADC channel_7 conersion done
#define ADC_CLKDIV           0X00000E00                   // ADC clock division bit
#define ADC_BURST            0X00010000                   // burst mode
#define ADC_PDN		           0X00200000                   // ADC power down mode
#define ADC_STRT_CNV         0X01000000                   // ADC start conersion 
/***********************************************************************************************************************************/
void      ADCInit              (uint8_t);
uint32_t  ADC_GetAdcData       (uint8_t  , uint8_t );
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
