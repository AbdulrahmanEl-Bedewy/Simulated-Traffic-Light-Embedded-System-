/*
 * bit_manipulation.h
 *
 * Created: 11/3/2022 8:00:50 PM
 *  Author: Abdulrahman Ayman
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define Set_bit(reg,bit_num) reg |= (1<<bit_num)
#define Clear_bit(reg,bit_num) reg &= ~(1<<bit_num)
#define Toggle_bit(reg,bit_num) reg ^= (1<<bit_num)
#define Read_bit(reg,bit_num) ((reg & (1<<bit_num)) >> bit_num)




#endif /* BIT_MANIPULATION_H_ */