#include "search_algos.h"

/**
 * binary_search - search for a value in a sorted array of integers using BSA.
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: he value to search for
 *
 * Return: If value is not present in array or if array is NULL, then return -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t n, left, right;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (n = left; n < right; n++)
			printf("%d, ", array[n]);
		printf("%d\n", array[n]);

		n = left + (right - left) / 2;
		if (array[n] == value)
			return (n);
		if (array[n] > value)
			right = n - 1;
		else
			left = n + 1;
	}

	return (-1);
}

