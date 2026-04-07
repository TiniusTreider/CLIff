#ifndef CONTROL_H
#define CONTROL_H

#include <signal.h>
#include <stddef.h>
#include <termios.h>

extern volatile sig_atomic_t should_stop;
extern struct termios original;

void setup(void);
void tick(void);
void clean(void);

extern size_t error_msg_size;
extern char *error_msg;
void error(char*);

#endif

