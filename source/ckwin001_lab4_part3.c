/*         Your Name & E-mail: Casey Kwinn, ckwin001@ucr.edu
*          Lab Section:023
 *         Assignment: Lab #4  Exercise #3
  
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link:
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "../header/simAVRHeader.h"
#endif

enum States{start, 0, 1, 2, 3}state;

void Tick(){
        switch(state){//transitions
                case start:
                        PORTB = 0x00; state = 0; PORTC = state; break;
                case 0:
			if (PORTA & 0x07 == 1) {state = 1;}
			else {state = 0;}
			PORTC = state; break;
		case 1:
			if (PORTA & 0x07 == 0) {state = 2;}
			else {state = 0;}
			PORTC = state; break;
                case 2:
			if (PORTA & 0x07 == 2) {state = 3; PORTB = 1;}
			else {state = 0;}
			PORTC = state; break;
		case 3:
			if (PORTA & 0x80) {state=0; PORTB=0;}
			else {state = 3;}
			PORTC = state; break;
                case default: break;
        }
}

int main(void) {
        DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
        DDRC = 0XFF; PORTC = 0x00;
        state = start;
        while(1) {Tick();}
        return 1;
}
