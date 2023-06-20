#include "main.h"

/**
 * print_alphabet_x10 - Make alphabet x10 times, in lowercase,
 * followed by a new line
 * Return: void
 */

void print_alphabet_x10(void)
{
	char ch;
	int i;

	while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}
