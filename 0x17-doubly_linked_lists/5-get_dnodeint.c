#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: Pointer to list
 * @index: index of the node
 * Return: Index of the node, starting from 0.
 * if the node does not exist, return NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int n;

	for (n = 0; n < index && head->next; n++)
	{
		head = head->next;
	}
	if (n < index)
		return (NULL);
	return (head);
}
