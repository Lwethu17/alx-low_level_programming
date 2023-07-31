#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: the first node in the linked list
 *
 * Return: Total sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *num = head;

	while (num)
	{
		sum += num->n;
		num = num->next;
	}
	return (sum);
}
