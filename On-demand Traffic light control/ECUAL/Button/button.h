/*
 * button.h
 *
 * Created: 11/4/2022 11:07:05 AM
 *  Author: Abdulrahman Ayman
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define Pull_Up 0
#define Pull_Down 1

void BUTTON_init(uint8_t ButtonPort,uint8_t ButtonPin);
void BUTTON_read(uint8_t ButtonPort,uint8_t ButtonPin, uint8_t Config, uint8_t* val); //val is 1 for pressed 0 for not pressed
																					 // CONFIG i.e. pull down/up 




#endif /* BUTTON_H_ */