#include "hash_tables.h"

/**
 * hash_table_delete - Deletes the hash table.
 * @ht: The hash table.
 * Return: void.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int n;
	hash_node_t *index1;
	hash_node_t *index2;

	if (ht == NULL)
		return;

	for (n = 0; n < ht->size; n++)
	{
		index1 = ht->array[n];
		while ((index2 = index1) != NULL)
		{
			index1 = index1->next;
			free(index2->key);
			free(index2->value);
			free(index2);
		}
	}
	free(ht->array);
	free(ht);
}
