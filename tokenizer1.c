#include "main.h"

/**
 * **str_tow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @c: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **str_tow(char *str, char *c)
{
	int i, j, k, m, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!c)
		c = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (! isDelim(str[i], c) && ( isDelim(str[i + 1], c) || !str[i + 1]))
			num_words++;
	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while ( isDelim(str[i], c))
			i++;
		k = 0;
		while (! isDelim(str[i + k], c) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
