#include "main.h"

/**
 * set_bit - sets the value of a bit 1 at a given index
 * @n: number to change in the pointer
 * @index: index of the bit to set to 1
 * Return: 1 if successful, or -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
