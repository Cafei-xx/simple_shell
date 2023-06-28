#include "cushell.h"
/**
 * _memset - fill memory with value
 * @ad: starting address of memory to be filled
 * @v: the desired value
 * @n: number of bytes to be changed
 * w
 * Return: changed array with new value for n bytes
 */
char *_memset(char *ad, char v, unsigned int n)
{
	int a = 0;

	for (; n > 0; a++)
	{
		ad[a] = v;
		n--;
	}
	return (ad);
}
