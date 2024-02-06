#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers using the LSA
 * @array: A pointer to the first elem of the array to be searched
 * @size: A pointer to the number of elems in the array
 * @value: the value to be searched for
 *
 * Return: If val is not present in array or if array is NULL, the return -1.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t n;

	if (array == NULL)
		return (-1);

	for (n = 0; n < size; n++)
	{
		printf("Value checked array[%ld] = [%d]\n", n, array[n]);
		if (array[n] == value)
			return (n);
	}

	return (-1);
}
