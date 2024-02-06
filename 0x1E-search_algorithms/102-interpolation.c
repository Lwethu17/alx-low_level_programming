#include "search_algos.h"

/**
 * interpolation_search -  search for a value in a sorted array of integer ISA
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array or if array is NULL, then return -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t n;
	size_t l;
	size_t r;

	if (array == NULL)
		return (-1);

	for (l = 0, r = size - 1; r >= l;)
	{
		n = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));
		if (n < size)
			printf("Value checked array[%ld] = [%d]\n", n, array[n]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", n);
			break;
		}

		if (array[n] == value)
			return (n);
		if (array[n] > value)
			r = n - 1;
		else
			l = n + 1;
	}

	return (-1);
}
