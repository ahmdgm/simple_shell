#include "main.h"

/**
 **_strncpy - copies a string
 *@d: the destination
 *@src: source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *d, char *src, int n)
{
	int i, j;
	char *s = d;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		d[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			d[j] = '\0';
			j++;
		}
	}
	return (s);
}


