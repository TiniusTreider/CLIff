#define _POSIX_C_SOURCE 200809L

#include "control.h"

#include <signal.h>
#include <string.h>
#include <unistd.h>

static inline void hide_cursor(void)
{
	(void)write(STDOUT_FILENO, "\033[?25l", 6);
}

static inline void enable_alt_screen(void)
{
	(void)write(STDOUT_FILENO, "\033[?1049h", 8);
}

static void handler(int sig)
{
	(void)sig;
	should_stop = 1;
}

static inline void set_signal(void)
{
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = handler;

	sigaction(SIGINT, &sa, NULL);
        sigaction(SIGALRM, &sa, NULL);
        sigaction(SIGTERM, &sa, NULL);
}

struct termios original;

static inline void enable_raw_mode(void)
{
	tcgetattr(STDIN_FILENO, &original);

	struct termios raw = original;

	raw.c_iflag &= ~(
		IXON |
		BRKINT |
		ICRNL |
		INPCK |
		ISTRIP
	);

	raw.c_oflag &= ~(OPOST);

	raw.c_cflag |= CS8;

	raw.c_lflag &= ~(
		ECHO |
		ICANON |
		IEXTEN
	);

	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void setup(void)
{
	hide_cursor();
	enable_alt_screen();
	set_signal();
	enable_raw_mode();
}

