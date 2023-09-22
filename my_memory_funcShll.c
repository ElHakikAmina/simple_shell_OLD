#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_bfreeShll - Frees a pointer and sets it to NULL.
 *
 * @my_ptrShll: Address of the pointer to be freed.
 *
 * Return: 1 for success, 0 for failure.
*/

int my_bfreeShll(void **my_ptrShll)
{
	if (my_ptrShll && *my_ptrShll)
	{
		free(*my_ptrShll);
		*my_ptrShll = NULL;
		return (1);
	}
	return (0);
}

/**
 * my_free_listShll - Frees all nodes of a linked list.
 *
 * @my_head_ptrShll: Address of the pointer to the head node.
 *
 * Return: Nothing.
*/

void my_free_listShll(my_list_stShll **my_head_ptrShll)
{
	my_list_stShll *my_nodeShll, *my_next_nodeShll, *my_headShll;

	if (!my_head_ptrShll || !*my_head_ptrShll)
		return;
	my_headShll = *my_head_ptrShll;
	my_nodeShll = my_headShll;
	while (my_nodeShll)
	{
		my_next_nodeShll = my_nodeShll->my_nextShll;
		free(my_nodeShll->my_strShll);
		free(my_nodeShll);
		my_nodeShll = my_next_nodeShll;
	}
	*my_head_ptrShll = NULL;
}

/**
 * my_ffreeShll - Frees a string of strings.
 *
 * @my_ppShll: String of strings to be freed.
 *
 * Return: Always 0.
*/

void my_ffreeShll(char **my_ppShll)
{
	char **my_aShll = my_ppShll;

	if (!my_ppShll)
		return;
	while (*my_ppShll)
		free(*my_ppShll++);
	free(my_aShll);
}

/**
 * _reallocShll - Reallocates a block of memory.
 *
 * @my_ptrShll: Pointer to the previously allocated block.
 * @my_old_sizeShll: Byte size of the previous block.
 * @my_new_sizeShll: Byte size of the new block.
 *
 * Return: A pointer to the reallocated memory.
*/

void *_reallocShll(void *my_ptrShll, unsigned int my_old_sizeShll,
		 unsigned int my_new_sizeShll)
{
	char *my_pShll;

	if (!my_ptrShll)
		return (malloc(my_new_sizeShll));
	if (!my_new_sizeShll)
		return (free(my_ptrShll), NULL);
	if (my_new_sizeShll == my_old_sizeShll)
		return (my_ptrShll);

	my_pShll = malloc(my_new_sizeShll);
	if (!my_pShll)
		return (NULL);
	my_old_sizeShll = my_old_sizeShll < my_new_sizeShll ?
		 my_old_sizeShll : my_new_sizeShll;
	while (my_old_sizeShll--)
		my_pShll[my_old_sizeShll] = ((char *)my_ptrShll)[my_old_sizeShll];
	free(my_ptrShll);
	return (my_pShll);
}

/**
 * _memsetShll - Fills the memory with a constant byte.
 *
 * @my_sShll: Pointer to the memory area.
 * @my_bShll: The byte used to fill *s.
 * @my_nShll: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area (*s).
*/

char *_memsetShll(char *my_sShll, char my_bShll, unsigned int my_nShll)
{
	unsigned int my_iShll;

	for (my_iShll = 0; my_iShll < my_nShll; my_iShll++)
		my_sShll[my_iShll] = my_bShll;
	return (my_sShll);
}
