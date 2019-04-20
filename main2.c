#include "serial.h"
#include "lcd.h"

int main(void)
{
  serial_init(47);
  init_lcd();
  lcd_init_4d();
  
  DDRB &= ~(1<<PB2);	//push button pin as input  
  DDRB |= (1 << PB0);	//sets mux select bit as an output
  
  char rxBuf;
  char distress[4] = "Help";
  size_t len = strlen(chararray);
  
	while(1) //infinite loop 
	{
  		_delay_ms(50);
    	if(PINB & (1<<PB2 == 0) //If switch is pressed
    	{
    		PORTB |= (1 << PB0);
    		for (int i=0; i<len; i++) {
      			lcd_write_string_4d(rxBuf);
      			serial_out(distress[i]);
      			rxBuf = serial_in();
			}
		}
	}
  
}
