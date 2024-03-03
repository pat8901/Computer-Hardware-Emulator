// Main entry point to start the emulation (to be implemented)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <../header/register.h>
#include "../header/clock.h"
#include <../header/ram/ram.h>

#define high 1
#define low 0

extern struct Clock c; // initial declaration in clock.c
extern struct Register reg;
extern struct Ram ram;

int main(void)
{
    // testing
    char a[16];
    printf("size of array: %lu bytes\n", sizeof(a));
    printf("size of element: %lu byte(s)\n", sizeof(a[0]));

    printf("index 0 value: 0x%02X\n", a[0]);
    a[0] = 0x42;
    printf("index 0 value: 0x%d\n", a[0]);
    printf("size of element: %lu byte(s)\n", sizeof(a[0]));
    printf("size of array: %lu bytes\n", sizeof(a));
    //
    printMem();

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