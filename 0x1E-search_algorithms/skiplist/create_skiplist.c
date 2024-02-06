#include <stdlib.h>
#include <math.h>
#include "../search_algos.h"

void free_skiplist(skiplist_t *list);

/**
 * init_express - This function initializes teh express lane in linked list
 * @list: the head node of the list
 * @size: Pointer to the number of nodes in the list.
 */
void init_express(skiplist_t *list, size_t size)
{
	const size_t step = sqrt(size);
	size_t n;
	skiplist_t *save;

	for (save = list, n = 0; n < size; ++n, list = list->next)
	{
		if (n % step == 0)
		{
			save->express = list;
			save = list;
		}
	}
}

/**
 * create_skiplist - This function creates a single linked list.
 * @array: The array used to fill teh list
 * @size: Pointer to the size of the array.
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list;
	skiplist_t *node;
	size_t save_size;

	list = NULL;
	save_size = size;
	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_skiplist(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->express = NULL;
		node->next = list;
		list = node;
	}
	init_express(list, save_size);
	return (list);
}
