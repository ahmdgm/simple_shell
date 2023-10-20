#include "main.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}



/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @oldsize: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int oldsize, unsigned int new_size)
{
	char *ptr2;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == oldsize)
		return (ptr);

	ptr2 = malloc(new_size);
	if (!ptr2)
		return (NULL);

	oldsize = oldsize < new_size ? oldsize : new_size;
	while (oldsize--)
		ptr2[oldsize] = ((char *)ptr)[oldsize];
	free(ptr);
	return (ptr2);
}
