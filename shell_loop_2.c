#include "main.h"
/**
 * find_built_in - finds a builtin command
 * @inf: the parameter & return info struct
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_built_in(info_t *inf)
{
	int i, built_in_ret = -1;
	builtin_table built_intbl[] = {
		{"exit", _my_exit},
		{"env", _my_env},
		{"help", _my_help},
		{"history", _myhistory},
		{"setenv", _myset_env},
		{"unsetenv", _my_unset_env},
		{"cd", _my_cd},
		{"alias", _my_alias},
		{NULL, NULL}
	};

	for (i = 0; built_intbl[i].type; i++)
		if (_strcmp(inf->argv[0], built_intbl[i].type) == 0)
		{
			inf->line_count++;
			built_in_ret = built_intbl[i].func(inf);
			break;
		}
	return (built_in_ret);
}

/**
 * findCmd - finds a command in PATH
 * @inf: the parameter & return info struct
 * Return: void
 */
void findCmd(info_t *inf)
{
	char *path = NULL;
	int i, k;

	inf->path = inf->argv[0];
	if (inf->linecount_flag == 1)
	{
		inf->line_count++;
		inf->linecount_flag = 0;
	}
	for (i = 0, k = 0; inf->arg[i]; i++)
		if (!isDelim(inf->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(inf, _get_env(inf, "PATH="), inf->argv[0]);
	if (path)
	{
		inf->path = path;
		fork_cmd(inf);
	}
	else
	{
		if ((interactive_mode(inf) || _get_env(inf, "PATH=")
			|| inf->argv[0][0] == '/') && is_cmd(inf, inf->argv[0]))
			fork_cmd(inf);
		else if (*(inf->arg) != '\n')
		{
			inf->status = 127;
			print_error(inf, "not found\n");
		}
	}
}
