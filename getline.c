#include <stdlib.h>
#include <unistd.h>
#include "main.h"
ssize_t _getline(char **lineptr, size_t *n)
{
	if (lineptr == NULL || n == NULL)
	{
		write(STDERR_FILENO, "Error: Invalid input\n", 21);
        return (-1);
	}

	size_t position = 0;/*in the buffer*/
	char store;/*stores the character to be read*/

	while (1)
	{/*create an loops that breaks after reading and returns 1*/
		if (read(STDIN_FILENO, &store, 1) != 1)
		{
			break;
		}

		if (position >= *n - 1)
		{/*if the position is greater than the buffer, double it*/
			size_t new_buffer = (*n) * 2;
			char *new_lineptr = realloc(*lineptr, new_buffer);
			
			if (new_lineptr == NULL)
			{
				write(STDERR_FILENO, "Error: Memory alloc failed\n", 31);
				return -1;
			}
			*lineptr = new_lineptr;
			*n = new_buffer;
		}

		(*lineptr)[position] = store;
		position++;

		if (store == '\n')
		{
			break;
		}
	}

	(*lineptr)[position] = '\0';
	return (position);
}

