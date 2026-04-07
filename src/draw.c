#include "control.h"
#include "draw.h"

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static inline void move_cursor(struct position pos)
{
        char buffer[32];
        size_t amount = snprintf(buffer, 31, "\033[%d;%dH", pos.y, pos.x);

        ssize_t num = write(STDOUT_FILENO, buffer, amount);
        if (num == -1)
                error("failed to write");
}

static inline void set_color(struct color col)
{
        char buffer[32];
        size_t amount = snprintf(
                buffer,
                31,
                "\033[38;5;%dm\033[48;5;%dm",
                col.fg,
                col.bg
        );

        ssize_t num = write(STDOUT_FILENO, buffer, amount);
        if (num == -1)
                error("failed to write");

}

void put_char(char c, struct position pos, struct color col)
{
        move_cursor(pos);
        set_color(col);

        ssize_t num = write(STDOUT_FILENO, &c, 1);
        if (num != 1)
                error("failed to write");
}

void put_string(char *s, size_t size, struct position pos, struct color col)
{
        move_cursor(pos);
        set_color(col);

        ssize_t num = write(STDOUT_FILENO, s, size);
        if (num != 1)
                error("failed to write");
}

