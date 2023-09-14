#include "NXP/iolpc2148.h"
#include "lcd.h"

void lcd_init()
{
  
     command(0x02); // Return cursor to home position 
    command(0x28); //word length 4 bit, 2 line
    command(0x0c); // display on, cursor off
    command(0x06); // to move the cursor to the right
    command(0x80); // Force cursor to beginning of 1st row
}
 
void command(unsigned char a)
{
    IO0PIN &= 0xffffff03;
    IO0PIN |= (a & 0xf0) << 0;
    IO0CLR |= bit(2);                //rs=0 register select as command
    IO0CLR |= bit(1);                //rw=0 write only
    IO0SET |= bit(3);                 //en=1
    lcd_delay();
    IO0CLR |= bit(3);                 //en=0
    
    IO0PIN &= 0xffffff03;
    IO0PIN |= ((a << 4)  & 0xf0) << 0;
    IO0CLR |= bit(2);                //rs=0
    IO0CLR |= bit(1);                //rw=0
    IO0SET |= bit(3);                 //en=1
    lcd_delay();
    IO0CLR |= bit(3);                 //en=0
}
 
void printString(unsigned char *s) 
{
    while(*s) {
        printChar(*s++); //sends each character to the data of the LCD
    }
}

void printChar(unsigned char b)
{
    IO0PIN &= 0xffffff03;
    IO0PIN |= (b & 0xf0) << 0;
    IO0SET |= bit(2);                //rs=1 rs data to the lcd
    IO0CLR |= bit(1);                //rw=0 write only
    IO0SET |= bit(3);            //en=1
    lcd_delay();
    IO0CLR |= bit(3);            //en=0
    
    IO0PIN &= 0xffffff03;
    IO0PIN |= ((b << 4)  & 0xf0) << 0;
    IO0SET |= bit(2);                //rs=1
    IO0CLR |= bit(1);                //rw=0
    IO0SET |= bit(3);            //en=1
    lcd_delay();
    IO0CLR |= bit(3);            //en=0
}

void lcd_delay()
    {
    unsigned int i;
    for(i=0;i<=1000;i++);
}