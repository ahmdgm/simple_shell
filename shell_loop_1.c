#include "main.h"

/**
 * hsh - main shell loop
 * @inf: the parameter & return info struct
 * @av: the argument vector av
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *inf, char **av)
{
	ssize_t r = 0;
	int built_in_ret = 0;

	while (r != -1 && built_in_ret != -2)
	{
		clear_info(inf);
		if (interactive_mode(inf))
			_puts("$ ");
		_e_put_char(BUF_FLUSH);
		r = get_input(inf);
		if (r != -1)
		{
			set_info(inf, av);
			built_in_ret = find_built_in(inf);
			if (built_in_ret == -1)
				findCmd(inf);
		}
		else if (interactive_mode(inf))
			_putchar('\n');
		free_info(inf, 0);
	}
	write_history(inf);
	free_info(inf, 1);
	if (!interactive_mode(inf) && inf->status)
		exit(inf->status);
	if (built_in_ret == -2)
	{
		if (inf->err_num == -1)
			exit(inf->status);
		exit(inf->err_num);
	}
	return (built_in_ret);
}



/**
 * fork_cmd - forks a an exec thread to run cmd
 * @inf: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *inf)
{
	pid_t childPpid;

	childPpid = fork();
	if (childPpid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (childPpid == 0)
	{
		if (execve(inf->path, inf->argv, get_environ(inf)) == -1)
		{
			free_info(inf, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(inf->status));
		if (WIFEXITED(inf->status))
		{
			inf->status = WEXITSTATUS(inf->status);
			if (inf->status == 126)
				print_error(inf, "Permission denied\n");
		}
	}
}
