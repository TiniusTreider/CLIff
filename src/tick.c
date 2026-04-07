#include "cliff.h"
#include "input.h"
#include "draw.h"

void tick(void)
{
        /* example tick function */

        static unsigned int pos_x = 5;
        static unsigned int pos_y = 5;
        static signed char vel_x = 1;
        static signed char vel_y = 2;

        pos_x += vel_x;
        pos_y += vel_y;

        if (pos_x >= 10)
                vel_x *= -1;
        if (pos_y >= 10)
                vel_y *= -1;
        if (pos_x < 2)
                vel_x *= -1;
        if (pos_y < 2)
                vel_y *= -1;

        const int c = non_blocking();

        static char out = ' ';

        if (c < 0x80 && c != INPUT_NONE)
                out = c;
        switch (c) {
                case INPUT_NONE:
                        break;
                case INPUT_UP:
                        out = '^'; break;
                case INPUT_RIGHT:
                        out = '>'; break;
                case INPUT_DOWN:
                        out = 'v'; break;
                case INPUT_LEFT:
                        out = '<';
        }

        static struct position pos;
        static struct position prev;

        prev = pos;

        pos = (struct position){
                .x = pos_x,
                .y = pos_y
        };
        const struct color col = (struct color){
                .fg = 0,
                .bg = 1
        };

        const struct color no = (struct color){
                .fg = 0,
                .bg = 0
        };

        put_char(out, pos, col);
        put_char(' ', prev, no);
}

