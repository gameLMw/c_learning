/* common.c */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void Error(const char *Msg)
{
    fprintf(stderr, "Error: %s\n", Msg);
}

void FatalError(const char *Msg)
{
    fprintf(stderr, "Fatal Error: %s\n", Msg);
    exit(1);
}