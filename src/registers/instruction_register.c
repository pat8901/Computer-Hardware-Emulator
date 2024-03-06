#include <stdio.h>
#include <stdlib.h>
#include <../header/registers/instruction_register.h>

#define high 1
#define low 0

void setStartInstruction(struct InstructionRegister *ir_ptr)
{
    ir_ptr->current_instr = 0;
}