/*====================================
File name : exerc_6_3.c
Date : 2021 - 03 - 05
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [PZU6-9MDJ-TCWT-F4XY]
====================================== */

// Include section
#include <stdio.h>

// Define section
#define ML13_Status 0x0B10
#define ML13_Control 0x0B00
// Status
#define CLOSING 0b10000000
#define OPENING 0b01000000
#define S2      0b00100000
#define S1      0b00010000
#define SENSOR  0b00001000
// Control
#define CLOSE   0b00000010
#define OPEN    0b00000001

// Main program section

/**
 * This program is a draft of a program controlling an automatic door which will open when it detects
 * a person and will remain open for a while afterwards before closing again.
 * 
 * Purpose: Demonstration of Exerc_6_3
 * DIT632
 * 
 * Author: Mattias Ekdahl, Emil Gustafsson, Simon Engström, 2021
 * 
**/

void setup() {

    // initially closes doors. changes bit 1 to 1 in control registry
    ML13_Control = ML13_Control | CLOSE;

    // attaches an interupt triggered by the sensor detecting a person turning bit 3 to 1, HIGH
    attachInterrupt(digitalPinToInterrupt(ML13_Status & SENSOR), sensorirq, HIGH);
}

void main() {
    
    // runs indefinitely
    while (1) {
        
    }
} 

// interupt method. if a person is detected by the sensor this method is continuously called
void sensorirq() {

    // reads bit 4 of status registry. if bit is not 1, i.e. door is not open, enter if statement
    if(ML13_Status & S1 != S1) {
        
        // turns bit 0 in control registry to 1
        ML13_Control = ML13_Control | OPEN;

        // loop while bit 6 indicates that door is still opening by being 1, turns to 0 when fully open
        while(ML13_Status & OPENING == OPENING) {}
    }
    
    // delay to keep the door open a while before closing
    for(int i = 0; i < 100; i++) {}

    // tells door to begin closing by turning bit 1 to 1
    ML13_Control = ML13_Control | CLOSE;
}