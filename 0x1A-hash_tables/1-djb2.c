#include "hash_tables.h"

/**
 * hash_djb2 - implements the djb2 algorithm.
 * @str: A pointer to string
 * Return: hash number implemented.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int n;

	hash = 5381;
	while ((n = *str++))
	{
		hash = ((hash << 5) + hash) + n; /* hash * 33 + n */
	}
	return (hash);
}
