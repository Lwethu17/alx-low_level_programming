#include "search_algos.h"

/**
 * advanced_binary_recursive - Searches recursively for a value in a sorted
 * array of integers using binary search binary algorithms
 * @array: A pointer to the first element of the [sub]array to search.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present, -1.
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t n;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (n = left; n < right; n++)
		printf("%d, ", array[n]);
	printf("%d\n", array[n]);

	n = left + (right - left) / 2;
	if (array[n] == value && (n == left || array[n - 1] != value))
		return (n);
	if (array[n] >= value)
		return (advanced_binary_recursive(array, left, n, value));
	return (advanced_binary_recursive(array, n + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
