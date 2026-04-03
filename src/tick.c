#include "control.h"
#include "input.h"

#include <stdio.h>

void tick(void)
{
        int c = non_blocking();
	if (c == INPUT_NONE)
                return;

        printf("\033[H");

        if (c < 0x80)
                printf("%c", c);

        switch (c) {
                case INPUT_UP:
                        printf("^"); break;
                case INPUT_RIGHT:
                        printf(">"); break;
                case INPUT_DOWN:
                        printf("v"); break;
                case INPUT_LEFT:
                        printf("<");
        }

        fflush(stdout);
}

