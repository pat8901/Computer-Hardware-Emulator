#include <stdio.h>
#include <stdlib.h>
#include <../../header/ram/ram.h>

#define high 1
#define low 0
#define byte char

struct Ram ram;

byte getMemValue()
{
}

// Print the entire contents of RAM
void printMem()
{
    for (int i = 0; i < sizeof(ram.memory) / sizeof(ram.memory[0]); i++)
    {
        printf("Index %d: 0x%02X\n", i, ram.memory[i]);
    }
}