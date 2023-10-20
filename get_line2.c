#include "main.h"


/**
 * get_input - gets a line minus the newline
 * @inf: parameter sstttructtt
 * Return: bytes read
 */
ssize_t get_input(info_t *inf)
{
	static char *buf; 
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(inf->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(inf, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i; /* get pointer for return */

		check_chainn(inf, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chainn(inf, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			inf->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (r);
}

/**
 * read_buf - reads a buffer
 * @inf: parameter struct
 * @buff: buffer for string
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *inf, char *buff, size_t *i)
{
	ssize_t s = 0;

	if (*i)
		return (0);
	s = read(inf->readfd, buff, READ_BUF_SIZE);
	if (s >= 0)
		*i = s;
	return (s);
}

