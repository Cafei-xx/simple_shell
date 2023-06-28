#include "cushell.h"

/**
 * _atoi - convert a string into an integer.
 * @str: string
 * Return: integer.
 */

int _atoi(char *str)
{
	int sign = 1, a = 0;
	unsigned int x = 0;

	while (!(str[a] <= '9' && str[a] >= '0') && str[a] != '\0')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] <= '9' && (str[a] >= '0' && str[a] != '\0'))
	{
		x = (x * 10) + (str[a] - '0');
		a++;
	}
	x *= sign;
	return (x);
}

/**
 * _isalpha - checks for alphabetic character
 * @ch: character
 * Return: 1 or 0
 */
int _isalpha(int ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}
