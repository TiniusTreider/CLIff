#include "control.h"
#include "fps.h"

#include <errno.h>
#include <stdint.h>
#include <time.h>

void sleep_ns(uint64_t nanosecs)
{
        if (nanosecs == 0)
                error("you can't set the fps to 0");

        struct timespec ts = {
                .tv_sec = (time_t)(nanosecs / NS_IN_S),
                .tv_nsec = (long)(nanosecs % NS_IN_S)
        };

        while (nanosleep(&ts, &ts) == -1 && errno == EINTR);
}

void get_ns(uint64_t *nanosecs)
{
        struct timespec ts;

        clock_gettime(CLOCK_MONOTONIC, &ts);

        *nanosecs = ts.tv_sec * NS_IN_S + ts.tv_nsec;
}

uint64_t curr_time = 0;
uint64_t deltatime = 0;

void keep_fps(size_t fps)
{
        const uint64_t tick_time = NS_IN_S / fps;

        const uint64_t last_time = curr_time;
        get_ns(&curr_time);
        deltatime = curr_time - last_time;

        if (tick_time > deltatime)
                sleep_ns(tick_time - deltatime);
}

