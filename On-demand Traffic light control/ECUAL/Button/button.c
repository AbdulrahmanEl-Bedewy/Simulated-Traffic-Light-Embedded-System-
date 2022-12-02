/*
 * button.c
 *
 * Created: 11/4/2022 11:07:16 AM
 *  Author: Abdulrahman Ayman
 */ 

#include "../../MCAL/Dio/dio.h"
#include "button.h"

void BUTTON_init(uint8_t ButtonPort,uint8_t ButtonPin){
	DIO_init(ButtonPort,ButtonPin,0);
}
void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin, uint8_t Config, uint8_t* val){
	if(Config == Pull_Down){
		DIO_read(ButtonPort,ButtonPin, val); 
	}
	else if(Config == Pull_Up ){
		DIO_read(ButtonPort,ButtonPin, val); 
		*val = !(*val);
	}
}