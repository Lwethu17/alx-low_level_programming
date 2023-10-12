#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: Pointer to list
 * Return: void.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *str;
	dlistint_t *check;

	str = head;
	while (str != NULL)
	{
		check = str->next;
		free(str);
		str = check;
	}
}
