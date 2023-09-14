#include "NXP/iolpc2148.h"
#include "keypad.h"

unsigned int range=0,i;
unsigned char r_loc,c_loc;
unsigned char key[4][3]={"123","456","789","*0#"};

unsigned char keypad()
{
    IO1PIN &= ~(0xff<<16);
    IO1PIN |= 0xf0<<16;

    while(c1 && c2 && c3); //lock if all c are high
    while(!c1 || !c2 || !c3) { // loop if one c is low
        if(!c1 && c2 && c3)     c_loc=0; // if c1 is low
        else if(c1 && !c2 && c3)    c_loc=1; //if c2 is low
        else if(c1 && c2 && !c3)    c_loc=2; //if c3 is low

        IO1CLR = 1<<16; //ground r0
        IO1SET = 0x0e<<16; // r1, r2 and r3 high
        if(!c1 || !c2 || !c3) { // if one of c is low
            r_loc=0; // row is 0
            break;
        }

        IO1CLR = 1<<17; // ground r1
        IO1SET = 0x0d<<16; // set r0, r1 and r3
        if(!c1 || !c2 || !c3) { // if one of c is low
            r_loc=1; //row is 1
            break;
        }
        
        IO1CLR = 1<<18; // ground r2
        IO1SET = 0x0b<<16; // set r0 r1 and r3 
        if(!c1 || !c2 || !c3) { // if one of c is low
            r_loc=2; //row is 2
            break;
        }

        IO1CLR = 1<<19; // ground r3
        IO1SET = 0x07<<16; // set r0 r1 and r2
        if(!c1 || !c2 || !c3) { // if one of c is low
            r_loc=3; //row is 3
            break;
        }
    }
    while(!c1 || !c2 || !c3); // stop if all c are high
    return (key[r_loc][c_loc]); //return row and column
}