#ifndef ANIMATIONS_H
#define ANIMATIONS_H

/** Animations Class
* @brief Contains the code for the Animations
* @authors Syed A. A. Zaidi, Bilaal Bashir
* @date 12/11/2018
*/

//1. Directives Section
#include "PLL_1.h"
#include "LCD.h"
#include <stdio.h>
#include "UART.h"


//2. Global Functions Declaration Section
/** Loading Screen 1 
*@param seconds How long to run the Animation for
*/
void Loading_Screen(int seconds);

/** Loading Screen 2 */
void Loading_Screen2(void);

/** Loading Screen Animated */
void Loading_Screen_Animated(int runs);

#endif


