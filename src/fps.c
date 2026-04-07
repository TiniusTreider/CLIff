#include "fps.h"

#include <errno.h>
#include <stdint.h>
#include <time.h>

void sleep_ns(uint64_t nanosecs)
{
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

void keep_fps(size_t fps)
{
        (void)fps;
}

