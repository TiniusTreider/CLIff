#include "control.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

size_t error_msg_size;
char *error_msg = NULL;

void error(char *msg)
{
        if (error_msg != NULL) {
                return;
        }

        size_t len = strlen(msg);
        error_msg = (char*)malloc(len + 1);
        error_msg[len] = '\0';
        error_msg_size = len;

        memcpy(error_msg, msg, len);

        should_stop = 1;
}

