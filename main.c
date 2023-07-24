#include <unistd.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t characters_read;

    write(STDOUT_FILENO, "$ ", 2); // Print the prompt

    while ((characters_read = _getline(&line, &bufsize)) != -1)
    {
        if (characters_read > 0)
        {
            write(STDOUT_FILENO, "You entered: ", 13);
            write(STDOUT_FILENO, line, characters_read);
        }

        // Free the line buffer to avoid memory leaks
        free(line);
        line = NULL;
        bufsize = 0;

        write(STDOUT_FILENO, "\n$ ", 3); // Print the prompt again for the next input
    }

    // Cleanup: Free the buffer
    free(line);

    return 0;
}

