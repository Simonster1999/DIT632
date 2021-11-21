/*====================================
File name : exerc_4_4.c
Date : 2021 - 02 - 19
Group nr 7
Members that contribute to the solutions
Emil Gustafsson
Mattias Ekdahl
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [VGP9-HVEG-QSCW-K7ZD]
====================================== */

// ---- Program template for Arduino in Tinkercad VT 2021
#include <avr/io.h>
#include <util/delay.h>

/* --- Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD Data direction register D
PORTD Outport D
PIND Inport D
*/

/**
 * This program lights the first two out of eight diodes and then cycles through all of them by repeatedly pushing the lights one step to the left. 
 *
 *
 * Purpose: Demonstration of Exerc_4_4
 * DIT632
 *
 * Author: Emil Gustafsson, Mattias Ekdahl 2021
 *
**/

void setup() { 
 // all D ports set to outbits. 
 DDRD = 0xFF;
 // all B ports set to inbits.
 DDRB = 0x00;
 // initial values in D ports 0-7 set to 00000011
 PORTD = B00000011;
}
void loop() {
 // ------ Main loop-------
  // only run if input is set to 1
  if(digitalRead(8) == 1) {
  	// handle the case where the last diode is lit. If its value is 1, rotate bits one step to the left and then write port 7's value onto port 0.
    if (digitalRead(7) == 1){
      PORTD = PIND << 1;
      digitalWrite(0, 1);
    }
    // if the last diode is not lit, rotate the bits one step to the left.
    else {

       PORTD = PIND << 1;
    }
  }
// wait for 500 millisecond(s) before looping again
delay(500); 
}
