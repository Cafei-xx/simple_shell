#include "cushell.h"

/**
 * _strlen - returns the length of a string
 * cute shell
 * @str: string
 * Return: length
 *
 */
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strcat - concatenates two strings in code
 * @dest: Buffer
 * @src: Buffer
 * Return: void
*/
char *_strcat(char *dest, const char *src)
{
	char *rslt = dest;

	while (*dest)
		dest++;
	for (; *src != '\0'; src++, dest++)
		*dest = *src;
	*dest = *src;
	return (rslt);
}

/**
 * _strcmp - compares two strings in a code
 *
 * @str1: the first string
 * @str2: the second string
 * Return: 0
 */
int _strcmp(char *str1, char *str2)
{
	int a = 0;

	while (str1[a] != '\0' && str2[a] != '\0')
	{
		if (str1[a] != str2[a])
		{
			return (str1[a] - str2[a]);
		}
		a++;
	}
	return (0);
}

/**
 * _strsub - finds the substring in the code
 * @str: The string to be looked for
 * @substr: The substring to be find.
 * Return: if substring true returns the addr of next, else Null
 */
char *_strsub(const char *str, const char *substr)
{
	for (; *substr; substr++, str++)
	{
		if (*substr != *str)
			return (NULL);
	}
	return ((char *)str);
}
