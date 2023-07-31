#include "lists.h"

/**
 * free_listint2 -  frees a listint_t list.
 * @head: listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *new;

	if (head == NULL)
		return;

	while (*head)
	{
		new = (*head)->next;
		free(*head);
		*head = new;
	}
	*head = NULL;
}
