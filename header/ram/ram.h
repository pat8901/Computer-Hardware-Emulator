// Stores 16 bytes of data. 16 locations, each location is a byte
#ifndef RAM_H
#define RAM_H
#define byte char

struct Ram
{
    // TODO: Can and should I make this smaller?
    unsigned int WR[16]; // write signals
    unsigned int EN[16]; // signal to put values onto the bus

    // 16 memory locations (index = byte)
    unsigned char memory[16];
};

void printMem(struct Ram *ram_ptr);
int loadProgramRandom(struct Ram *ram_ptr);
byte getMemValue(struct Ram *ram_ptr, int idx);

#endif