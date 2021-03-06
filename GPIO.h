/**********************************************************************************************************************************
************************************** FILE NAME   :   GPIO.h:          ***********************************************************
***********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <lpc214x.h>
#include "Hardware.h"
/***********************************************************************************************************************************/
#define GPIO0   0
#define GPIO1   1
#define INPUT   0
#define OUTPUT  1
/***********************************************************************************************************************************/
void     GpioInit(void);
void     GpioSetDirection(uint8_t ,uint8_t,uint32_t);
void     GpioSetBit      (uint8_t ,uint32_t );
void     GpioClearBit    (uint8_t ,uint32_t );
uint32_t GpioGetBit      (uint8_t ,uint32_t );
/**********************************************************************************************************************************
************************************** END FILE  **********************************************************************************
***********************************************************************************************************************************/
