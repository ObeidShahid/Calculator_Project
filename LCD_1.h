#ifndef LCD_H
#define LCD_H

void lcd_Init(void);
void lcdENpulse(void);
void lcdClearScreen(void);
void lcdWriteCommand(unsigned char c);
void lcdRS_reset(void);
#endif
