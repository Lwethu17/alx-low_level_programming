#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers using JSA.
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array or if array is NULL, then return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t n;
	size_t jump;
	size_t step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (n = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		n = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", n, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; n < jump && array[n] < value; n++)
		printf("Value checked array[%ld] = [%d]\n", n, array[n]);
	printf("Value checked array[%ld] = [%d]\n", n, array[n]);

	return (array[n] == value ? (int)n : -1);
}
