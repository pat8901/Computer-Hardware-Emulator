// 4-bit register (DM74LS161A)
// for demonstration I will increment count every cycle, however outside of demo increment
// after completion of a instruction which could take several clock cycles
struct InstructionPointer
{
    int CO; // (counter out) pull high to place instruction onto the bus
    int CE; // (count enable) pull high to increment next instruction
    int j;  // (jump) pull high to set return point, i.e. loops
    int CL; // (clear) clears register values

    unsigned int instruction;
};