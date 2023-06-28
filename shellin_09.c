#include "cushell.h"

/**
* write_char - writes the character
* @ch: The character to print
* @r: The file w descriptor to write to
* Return: 1
*/
int write_char(char ch, int r)
{
	static int x;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(r, buffer, x);
		x = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[x++] = ch;
	return (1);
}

/**
* _inpstr - prints an input string
* @str: the string to be printed
* @r: the filedescriptor to write to
* Return: the number of chars put
*/
int _inpstr(char *str, int r)
{
	int x = 0;

	if (!str)
		return (0);
	for (; str[x] != '\0'; x++)
	{
		write_char(str[x], r);
	}
	return (x);
}
/**
* _writechar - writes the character
* @ch: The w character to print
* Return: On success 1.
*/
int _writechar(char ch)
{
	static int x;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buffer, x);
		x = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[x++] = ch;
	return (1);
}

/**
* _inputstr - prints an input string
* @str: string
* w
* Return: Nothing
*/
void _inputstr(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_writechar(str[x]);
		x++;
	}
}

/**
* _printdecimal - prints a decimal
* @a: the input
* @r: the filedescriptor to write to
*Return: number of characters
*/
int _printdecimal(int a, int r)
{
	int (*__putchar)(char) = _putchar;
	int x, y = 0;
	unsigned int i, j;
	unsigned int n = 1;

	if (r == STDERR_FILENO)
		__putchar = _writechar;
	if (a < 0)
	{
		i = -a;
		__putchar('-');
		y++;
	}
	else
	{
		while (n <= j)
		{
			n *= 10;
		}
		n /= 10;
		while (n >= 1)
		{
			__putchar('0' + j / n);
			y++;
			j %= n;
			n /= 10;
		}
	}
	return (y);
}
