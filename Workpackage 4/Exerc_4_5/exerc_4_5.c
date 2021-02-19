/*====================================
File name : exerc_4_5.c
Date : 2021 - 02 - 18
Group nr 7
Members that contribute to the solutions
Mattias Ekdahl
Emil Gustafsson
Simon Engström
Member not present at demonstration time :
---
Demonstration code : [VGP9-HVEG-QSCW-K7ZD]
====================================== */

/* --- Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD Data direction register D
PORTD Outport D
PIND Inport D
*/

//constants section
const int ROW1 = 11;
const int ROW2 = 10;
const int ROW3 = 9;
const int ROW4 = 8;
const int COL1 = 7;
const int COL2 = 6;
const int COL3 = 5;
const int COL4 = 4;

//main program section

/**
 * This program enables the use of a keypad using arduino.
 *
 *
 * Purpose: Demonstration of Exerc_4_5
 * DIT632
 *
 * Author: Simon Engström, 2021
 *
**/

void setup()
{
    //configuring the in and out ports
     DDRD = 0x00;
     DDRB= 0xFF;

    Serial.begin(9600);
}

void loop()
{
    //assigns the pressedKey attribute to the value returned by the keyPress() funsction
  char pressedKey = keyPress();
  
  //as long as the returned value does not equal "X" we print out the value
    if (pressedKey != 'X')
    {
        Serial.println(pressedKey);
        delay(1000);
    }
}

char keyPress()
{
    //we write to the input rows, and read from the output columns
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

    //for each combination of rows and columns we check if a connection has been made, and return the corrisponding number/letter
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