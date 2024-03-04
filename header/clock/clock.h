#ifndef CLOCK_H
#define CLOCK_H

struct Clock
{
    int status;
    int timing;
    int power;
};

int startClock();
void powerOn(struct Clock *p);
void printClockStatus(struct Clock *p);

#endif