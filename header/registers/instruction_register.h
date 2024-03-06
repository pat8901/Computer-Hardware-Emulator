// 8-bit instruction register.4-bit mem address (higher), 4-bit instruction (lower)
#ifndef INSTRUCTION_REGISTER_H
#define INSTRUCTION_REGISTER_H

struct InstructionRegister
{
    // unsigned int memory_address;

    unsigned int current_instr;
};

void setStartInstruction(struct InstructionRegister *ir_ptr);

#endif