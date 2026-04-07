#include "control.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static inline void show_cursor(void)
{
	(void)write(STDOUT_FILENO, "\033[?25h", 6);
}

static inline void disable_alt_screen(void)
{
	(void)write(STDOUT_FILENO, "\033[?1049l", 8);
}

static inline void disable_raw_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}

static inline void clean_error(void)
{
        if (error_msg == NULL)
                return;

        size_t len = error_msg_size;
        write(STDERR_FILENO, error_msg, len);
        free(error_msg);
}

void clean(void)
{
	show_cursor();
	disable_alt_screen();
	disable_raw_mode();

        clean_error();
}

