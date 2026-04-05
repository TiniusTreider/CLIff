#include "draw.h"

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

struct position {
        unsigned int x;
        unsigned int y;
};
struct color {
        unsigned char foreground;
        unsigned char background;
};

static inline void move_cursor(struct position pos)
{
        char buffer[32];
        size_t amount = snprintf(buffer, 31, "\033[%d;%dH", pos.y, pos.x);
        (void)write(STDOUT_FILENO, buffer, amount);
}

static inline void set_color(struct color)
{
        (void)color;
}

void put_char(char c, struct position pos, struct color col)
{
        (void)c;
        (void)pos;
        (void)col;
}

void put_string(char *s, struct position pos, struct color col)
{
        (void)s;
        (void)pos;
        (void)col;
}

