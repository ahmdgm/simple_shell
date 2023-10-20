#include "main.h"

/**
 * _e_puts - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _e_puts(char *str)
{
	int counter = 0;

	if (!str)
		return;
	while (str[counter] != '\0')
	{
		_e_put_char(str[counter]);
		counter++;
	}
}

/**
 * _put_fd - writes the character c to given fd
 * @ch: The character to print
 * @fd: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _put_fd(char ch, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

