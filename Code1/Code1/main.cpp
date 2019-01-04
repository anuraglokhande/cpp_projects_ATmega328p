/*
 * Code1.cpp
 *
 * Created: 04/01/2019 7:46:31 PM
 * Author : Anurag
 * code function: code is written for pinmode function and digitalWrite function for port B only like in Arduino
 * verified only for LED as OUTPUT
 */ 

#include <avr/io.h>

#define F_CPU 8000000UL	//need to put before #include <util/delay.h>
						//otherwise it will throw #warning "F_CPU not defined for <util/delay.h>"
						//and in program, resolution of 1sec will be wrong 
#include <util/delay.h>

/* global macros */
#define DELAY_MS 1000
#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0


/* global functions */

void pinMode(const char,const char);
//pinMode(LED_PIN_RED, OUTPUT);
void digitalWrite(const char,const char);
//digitalWrite(BUZZER_PIN1, HIGH);

class Box {
	public:
	/* setting port pin for led blinking */
	
	void setFunction_port_b(void)
	{
		/* This will ON the on board LED ON of Arduino nano  */
			PORTB = 0xff;	//make PORT B as OUTPUT
			DDRB = 0xff;	//make PORT B all pins HIGH
	}
	
	void clearFunction_port_b(void)
	{
		/* This will OFF the on board LED ON of Arduino nano  */
		PORTB = 0xff;	//make PORT B as OUTPUT
		DDRB = 0x00;	//make PORT B all pins LOW
	}
	
};


int main(void)
{
    /* Replace with your application code */
	//Box Box1;        // Declare Box1 of type Box
	pinMode(5,OUTPUT);
	digitalWrite(5,HIGH);
	
}

void pinMode(const char pin,const char mode)
{
	if (mode == OUTPUT)
	{
		DDRB = DDRB | (1<<pin);
	}
	else
	{
		DDRB = DDRB & (0<<pin);
	}	
}

void digitalWrite(const char pin,const char level)
{
		if (level == HIGH)
		{
			PORTB = PORTB | (1<<pin);
		}
		else
		{
			PORTB = PORTB & (0<<pin);
		}
	
}