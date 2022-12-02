/*
 * timer.c
 *
 * Created: 11/4/2022 7:01:06 AM
 *  Author: Abdulrahman Ayman
 */ 
#include <math.h>
#include "../../Utilities/types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "timer.h"

void timer0_init(Timer timer){
	switch(timer.mode){
		case normal:
			TCCR0 = 0x00;
			break;
		case PWM_Phase_Correct:
			Set_bit(TCCR0,6);
			Clear_bit(TCCR0,3);
			break;
		case CTC:
			Set_bit(TCCR0,3);
			Clear_bit(TCCR0,6);
			break;
		case Fast_PWM:
			Set_bit(TCCR0,6);
			Set_bit(TCCR0,3);
			break;
	}
	TCNT0 = timer.initial;
} // initialize timer
// chooses mode and set initial value

void timer0_start(Timer timer){
	switch(timer.prescaler){
		case No_prescale:
			Set_bit(TCCR0,0);
			Clear_bit(TCCR0,1);
			Clear_bit(TCCR0,2);
			break;
		case prescale_8:
			Clear_bit(TCCR0,0);
			Set_bit(TCCR0,1);
			Clear_bit(TCCR0,2);
			break;
		case prescale_64:
			Set_bit(TCCR0,0);
			Set_bit(TCCR0,1);
			Clear_bit(TCCR0,2);
			break;
		case prescale_256:
			Clear_bit(TCCR0,0);
			Clear_bit(TCCR0,1);
			Set_bit(TCCR0,2);
			break;
		case prescale_1024:
			Set_bit(TCCR0,0);
			Clear_bit(TCCR0,1);
			Set_bit(TCCR0,2);
			break;
	}

} // sets prescaler to start

void timer0_stop(){
	TCCR0 &= ~((1<<0) | (1<<1) | (1<<2));
	
} // stop timer
uint8_t timer0_state(){
	return ((TIFR &(1<<0)) == 1);
} // checks for overflow flag

void timer0_set_val(uint8_t val){
	TCNT0 = val;
}

void timer0_delay(int t,Prescaler prescale, uint8_t* interr){
		volatile double t_tick = prescale/1000.0; //in ms
		volatile double t_max = 256 * t_tick; 
		volatile int overflow_num;
		volatile uint8_t initial;
		if(t<t_max){
			overflow_num = 1;
			initial = (t_max - t)/t_tick;
		}
		else{
			overflow_num = ceil(t/t_max);
			initial = 256 - (t/(overflow_num*t_tick));
		}
		volatile int temp = 0;
		volatile Timer timer={normal,initial,prescale};
		timer0_init(timer);
		timer0_start(timer);
		while(temp != overflow_num && !(*interr))
		{

			while(!timer0_state() && !(*interr));
			temp++;
			TCNT0 = timer.initial;
			Set_bit(TIFR,0);
		}
		
} // creates a delay of t ms






//********************************************************************************************************************************************
//********************************************************************************************************************************************
//********************************************************************************************************************************************


void timer1_init(Timer timer){
	switch(timer.mode){
		case normal:
			TCCR1A = 0x00;
			TCCR1B = 0X00;
			break;
		//case PWM_Phase_Correct:
		//Set_bit(TCCR1A,6);
		//Clear_bit(TCCR0,3);
		//break;
		//case CTC:
		//Set_bit(TCCR0,3);
		//Clear_bit(TCCR0,6);
		//break;
		//case Fast_PWM:
		//Set_bit(TCCR0,6);
		//Set_bit(TCCR0,3);
		//break;
		default:
			break;
	}
	timer1_set_val(timer.initial);
} // initialize timer
// chooses mode and set initial value

void timer1_start(Timer timer){
	switch(timer.prescaler){
		case No_prescale:
		Set_bit(TCCR1B,0);
		Clear_bit(TCCR1B,1);
		Clear_bit(TCCR1B,2);
		break;
		case prescale_8:
		Clear_bit(TCCR1B,0);
		Set_bit(TCCR1B,1);
		Clear_bit(TCCR1B,2);
		break;
		case prescale_64:
		Set_bit(TCCR1B,0);
		Set_bit(TCCR1B,1);
		Clear_bit(TCCR1B,2);
		break;
		case prescale_256:
		Clear_bit(TCCR1B,0);
		Clear_bit(TCCR1B,1);
		Set_bit(TCCR1B,2);
		break;
		case prescale_1024:
		Set_bit(TCCR1B,0);
		Clear_bit(TCCR1B,1);
		Set_bit(TCCR1B,2);
		break;
	}

} // sets prescaler to start

void timer1_stop(){
	TCCR1B &= ~((1<<0) | (1<<1) | (1<<2));
	
} // stop timer
uint8_t timer1_state(){
	return (((TIFR &(1<<2))>>2) == 1);
} // checks for overflow flag

void timer1_set_val(unsigned int val){
	volatile unsigned p = (val & 0xFF00);
	TCNT1H = (val & 0xFF00)>>8;
	TCNT1L = (val & 0x00FF);
}

void timer1_delay(double t,Prescaler prescale, uint8_t* interr){
	 volatile double t_tick = prescale/1000.0; //in ms
	 volatile double t_max = 65536 * t_tick;
	 volatile int overflow_num;
	 volatile unsigned int initial;

	if( t < t_max){
		overflow_num = 1;
		initial = (t_max - t)/t_tick;
	}
	else{
		overflow_num = ceil(t/t_max);
		initial = 65536 - (t/(overflow_num*t_tick));
	}
	 int temp = 0;
	 Timer timer={normal,initial,prescale};
	timer1_init(timer);
	timer1_start(timer);
	while(temp != overflow_num && !(*interr))
	{

		while(!timer1_state() && !(*interr));
		temp++;
		timer1_set_val(timer.initial);
		Set_bit(TIFR,2);
	}
	
} // creates a delay of t ms