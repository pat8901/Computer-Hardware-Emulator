#include <stdio.h>
#include <unistd.h>
#include <../header/clock.h>

#define high 1
#define low 0

struct Clock c;

int startClock(void)
{
    // printf("clock power:%d\n", c.power);

    if (c.power == high)
    {
        if (c.status == high)
        {
            c.status = low;
        }
        else
        {
            c.status = high;
        }
        printf("clock status %d || ", c.status);
        usleep(c.timing);
    }

    return 0;
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
