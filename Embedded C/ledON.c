#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
  DDRB |= ((1 << DDB5));        // sets the data direction register (DDR) for port B and is set to 1 (configuring for OUTPUT)
  while (1) {                   // starts an infinte loop 

    PORTB = ((1 <<  PB5));      //turn led on

  }
  
  return 0;