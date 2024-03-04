#include <stdio.h>
#include <stdlib.h>
#include <../header/instruction_register.h>

#define high 1
#define low 0

struct InstructionRegister ir;

void setStartInstruction()
{
    ir.current_instr = 0;
}