// Main entry point to start the emulation (to be implemented)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <../header/register.h>
#include "../header/clock.h"

#define high 1
#define low 0

extern struct Clock c; // initial declaration in clock.c
extern struct Register reg;

int main(void)
{
    c.power = high;
    c.timing = 1000000;
    c.status = low;
    // Look into platform specific C librarys to implement this
    // for changeing the value on key press
    reg.mr = low;

    while (c.power == high)
    {
        startClock();
        reg.cp = c.status;
        if (reg.cp == high)
        {
            setRegisterOutputs();
            setRegisterInputsRandom();
        }
        printRegisterInputs();
        printRegisterOuputs();
    }

    return 0;
}