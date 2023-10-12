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
	dlistint_t *str;
	unsigned int n;
	unsigned int len;

	len = len_node(&head);
	str = *head;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		str = str->next;
		free(*head);
		*head = str;
		if (str != NULL)
			str->prev = NULL;
		return (1);
	}
	for (n = 0; n <= index - 1; n++)
	{
		str = str->next;
		if (!str)
			return (-1);
	}
	if (len - 1 == index)
	{
		str->prev->next = NULL;
		free(str);
		return (1);
	}
}

/**
 * len_node - list len
 * @node:list
 * Return:unsigned int
 */
unsigned int len_node(dlistint_t **node)
{
	unsigned int len = 0;
	dlistint_t *str;

	str = *node;
	while (str != NULL)
	{
		len += 1;
		str = str->next;
	}
	return (len);
}
