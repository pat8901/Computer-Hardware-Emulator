#include <stdio.h>
#include <unistd.h>
#include "../../header/clock/clock.h"

#define high 1
#define low 0

// struct Clock c;

int startClock(struct Clock *ptr_clk)
{

    if (ptr_clk->power == high)
    {
        if (ptr_clk->status == high)
        {
            ptr_clk->status = low;
        }
        else
        {
            ptr_clk->status = high;
        }
        printf("clock status %d || ", ptr_clk->status);
        usleep(ptr_clk->timing);
    }

    return 0;
}

void initClock(struct Clock *ptr_clk, int power, int timing, int status)
{
    ptr_clk->power = power;
    ptr_clk->timing = timing;
    ptr_clk->status = status;
}

// testing
void printClockStatus(struct Clock *ptr_clk)
{
    printf("power: %d\n", ptr_clk->power);
    printf("timing: %d\n", ptr_clk->timing);
    printf("status: %d\n", ptr_clk->status);
}

// possibly use this if the implementation was multi-threaded
// multi-threaded application brings it's own problems however
int startClockMulti(void)
{
    struct Clock clock;
    clock.power = high;
    clock.timing = 1000000;
    clock.status = high;

    printf("%d\n", clock.status);
    usleep(clock.timing);

    while (clock.power == high)
    {
        if (clock.status == high)
        {
            clock.status = low;
        }
        else
        {
            clock.status = high;
        }

        printf("%d\n", clock.status);
        usleep(1000000); // Sleeps for a second
    }

    return 0;
}
