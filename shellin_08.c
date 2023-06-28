#include "cushell.h"

/**
 * free_str - frees string
 * w
 * @str: string
 */

void free_str(char **str)
{
	int x = 0;

	if (!str)
	return;

	for (; str[x] != NULL; x++)
	{
		free(str[x]);
		str[x] = NULL;
	}
	free(str);
}

/**
 * free_ptr - frees a pointer
 * @p: pointers's adress
 * Return: 1 or 0;
 */

int free_ptr(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
