#include "hash_tables.h"

/**
 * hash_table_create -  creates a hash table.
 * @size: the size of the array
 * Return: a pointer to the newly created hash table,
 * If something went wrong, your function should return NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *list;
	hash_node_t **array;
	unsigned long int n;

	list = malloc(sizeof(hash_table_t));
	if (list == NULL)
		return (NULL);

	array = malloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (n = 0; n < size; n++)
		array[n] = NULL;

	list->array = array;
	list->size = size;

	return (list);
}
