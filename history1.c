#include "main.h"

/**
 * get_history_file - gets the history file
 * @inf: parameter one
 * Return: allocated string 
 */

char *get_history_file(info_t *inf)
{
	char *buffer, *direction;

	direction = _get_env(inf, "HOME=");
	if (!direction)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(direction) + _strlen(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, direction);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE);
	return (buffer);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @inf: info oarameter for struct
 * Return: 1 on success, else -1
 */
int write_history(info_t *inf)
{
	ssize_t fd;
	char *filename = get_history_file(inf);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = inf->history; node; node = node->next)
	{
		_puts_fd(node->str, fd);
		_put_fd('\n', fd);
	}
	_put_fd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}



/**
 * renumber_history - renumbers the history linked list after changes
 * @inf: Structure containing potential arguments. Used to maintain
 * Return: the new histcount
 */
int renumber_history(info_t *inf)
{
	list_t *node = inf->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (inf->histcount = i);
}
