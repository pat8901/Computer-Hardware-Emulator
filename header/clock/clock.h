#ifndef CLOCK_H
#define CLOCK_H

struct Clock
{
    int status;
    int timing;
    int power;
};

int startClock(struct Clock *ptr_clk);
void initClock(struct Clock *ptr_clk, int power, int timing, int status);
void printClockStatus(struct Clock *p);

#endif