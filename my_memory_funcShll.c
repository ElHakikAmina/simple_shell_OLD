#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_bfreeShll - function that frees a pointer and nulls the address
 *
 * @my_ptrShll: it is an address of pointer to be freed
 *
 * Return: 1 for success 0 for fail
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
 * my_free_listShll - function that frees all nodes of a list
 *
 * @my_head_ptrShll: it is an address of pointer to head node
 *
 * Return: Nothing
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
 * my_ffreeShll - function that frees a string of strings
 *
 * @my_ppShll: it is a string of strings
 *
 * Return: Always 0
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
 * _reallocShll - function that  reallocates a block of memory
 *
 * @my_ptrShll: it is a  pointer to previous mallocated block
 * @my_old_sizeShll: it is a byte size of previous block
 * @my_new_sizeShll:it is a byte size of new block
 *
 * Return: a pointer
*/

void *_reallocShll(void *my_ptrShll, unsigned int my_old_sizeShll, unsigned int my_new_sizeShll)
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
        my_old_sizeShll = my_old_sizeShll < my_new_sizeShll ? my_old_sizeShll : my_new_sizeShll;
        while (my_old_sizeShll--)
                my_pShll[my_old_sizeShll] = ((char *)my_ptrShll)[my_old_sizeShll];
        free(my_ptrShll);
        return (my_pShll);
}

/**
 * _memsetShll - function that fills the memory with const byte
 *
 * @my_sShll: it is a pointer ta memory area
 * @my_bShll: it is a the byte to fill *s with
 * @my_nShll: it is a  the amount of bytes to be filled
 *
 * Return: it returns (s)
*/

char *_memsetShll(char *my_sShll, char my_bShll, unsigned int my_nShll)
{
	unsigned int my_iShll;

	for (my_iShll = 0; my_iShll < my_nShll; my_iShll++)
		my_sShll[my_iShll] = my_bShll;
	return (my_sShll);
}
