#include <stdio.h>
#include <stdlib.h>
#include "../../header/registers/instruction_pointer.h"

#define high 1
#define low 0

void setStartNextInstruction(struct InstructionPointer *ip_ptr)
{
    ip_ptr->next_instr = 1;
}