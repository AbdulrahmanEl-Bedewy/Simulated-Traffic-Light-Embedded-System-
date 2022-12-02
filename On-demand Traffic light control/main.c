/*
 * On-demand Traffic light control.c
 *
 * Created: 11/3/2022 5:35:33 PM
 * Author : Abdurlahman Ayman
 */ 

#include "Utilities/bit_manipulation.h"
#include "Utilities/registers.h"
#include "MCAL/Dio/dio.h"
#include "MCAL/Interrupt/interrupt.h"
#include "MCAL/Timer/timer.h"
#include "ECUAL/LED/led.h"
#include "ECUAL/Button/button.h"
#include "Application/app.h"

int main(void)
{	
	// Testing Drivers
	
	//uint8_t temp = 0;
	//
	//LED_init(Port_A,0);
	//
	//LED_off(Port_A,0);
	//timer1_delay(500,1024, &temp);
	//LED_on(Port_A, 0);
	//timer1_delay(2000,1024, &temp);
	//LED_off(Port_A, 0);
	//timer1_delay(500,1024, &temp);
	//LED_toggle(Port_A, 0);
	//timer1_delay(500,1024, &temp);
	//LED_toggle(Port_A, 0);
	//BUTTON_init(Port_D,2);
	//
	//while (1)
	//{
		//uint8_t prev = temp;
		//BUTTON_read(Port_D,2, Pull_Down, &temp);
		//if(temp && !prev)
			//LED_toggle(Port_A, 0);
	//}
	
	app_init();
	app_start();
}