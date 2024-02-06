#include <stdlib.h>
#include "../search_algos.h"

/**
 * free_list - This function deallocates the singly linked list
 * @list: the linked list to be freed.
 */
void free_list(listint_t *list)
{
	listint_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}
