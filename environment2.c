#include "main.h"

/**
 * _myset_env - function to Initialize a new environment variable
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myset_env(info_t *inf)
{
	if (inf->argc != 3)
	{
		_e_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _my_unset_env - Remove an environment variable
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 0
 */
int _my_unset_env(info_t *inf)
{
	int i;

	if (inf->argc == 1)
	{
		_e_puts("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= inf->argc; i++)
		_unsetenv(inf, inf->argv[i]);
	return (0);
}

