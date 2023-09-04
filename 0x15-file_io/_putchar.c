#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes to character c to sdout
 * @c: The character to print
 *
 * Return: On success 1, on error -1 is returned amd errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
