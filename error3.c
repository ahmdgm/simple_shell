#include "main.h"

/**
 * _puts_fd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 * Return: the number of chars put
 */
int _puts_fd(char *str, int fd)
{
	int counter = 0;

	if (!str)
		return (0);
	while (*str)
	{
		counter += _put_fd(*str++, fd);
	}
	return (counter);
}

/**
 * _e_put_char - writes the character c to stderr
 * @ch: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _e_put_char(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}
/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buff: address for string
 * Return: Always 0;
 */
void remove_comments(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
		if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: first parameter
 * @base: second parameter
 * @flag: flag parameter
 * Return: string
 */
char *convert_number(long int num, int base, int flag)
{
	static char *arr;
	static char buff[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

