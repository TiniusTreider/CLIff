#include "control.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t error_msg_size;
char *error_msg = NULL;

#define ALLOC_ERROR "error allocating error message"

static inline void errorerror(void)
{
        write(STDERR_FILENO, ALLOC_ERROR, sizeof(ALLOC_ERROR) - 1);
}

void error(char *msg)
{
        if (error_msg != NULL) {
                return;
        }

        size_t len = strlen(msg);
        error_msg = (char*)malloc(len + 1);
        if (error_msg == NULL) {
                errorerror();
                should_stop = 1;
                return;
        }

        error_msg[len] = '\0';
        error_msg_size = len;

        memcpy(error_msg, msg, len);

        should_stop = 1;
}

