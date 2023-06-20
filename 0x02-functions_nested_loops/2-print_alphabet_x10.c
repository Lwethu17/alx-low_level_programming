#include "main.h"

/**
 * print_alphabet_x10 - Make alphabet x10 times, in lowercase,
 * followed by a new line
 * Return: void
 */

void print_alphabet_x10(void)
{
	char c;
	int i;

	while (i < 10)
	{
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
}
