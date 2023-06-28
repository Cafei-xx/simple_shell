#include "cushell.h"
/**
 * *_realloc - reallocates a memory
 * @ptr: pointer
 * @old_size: size old
 * @new_size: new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *x = NULL;
	char *y;
	unsigned int a;

	if (new_size == old_size)
		return (x);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	x = malloc(new_size);
	if (!x)
		return (NULL);

	y = ptr;

	if (new_size < old_size)
	{
		for (a = 0; a < new_size; a++)
			x[a] = y[a];
	}

	if (new_size > old_size)
	{
		for (a = 0; a < old_size; a++)
			x[a] = y[a];
	}

	free(ptr);
	return (x);
}
