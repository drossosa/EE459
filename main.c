#include "serial.h"	
#include "lcd.h"

int main(void){
	serial_init(47); //9600 BAUD rate 
	init_lcd();
	lcd_init_4d();

	char rxBuf;
	// uint8_t authorName[] = "Alex Drossos";

	DDRB |= (1 << PB0); //multiplexer select bit
	PORTB |= (1 << PB0); //turn on to select XBEE

	while(1){
		lcd_write_character_4d(rxBuf);
		serial_out('C');
		rxBuf = serial_in();
		//lcd_write_string_4d(authorName);
	}

	return(0);
}