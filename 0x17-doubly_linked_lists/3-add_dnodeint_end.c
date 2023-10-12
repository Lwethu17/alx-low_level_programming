#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Adds  a new node at the end of a dlistint_t list.
 * @head: Pointer.
 * @n: Pointer to the element in the list.
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *str;

	str = *head;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
	{
		new->next = NULL;
		new->n = n;
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (str->next)
	{
		str = str->next;
	}
	str->next = new;
	new->prev = str;
	new->next = NULL;
	new->n =  n;
	return (new);
}
