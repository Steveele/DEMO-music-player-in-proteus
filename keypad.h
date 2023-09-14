#include "NXP/iolpc2148.h"

#define c1 (IO1PIN&1<<20)
#define c2 (IO1PIN&1<<21)
#define c3 (IO1PIN&1<<22)



unsigned char keypad(void);