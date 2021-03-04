#define ML13_Status 0x0B10
#define ML13_Control 0x0B00

// Status
#define CLOSING     0b110000000
#define OPENING     0b101000000
#define S2          0b100100000
#define S1          0b100010000
#define SENSOR      0b100001000

// Control
#define CLOSE       0b000000010
#define OPEN        0b000000001

void setup() {

    CLOSE = 1;
    attachInterrupt(digitalPinToInterrupt(SENSOR), sensorirq, HIGH);
}

void main() {
    
    while (1) {
        
    }
} 

void sensorirq() {

    // if not open
    if(S1 != 1) {
        OPEN = 1;

        // while oopening
        while(OPENING == 1) {}
    }
    
    // delay before closing
    for(int i = 0; i < 100; i++) {}

    CLOSE = 1;
}