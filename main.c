/*	Author: jiakangliu
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum states {START, OFF, PRESS, RELEASE, ON}state;

unsigned char tickFuc(){
  unsigned char tmpB = 0x00;
  switch (state) {
    case OFF:
      if(PINA == 0x04)
        state = PRESS;
      else
        state = OFF;
      break;
    case PRESS:
      if(PINA == 0x00)
        state = RELEASE;
      else
        state = OFF;
      break;
    case RELEASE:
      if(PINA == 0x02)
        state = ON;
      else
        state = OFF;
      break;
    case ON:
      if(PINA == 0x80)
        state = OFF;
      else
        state = ON;
      break;
    default:
      state = OFF;
      break;
  }
  switch (state) {
    case OFF:
      tmpB = 0x00;
      break;
    case PRESS:
      tmpB = 0x00;
      break;
    case RELEASE:
      tmpB = 0x00;
      break;
    case ON:
      tmpB = 0x01;
      break;
    default:
      break;
  }
  return tmpB;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    state = OFF;

    /* Insert your solution below */
    while (1) {
      PORTB = tickFuc();
    }
    return 1;
}
