#include "main.h"

/**
 * _erratoi - function to converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @inf: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string
 */
void print_error(info_t *inf, char *estr)
{
	_e_puts(inf->fname);
	_e_puts(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_e_puts(": ");
	_e_puts(inf->argv[0]);
	_e_puts(": ");
	_e_puts(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @in: the input
 * @fd: the filedescriptor to write to
 * Return: number of characters printed
 */
int print_d(int in, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _e_put_char;
	if (in < 0)
	{
		_abs_ = -in;
		__putchar('-');
		count++;
	}
	else
		_abs_ = in;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}


