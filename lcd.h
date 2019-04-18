#include <avr/io.h>
#include <util/delay.h>

void init_lcd(void);
void lcd_init_4d(void);
void lcd_write_4(uint8_t);
void lcd_write_instruction_4d(uint8_t);
void lcd_write_string_4d(uint8_t *);
void lcd_write_character_4d(uint8_t);