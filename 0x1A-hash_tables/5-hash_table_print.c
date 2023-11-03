#include "hash_tables.h"

/**
 * hash_table_print - Print out the hash table
 * @ht: hash table to read from
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx, m;
	hash_node_t *node;

	idx = m = 0;
	if (!ht)
		return;
	printf("{");
	while (idx < ht->size)
	{
		node = ht->array[idx];
		while (node)
		{
			printf("\'%s\': \'%s\'", node->key, node->value);

			if (node->next)
				printf(", ");
			node = node->next;
		}

		while (!(ht->array[idx + 1]))
			idx++;

		if (m && idx < ht->size)
			printf(", ");
		else
			m = 1;

		idx++;
	}
	printf("}\n");
}
