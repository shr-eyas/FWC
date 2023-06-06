//blink LED
//through an assembly routine
#include <avr/io.h>

//external assembly functions declared separately
extern void init(void);
extern void disp_led(uint8_t);
extern void delay(uint8_t, uint8_t, uint8_t);

 int main (void) {
 
  while (1) {
  
	  init();   	  
	  disp_led(0);     //turn led off  
	  delay(0, 0, 54); //delay	  
	  disp_led(1);     //turn led on
	  delay(0, 0, 54);	  	  
  }

  return 0;

}
