#ifndef FPS_H
#define FPS_H

#include <stdint.h>
#include <stddef.h>

#define NS_IN_S 1000000000ULL

void sleep_ns(uint64_t);
void get_ns(uint64_t*);

void keep_fps(size_t);

#endif

