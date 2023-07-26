#include <stddef.h>
#include <stdlib.h>

/**
* _strcpy - function that makes a copy of
* a string
* @src : the source string
* Return: returns the copied string
*/
char *_strcpy(const char *src)
{
	char *dest;
	size_t len = 0, i;

	if (src == NULL)
		return (NULL);

	while (src[len] != '\0')
	{
		len++;
	}

	dest = (char *)malloc(len + 1);
	if (dest == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * _strtok - function that delimit
 * @str: the string to be tokenized
 * @delimiters: the delimiters
 * Return: the next token
 **/
char *_strtok(char *str, const char *delimiters)
{
	size_t i;
	int located_d = 0;
	static char *last_token;
	char *start_token;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		str = _strcpy(str);
		last_token = str;
	} /*set to last token*/

	while (*str != '\0')
	{
		for (i = 0; delimiters[i] != '\0'; i++)
		{
			if (*str == delimiters[i])
			{
				*str = '\0';
				located_d = 1;
				break;
			}
		}
		if (located_d)
		{
			break;
		}
		str++;
	}

	if (*str == '\0')
	{
		free(str);
		last_token = NULL;
		return (NULL);
	}

	start_token = str;
	last_token = str + 1;

	return (start_token);
}
