#include "Animations.h"

//1. Function Definitions Section
void Loading_Screen(int seconds){
		unsigned long i;
	for (i=0;i<seconds;i++){
		lcdWriteCommand(0x02);
		lcdWriteString("Calculator (:+})");
		lcdWriteCommand(0xC0);
		lcdWriteString("Loading");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("Calculator (;+})");
		lcdWriteCommand(0xC0);
		lcdWriteString("Loading.");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("Calculator (:+})");
		lcdWriteCommand(0xC0);
		lcdWriteString("Loading..");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("Calculator (;+})");
		lcdWriteCommand(0xC0);
		lcdWriteString("Loading...");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("Calculator (:+})");
		lcdWriteCommand(0xC0);
		lcdWriteString("Loading....");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("Calculator (;+})");
		lcdWriteCommand(0xC0);
		lcdWriteString("Loading.....");
		SysTick_Wait_1us(200000);
		lcdClearScreen();
	}
}


void Loading_Screen2(void){
	lcdWriteCommand(0x02);
		lcdWriteString("a              d");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("oa            di");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("Loa          din");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString(" Loa        ding");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("  Loa      ding ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("   Loa    ding  ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("    Loa  ding   ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading    ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading.   ");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading..  ");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading... ");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading    ");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading.   ");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading..  ");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0x02);
		lcdWriteString("     Loading... ");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0xC0);
		lcdWriteString("       <>       ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString("      <-->      ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString("     <---->     ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString("    <------>    ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString("   <-------->   ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString("  <---------->  ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString(" <------------> ");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString("<-------------->");
		SysTick_Wait_1us(200000);
		lcdWriteCommand(0xC0);
		lcdWriteString("<------W!------>");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0xC0);
		lcdWriteString("<-----Wee!----->");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0xC0);
		lcdWriteString("<----Welme!---->");
		SysTick_Wait_1us(250000);
		lcdWriteCommand(0xC0);
		lcdWriteString("<---Welcome!--->");
		SysTick_Wait_1us(2500000);
		lcdClearScreen();
}

void Loading_Screen_Animated(int runs){
	lcdClearScreen();
	lcdWriteCommand(0x0C);
	int b;
	int f;
	for(f=0;f<runs;f++)
	{
	
	for(b=1;b<16;b+=2)
	{
		lcdGoto(1,1);
		lcdWriteString("     Loading.   ");
		lcdGoto(2,b);
		lcdWriteChar(2);
		SysTick_Wait_1us(40000);
		lcdClearScreen();
		lcdGoto(1,1);
		lcdWriteString("     Loading..  ");
		lcdGoto(2,b);
		lcdWriteChar(3);
		SysTick_Wait_1us(40000);
		lcdClearScreen();
		lcdGoto(1,1);
		lcdWriteString("     Loading... ");
		lcdGoto(2,b);
		lcdWriteChar(4);
		lcdGoto(2,1+b);
		lcdWriteChar(5);
		SysTick_Wait_1us(40000);
		lcdClearScreen();
		lcdGoto(1,1);
		lcdWriteString("     Loading..  ");
		lcdGoto(2,1+b);
		lcdWriteChar(6);
		SysTick_Wait_1us(40000);
		lcdClearScreen();
		lcdGoto(1,1);
		lcdWriteString("     Loading.   ");
		lcdGoto(2,1+b);
		lcdWriteChar(7);
		SysTick_Wait_1us(40000);
		lcdClearScreen();
	}
	
	
}
	lcdWriteCommand(0x0F);
}
