#include "LCD.h"
	
//1. Declerations Section
//Variables
unsigned char uppernibble, lowernibble, uppernibble2, uppernibble3, lowernibble3;
unsigned long PB;
unsigned long EN;
//char Locked[8];

//2. Function Definitions
void lcdWriteChar(char c3){
	lcdRS = 0x04;								//set RS to high for command entry for data entry
	uppernibble3 = (c3&0xF0);		//Bit masking for only the upper nibble
	lowernibble3 = (c3&0x0F);		//Bit masking for only the lower nibble
	lcdDB = (uppernibble3>>2);	//Writing uppernibble to lcd, shifting two to the right for PB2-5
	lcdENpulse();								//Pulse EN line
	lcdDB = (lowernibble3<<2);	//Writing lowernibble to lcd, shifting two to the left for PB2-5 
	lcdENpulse();								//Pulse EN line
	SysTick_Wait_50ns(3000);		//Wait 150us
}

void lcdWriteHalfCommand(unsigned char c2){
	lcdRS = 0x00;								//set RS to 0 for command entry 
	uppernibble2 = (c2&0xF0);		//Bit masking for only the upper nibble
	lcdDB = (uppernibble2>>2);	//Writing uppernibble to lcd, shifting two to the right for PB2-5
	lcdENpulse();								//Pulse EN line
	SysTick_Wait_1us(4200);			//Wait 4.2ms
}

void lcdWriteCommand(unsigned char c){
	lcdRS = 0x00;								//set RS to 0 for command entry
	uppernibble = (c&0xF0);			//Bit masking for only the upper nibble
	lowernibble = (c&0x0F);			//Bit masking for only the lower nibble
	lcdDB = (uppernibble>>2);		//Writing uppernibble to lcd, shifting two to the right for PB2-5
	lcdENpulse();								//Pule EN line
	lcdDB = (lowernibble<<2);		//Writing lowernibble to lcd, shifting two to the left for PB2-5
	lcdENpulse();								//Pulse EN line
	SysTick_Wait_1us(3200);			//Wait 3.2ms
}

void lcd_Init(void){
	lcdEN = 0x00;								//clear EN
	lcdDB = 0x00;								//clear DB
	lcdRS = 0x00;								//clear RS
	SysTick_Wait_1us(100000);		//Wait 100ms
	lcdWriteHalfCommand(0x30);	//Send 0011 to DB
	lcdWriteHalfCommand(0x30);	//Send 0011 Again
	lcdWriteHalfCommand(0x30);	//Send 0011 Again
	lcdWriteHalfCommand(0x20);	//Send 0010 to set lcd to 4-bit mode
	lcdWriteCommand(0x28);			//Send 0010 followed by 1000 to lcd. Set to two Lines and Small font
	lcdWriteCommand(0x0F);			//Send 0000 followed by 1111 to turn display cursor and blinking on 
	lcdWriteCommand(0x01);			//Send 0000 followed by 0001 to clear display
	lcdWriteCommand(0x06);			//Send 0000 followed by 0110 to set Increment on
	
	//Initilalization over
}

void lcdENpulse(void){
	lcdEN = 0x08;								//set EN as high
	SysTick_Wait_50ns(20); 			//Delay 1us
	lcdEN = 0x00;								//clear EN
}

void lcdClearScreen(void){				
	lcdWriteCommand(0x01);			//Clears LCD screen
}

void lcdWriteString (char *string) {
	while(*string){							//While loop for writing string
		lcdWriteChar(*string);		//Send String to lcd
		string++;									//Increment string
	}
}

void lcdGoto(int line,char input){
	if(line == 1){
	lcdWriteCommand(0x80+input-1);
	}else if (line==2)
	{
		lcdWriteCommand(0x80+64-1+input);
	}	
}
void lcdLoadCustomCharacters(void){
	char Locked[8] = {0x0E,
	0x11, //0x11
	0x11,
	0x11,
	0x1F,
	0x1B,
	0x1B,
	0x1F
};
	unsigned long Unlocked[8] = {
	0x1F,
	0x11,
	0x10,
	0x10,
	0x1F,
	0x1B,
	0x1B,
	0x1F
};
	
unsigned long ball1[8] = {
	0x00,
	0x00,
	0x00,
	0x18,
	0x18,
	0x00,
	0x00,
	0x00
};

unsigned long ball2[8] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x06,
	0x06,
	0x00
};

unsigned long ball3[8] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x01,
	0x01
};

unsigned long ball4[8] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x10,
	0x10
};

unsigned long ball5[8] = {
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x0C,
	0x0C,
	0x00
};

unsigned long ball6[8] = {
	0x00,
	0x00,
	0x00,
	0x03,
	0x03,
	0x00,
	0x00,
	0x00
};
	lcdWriteCommand(0x40);
	int i;
	for(i=0;i<8;i++) {
		lcdWriteChar(Locked[i]);
	}
	for(i=0;i<8;i++) {
		lcdWriteChar(Unlocked[i]);
	}
	for(i=0;i<8;i++) {
		lcdWriteChar(ball1[i]);
	}
	for(i=0;i<8;i++) {
		lcdWriteChar(ball2[i]);
	}
	for(i=0;i<8;i++) {
		lcdWriteChar(ball3[i]);
	}
	for(i=0;i<8;i++) {
		lcdWriteChar(ball4[i]);
	}
	for(i=0;i<8;i++) {
		lcdWriteChar(ball5[i]);
	}
	for(i=0;i<8;i++) {
		lcdWriteChar(ball6[i]);
	}
  lcdWriteCommand(0x02);
}
