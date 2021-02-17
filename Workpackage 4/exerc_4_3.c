#include <time.h>
#include <stdio.h>

void f_delay(int);
unsigned char random_inport( void);
void printport( int);
void convert(int bin[4]);

int main(){
	int nr;
	unsigned char port;
	srand(time(0)); 
	for ( nr=0; nr < 10; nr++){   
		port = random_inport();   
		printport( port);   
		f_delay(5);
	}
	return(0);
}

void f_delay( int tenth_sec){   
	clock_t start_t, end_t;   
	long int i;   
	start_t = clock();   
	do{      
		for(i=0; i< 10000000; i++);      
		end_t = clock();
	}while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
	return;
}

unsigned char random_inport( void){
	unsigned char inport = 0;
	inport=  rand() % 256;
	return (inport);
}

void printport( int portvalue){
	int binchar[8], key[4], rest,j, i=0;
	rest = portvalue;
	while(rest!=0){
		binchar[i++]= rest % 2;
		rest = rest / 2;
	}
	// Fill to 8 bits
	while( i<8){
		binchar[i++]=0;
	}
	// Print bits and at the end corresponding decimal value
	for (j = i - 1;j > -1;j--) {
		if(binchar[7] == 0) {
			printf("  %d", binchar[j]);
			if (j < 4) key[j] = binchar[j];
		}
	}
	if (binchar[7] == 0) {
		convert(key);
		printf("\n");
	}
	return;
}

void convert(int bin[4]) {
	int key = 0, hex = 0, remainder, k = 1;
	for (int i = 3; i > -1; i--) {
		key *= 10;
		key += bin[i];
	}
	while (key != 0) {
		remainder = key % 10;
		hex = hex + remainder * k;
		k = k * 2;
		key = key / 10;
	}
	printf("\nThe %1X-key was pressed\n", hex);
}