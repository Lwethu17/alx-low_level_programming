#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: structure list.
 * Return: num of elementsin the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;
	int n = 0;

	for (n = 0; h; n++)
	{
		len += 1;
		h = h->next;
	}
	return (len);
}
