#include "hash_tables.h"

/**
 * hash_table_get - a function that retrieves a value associated with a key.
 * @ht: the hash table you want to look into
 * @key: the key you are looking for
 * Return: the value associated with the element, or NULL if key not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int key_index;
	hash_node_t *index;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	key_index = key_index((unsigned char *)key, ht->size);

	index = ht->array[key_index];

	while (index != NULL)
	{
		if (strcmp(index->key, key) == 0)
			return (index->value);
		index = index->next;
	}

	return (NULL);
}
