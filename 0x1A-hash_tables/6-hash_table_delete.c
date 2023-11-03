#include "hash_tables.h"

/**
 * hash_table_delete - removes the hash table
 * @ht: the hash table of hash_table_t
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	int m;
	hash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	for (m = 0; m < (int)ht->size; m++)
	{
		node = ht->array[m];
		if (!node)
			continue;
		while (node)
		{
			free(node->value);
			free(node->key);
			tmp = node->next;
			free(node);
			node = tmp;
		}
	}
	free(ht->array);
	free(ht);
}
