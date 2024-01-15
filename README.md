### Task 2
The trick is to do it using a counter so you can press whenever, and not only when the light is updating. Also without interrupt.
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
PORTB ^= (1 << PB0); // LED 1 TOGGLE
PORTD ^= (1 << PD6); // LED 2 TOGGLE
```