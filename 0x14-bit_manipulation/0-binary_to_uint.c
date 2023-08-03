#include "main.h"

/**
 * binary_to_uint -  converts a binary number to an unsigned int
 * @b: string pointer to binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int c;
	unsigned int val = 0;

	if (!b)
		return (0);

	for (c = 0; b[c]; c++)
	{
		if (b[c] < '0' || b[c] > '1')
			return (0);
		val = 2 * val + (b[c] - '0');
	}
	return (val);
}