#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print in the binary
 */
void print_binary(unsigned long int n)
{
	int b, check = 0;
	unsigned long int c;

	for (b = 63; b >= 0; b--)
	{
		c = n >> b;

		if (c & 1)
		{
			_putchar('1');
			check++;
		}
		else if (check)
			_putchar('0');
	}
	if (!check)
		_putchar('0');
}
