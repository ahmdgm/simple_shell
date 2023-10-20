#include "main.h"
/**
 * **str_tow2 - splits a string into words
 * @str: the input string
 * @c: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **str_tow2(char *str, char c)
{
	int i, j, k, z, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != c && str[i + 1] == c) ||
		    (str[i] != c && !str[i + 1]) || str[i + 1] == c)
			num_words++;
	if (num_words == 0)
		return (NULL);
	s = malloc((1 + num_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < num_words; j++)
	{
		while (str[i] == c && str[i] != c)
			i++;
		k = 0;
		while (str[i + k] != c && str[i + k] && str[i + k] != c)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (z = 0; z < k; z++)
			s[j][z] = str[i++];
		s[j][z] = 0;
	}
	s[j] = NULL;
	return (s);
}
