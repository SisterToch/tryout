#include <stdlib.h>

void *_realloc(void *ptr, size_t n)
{
	if (ptr == NULL)
	{
		return malloc(n);
	}

	if (n == 0)
	{
		free(ptr);
		return (NULL);
	}
	
	void *ptr_new = malloc(n);
	if (ptr_new == NULL)
	{
		return (NULL);
	}

	size-t former_n = malloc
