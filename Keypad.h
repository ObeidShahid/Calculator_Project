#ifndef _KEYPAD_H
#define _KEYPAD_H

/** Keypad Class
* @brief Contains the code for the Keypad
* @authors Syed A. A. Zaidi, Bilaal Bashir
* @date 12/11/2018
*/

//1. Directives Section
#include <stdio.h>   // standard C library 
#include "UART.h"    // functions to implment input/output
#include "LCD.h"
#include "PLL_1.h"

//2. Global Functions Declerations Section
/** Initialise Keypad */
void Keypad_Init(void);

/** Read Keypad Value 
*@return Value of Button Pressed
*/
unsigned char readKeypad (void);

/** Read Input Value for PIN Function
*@param in The Key that was pressed (float)
*/
void ReadValue(float in);

/** Reset Answer for PIN Function */
void ResetAnswer(void);


//3. Global Variables Section
extern float Answer;

#endif

