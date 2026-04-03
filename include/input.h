#ifndef INPUT_H
#define INPUT_H

#include <limits.h>

#define INPUT_NONE '\0'
#define INPUT_UP CHAR_MAX + 1
#define INPUT_RIGHT CHAR_MAX + 2
#define INPUT_DOWN CHAR_MAX + 3
#define INPUT_LEFT CHAR_MAX + 4

int non_blocking(void);

#endif

