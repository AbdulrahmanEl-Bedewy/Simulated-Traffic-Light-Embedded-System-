/*
 * Dio.h
 *
 * Created: 11/4/2022 5:54:52 AM
 *  Author: Abdulrahman Ayman
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/types.h"

#define HIGH 1
#define LOW 0

#define INPUT 0
#define OUTPUT 1

#define Port_A 'A'
#define Port_B 'B'
#define Port_C 'C'
#define Port_D 'D'

void DIO_init(uint8_t port_num,uint8_t pin_num,uint8_t dir);
void DIO_write(uint8_t port_num,uint8_t pin_num,uint8_t val);
void DIO_read(uint8_t port_num,uint8_t pin_num, uint8_t* val);
void DIO_toggle(uint8_t port_num,uint8_t pin_num);



#endif /* DIO_H_ */