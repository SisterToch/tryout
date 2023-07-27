#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Enter lines of text (Ctrl+D to quit):\n");

    while ((nread = _getline(&line, &len)) != -1)
    {
        printf("Characters read: %zd\n", nread);
        printf("Line: %s", line);
    }

    free(line);
    return 0;
}

