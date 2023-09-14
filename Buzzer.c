#include "Buzzer.h"
#include "NXP/iolpc2148.h"

void Buzzer_C_on(void)
{
 IO1DIR |= bit(23);
 IO1SET |= (1<<23);
 
}
void Buzzer_C_off(void)
{
  IO1DIR |= (1<<23);
  IO1CLR |= bit(23);
}

void Buzzer_D_on(void)
{
 IO1DIR |= bit(24);
 IO1SET |= (1<<24); 
}
void Buzzer_D_off(void)
{
  IO1DIR |= (1<<24);
  IO1CLR |= bit(24);
}

void Buzzer_E_on(void)
{
 IO1DIR |= bit(25);
 IO1SET |= (1<<25);
 
}
void Buzzer_E_off(void)
{
  IO1DIR |= (1<<25);
  IO1CLR |= bit(25);
}

void Buzzer_F_on(void)
{
 IO1DIR |= bit(26);
 IO1SET |= (1<<26);
 
}
void Buzzer_F_off(void)
{
  IO1DIR |= (1<<26);
  IO1CLR |= bit(26);
}

void Buzzer_G_on(void)
{
 IO1DIR |= bit(27);
 IO1SET |= (1<<27);
 
}
void Buzzer_G_off(void)
{
  IO1DIR |= (1<<27);
  IO1CLR |= bit(27);
}

void Buzzer_A_on(void)
{
 IO1DIR |= bit(28);
 IO1SET |= (1<<28);
 
}
void Buzzer_A_off(void)
{
  IO1DIR |= (1<<28);
  IO1CLR |= bit(28);
}

void Buzzer_B_on(void)
{
 IO1DIR |= bit(29);
 IO1SET |= (1<<29);
 
}
void Buzzer_B_off(void)
{
  IO1DIR |= (1<<29);
  IO1CLR |= bit(29);
}
