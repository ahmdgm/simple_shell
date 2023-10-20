#include "main.h"


/**
 * _unsetenv - Remove an environment variable
 * @inf: Structure 
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *inf, char *var)
{
	list_t *node = inf->env;
	size_t counter = 0;
	char *p;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = start_with(node->str, var);
		if (p && *p == '=')
		{
			inf->env_changed = delete_node_at_index(&(inf->env), counter);
			counter = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		counter++;
	}
	return (inf->env_changed);
}

