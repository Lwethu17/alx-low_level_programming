#include "hash_tables.h"

/**
 * shash_table_create - creates a shash table with a given size
 *
 * @size: size of the shash table
 * Return: the created shash table, or NULL if function fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *list;
	shash_node_t **array;
	unsigned long int n;

	list = malloc(sizeof(shash_table_t));
	if (list == NULL)
		return (NULL);

	array = malloc(sizeof(shash_node_t *) * size);
	if (array == NULL)
		return (NULL);

	for (n = 0; n < size; n++)
		array[n] = NULL;

	list->array = array;
	list->size = size;
	list->shead = NULL;
	list->stail = NULL;

	return (list);
}

/**
 * add_n_shash - adds a node at the beginning of a shash at a given index
 *
 * @h: head of the shash linked list
 * @key: key of the shash
 * @value: value to store
 * Return: created node
 */
shash_node_t *add_n_shash(shash_node_t **h, const char *key, const char *value)
{
	shash_node_t *index;

	index = *h;

	while (index != NULL)
	{
		if (strcmp(key, index->key) == 0)
		{
			free(index->value);
			index->value = strdup(value);
			return (index);
		}
		index = index->next;
	}

	index = malloc(sizeof(shash_node_t));

	if (index == NULL)
		return (NULL);

	index->key = strdup(key);
	index->value = strdup(value);
	index->next = *h;

	*h = index;

	return (index);
}

/**
 * add_i_shash - adds a node on the DLL of the shash table
 *
 * @ht: pointer to the table
 * @new: new node to add
 * Return: no return
 */
void add_i_shash(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *index1, *index2;
	int ret;

	index1 = index2 = ht->shead;

	while (index1 != NULL)
	{
		ret = strcmp(new->key, index1->key);
		if (ret == 0)
		{
			return;
		}
		else if (ret < 0)
		{
			new->sprev = index1->sprev;

			if (index1->sprev)
				index1->sprev->snext = new;
			else
				ht->shead = new;

			index1->sprev = new;
			new->snext = index1;

			return;
		}
		index2 = index1;
		index1 = index1->snext;
	}

	new->sprev = index2;
	new->snext = NULL;

	if (ht->shead)
		index2->snext = new;
	else
		ht->shead = new;

	ht->stail = new;
}

/**
 * shash_table_set - adds a hash (key, value) to a given shash table
 *
 * @ht: pointer to the shash table
 * @key: key of the shash
 * @value: value to store
 * Return: 1 if successes, 0 if fails
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int key_index;
	shash_node_t *new;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	key_index = key_index((unsigned char *)key, ht->size);

	new = add_n_shash(&(ht->array[k_index]), key, value);

	if (new == NULL)
		return (0);

	add_i_shash(ht, new);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 *
 * @ht: pointer to the shash table
 * @key: key of the shash
 * Return: value of the shash.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int key_index;
	shash_node_t *index;

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

/**
 * shash_table_print - prints the keys and values of the shash table
 *
 * @ht: pointer to the shash table
 * Return: no return
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	char *val;

	if (ht == NULL)
		return;

	printf("{");
	val = "";

	index = ht->shead;

	while (index != NULL)
	{
		printf("%s'%s': '%s'", val, index->key, index->value);
		val = ", ";
		index = index->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints the keys and values of the shash table
 * in reverse
 *
 * @ht: pointer to the shash table
 * Return: no return
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *index;
	char *val;

	if (ht == NULL)
		return;

	printf("{");
	val = "";

	index = ht->stail;

	while (index != NULL)
	{
		printf("%s'%s': '%s'", val, index->key, index->value);
		val = ", ";
		index = index->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - deletes a shash table
 *
 * @ht: pointer to the shash table
 * Return: no return
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int n;
	shash_node_t *index1;
	shash_node_t *index2;

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
