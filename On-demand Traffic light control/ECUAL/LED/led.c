/*
 * led.c
 *
 * Created: 11/4/2022 10:41:16 AM
 *  Author: Abdulrahman Ayman
 */ 

#include "../../MCAL/Dio/dio.h"
#include "../../MCAL/Timer/timer.h"
#include "led.h"

void LED_init(uint8_t ledPort,uint8_t ledPin){
	DIO_init(ledPort,ledPin,1);
}
void LED_on(uint8_t ledPort,uint8_t ledPin){
	DIO_write(ledPort,ledPin,1);
}
void LED_off(uint8_t ledPort,uint8_t ledPin){
	DIO_write(ledPort,ledPin,0);
}
void LED_toggle(uint8_t ledPort,uint8_t ledPin){
	DIO_toggle(ledPort,ledPin);
}
//void LED_blink(uint8_t ledPort,uint8_t ledPin,int delay,Prescaler prescale){
	//DIO_write(ledPort,ledPin,1);
	//timer1_delay(delay,prescale);
	//DIO_write(ledPort,ledPin,0);
	//timer1_delay(delay,prescale);
//}
