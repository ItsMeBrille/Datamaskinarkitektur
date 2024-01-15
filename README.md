<<<<<<< HEAD
### Task 2
The trick is to do it using a counter so you can press whenever, and not only when the light is updating. Also without interrupt.
=======
### Oppgave 2
>>>>>>> 8d48cbc17cb40364190b197cb6bf3477e850506e
```c
while (1){
	// Wait
	_delay_ms(1);
	timepassed+=1;

	// If button pressed
	
	// Toggle when times up
	if(timepassed >= delay){
		PORTB ^= (1 << PB0); // LED 1 TOGGLE
		timepassed = 0;		
	}
}
```

### Oppgave 3/4
XOR for toggle:
```c
<<<<<<< HEAD
PORTB ^= (1 << PB0); // LED 1 TOGGLE
PORTD ^= (1 << PD6); // LED 2 TOGGLE
```
=======
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
>>>>>>> 8d48cbc17cb40364190b197cb6bf3477e850506e
