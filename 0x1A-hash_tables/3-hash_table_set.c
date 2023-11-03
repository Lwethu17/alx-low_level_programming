#include "hash_tables.h"

/**
 * add_n_hash - Adds a new node at the start of the hash index.
 * @head: Pointer to the head of the hash table.
 * @key: key index of the hash table
 * @value: value to be stored.
 * Return: Head of the hash linked list.
 */
hash_node_t *add_n_hash(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *index;

	index = *head;

	while (index != NULL)
	{
		if (str(key, index->key) == 0)
		{
			free(index->value);
			index->value = strdup(value);
			return (*head);
		}
		index = index->next;
	}
	index = malloc(sizeof(hash_node_t));

	if (index == NULL)
		return (NULL);

	index->key = strdup(key);
	index->value = strdup(value);
	index->next = *head;
	*head = index;

	return (*head);
}

/**
 * hash_table_set - a function that adds an element to the hash table.
 * @ht: is the hash table you want to add or update the key/value to
 * @key: the key.
 * @value: the value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int key_index;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	key_index = key_index((unsigned char *)key, ht->size);

	if (add_n_hash(&(ht->array[key_index]), key, value) == NULL)
		return (0);

	return (1);
}
