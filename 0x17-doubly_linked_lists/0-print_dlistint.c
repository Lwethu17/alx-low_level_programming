#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Pointer to head of a doubly linked list.
 * Return: the number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *tmp = h;
	size_t i = 0;

	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		printf("%d\n", tmp->i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}
