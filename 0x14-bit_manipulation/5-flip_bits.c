#include "main.h"

/**
 * flip_bits - returns the number of bits to flip
 * you would need to flip to get from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int c, check = 0;
	unsigned long int temp;
	unsigned long int size = n ^ m;

	for (c = 63; c >= 0; c--)
	{
		temp = size >> c;
		if (temp & 1)
			check++;
	}
	return (check);
}
