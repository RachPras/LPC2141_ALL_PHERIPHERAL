 ****************************************************************************************************************************************
*******************************LPC2141 PROGRAMMING MODULES **********************************************************

                       Here a list of all modules and its Functions 
_____________________________________________________________________________________________________________________________________
|Sl.No|  Modules   |                 Functions                                 |                Related Files	   					|		      
|     |            |														   |____________________________________________________|
|     |            |														   |Source Code            |  Header Files              |
|_____|____________|___________________________________________________________|_______________________|____________________________|			 
| 1.  |  HARDWARE  | Set the CLK of the micro-controller,Initializes           | HARDWARE.c            |  HARDWARE.h                |
|	  |			   | the watchdog timer and interrupts call.                   |                       |                            |
| 2.  |  GPIO      | General Purpose Input/Output ports.                       | GPIO.c                |  GPIO.h                    |
| 3.  |  UART      | Universal Asynchronous Receiver/Transmitter used for      | UART.c                |  UART.h                    |
|	  |			   | serial communication.                                     |                       |                            |
| 4.  |  ADC       | 10 bit internal Analog to Digital converter.              | ADC.c                 |  ADC.h                     |
| 5.  |  PWM       | Pulse Width Modulator.                                    | PWM.c                 |  PWM.h                     |
| 6.  |  TIMER     | Two 32-bit timers/external event counters.                | TIMER.c               |  TIMER.h                   |
| 7.  |  EINT      | External interrupt pins ,level or edge on that pin        | EINT.c                |  EINT.h                    |
|	  |			   | will set its interrupt flag in this register.			   |                       |                            |
| 8.  |  SPI       | Serial Peripheral Interface unit                          | SPI.c                 |  SPI.h                     |
|_____|____________|___________________________________________________________|_______________________|____________________________|

----> Related Files are should be added for activate the PLL ,Configure the sytem clock, watchdog Timer and intrerrupts call .
		HARDWARE.c
		HARDWARE.h

----> General Purpose Input/Output ports: Total of 30 input/output and a single output only pin out of 32 pins are available on PORT0. 
									      PORT1 has up to 16 pins available for GPIO functions.
		Related Files are should be added for GPIO operation. 
		GPIO.c
		GPIO.h

----> Analog To Digital Converter Module: The micro-controller includes two 10-bit ADC modules .									
		Related Files are should be added for ADC conversion
		ADC.c
	    ADc.h

----> Universal Asynchronous Receiver/Transmitter: The micro-controller includes two UARTs  									
		Related Files are should be added for UART Communication
		UART.c
		UART.h
		
----> Timer Counter: The micro-controller includes two 32 bit timer/counters  									
		Related Files are should be added for Timer operation.
		TIMER.c
		TIMER.h

----> External Interrupt pin : The level or edge on that pin will set its interrupt flag in this register.  									
		Related Files are should be added for External interrupt operation.
		EINT.c
		EINT.h
 
----> Serial Peripheral Interface:
		Related Files are should be added for SPI communication.
		SPI.c
		SPI.h
		
		
****************************************************************************************************************************************
****************************************************************************************************************************************
****************************************************************************************************************************************