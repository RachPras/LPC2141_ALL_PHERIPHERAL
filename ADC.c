/**********************************************************************************************************************************
************************************* FILE NAME   :   GPIO.c:          ************************************************************
****                 10 bit intrnal Analog to Digital converter                        
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <LPC214X.H>
#include "HARDWARE.h"
#include "ADC.h"
/**********************************************************************************************************************************
** Function name   : ADCInit
** Descriptions    : Initialize the ADC channel  	
** parameters      : portnumber ->(ADC0 or ADC1)
** Returned value  : None
***********************************************************************************************************************************/
void ADCInit(uint8_t portnumber)
{
	if(portnumber == 0)
	{
		PCON_ADC0;                                           // Power on ADC module   						                                           
		AD0INTEN   = 0X00000000;                             // Disable all interupts flags                 
	  PIN_ADC0_1;                                          // Configure the necessary pin as ADC input
	  PIN_ADC0_2;                                          // Configure the necessary pin as ADC input
	}
	else if(portnumber == 1)
	{
		PCON_ADC1;                                           // Power on ADC module   						                                           
		AD1INTEN   = 0X00000000;                             // Disable all interupts flags                 
	}
}
/**********************************************************************************************************************************
** Function name   : ADC_GetAdcData
** Descriptions    : Read the converted value  	
** parameters      : adc_number ->(ADC0 or ADC1),channel_no->(channel for conversion)
** Returned value  : return converted value
***********************************************************************************************************************************/
uint32_t ADC_GetAdcData(uint8_t portnumber , uint8_t channel_no)
{
	uint16_t adc;
	if( portnumber == 0)
	{		
		switch(channel_no)
		{
			case ADC_CH0:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH0;     // Select AD0.0, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH0));                   // Check end of conversion (Done bit) and read result
					adc = ((AD0DR0 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH1:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH1;     // Select AD0.1, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH1));                   // Check end of conversion (Done bit) and read result
					adc = ((AD0DR1 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH2:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH2;		// Select AD0.2, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH2)); 									// Check end of conversion (Done bit) and read result
					adc = ((AD0DR2 >> 6) & 0x3ff) ;                         // Return 10 bit result
					break;
			}
			case ADC_CH3:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH3;     // Select AD0.3, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH3));                   // Check end of conversion (Done bit) and read result
					adc = ((AD0DR3 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH4:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH4;		 // Select AD0.4, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH4)); 									 // Check end of conversion (Done bit) and read result
					adc = ((AD0DR4 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH5:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH5;		 // Select AD0.5, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH5)); 									 // Check end of conversion (Done bit) and read result
					adc = ((AD0DR5 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH6:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH6;		 // Select AD0.6, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH6)); 									 // Check end of conversion (Done bit) and read result
					adc = ((AD0DR6 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH7:
			{
					AD0CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH7;		 // Select AD0.7, Select clock for ADC, Start of conversion
					while(!(AD0STAT & ADC_CONV_DONE_CH7)); 									 // Check end of conversion (Done bit) and read result
					adc = ((AD0DR7 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
		}
	}
	else if(portnumber == 1)
	{		
		switch(channel_no)
		{
			case ADC_CH0:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH0;     // Select AD1.0, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH0));                   // Check end of conversion (Done bit) and read result
					adc = ((AD1DR0 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH1:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH1;     // Select AD1.1, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH1));                   // Check end of conversion (Done bit) and read result
					adc = ((AD1DR1 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH2:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH2;		// Select AD1.2, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH2)); 									// Check end of conversion (Done bit) and read result
					adc = ((AD1DR2 >> 6) & 0x3ff) ;                         // Return 10 bit result
					break;
			}
			case ADC_CH3:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH3;     // Select AD1.3, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH3));                   // Check end of conversion (Done bit) and read result
					adc = ((AD1DR3 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH4:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH4;		// Select AD1.4, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH4)); 									// Check end of conversion (Done bit) and read result
					adc = ((AD1DR4 >> 6) & 0x3ff) ;                         // Return 10 bit result
					break;
			}
			case ADC_CH5:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH5;		// Select AD1.5, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH5)); 									// Check end of conversion (Done bit) and read result
					adc = ((AD1DR5 >> 6) & 0x3ff) ;                         // Return 10 bit result
					break;
			}
			case ADC_CH6:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH6;     // Select AD1.6, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH6));                   // Check end of conversion (Done bit) and read result
					adc = ((AD1DR6 >> 6) & 0x3ff) ;                          // Return 10 bit result
					break;
			}
			case ADC_CH7:
			{
					AD1CR = ADC_STRT_CNV|ADC_PDN|ADC_CLKDIV|ADC_SEL_CH7;		// Select AD1.7, Select clock for ADC, Start of conversion
					while(!(AD1STAT & ADC_CONV_DONE_CH7)); 									// Check end of conversion (Done bit) and read result
					adc = ((AD1DR7 >> 6) & 0x3ff) ;                         // Return 10 bit result
					break;
			}
		}
	}
	return adc;
}
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
