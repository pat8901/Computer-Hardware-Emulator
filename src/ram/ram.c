#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../header/ram/ram.h"

#define high 1
#define low 0
#define byte char

byte getMemValue(struct Ram *ram_ptr, int idx)
{
    printf("RAM value %d: 0x%02X || ", idx, ram_ptr->memory[idx]);
    return ram_ptr->memory[idx];
}

// Print the entire contents of RAM
void printMem(struct Ram *ram_ptr)
{
    for (int i = 0; i < sizeof(ram_ptr->memory) / sizeof(ram_ptr->memory[0]); i++)
    {
        printf("Index %d: 0x%02X\n", i, ram_ptr->memory[i]);
    }
}

// Loads random numbers into RAM for testing purposes
int loadProgramRandom(struct Ram *ram_ptr)
{
    srand(time(NULL));

    for (int i = 0; i < sizeof(ram_ptr->memory) / sizeof(ram_ptr->memory[0]); i++)
    {
        ram_ptr->memory[i] = rand() % 256; // I think this is exclusive, i.e. 256 not included
    }
    return 0;
}
