#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <../../header/ram/ram.h>

#define high 1
#define low 0
#define byte char

struct Ram ram;

byte getMemValue(int idx)
{
    printf("RAM value %d: 0x%02X || ", idx, ram.memory[idx]);
    return ram.memory[idx];
}

// Print the entire contents of RAM
void printMem()
{
    for (int i = 0; i < sizeof(ram.memory) / sizeof(ram.memory[0]); i++)
    {
        printf("Index %d: 0x%02X\n", i, ram.memory[i]);
    }
}

// Loads random numbers into RAM for testing purposes
int loadProgramRandom()
{
    srand(time(NULL));

    for (int i = 0; i < sizeof(ram.memory) / sizeof(ram.memory[0]); i++)
    {
        ram.memory[i] = rand() % 256; // I think this is exclusive, i.e. 256 not included
    }
    return 0;
}
