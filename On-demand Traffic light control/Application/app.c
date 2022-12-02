/*
 * app.c
 *
 * Created: 11/13/2022 11:08:04 PM
 *  Author: Abdulrahman Ayman Elbedewy
 */ 
#include "app.h"
#include "../Utilities/bit_manipulation.h"
#include "../Utilities/registers.h"
#include "../MCAL/Dio/dio.h"
#include "../MCAL/Interrupt/interrupt.h"
#include "../MCAL/Timer/timer.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/Button/button.h"

#define Led_Green1 Port_A,0
#define Led_Yellow1 Port_A,1
#define Led_Red1 Port_A,2

#define Led_Green2 Port_B,0
#define Led_Yellow2 Port_B,1
#define Led_Red2 Port_B,2

int Car_Light_Turn = 0;
int Ped_Light_Turn = 2;
int Ped_Green = 0;
uint8_t arr[] = {0,1,2,1};

uint8_t button = 0;


void app_init()
{
	MCUCR |= (1<<1);  // set int0 to work on falling edge 
	MCUCR &= ~(1<<0);
	GICR |= (1<<6);
	sei();
	//timer1_delay(500,1024, &button);

	LED_init(Led_Green1);
	LED_init(Led_Yellow1);
	LED_init(Led_Red1);

	LED_init(Led_Green2);
	LED_init(Led_Yellow2);
	LED_init(Led_Red2);


	LED_off(Led_Green1);
	LED_off(Led_Yellow1);
	LED_off(Led_Red1);

	LED_off(Led_Green2);
	LED_off(Led_Yellow2);
	LED_off(Led_Red2);

	BUTTON_init(Port_D,2);
}

void app_start()
{

	

	volatile Timer timer={normal,11,1024};
	timer1_init(timer);
	
	while (1)
	{
		uint8_t temp = 0;
		
		LED_on(Port_A, arr[Car_Light_Turn]);
		LED_on(Port_B, Ped_Light_Turn);
		if(Ped_Green)
		LED_on(Port_B, 0);
		timer0_start(timer);
		while (temp != 20 && !button)
		{
			while (!timer0_state() && !button);
			temp++;
			TCNT0 = timer.initial;
			Set_bit(TIFR, 0);

			if (arr[Car_Light_Turn] == 1)
			LED_toggle(Port_A, arr[Car_Light_Turn]);
			if (Ped_Light_Turn == 1)
			LED_toggle(Port_B, Ped_Light_Turn);
		}
		timer0_stop();
		LED_off(Port_A,arr[Car_Light_Turn]);
		LED_off(Port_B,Ped_Light_Turn);
		if(Ped_Green)
		LED_off(Port_B, 0);
		
		if(!button){
			Car_Light_Turn = (++Car_Light_Turn) % 4;
			if(Ped_Light_Turn == 0 && !Ped_Green){
				Ped_Light_Turn = 1;
				Ped_Green = 1;
			}
			else if(Ped_Light_Turn == 1 && Ped_Green){
				Ped_Light_Turn = 2;
				Ped_Green = 0;
			}
			else if(Ped_Light_Turn == 1)
			Ped_Light_Turn = 0;
		}
		else{
			if(Car_Light_Turn == 0){
				Car_Light_Turn = 1;
				Ped_Light_Turn = 1;
			}
			else if (arr[Car_Light_Turn] == 1 && Ped_Light_Turn == 2){
				Ped_Light_Turn = 1;
				Car_Light_Turn = 1;
			}
			else if(Car_Light_Turn == 2){
				Ped_Light_Turn = 0;
			}
		}

		button = 0;
		//LED_on(Port_A, Car_Light_Turn);
		//timer1_delay(10000,prescale_1024);
		//LED_off(Port_A, Car_Light_Turn);
		//timer1_delay(5000,prescale_1024);
	}
}

ISR(EXT_INT_0){
	//timer1_stop();
	//if(!(arr[Car_Light_Turn] == 1 && Ped_Light_Turn==1))
	if(Ped_Light_Turn == 2)
	button = 1;
}