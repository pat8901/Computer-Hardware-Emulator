// 8-bit general purpose register

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <../header/register.h>
#include "../header/clock.h"

#define high 1
#define low 0

struct Register reg;
extern struct Clock c; // initial declaration in clock.c
int startClock();

void setRegisterInputsRandom()
{
    srand(time(NULL));

    reg.D0 = rand() % 2;
    reg.D1 = rand() % 2;
    reg.D2 = rand() % 2;
    reg.D3 = rand() % 2;
    reg.D4 = rand() % 2;
    reg.D5 = rand() % 2;
    reg.D6 = rand() % 2;
    reg.D7 = rand() % 2;
}

/*Information meeting the setup and hold time requirements of the D inputs is
transferred to the Q outputs on the LOW-to-HIGH transition of the clock input.*/
void setRegisterOutputs()
{
    reg.Q0 = reg.D0;
    reg.Q1 = reg.D1;
    reg.Q2 = reg.D2;
    reg.Q3 = reg.D3;
    reg.Q4 = reg.D4;
    reg.Q5 = reg.D5;
    reg.Q6 = reg.D6;
    reg.Q7 = reg.D7;
}

void printRegisterInputs()
{
    printf("Register Input: %d %d %d %d %d %d %d %d || ", reg.D0, reg.D1, reg.D2, reg.D3, reg.D4, reg.D5, reg.D6, reg.D7);
}

void printRegisterOuputs()
{
    printf("Register Output: %d %d %d %d %d %d %d %d\n", reg.Q0, reg.Q1, reg.Q2, reg.Q3, reg.Q4, reg.Q5, reg.Q6, reg.Q7);
}

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