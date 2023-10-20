#include "main.h"

/**
 * b_free - frees a pointer and NULLs the address
 * @pp: address of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **pp)
{
	if (pp && *pp)
	{
		free(*pp);
		*pp = NULL;
		return (1);
	}
	return (0);
}
