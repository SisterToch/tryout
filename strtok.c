#include <stddef.h>
/**
*/
char *_strtok(char *str, const char *delimiters)
{
	size_t i; int located_d = 0;
	static char *last_token; char *start_token;
	if (str == NULL)
	{
		str = last_token;
	}/*if str is null, set to the last token*/
	
	while (*str != '\0')
	{
		for (i = 0; delimiters[i] != '\0'; i++)
		{
			if (*str == delimiters[i])
			{
				break;
			}
		}
		if (delimiters[i] == '\0')
		{
			break;
		}
		str++;
	}
	
	if (*str == '\0')
	{
		return (NULL);
	}
	
	start_token = str;

	while (*str != '\0')
	{
		for(i = 0; delimiters[i] != '\0'; i++)
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
	if (located_d)
	{
		last_token = str + 1;
	}
	else
	{
		last_token = NULL;
	}
	
	return (start_token);
}
