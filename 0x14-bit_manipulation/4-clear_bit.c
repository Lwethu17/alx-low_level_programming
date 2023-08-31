#include "main.h"

/**
 * clear_bit - sets the value of a bit 0 at given index
 * @n: number to change in the pointer
 * @index: index of a bit to clear
 * Return: 1 if successful, -1 if error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
