#include <stdio.h>
#include <unistd.h>
#include <../header/clock.h>

#define true 1
#define false 0

int main(void)
{
    struct Clock clock;
    clock.power = true;
    clock.timing = 1000000;
    clock.status = true;

    printf("%d\n", clock.status);
    usleep(clock.timing);

    while (clock.power == true)
    {
        if (clock.status == true)
        {
            clock.status = false;
        }
        else
        {
            clock.status = true;
        }

        printf("%d\n", clock.status);
        usleep(1000000); // Sleeps for a second
    }

    return 0;
}