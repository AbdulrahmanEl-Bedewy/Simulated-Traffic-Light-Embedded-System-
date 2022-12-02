/*
 * led.h
 *
 * Created: 11/4/2022 10:41:35 AM
 *  Author: Abdulrahman Ayman
 */ 

#include "../../Utilities/types.h"

#ifndef LED_H_
#define LED_H_


void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);
//void LED_blink(uint8_t ledPort,uint8_t ledPin,int delay,Prescaler prescale); // time in ms


#endif /* LED_H_ */