#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: Address to the first element
 *
 * Return: Address to the first element in new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prior = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prior;
		prior = *head;
		*head = next;
	}
	*head = prior;

	return (*head);
}

