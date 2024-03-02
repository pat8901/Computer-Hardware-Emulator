// Stores 16 bytes of data. 16 locations, each location is a byte

struct Ram
{
    unsigned int WR[16]; // write signals
    unsigned int EN[16]; // signal to put values onto the bus

    // 16 memory location
    unsigned int mem0[8];
    unsigned int mem1[8];
    unsigned int mem2[8];
    unsigned int mem3[8];
    unsigned int mem4[8];
    unsigned int mem5[8];
    unsigned int mem6[8];
    unsigned int mem7[8];
    unsigned int mem8[8];
    unsigned int mem9[8];
    unsigned int mem10[8];
    unsigned int mem11[8];
    unsigned int mem12[8];
    unsigned int mem13[8];
    unsigned int mem14[8];
    unsigned int mem15[8];
};