#include "main.h"
/**
 * replace__vars - replace vars in the tokenized string
 * @inf: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int replace__vars(info_t *inf)
{
	int i = 0;
	list_t *node;

	for (i = 0; inf->argv[i]; i++)
	{
		if (inf->argv[i][0] != '$' || !inf->argv[i][1])
			continue;

		if (!_strcmp(inf->argv[i], "$?"))
		{
			replace_String(&(inf->argv[i]),
				_strdupp(convert_number(inf->status, 10, 0)));
			continue;
		}
		if (!_strcmp(inf->argv[i], "$$"))
		{
			replace_String(&(inf->argv[i]),
				_strdupp(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(inf->env, &inf->argv[i][1], '=');
		if (node)
		{
			replace_String(&(inf->argv[i]),
				_strdupp(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_String(&inf->argv[i], _strdupp(""));

	}
	return (0);
}

/**
 * replace_String - function to replace string
 * @oldd: address of old string
 * @neww: new string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_String(char **oldd, char *neww)
{
	free(*oldd);
	*oldd = neww;
	return (1);
}
