### Task 2
```c
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>


int main(void){
	DDRB = (1 << PB0); // LED 1
	
	// Initialize variables
	int delay = 100;
	int timepassed = 0;
	_Bool prev = 0;

	while (1){
		// Wait
		_delay_ms(1);
		timepassed+=1;


		// If button pressed
		if(bit_is_clear(PIND, 7)){
			// If button pressed now
			if(prev == 0){
				// Change timepassed
				if(delay == 100){delay = 1000;}
				else {delay = 100;}
				// Set lastbutton to pressed
				prev = 1;
			}
		}
		// Not pressed, allow press next round
		else {
			prev = 0;
		}
		
		// Toggle when times up
		if(timepassed >= delay){
			PORTB ^= (1 << PB0); // LED 1 TOGGLE
			timepassed = 0;		
		}
	}
}
```

### Oppgave 3/4

```c
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
		_delay_ms(10);

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
```