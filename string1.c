#include "main.h"

/**
 * _strlen - determine length of string
 * @c: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *c)
{
	int i = 0;

	if (!c)
		return (0);
	while (*c++)
		i++;
	return (i);
}



/**
 * start_with - checks if needle starts with hystack
 * @hystack: string to be searched
 * @needle: the substring to find
 * Return: address of next char of hystack or NULL
 */
char *start_with(const char *hystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *hystack++)
			return (NULL);
	return ((char *)hystack);
}
/**
 * _strcat - concatenates strings
 * @dest: the destination to be concatinated
 * @src: the source string
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *m = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (m);
}
