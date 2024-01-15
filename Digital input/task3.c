#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>



int main(void){
	DDRB = (1 << PB0); // LED 1
	DDRD = (1 << PD6); // LED 2

	_Bool prev = 0;

	while (1){
		// Wait
		_delay_ms(5);

		// If button pressed
		if(bit_is_clear(PIND, 7)){
			// If button ready
			if(prev == 0){
				PORTB ^= (1 << PB0); // LED 1 TOGGLE
				PORTD ^= (1 << PD6); // LED 2 TOGGLE
				// Set lastbutton to pressed
				prev = 1;
			}
		}
		// Not pressed, allow press next round
		else {
			prev = 0;
		}
	}
}