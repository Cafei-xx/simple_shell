#include "cushell.h"

/**
 * _putchar - returns the character a to stdout
 * @ch: The character to print
 * Return: On success 1,-1 if error
 */
int _putchar(char ch)
{
	static int a;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(1, buffer, a);
		a = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[a++] = ch;
	return (1);
}
/**
 * _strdup - duplicates a string
 * @str: the string to be duplicated
 * Return: pointer to the dup string
 */
char *_strdup(char *str)
{
	int len, a = 0;
	char *x;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;

	x = malloc(sizeof(char) * (len + 1));

	if (x == NULL)
		return (NULL);

	for (a = 0; str[a]; a++)
		x[a] = str[a];

	return (x);
}
/**
 * _strcpy - a function that copies a string
 * @dest: the destination
 * @src: the source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int a = -1;

	do {
		a++;
		dest[a] = src[a];
	} while (src[a] != '\0');
	return (dest);
}
/**
 * _puts - prints an input string in w
 * @str: the string to be printed out
 * Return: Nothing
 */
void _puts(char *str)
{
	if (!str)
		return;
	int a = 0;

	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
}
