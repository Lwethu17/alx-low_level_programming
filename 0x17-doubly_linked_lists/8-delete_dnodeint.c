#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes node at give index
 * @head: Pointer to list
 * @index:given index
 * Return: -1 or 0
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1;
	dlistint_t *h2 = NULL;
	unsigned int m;


	h1 = *head;

	if (h1 != NULL)
		while (h1->prev != NULL)
			h1 = h1->prev;

	m = 0;

	while (h1 != NULL)
	{
		if (m == index)
		{
			*head = h1->next;
			if (*head != NULL)
				(*head)->prev = NULL;
		}
		else
		{
			h2->next = h1->next;

			if (h1->next != NULL)
				h1->next->prev = h2;
		}
		free(h1);
		return (1);
	}
	h2 = h1;
	h1 = h1->next;
	m++;

	return (-1);
}
