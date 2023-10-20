#include "main.h"

/**
 * set_info - initializes info_t struct
 * @inf: struct address
 * @av: argument vector
 */
void set_info(info_t *inf, char **av)
{
	int i = 0;

	inf->fname = av[0];
	if (inf->arg)
	{
		inf->argv = str_tow(inf->arg, " \t");
		if (!inf->argv)
		{

			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = _strdupp(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (i = 0; inf->argv && inf->argv[i]; i++)
			;
		inf->argc = i;

		replace_Alias(inf);
		replace__vars(inf);
	}
}

