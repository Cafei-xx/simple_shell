#include "cushell.h"

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the max of bytes to be used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a = 0;
	int b = 0;

	while (dest[a] != '\0')
		a++;
	for (; b < n && src[b] != '\0'; b++)
		dest[a++] = src[b];
	dest[a] = '\0';
	return (dest);
}

/**
 **_strncpy - function to copy a string
 *@dest: dest string
 *@src: src string
 *@n: characters to be copied
 *Return: concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a = 0;

	while (a < n && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	for (; a < n; a++)
		dest[a] = '\0';
	return (dest);
}

/**
 **_strchr - locates character w in string
 *@s: the parsed string
 *@c: character w searched
 *Return: pointer to the memory area
 */

char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
			return (s);
	}

	return (NULL);
}
