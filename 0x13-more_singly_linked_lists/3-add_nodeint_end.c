#include "lists.h"

/**
 * add_nodeint_end -  adds a new node at the end of a listint_t list.
 * @head: Adress to first node in the list
 * @n: input in the recent node
 *
 * Return: the address of the recent node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *recent;
	listint_t *x = *head;

	recent = malloc(sizeof(listint_t));
	if (!recent)
		return (NULL);

	recent->n = n;
	recent->next = NULL;

	if (*head == NULL)
	{
		*head = recent;
		return (recent);
	}

	while (x->next)
		x = x->next;
	x->next = recent;

	return (recent);
}
