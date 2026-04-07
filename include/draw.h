#ifndef DRAW_H
#define DRAW_H

#include <stddef.h>

struct position {
        unsigned int x;
        unsigned int y;
};
struct color {
        unsigned char fg;
        unsigned char bg;
};

void put_char(char, struct position, struct color);
void put_string(char*, size_t size, struct position, struct color);

#endif

