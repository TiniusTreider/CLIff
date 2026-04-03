#include "control.h"
#include "input.h"

#include <errno.h>
#include <unistd.h>

static unsigned char buffer[3];
static int buffer_fill = 0;

static inline void fill(void)
{
        char inp;
        ssize_t num;

        for (int i = 0; i < 16; i++)
        {
                num = read(STDIN_FILENO, &inp, 1);
                if (num == 1)
                        break;

                if (num == 0 || errno == EAGAIN || errno == EWOULDBLOCK) {
                        return;
                } else if (errno != EINTR) {
                        error("Error reading input");
                        return;
                }
        }

        if (num != 1)
                return;

        buffer[buffer_fill] = inp;
        buffer_fill++;
}

#define MAX_ASCII 0x80

int non_blocking(void)
{
        buffer_fill = 0;

        fill();
        if (buffer_fill != 1)
                return INPUT_NONE;

        else if (buffer[0] < MAX_ASCII && buffer[0] != '\033')
                return (int)buffer[0];

        else if (buffer[0] != '\033')
                return INPUT_NONE;

        fill();
        if (buffer_fill != 2)
                return INPUT_NONE;

        else if (buffer[1] != '[')
                return INPUT_NONE;

        fill();
        if (buffer_fill != 3)
                return INPUT_NONE;

        switch (buffer[2]) {
                case 'A':
                        return INPUT_UP;
                case 'B':
                        return INPUT_DOWN;
                case 'C':
                        return INPUT_RIGHT;
                case 'D':
                        return INPUT_LEFT;
        }

        return INPUT_NONE;
}

