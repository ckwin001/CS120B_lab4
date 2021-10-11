/*         Your Name & E-mail: Casey Kwinn, ckwin001@ucr.edu
*          Lab Section:023
 *         Assignment: Lab #4  Exercise #4
  
 *         I acknowledge all content contained herein, excluding template or example code, is my own original work.
 *
 *         Demo Link:
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "../header/simAVRHeader.h"
#endif

enum States{start, s0, s1, s2, s3, s4, s5}state;

void Tick(){
        switch(state){//transitions
                case start:
                        PORTB = 0x00; state = s0; PORTC = state; break;
                case s0:
			if ((PINA & 0x07) == 4) {state = s1;}
			else {state = 0;}
			PORTC = 0; break;
		case s1:
			if ((PINA & 0x07) == 0) {state = s2;}
			else {state = s0;}
			PORTC = 1; break;
                case s2:
			if ((PINA & 0x07) == 2) {state = s3; PORTB = 1;}
			else {state = s0;}
			PORTC = 2; break;
		case s3:
			if (PINA & 0x80) {state=s0; PORTB=0;}
			else if ((PINA & 0x07) == 4) {state = s4;}
			else {state = s3;}
			PORTC = 3; break;
		case s4:
			if (PINA & 0x80) {state=s0; PORTB=0;}
                        else if ((PINA & 0x07) == 0) {state = s5;}
                        else {state = s3;}
                        PORTC = 4; break;
		case s5:
			if ((PINA&0x80)||((PINA&0x07)==2)) {state=s0; PORTB=0;}
                        else {state = s3;}
                        PORTC = 5; break;
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
