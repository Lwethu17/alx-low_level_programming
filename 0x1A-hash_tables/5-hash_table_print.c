#include "hash_tables.h"

/**
 * hash_table_print -  prints a hash table.
 * @ht: the hash table
 * Return: void.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int n;
	hash_node_t *index;
	char *val;

	if (ht == NULL)
		return;

	printf("{");
	val = "";

	for (n = 0; n < ht->size; n++)
	{
		index = ht->array[n];
		while (index != NULL)
		{
			printf("%s'%s': '%s'", val, index->key, index->value);
			val = ", ";
			index = index->next;
		}
	}
	printf("}\n");
}
