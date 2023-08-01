#include "lists.h"

/**
 * find_listint_loop -  finds the loop in a linked list.
 * @head: linked list to search for
 *
 * Return: address of the element where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *cat = head;
	listint_t *dog = head;

	if (!head)
		return (NULL);

	while (cat && dog && dog->next)
	{
		dog = dog->next->next;
		cat = cat->next;
		if (dog == cat)
		{
			cat = head;
			while (cat != dog)
			{
				cat = cat->next;
				dog = dog->next;
			}
			return (dog);
		}
	}
	return (NULL);
}
