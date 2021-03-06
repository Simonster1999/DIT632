/*====================================
File name : exerc_5_1.c
Date : 2021 - 02 - 25
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [XNNW-YDBD-576B-5366]
====================================== */

/* --- Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD Data direction register D
PORTD Outport D
PIND Inport D
*/

// constants section
const int ROW1 = 11;
const int ROW2 = 10;
const int ROW3 = 9;
const int ROW4 = 8;
const int COL1 = 7;
const int COL2 = 6;
const int COL3 = 5;
const int COL4 = 4;

// variable declarations
char keynumber = 'X';   // most recent key
bool keyhit = false;    // has a key been pressed or not

// main program section

/**
 * This program enables the use of a keypad using arduino using interrupts instead of polling.
 *
 *
 * Purpose: Demonstration of Exerc_5_1
 * DIT632
 *
 * Author: Emil Gustafsson, Mattias Ekdahl, Simon Engström, 2021
 *
**/

void setup()
{
    // configuring the in and out ports
	DDRD = 0x00;
    DDRB= 0xFF;

    Serial.begin(9600);

    // creates a interrupt which checks whether digital pin 2 is FALLING, aka going from 1 to 0
  	attachInterrupt(digitalPinToInterrupt(2), keyboardirq, FALLING);
}

void loop()
{
    // checks if key has been hit without polling
    if (keyhit) {
      
        Serial.println(keynumber);

        // sets keyhit to false, allows for another key to be detected and read by the interupt
      	keyhit = false;
    }
}

char keyPress()
{
    // sets all rows to HIGH so each row can individually be set to LOW
  	digitalWrite(ROW1, HIGH);
  	digitalWrite(ROW2, HIGH);
  	digitalWrite(ROW3, HIGH);
  	digitalWrite(ROW4, HIGH);

    // we write to the input rows, and read from the output columns
  	digitalWrite(ROW1, LOW);
    int r1c1 = digitalRead(COL1);
    int r1c2 = digitalRead(COL2);
    int r1c3 = digitalRead(COL3);
    int r1c4 = digitalRead(COL4);
  	digitalWrite(ROW1, HIGH);
 	
  	digitalWrite(ROW2, LOW);
    int r2c1 = digitalRead(COL1);
    int r2c2 = digitalRead(COL2);
    int r2c3 = digitalRead(COL3);
    int r2c4 = digitalRead(COL4);
  	digitalWrite(ROW2, HIGH);

    digitalWrite(ROW3, LOW);
    int r3c1 = digitalRead(COL1);
    int r3c2 = digitalRead(COL2);
    int r3c3 = digitalRead(COL3);
    int r3c4 = digitalRead(COL4);
  	digitalWrite(ROW3, HIGH);

    digitalWrite(ROW4, LOW);
    int r4c1 = digitalRead(COL1);
    int r4c2 = digitalRead(COL2);
    int r4c3 = digitalRead(COL3);
    int r4c4 = digitalRead(COL4);
  	digitalWrite(ROW4, HIGH);
  	
    // sets all rows to LOW so the interrupt can detect new key presses
  	digitalWrite(ROW1, LOW);
  	digitalWrite(ROW2, LOW);
  	digitalWrite(ROW3, LOW);
  	digitalWrite(ROW4, LOW);
  
    // for each combination of rows and columns we check if a connection has been made, 
    // and return the corrisponding number/letter
    if (r1c1 == 0)
    {
        return '1';
    }
    else if (r1c2 == 0)
    {
        return '2';
    }
    else if (r1c3 == 0)
    {
        return '3';
    }
    else if (r1c4 == 0)
    {
        return 'A';
    }
    else if (r2c1 == 0)
    {
        return '4';
    }
    else if (r2c2 == 0)
    {
        return '5';
    }
    else if (r2c3 == 0)
    {
        return '6';
    }
    else if (r2c4 == 0)
    {
        return 'B';
    }
    else if (r3c1 == 0)
    {
        return '7';
    }
    else if (r3c2 == 0)
    {
        return '8';
    }
    else if (r3c3 == 0)
    {
        return '9';
    }
    else if (r3c4 == 0)
    {
        return 'C';
    }
    else if (r4c1 == 0)
    {
        return '*';
    }
    else if (r4c2 == 0)
    {
        return '0';
    }
    else if (r4c3 == 0)
    {
        return '#';
    }
    else if (r4c4 == 0)
    {
        return 'D';
    }
    else
    {
        return 'X';
    }
}

// interrupt method, triggers whenever a key is pressed
void keyboardirq() {
  
  // checks if a key has already been pressed, incase multiple interrupts are triggered by switching
  // rows to HIGH and LOW again
  if(!keyhit){

    // reads which key was pressed, assigns it to keynumber
    keynumber = keyPress();

    // assigns keyhit to true indicating that a key was pressed
  	keyhit = true;
  }
}
