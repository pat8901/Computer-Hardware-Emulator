// Main entry point to start the emulation (to be implemented)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../header/registers/register.h"
#include "../header/clock/clock.h"
#include "../header/ram/ram.h"
#include "../header/registers/instruction_register.h"
#include "../header/registers/instruction_pointer.h"

#define high 1
#define low 0

struct Clock clk;
struct Register reg;
struct Ram ram;
struct InstructionRegister ir;
struct InstructionPointer ip;

int main(void)
{
    // Initializing hardware
    struct Clock *ptr_clk = &clk;
    struct Ram *ram_ptr = &ram;
    struct Register *ptr_reg = &reg;
    struct InstructionPointer *ip_ptr = &ip;
    struct InstructionRegister *ir_ptr = &ir;

    // loading program
    loadProgramRandom(ram_ptr);
    setStartInstruction(ir_ptr);
    setStartNextInstruction(ip_ptr);
    printMem(ram_ptr);

    // Starting clock
    initClock(ptr_clk, high, 1000000, low);
    printClockStatus(ptr_clk);
    reg.mr = low;

    // Running CPU
    while (ir.current_instr < 16 || ip.next_instr < 16)
    {
        startClock(ptr_clk);
        ptr_reg->cp = ptr_clk->status;

        // When clock signal is 1 (rising edge triggered)
        if (ptr_reg->cp == high)
        {
            setRegisterOutputs(ptr_reg);
            setRegisterInputsRandom(ptr_reg);
            getMemValue(ram_ptr, ir.current_instr);
            ir.current_instr = ip.next_instr;
            ip.next_instr++;
        }
        printRegisterInputs(ptr_reg);
        printRegisterOutputs(ptr_reg);
    }

    return 0;
}
