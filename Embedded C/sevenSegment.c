#include <avr/io.h>
 
int main (void)
{
	
  DDRD |= 0xFC;               //set PD2-PD7 as output pins 0xFC=0b11111100 (binary)
  DDRB |= ((1 << DDB0));      //set PB0 as output pin (1 << DDB0) (shifts the value 1 to the left by the number of bits specified by DDB0, which is 0 in this case)
	                      //it sets the first bit of DDRB to 1 using the |= operator

  while (1) {

    PORTB = ((1 <<  PB0));    //turn PB0 off (pin 8)

    // PD2 corresponds to digital pin 2
    // PD3 corresponds to digital pin 3
    // PD4 corresponds to digital pin 4
    // PD5 corresponds to digital pin 5
    // PD6 corresponds to digital pin 6
    // PD7 corresponds to digital pin 7 

    PORTD = 0b11100100;        
            //76543201
  }


  return 0;

}
