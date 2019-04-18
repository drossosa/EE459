#include <avr/io.h>
#include <util/delay.h>

void  serial_init(unsigned  short  ubrr);
void  serial_out(char ch);
char  serial_in ();