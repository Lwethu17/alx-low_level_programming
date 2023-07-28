#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of list
 * @head: double points to the list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the recent element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *recent;
	unsigned int len = 0;

	while (str[len])
		len++;

	recent = malloc(sizeof(list_t));
	if (!recent)
		return (NULL);

	recent->str = strdup(str);
	recent->len = len;
	recent->next = (*head);
	(*head) = recent;

	return (*head);
}
