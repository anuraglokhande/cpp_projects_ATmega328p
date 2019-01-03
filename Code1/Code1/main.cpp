/*
 * Code1.cpp
 *
 * Created: 03/01/2019 7:46:31 PM
 * Author : Anurag
 * code function: this code is to check only "how to work with class in embedded system and
 * is it work or not"
 * Aim of project: Blinking of On board LED of Arduino nano
 * this is edited for seeing changes and trial of git
 */ 

#include <avr/io.h>

#define F_CPU 8000000UL	//need to put before #include <util/delay.h>
						//otherwise it will throw #warning "F_CPU not defined for <util/delay.h>"
						//and in program, resolution of 1sec will be wrong 
#include <util/delay.h>


#define DELAY_MS 1000

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
	Box Box1;        // Declare Box1 of type Box
	

	
    while (1) 
    {
			Box1.setFunction_port_b();
			_delay_ms(DELAY_MS);
			Box1.clearFunction_port_b();
			_delay_ms(DELAY_MS);
    }
}

