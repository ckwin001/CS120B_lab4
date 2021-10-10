#include <avr/io.h>
#ifdef _SIMULATE_
#include "../header/simAVRHeader.h"
#endif

enum States{start, offRelease, onPress, onRelease, offPress}state;

void Tick(){
	switch(state){//transitions
		case start:
			PORTB = 0x01; state = offRelease; break;
		case offRelease:
			if (PINA & 0x01) {state = onPress; B = 0x02;}
			else {state = offRelease;}
			break;
		case onPress:
			if (PINA & 0x01) {state = onPress;}
			else {state = onRelease;}
			break;
		case onRelease:
			if (PINA & 0x01) {state = offPress; B = 0x01;}
			else {state = onRelease;}
			break;
		case offPress:
			if(PINA & 0x01) {state = offPress;}
			else {state = offRelease;}
			break;
		case default:
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0XFF; PORTB = 0x00;
	state = start;
	while(1) {Tick();}
	
	return 1;
}
