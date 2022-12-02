/*
 * dio.c
 *
 * Created: 11/4/2022 6:00:37 AM
 *  Author: Abdulrahman Ayman
 */ 

#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/registers.h"
#include "dio.h"

void DIO_init(uint8_t port_num,uint8_t pin_num,uint8_t dir){
	switch(port_num){
		case 'A':
			if(dir == 1)
				Set_bit(DDRA,pin_num);
			else if(dir == 0)
				Clear_bit(DDRA,pin_num);
			break;
			
		case 'B':
			if(dir == 1)
				Set_bit(DDRB,pin_num);
			else if(dir == 0)
				Clear_bit(DDRB,pin_num);
			break;
		
		case 'C':
			if(dir == 1)
				Set_bit(DDRC,pin_num);
			else if(dir == 0)
				Clear_bit(DDRC,pin_num);
			break;
		
		case 'D':
			if(dir == 1)
				Set_bit(DDRD,pin_num);
			else if(dir == 0)
				Clear_bit(DDRD,pin_num);
			break;
	
	}
}

void DIO_write(uint8_t port_num,uint8_t pin_num,uint8_t val){
		switch(port_num){
			case 'A':
				if(val == 1)
					Set_bit(PORTA,pin_num);
				else if(val == 0)
					Clear_bit(PORTA,pin_num);
				break;
			
			case 'B':
				if(val == 1)
					Set_bit(PORTB,pin_num);
				else if(val == 0)
					Clear_bit(PORTB,pin_num);
				break;
			
			case 'C':
				if(val == 1)
					Set_bit(PORTC,pin_num);
				else if(val == 0)
					Clear_bit(PORTC,pin_num);
				break;
			
			case 'D':
				if(val == 1)
					Set_bit(PORTD,pin_num);
				else if(val == 0)
					Clear_bit(PORTD,pin_num);
				break;
			
		}
}
void DIO_read(uint8_t port_num,uint8_t pin_num, uint8_t* val){
	
			switch(port_num){
				case 'A':
					*val = Read_bit(PINA,pin_num);
				break;
				
				case 'B':
					*val = Read_bit(PINB,pin_num);		
				break;
				
				case 'C':
					//*val = Read_bit(PINC,pin_num);
					*val = ((PINC & (1<<pin_num)) >> pin_num);
				break;
				
				case 'D':
					*val = Read_bit(PIND,pin_num);
				break;
				
			}
}

void DIO_toggle(uint8_t port_num,uint8_t pin_num){
	switch(port_num){
		case 'A':
			Toggle_bit(PORTA,pin_num);
		break;
		
		case 'B':
			Toggle_bit(PORTB,pin_num);
		break;
		
		case 'C':
			Toggle_bit(PORTC,pin_num);
		break;
		
		case 'D':
			Toggle_bit(PORTD,pin_num);
		break;
		
	}
}