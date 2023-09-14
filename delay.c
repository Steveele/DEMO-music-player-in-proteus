#include "NXP/iolpc2124.h"
#include "delay.h"

void delay(int x)
{
  unsigned int temp, ct;
    for(ct=0; ct<30; ct++) {
        for(temp=0; temp < x; temp++);
    }  
}