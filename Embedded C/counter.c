#include <avr/io.h>
#include <util/delay.h>

//Declaring all variables as integers
int D0, D1, D2, CLK;
int Q0 = 0, Q1 = 0, Q2 = 0;

//Creating a function
void ref(int D0, int D1, int D2, int CLK) {
    if (D0)
        PORTD |= (1 << PD2);
    else
        PORTD &= ~(1 << PD2);
    
    if (D1)
        PORTD |= (1 << PD3);
    else
        PORTD &= ~(1 << PD3);
    
    if (D2)
        PORTD |= (1 << PD4);
    else
        PORTD &= ~(1 << PD4);
    
    if (CLK)
        PORTB |= (1 << PB3);
    else
        PORTB &= ~(1 << PB3);
}

int main(void) {
    //Setting DDR registers for required pins
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4);
    DDRB |= (1 << PB3);
    
    //Setting input pins
    DDRD &= ~((1 << PD6) | (1 << PD7) | (1 << PD8));
    
    //the loop function runs over and over again
    while (1) {
        PORTB |= (1 << PB3);
        _delay_ms(1000);
        
        Q0 = (PIND >> PD6) & 0x01;
        Q1 = (PIND >> PD7) & 0x01;
        Q2 = (PIND >> PD8) & 0x01;
        
        D2 = Q1;
        D1 = Q0;
        D0 = !(Q1 || Q2);
        
        PORTB &= ~(1 << PB3);
        ref(D0, D1, D2, CLK);
    }
}
