/*
 * timer.h
 *
 * Created: 11/4/2022 6:47:43 AM
 *  Author: Abdulrahman Ayman
 */ 


#ifndef TIMER_H_
#define TIMER_H_

typedef enum Prescaler
{
	No_prescale = 1,
	prescale_8 = 8,
	prescale_64 = 64,
	prescale_256 = 256,
	prescale_1024 = 1024
}Prescaler;

typedef enum Mode{
	normal,
	PWM_Phase_Correct,
	CTC,
	Fast_PWM
}Mode;
typedef struct Timer{
		Mode mode;
		unsigned int initial;
		Prescaler prescaler;
}Timer;


void timer0_init(Timer); // initialize timer
						// chooses mode and set initial value
void timer0_start(Timer); // sets prescaler to start
void timer0_stop(); // stop timer 
uint8_t timer0_state(); // checks for overflow flag
void timer0_set_val(uint8_t val); // sets initial
void timer0_delay(int t,Prescaler prescale, uint8_t* interr); // creates a delay of t ms

void timer1_init(Timer); // initialize timer
// chooses mode and set initial value
void timer1_start(Timer); // sets prescaler to start
void timer1_stop(); // stop timer
uint8_t timer1_state(); // checks for overflow flag
void timer1_set_val(unsigned int val); // sets initial
void timer1_delay(double t,Prescaler prescale, uint8_t* interr); // creates a delay of t ms


#endif /* TIMER_H_ */