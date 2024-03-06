// 8-bit general purpose register
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../header/registers/register.h"
#include "../../header/clock/clock.h"

#define high 1
#define low 0

void setRegisterInputsRandom(struct Register *ptr_reg)
{
    srand(time(NULL));

    ptr_reg->D0 = rand() % 2;
    ptr_reg->D1 = rand() % 2;
    ptr_reg->D2 = rand() % 2;
    ptr_reg->D3 = rand() % 2;
    ptr_reg->D4 = rand() % 2;
    ptr_reg->D5 = rand() % 2;
    ptr_reg->D6 = rand() % 2;
    ptr_reg->D7 = rand() % 2;
}

/*Information meeting the setup and hold time requirements of the D inputs is
transferred to the Q outputs on the LOW-to-HIGH transition of the clock input.*/
void setRegisterOutputs(struct Register *ptr_reg)
{
    ptr_reg->Q0 = ptr_reg->D0;
    ptr_reg->Q1 = ptr_reg->D1;
    ptr_reg->Q2 = ptr_reg->D2;
    ptr_reg->Q3 = ptr_reg->D3;
    ptr_reg->Q4 = ptr_reg->D4;
    ptr_reg->Q5 = ptr_reg->D5;
    ptr_reg->Q6 = ptr_reg->D6;
    ptr_reg->Q7 = ptr_reg->D7;
}

void printRegisterInputs(struct Register *ptr_reg)
{
    printf("Register Input: %d %d %d %d %d %d %d %d || ", ptr_reg->D0, ptr_reg->D1, ptr_reg->D2, ptr_reg->D3, ptr_reg->D4, ptr_reg->D5, ptr_reg->D6, ptr_reg->D7);
}

void printRegisterOutputs(struct Register *ptr_reg)
{
    printf("Register Output: %d %d %d %d %d %d %d %d\n", ptr_reg->Q0, ptr_reg->Q1, ptr_reg->Q2, ptr_reg->Q3, ptr_reg->Q4, ptr_reg->Q5, ptr_reg->Q6, ptr_reg->Q7);
}
