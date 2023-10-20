#include "main.h"
/**
 * ffree - frees a string of strings
 * @pptr: string of strings
 * Return: void
 */
void ffree(char **pptr)
{
	char **m = pptr;

	if (!pptr)
		return;
	while (*pptr)
		free(*pptr++);
	free(m);
}
