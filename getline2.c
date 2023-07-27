#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _getline - Reads input from stdin
 * @lineptr: Pointer to the buffer
 * @n: Pointer to number of input
 * Return: Number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	if (*lineptr == NULL)
	{
		if (allocate_Buffer(lineptr, n) == -1)
		{
			return (-1);
		}
	}

	size_t position = readInput2Buffer(*lineptr, *n);

	if (position == (size_t)-1)
	{
		return (-1);
	}

	(*lineptr)[position] = '\0';
	return (position);
}

/**
 * allocate_Buffer - Allocates memory for the initial buffer
 * @lineptr: Pointer to the buffer
 * @n: Pointer to the size of the buffer
 * Return: 0 on success otherwise, -1.
 */
int allocate_Buffer(char **lineptr, size_t *n)
{
	*n = 128; /* Random initial buffer size */
	*lineptr = (char *)malloc(*n);

	if (*lineptr == NULL)
	{
		write(STDERR_FILENO, "Error: Memory alloc failed\n", 27);
		return (-1);
	}

	return (0);
}

/**
 * readInput2Buffer - Reads input from stdin and stores it in the buffer
 * @buffer: Pointer to the buffer
 * @n: Size of the buffer
 * Return: Number of characters read
 */
size_t readInput2Buffer(char *buffer, size_t n)
{
	size_t position = 0; /* Position in the buffer */
	char store; /* Stores the character to be read */

	while (1)
	{
		if (read(STDIN_FILENO, &store, 1) != 1)
		{
			break; /* Break the loop upon read failure or EOF */
		}

		if (position >= n - 1)
		{
			size_t new_buffer = n + 128; /* Incremental buffer size increase */
			char *new_lineptr = (char *)malloc(new_buffer);

			if (new_lineptr == NULL)
			{
				write(STDERR_FILENO, "Error: Memory alloc failed\n", 27);
				free(buffer); /* Free the previously allocated memory */
				return (-1);
			}

			copyBufferContent(new_lineptr, buffer, position);

			free(buffer);
			buffer = new_lineptr;
			n = new_buffer;
		}

		buffer[position++] = store;

		if (store == '\n')
		{
			break; /* Break upon meeting newline */
		}
	}

	return (position);
}

/**
 * copyBufferContent - Copies content from the old buffer to the new buffer
 * @dest: Destination buffer
 * @src: Source buffer
 * @len: Length of content to copy
 */
void copyBufferContent(char *dest, const char *src, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
}

