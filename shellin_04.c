#include "cushell.h"

/**
 * _delimeter - if character is a delimiter
 * @ch: character
 * @d: delimeter
 * Return: 1 or 0
 */

int _delimeter(char ch, char *d)
{
	for (; *d != '\0'; d++)
	{
		if (*d == ch)
			return (1);
	}
	return (0);
}

/**
 * **strtow - splits a string into words
 * @str: string
 * @d: delimeter
 * Return: pointer or NULL
 */

char **strtow(char *str, char *d)
{
	int a = 0, b = 0;
	int x = 0, y = 0;
	int w = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (; str[a] != '\0'; a++)
		if (!_delimeter(str[a], d) && (_delimeter(str[a + 1], d) || !str[a + 1]))
			w++;

	if (w == 0)
		return (NULL);
	s = malloc((1 + w) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < w; b++)
	{
		while (_delimeter(str[a], d))
			a++;
		x = 0;
		while (!_delimeter(str[a + x], d) && str[a + x])
			x++;
		s[b] = malloc((x + 1) * sizeof(char));
		if (!s[b])
		{
			for (x = 0; x < b; x++)
				free(s[x]);
			free(s);
			return (NULL);
		}
		for (y = 0; y < x; y++)
			s[b][y] = str[a++];
		s[b][y] = 0;
	}
	s[b] = NULL;
	return (s);
}


/**
 * **strtow2 - splits a string into words
 * @str: string
 * @d: delimeter
 * Return: pointer or NULL
 */
char **strtow2(char *str, char d)
{
	int a = 0, b = 0;
	int x = 0, y = 0, w = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			w++;
	if (w == 0)
		return (NULL);
	s = malloc((1 + w) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < w; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		while (str[a + x] != d && str[a + x] && str[a + x] != d)
			x++;
		s[b] = malloc((x + 1) * sizeof(char));
		if (!s[b])
		{
			for (; x < b; x++)
				free(s[x]);
			free(s);
			return (NULL);
		}
		for (; y < x; y++)
			s[b][y] = str[a++];
		s[b][y] = 0;
	}
	s[b] = NULL;
`	return (s);
}
