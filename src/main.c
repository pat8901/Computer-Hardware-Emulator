// Main entry point to start the emulation (to be implemented)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <../header/registers/register.h>
#include "../header/clock/clock.h"
#include <../header/ram/ram.h>
#include <../header/registers/instruction_register.h>
#include <../header/registers/instruction_pointer.h>

#define high 1
#define low 0

extern struct Clock c; // initial declaration in clock.c
extern struct Register reg;
extern struct Ram ram;
extern struct InstructionRegister ir;
extern struct InstructionPointer ip;

int main(void)
{
    // loading program
    loadProgramRandom();
    setStartInstruction();
    setStartNextInstruction();

    printMem();

    // Starting clock
    c.power = high;
    c.timing = 1000000;
    c.status = low;
    reg.mr = low;

    // Running CPU
    while (ir.current_instr < 16 || ip.next_instr < 16)
    {
        startClock();
        reg.cp = c.status;

        // When clock signal is 1 (rising edge triggered)
        if (reg.cp == high)
        {
            setRegisterOutputs();
            setRegisterInputsRandom();
            getMemValue(ir.current_instr);
            ir.current_instr = ip.next_instr;
            ip.next_instr++;
        }
        printRegisterInputs();
        printRegisterOuputs();
    }

    return 0;
}

// while (c.power == high)
// {
//     startClock();
//     reg.cp = c.status;
//     if (reg.cp == high)
//     {
//         setRegisterOutputs();
//         setRegisterInputsRandom();
//     }
//     printRegisterInputs();
//     printRegisterOuputs();
// }

// return 0;
//}