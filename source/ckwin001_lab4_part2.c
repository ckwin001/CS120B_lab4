/*         Your Name & E-mail: Casey Kwinn, ckwin001@ucr.edu
*          Lab Section:023
 *         Assignment: Lab #4  Exercise #2
  
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link:
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "../header/simAVRHeader.h"
#endif

enum States{start, A00, A01, A10, A11}state;

void Tick(){
        switch(state){//transitions
                case start:
                        PORTC = 0x07; state = A00; break;
                case A00:
                        if (PINA & 0x03 == 0) {state = A00;}
                        else if(PINA & 0x03 == 1) {
				state = A01;
				if(PORTC > 0){PORTC -= 1;}
			}
			else if(PINA & 0x03 == 2) {
				state = A10;
				if(PORTC < 9){PORTC += 1;}
			}
			else if(PINA & 0x03 == 3) {state = A11; PORTC = 0;}
                        break;

                case A01:
			if (PINA & 0x03 == 0) {state = A00;}
                        else if(PINA & 0x03 == 1) {
                                state = A01;
                        }
                        else if(PINA & 0x03 == 2) {
                                state = A10;
                                if(PORTC < 9){PORTC += 1;}
                        }
                        else if(PINA & 0x03 == 3) {state = A11; PORTC = 0;}
                        break;

                case A10:
			if (PINA & 0x03 == 0) {state = A00;}
                        else if(PINA & 0x03 == 1) {
                                state = A01;
                                if(PORTC > 0){PORTC -= 1;}
                        }
                        else if(PINA & 0x03 == 2) {
                                state = A10;
                        }
                        else if(PINA & 0x03 == 3) {state = A11; PORTC = 0;}
                        break;

                case A11:
			if (PINA & 0x03 == 0) {state = A00;}
                        else if(PINA & 0x03 == 1) {
                                state = A01;
                                if(PORTC > 0){PORTC -= 1;}
                        }
                        else if(PINA & 0x03 == 2) {
                                state = A10;
                                if(PORTC < 9){PORTC += 1;}
                        }
                        else if(PINA & 0x03 == 3) {state = A11;}
                        break;

                case default:
			break;
        }
}

int main(void) {
        DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0XFF; PORTC = 0x00;
        state = start;
        while(1) {Tick();}

        return 1;
}
