// 8-bit instruction register.4-bit mem address (higher), 4-bit instruction (lower)
struct InstructionRegister
{
    // unsigned int memory_address;

    unsigned int current_instr;
};

void setStartInstruction();