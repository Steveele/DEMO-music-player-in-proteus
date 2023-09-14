#include "NXP/iolpc2148.h"
#include "delay.h"
#include "keypad.h"
#include "lcd.h"
#include "Buzzer.h"
#include "MusicCollection.h"

#define bit(x) (1<<x) //define macro for lcd


unsigned char pass[4] = "0852"; 
unsigned char choice[4] = "1234";
  unsigned char inp[1];

int passErrorCount = 0;
int passErrorCount2 = 0;
void takePassword();

void showMusicList();

int main()
{
    
    unsigned char rx_arr[4]; // accepts data from keypad
    int count;  
    
    VPBDIV=0x01;                 // PCLK = 60MHz
    IO1DIR |= 0x0f<<16;    // p1.16 - p1.19 as o/p for the key pad rows A,B,C,D 
    IO0DIR |= 0xf00fc;  //p0.02 - p0.07 for LCD and p0.16 - p0.18 for the DC motor
    
    lcd_init();
    delay(7000);
    command(0x80); //fisrt line fisrt position
    printString(" WELCOME TO MUSIC");
     command(0XC5);
     printString("PLAYER");
     delay(15000);
     command(0x01);
     
     command(0x80);
    printString("ENTER PASSWORD");
    command(0xc5);
    printString("TO LOGIN");
    delay(10000);
    
    while(1)     
    { 
    space: 
      if(passErrorCount<3){
        if (passErrorCount ==0) 
        { command(0x01);
          command(0x80);
          printString("  Password ");
        }
        else
        {
          command(0x80);
          printString("Enter Again");
        }
        
        command(0xc5); //set cursor to second row 5th posistion
        for(count=0; count < 4; count++) 
        {
          rx_arr[count] = keypad();
          printChar('*');
        }
    
        if ((pass[0] == rx_arr[0]) && (pass[1] == rx_arr[1]) && (pass[2] == rx_arr[2]) && (pass[3] == rx_arr[3]) )
        {
          showMusicList();
          break;
        }
        else
        {          
          command(0x80); 
          printString("~Wrong Password~");                
          delay(7000);
          command(0x01);  
          
           Buzzer_D_on();
            delay(10000);
             Buzzer_D_off();
            delay(5000);
          
          passErrorCount++;        
        }        
      }
    else
    {      
          passErrorCount2++;
          passErrorCount=0;
          
          if(passErrorCount2 < 2)
          {
            
             
            
             command(0x80); 
          printString("wait 5 sec");                
          delay(10000);
          command(0xc5);
          printString("five");
          delay(10000);
          command(0xc5);
          printString("four");
          delay(10000);
          command(0xc5);
          printString("three");
          delay(10000);
          command(0xc5);
          printString(" two ");
          delay(10000);
          command(0xc5);
          printString(" one");
          delay(10000);
          command(0xc5);
          
          
          delay(10000);
            
            goto space;
          }
          else
          {
            command(0x01);
            command(0x80);
            
            printString("You are locked");
            
              Buzzer_D_on();
            delay(20000);
             Buzzer_D_off();
            delay(5000);
            
            passErrorCount2 = 0;
            passErrorCount = 0;
            break;          
            
          }
    }
}
}
void showMusicList()
{   
  command(0x01);
     command(0x80);
    printString("OPENNING....");
    command(0xc0);
    printString("COLLECTION ");
        delay(20000);

list :
  command(0x01);
  
  
    command(0x80);
    printString("1. dispacito    ");
    command(0xc0);
    printString("2. my love   ");
    
    delay(7000);
    
    command(0x01);
    command(0x80);
    printString("3. country");
    command(0xc0);
    printString("4. nalegn   ");
    Buzzer_C_off();
    delay(5000);
   
    inp[0] = keypad();
    
    if(choice[0] == inp[0])
    {
      command(0x01);
      command(0x80);
      printString("Now palying...");
      command(0xc0);
      printString("Dispacito");
      
      for(int i =0; i < 2; i++)
      {
        inp[0] = 0;
        Dispacito();
      }
      
      goto list;
      
    }
    else if(choice[1] == inp[0])
    {
      command(0x01);
      command(0x80);
      printString("Now palying...");
      command(0xc0);
      printString("MY LOVE");
        for(int i =0; i < 2; i++)
      {
        inp[0] = 0;
        myLove();
      }
      
      goto list;
     // break;
      
    }
    else if(choice[2] == inp[0])
    {
      command(0x01);
      command(0x80);
      printString("Now palying...");
      command(0xc0);
      printString("country");
      for(int i =0; i < 2; i++)
      {
        inp[0] = 0;
        country();
      }
      
      goto list;
      //break;
      
    }
    else if(choice[3] == inp[0])
    {
      command(0x01);
      command(0x80);
      printString("Now palying...");
      command(0xc0);
      printString("nalegn");
      
      for(int i =0; i < 2; i++)
      {
        inp[0] = 0;
        nalegn();
      }
      goto list;
      //break;
      
    }
    else 
    {
    // continue;  
    }   
       
  
}














