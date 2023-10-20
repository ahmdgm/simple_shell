#include "main.h"

/**
 * interactive_mode - returns true if shell is interactive mode
 * @inf: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive_mode(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * isDelim - checks if character is a delimeter
 * @c: the char to check
 * @dl: the delimeter string
 * Return: 1 if true, 0 if false
 */
int isDelim(char c, char *dl)
{
	while (*dl)
		if (*dl++ == c)
			return (1);
	return (0);
}


