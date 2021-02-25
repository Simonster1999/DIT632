/* --- Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD Data direction register D
PORTD Outport D
PIND Inport D
*/

const int ROW1 = 11;
const int ROW2 = 10;
const int ROW3 = 9;
const int ROW4 = 8;
const int COL1 = 7;
const int COL2 = 6;
const int COL3 = 5;
const int COL4 = 4;

char keynumber = 'X';
bool keyhit = false;

void setup()
{
	DDRD = 0x00;
    DDRB= 0xFF;

    Serial.begin(9600);

  	attachInterrupt(digitalPinToInterrupt(2), keyboardirq, FALLING);
}

void loop()
{
    if (keyhit) {
      
        Serial.println(keynumber);
      	keyhit = false;
    }
}

char keyPress()
{
  	digitalWrite(ROW1, HIGH);
  	digitalWrite(ROW2, HIGH);
  	digitalWrite(ROW3, HIGH);
  	digitalWrite(ROW4, HIGH);

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
  	
  	digitalWrite(ROW1, LOW);
  	digitalWrite(ROW2, LOW);
  	digitalWrite(ROW3, LOW);
  	digitalWrite(ROW4, LOW);
  
  
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

void keyboardirq() {
  
  if(!keyhit){
    
    keynumber = keyPress();
  	keyhit = true;
  }
}