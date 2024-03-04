#include <stdio.h>
#include <stdlib.h>
#include <../header/instruction_pointer.h>

#define high 1
#define low 0

struct InstructionPointer ip;

void setStartNextInstruction()
{
    ip.next_instr = 1;
}