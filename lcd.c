#include "lcd.h"


uint8_t authorName[] = "Alex Drossos";


// int main(void) {
// 	init_lcd();
	
// 	lcd_init_4d();	//initialize for 4bit mode 
	
// 		//print out my name on LCD
	
// 	while(1) {
// 		lcd_write_string_4d(authorName);
// 	}
// 	return 0;
// }


void init_lcd(void) {
	PORTD = 0x00;
	PORTC = 0x00;
	PORTB = 0x00;
	
	DDRC |= (1 << PC1);		//set data lines PC1-4 as outputs 
	DDRC |= (1 << PC2);
	DDRC |= (1 << PC3);
	DDRC |= (1 << PC4);
	
	DDRD |= (1 << PD5);		//Register select PD5
	DDRD |= (1 << PD6); 	//Enable line PD6	

}

void lcd_init_4d(void) {
	_delay_ms(100);
	
	PORTD &= ~(1 << PD5);
	PORTD &= ~(1 << PD6);	
	
	lcd_write_4(0b00110000);	//Function reset
	_delay_ms(10);
	lcd_write_4(0b00110000);
	_delay_ms(200);
	lcd_write_4(0b00110000);
	_delay_ms(200);
	
	lcd_write_4(0b00101000);	//set to 4bit mode
	_delay_us(80);
	lcd_write_instruction_4d(0b00101000);
	_delay_us(80);
	
	lcd_write_instruction_4d(0b00001000);	//display off
	_delay_us(80);	
	lcd_write_instruction_4d(0b00000001);	//clear displayRAM
	_delay_us(4);
	lcd_write_instruction_4d(0b00000110);	//Entry Mode
	_delay_us(80);
	lcd_write_instruction_4d(0b00001100);	//Turn display ON
	_delay_us(80);
	
}

void lcd_write_4(uint8_t theByte) {
	PORTC &= ~(1 << PC4);
	if (theByte & 1<<7) PORTC |= (1 << PC4);
	PORTC &= ~(1 << PC3);
	if (theByte & 1<<6) PORTC |= (1 << PC3);
	PORTC &= ~(1 << PC2);
	if (theByte & 1<<5) PORTC |= (1 << PC2);
	PORTC &= ~(1 << PC1);
	if (theByte & 1<<4) PORTC |= (1 << PC1);

	PORTD |= (1 << PD6);	//enable pulse
	_delay_us(1);
	PORTD &= ~(1 << PD6);
	_delay_us(1);
}

void lcd_write_instruction_4d(uint8_t theInstruction) {
	PORTD &= ~(1 << PD5);
	PORTD &= ~(1 << PD6);	
	lcd_write_4(theInstruction); 
	lcd_write_4(theInstruction << 4);
	_delay_ms(2);
}

void lcd_write_character_4d(uint8_t theData) {
	PORTD |= (1 << PD5);
	PORTD &= ~(1 << PD6);
	lcd_write_4(theData);
	lcd_write_4(theData << 4);	
	_delay_ms(2);

}	
void lcd_write_string_4d(uint8_t inpString[]) {
	volatile int i = 0;
	while (inpString[i] != 0) {
		lcd_write_character_4d(inpString[i]);
		i++;
		_delay_us(80);
	}
}