#include "main.h"

/**
 * _my_env - prints the current environment
 * @inf: Structure
 * Return: Always 0
 */
int _my_env(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _get_env - gets the value of an environ variable
 * @inf: Structure parameter
 * @name: env var name
 * Return: the value
 */
char *_get_env(info_t *inf, const char *name)
{
	list_t *node = inf->env;
	char *ptr;

	while (node)
	{
		ptr = start_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}


/**
 * populate_env_list - populates env linked list
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	inf->env = node;
	return (0);
}


