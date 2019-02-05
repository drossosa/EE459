
#include <avr/io.h>
#include <util/delay.h>

int main(void) {

	PORTD = 0x00;
	PORTC = 0x00;
	PORTB = 0x00;
	
	DDRB |= (1 << PB0);	// Set PORTB bit 0 for output
	DDRB |= (1 << PB1);
	DDRB |= (1 << PB2);
	DDRB |= (1 << PB3);
	DDRB |= (1 << PB4);
	DDRB |= (1 << PB5);
	DDRB |= (1 << PB7);
	
	DDRC |= (1 << PC0);
	DDRC |= (1 << PC1);
	DDRC |= (1 << PC2);
	DDRC |= (1 << PC3);
	DDRC |= (1 << PC4);
	DDRC |= (1 << PC5);
	
	DDRD |= (1 << PD0);       
	DDRD |= (1 << PD1); 
	DDRD |= (1 << PD2);
	DDRD |= (1 << PD3);
	DDRD |= (1 << PD4);
	DDRD |= (1 << PD5);
	DDRD |= (1 << PD6); 
	DDRD |= (1 << PD7); 

	while(1) {
	PORTB |= (1 << PB0); //sets trigger signal 
	_delay_ms(250);		// delay 250 ms so it shows up on oscill
	PORTB &= ~(1 << PB0); //clears trigger signal 
	_delay_ms(250);
	PORTB |= (1 << PB1); 
	_delay_ms(250);
	PORTB &= ~(1 << PB1); 
	_delay_ms(250);
	PORTB |= (1 << PB2); 
	_delay_ms(250);
	PORTB &= ~(1 << PB2);
	_delay_ms(250); 
	PORTB |= (1 << PB3);
	_delay_ms(250); 
	PORTB &= ~(1 << PB3);
	_delay_ms(250);
	PORTB |= (1 << PB4); 
	_delay_ms(250);
	PORTB &= ~(1 << PB4);
	_delay_ms(250); 
	PORTB |= (1 << PB5); 
	_delay_ms(250);
	PORTB &= ~(1 << PB5);
	_delay_ms(250); 
	PORTB |= (1 << PB7); 
	_delay_ms(250);
	PORTB &= ~(1 << PB7);
	_delay_ms(250); 
	
	PORTC |= (1 << PC0);
	_delay_ms(250);
	PORTC &= ~(1 << PC0);
	_delay_ms(250); 
	PORTC |= (1 << PC1);
	_delay_ms(250); 
	PORTC &= ~(1 << PC1); 
	_delay_ms(250);
	PORTC |= (1 << PC2);
	_delay_ms(250); 
	PORTC &= ~(1 << PC2);
	_delay_ms(250); 
	PORTC |= (1 << PC3);
	_delay_ms(250); 
	PORTC &= ~(1 << PC3);
	_delay_ms(250);
	PORTC |= (1 << PC4);
	_delay_ms(250); 
	PORTC &= ~(1 << PC4);
	_delay_ms(250); 
	PORTC |= (1 << PC5);
	_delay_ms(250); 
	PORTC &= ~(1 << PC5);
	_delay_ms(250);
	
	PORTD |= (1 << PD0); 
	_delay_ms(250);
	PORTD &= ~(1 << PD0);
	_delay_ms(250); 
	PORTD |= (1 << PD1);
	_delay_ms(250); 
	PORTD &= ~(1 << PD1);
	_delay_ms(250); 
	PORTD |= (1 << PD2);
	_delay_ms(250); 
	PORTD &= ~(1 << PD2);
	_delay_ms(250); 
	PORTD |= (1 << PD3); 
	_delay_ms(250);
	PORTD &= ~(1 << PD3);
	_delay_ms(250);
	PORTD |= (1 << PD4);
	_delay_ms(250); 
	PORTD &= ~(1 << PD4);
	_delay_ms(250); 
	PORTD |= (1 << PD5);
	_delay_ms(250); 
	PORTD &= ~(1 << PD5);
	_delay_ms(250); 
	PORTD |= (1 << PD6); 
	_delay_ms(250);
	PORTD &= ~(1 << PD6);
	_delay_ms(250); 
	PORTD |= (1 << PD7);
	_delay_ms(250); 
	PORTD &= ~(1 << PD7); 
	_delay_ms(250);
	}
return 0;

}