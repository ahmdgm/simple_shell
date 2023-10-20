#include "main.h"

/**
 * _my_exit - exits the shell
 * @inf: Structure containing potential arguments
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _my_exit(info_t *inf)
{
	int exitcheck;

	if (inf->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(inf->argv[1]);
		if (exitcheck == -1)
		{
			inf->status = 2;
			print_error(inf, "Illegal number: ");
			_e_puts(inf->argv[1]);
			_e_put_char('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 **_strchr - function to locates a character in a string
 *@s: the string to be parsed
 *@ch: the character to look for
 *
 *Return:  a pointer to the memory area
 */
char *_strchr(char *s, char ch)
{
	do {
		if (*s == ch)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * _strncat - function to concatenates two strings
 *@d: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *d, char *src, int n)
{
	int i, j;
	char *s = d;

	i = 0;
	j = 0;
	while (d[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		d[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		d[i] = '\0';
	return (s);
}

