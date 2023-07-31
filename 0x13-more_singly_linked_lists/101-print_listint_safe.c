#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: Address to the head of the linked list
 *
 * Return: The number of fork
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t fork, index = 0;

	fork = looped_listint_len(head);

	if (fork == 0)
	{
		for (; head != NULL; fork++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < fork; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (fork);
}

/**
 *  looped_listint_len - Calculates the number of unique codes
 *  in a looped listint_t linked list.
 *  @head: address to the head of the listint_t to check
 *  Return: If the list is not looped -0.
 *  Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *i, *n;
	size_t fork = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	i = head->next;
	n = (head->next)->next;

	while (n)
	{
		if (i == n)
		{
			i = head;
			while (i != n)
			{
				fork++;
				i = i->next;
				n = n->next;
			}
			i = i->next;

			while (i != n)
			{
				fork++;
				i = i->next;
			}
			return (fork);
		}
		i = i->next;
		n = (n->next)->next;
	}
	return (0);
}
