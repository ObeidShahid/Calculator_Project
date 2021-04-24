#ifndef KEYPAD_TEST_H
#define KEYPAD_TEST_H

//1. Directives Section
#include <stdio.h>   // standard C library 
#include "UART.h"    // functions to implment input/output
#include "LCD.h"
#include "Keypad.h"
#include "PLL_1.h"
/**
*\brief Checks each row and column to see if the keypad is working as expected
*
*\returns 1 if all test passsed
*/
int Keypad_Test()
{
		lcdClearScreen();
		lcdGoto(1,1);
		int passed = 0;
    //Test Keypad Row1 & Col1
    lcdWriteString("Please Press 1");
		lcdGoto(2,1);
		printf("\nPress 1 on the Keypad\n");
		char KeyTest;
		KeyTest=readKeypad();			//Read Keypadinput into input2, to be used with the switch
		while (KeyTest == 'G'){		//'G' is the placeholder value that was given to the keypad in case of no new key presses
		KeyTest=readKeypad();		//Keeps reading in the input to keypad until it is not equal to the placeholder
		}
		if(KeyTest == 1)
		{
		passed = 1;
		printf("\nKeypad Test 1 Passed\n");
		} else {
			passed = 0;
			printf("\nKeypad Test 1 Failed\n");
		}
		lcdClearScreen();
		lcdGoto(1,1);
		
		
		//Test Keypad Row2 & Col2
    lcdWriteString("Please Press 5");
		lcdGoto(2,1);
		printf("\nPress 5 on the Keypad\n");
		KeyTest=readKeypad();			//Read Keypadinput into input2, to be used with the switch
		while (KeyTest == 'G'){		//'G' is the placeholder value that was given to the keypad in case of no new key presses
		KeyTest=readKeypad();		//Keeps reading in the input to keypad until it is not equal to the placeholder
		}
		if(KeyTest == 5)
		{
		passed = 1;
		printf("\nKeypad Test 2 Passed\n");
		}	else {
			passed = 0;
			printf("\nKeypad Test 2 Failed\n");
		}
		lcdClearScreen();
		lcdGoto(1,1);
		
		
		//Test Keypad Row3 & Col3
    lcdWriteString("Please Press 9");
		lcdGoto(2,1);
		printf("\nPress 9 on the Keypad\n");
		KeyTest=readKeypad();			//Read Keypadinput into input2, to be used with the switch
		while (KeyTest == 'G'){		//'G' is the placeholder value that was given to the keypad in case of no new key presses
		KeyTest=readKeypad();		//Keeps reading in the input to keypad until it is not equal to the placeholder
		}
		if(KeyTest == 9)
		{
		passed = 1;
		printf("\nKeypad Test 3 Passed\n");
		}	else {
			passed = 0;
		printf("\nKeypad Test 3 Failed\n");
		}
		lcdClearScreen();
		lcdGoto(1,1);
		
		
		//Test Keypad Row4 & Col4
    lcdWriteString("Please Press D");
		lcdGoto(2,1);
		printf("\nPress D on the Keypad\n");
		KeyTest=readKeypad();			//Read Keypadinput into input2, to be used with the switch
		while (KeyTest == 'G'){		//'G' is the placeholder value that was given to the keypad in case of no new key presses
		KeyTest=readKeypad();		//Keeps reading in the input to keypad until it is not equal to the placeholder
		}
		if(KeyTest == 'D')
		{
		passed = 1;
		printf("\nKeypad Test 4 Passed\n");
		}	else {
			passed = 0;
		printf("\nKeypad Test 4 Failed\n");
		}
		lcdClearScreen();
		lcdGoto(1,1);
    
    if (passed == 1)
		{
		lcdWriteString("Keypad Test Pass");
		printf("\nAll Keypad Tests Passed\n");
		} else if (passed == 0) {
		lcdWriteString("Keypad Test Fail");
		printf("\nNot All Keypad Tests Passed\n");
		}
		SysTick_Wait_1us(1500000);
		lcdClearScreen();
		lcdGoto(1,1);
    return passed;

}
#endif

