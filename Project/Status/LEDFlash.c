///-----------------------------------------------------------------------------
// 
// MODULE FILE 
//
// Filename:		LEDFlash.c
// Description:	Flashes LED to should that micro is operational.
//							Motor Control PCB LEDs
//							-----------------------
//							Status LED 	- PB5
//							M1 Busy			- PC6
//							M2 Busy			- PC7
//							M3 Busy			- PB15 (External Board)
//
// Date:  			7th July 17
// Author:			Ernest Cooke
//
//-----------------------------------------------------------------------------
//
// Notes       : 
// Limimations :
// References  : 
//-----------------------------------------------------------------------------
//
// Copyright (c) 2017, Randox Laboratories Ltd
//
//-----------------------------------------------------------------------------
// VERSION HISTORY:
// ----------------
// Version: 		1.0
// Date:				
// Revised By: 	Ernest Cooke
// Description:	Original 
//
//-----------------------------------------------------------------------------

#define __FLASH_LED_C_

//-----------------------------------------------------------------------------
// MODULES USED
//-----------------------------------------------------------------------------
#include "LEDFlash.h"
#include "stm32f10x.h"                  // Device header

//-----------------------------------------------------------------------------
// DEFINITIONS AND MACRO 
//-----------------------------------------------------------------------------

	#define LED_PIN				GPIO_Pin_5
	#define LED_PORT			GPIOB
	#define LED_CLK				RCC_APB2Periph_GPIOB
	#define FLASH_PERIOD	500

//-----------------------------------------------------------------------------
// TYPEDEFS AND STRUCTURES 
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// GLOBAL VARIABLES
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// PROTOTYPES OF LOCAL FUNCTIONS
//-----------------------------------------------------------------------------
void Flash_GPIO(void);

//-----------------------------------------------------------------------------
// LOCAL FUNCTIONS
//-----------------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Function: 		LEDGPIO
// Added By: 		Ernest Cooke 
// Description: GPIO initialization of LED indicator
// Arguments: 	None 
// Returns: 		None
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void LED_GPIO(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(LED_CLK,ENABLE);

	GPIO_InitStructure.GPIO_Pin = LED_PIN;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

//-----------------------------------------------------------------------------
// EXPORTED VARIABLES
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// EXPORTED FUNCTIONS
//-----------------------------------------------------------------------------

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Function: 		FLASH_LED
// Added By: 		Ernest
// Description: Flash a LED to show that the system is alive.   
// Arguments: 	None 
// Returns: 		None
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Flash_LED (void) 
{
	LED_GPIO();
	
	while (1) 
	{
		//TOGGLE_LED;
		LED_PORT->ODR ^= LED_PIN;
		osDelay (FLASH_PERIOD);
	}
	
}
//-----------------------------------------------------------------------------
// EOF
//-----------------------------------------------------------------------------
