#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "main.h"
/**
 * _strtok - replica of the strtok func
 * @string: the string to be tokenized
 * @delimiter: the delimiters
 * Return: the next token
 **/
char *_strtok(char *string, char *delimiter)
{
	static char *position;
	char *start_tok;
	int i = 0;

	if (string == NULL)
		return (NULL);
	if (string != NULL)
		position = string;
	for (; *position != '\0'; position++)
	{
		for (; delimiter[i] != '\0'; i++)
		{
			if (*position == delimiter[i])
			break;
		}
		if (delimiter[i] == '\0')
			break;
	}
	start_tok = position;
	if (*start_tok == '\0')
		return (NULL);
	for (; *position != '\0'; position++)
	{
		for (; delimiter[i] != '\0'; i++)
		{
			if (*position == delimiter[i])
			{
				*position = '\0';
				position++;
				return (start_tok);
			}
		}
	}
	return (start_tok);
}
