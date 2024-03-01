#include "shell.h"

/**
 * info_copy - copies information between void pointer in prog.
 * @crtptr: destination pointer new loc.
 * @pr: source pointer.
 * @size: size of the current pointer
 *
 * Return: no return.
 */
void info_copy(void *crtptr, const void *pr, unsigned int size)
{
	char *char_pr = (char *)pr;
	char *char_crtptr = (char *)crtptr;
	unsigned int p;

	for (p = 0; p < size; p++)
		char_crtptr[p] = char_pr[p];
}

/**
 * allocates_mem - reallocates a memory.
 * @pr: pointer to the memory previously assigned.
 * @pv_size: size, in bytes, of the allocated space of pr.
 * @crt_size: new size, in bytes, of the new memory.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *allocates_mem(void *pr, unsigned int pv_size, unsigned int crt_size)
{
	void *crtptr;

	if (pr == NULL)
		return (malloc(crt_size));

	if (crt_size == 0)
	{
		free(pr);
		return (NULL);
	}

	if (crt_size == old_size)
		return (tr);

	crtptr = malloc(crt_size);
	if (crtptr == NULL)
		return (NULL);

	if (crt_size < pv_size)
		info_copy(crtptr, pr, crt_size);
	else
		info_copy(crtptr, pr, pv_size);

	free(pr);
	return (crtptr);
}

/**
 * alloc_dab - reallocates a memory of a double pointer
 * @pr: double pointer to the memory previously assigned
 * @pv_size: size, in bytes, of the allocated space of ptr.
 * @crt_size: new size, in bytes, of the new memory block.
 *
 * Return: pr.
 * if crt_size == pv_size, returns pr without changes.
 * if malloc fails, returns NULL.
 */
char **alloc_dab(char **pr, unsigned int pv_size, unsigned int crt_size)
{
	char **crtptr;
	unsigned int p;

	if (pr == NULL)
		return (malloc(sizeof(char *) * crt_size));

	if (crt_size == pv_size)
		return (pr);

	crtptr = malloc(sizeof(char *) * crt_size);
	if (crtptr == NULL)
		return (NULL);

	for (p = 0; p < pv_size; p++)
		crtptr[p] = pr[p];

	free(pr);

	return (crtptr);
}
