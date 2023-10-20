#include "main.h"

/**
 * list_len - determines the length of LS
 * @ptr: pointer to the first node
 * Return: size of list
 */
size_t list_len(const list_t *ptr)
{
	size_t i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}


/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @pr: string to matching
 * @c: the next character after prefix
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *pr, char c)
{
	char *p = NULL;

	while (node)
	{
		p = start_with(node->str, pr);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
