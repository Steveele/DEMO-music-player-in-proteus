#include "NXP/iolpc2148.h"
#define bit(x) (1<<x) 

void lcd_init(void); 
void command(unsigned char a); 
void printChar(unsigned char b); 
void prinString(unsigned char *s); 
void lcd_delay(void);