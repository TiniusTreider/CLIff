#include "control.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *error_msg = NULL;

void error(char *msg)
{
        size_t len = strlen(msg);
        error_msg = (char*)malloc(len);
        strcpy(error_msg, msg);

        should_stop = 1;
}

