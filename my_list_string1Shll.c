#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_delete_node_at_indexShll -  deletes node at given index
 *
 * @my_headShll: it is a address of pointer to first node
 * @my_indexShll: it is aindex of node to delete
 *
 * Return: 1 on success, 0 on failure
*/

int my_delete_node_at_indexShll(my_list_stShll **my_headShll, unsigned int my_indexShll)
{
	my_list_stShll *my_nodeShll, *my_prev_nodeShll;
	unsigned int my_iShll = 0;

	if (!my_headShll || !*my_headShll)
		return (0);

	if (!my_indexShll)
	{
		my_nodeShll = *my_headShll;
		*my_headShll = (*my_headShll)->my_nextShll;
		free(my_nodeShll->my_strShll);
		free(my_nodeShll);
		return (1);
	}
	my_nodeShll = *my_headShll;
	while (my_nodeShll)
	{
		if (my_iShll == my_indexShll)
		{
			my_prev_nodeShll->my_nextShll = my_nodeShll->my_nextShll;
			free(my_nodeShll->my_strShll);
			free(my_nodeShll);
			return (1);
		}
		my_iShll++;
		my_prev_nodeShll = my_nodeShll;
		my_nodeShll = my_nodeShll->my_nextShll;
	}
	return (0);
}

/**
 * my_list_lenShll -function that  determines length of linked list
 *
 * @my_hShll: it is a pointer to first node
 *
 * Return: it returns size of list
*/

size_t my_list_lenShll(const my_list_stShll *my_hShll)
{
	my_size_tShll my_iShll = 0;

	while (my_hShll)
	{
		my_hShll = my_hShll->my_nextShll;
		my_iShll++;
	}
	return (my_iShll);
}

/**
 * my_list_to_stringsShll - function that returns an array of strings of the list->str
 *
 * @my_headShll: it is a pointer to first node
 *
 * Return: it returns  array of strings
 */
char **my_list_to_stringsShll(my_list_stShll *my_headShll)
{
	my_list_stShll *my_nodeShll = my_headShll;
	my_size_tShll my_iShll = my_list_lenShll(my_headShll), my_jShll;
	char **my_strsShll;
	char *my_strShll;

	if (!my_headShll || !my_iShll)
		return (NULL);
	my_strsShll = malloc(sizeof(char *) * (my_iShll + 1));
	if (!my_strsShll)
		return (NULL);
	for (my_iShll = 0; my_nodeShll; my_nodeShll = my_nodeShll->my_nextShll, my_iShll++)
	{
		my_strShll = malloc(_strlenShll(my_nodeShll->my_strShll) + 1);
		if (!my_strShll)
		{
			for (my_jShll = 0; my_jShll < my_iShll; my_jShll++)
				free(my_strsShll[my_jShll]);
			free(my_strsShll);
			return (NULL);
		}

		my_strShll = _strcpyShll(my_strShll, my_nodeShll->my_strShll);
		my_strsShll[my_iShll] = my_strShll;
	}
	my_strsShll[my_iShll] = NULL;
	return (my_strsShll);
}

/**
 * my_get_node_indexShll - function that gets the index of a node
 *
 * @my_headShll: it is a pointer to list head
 * @my_nodeShll: it is a pointer to the node
 *
 * Return: it returns  index of node or -1
*/

ssize_t my_get_node_indexShll(my_list_stShll *my_headShll, my_list_stShll *my_nodeShll)
{
	my_size_tShll my_iShll = 0;

	while (my_headShll)
	{
		if (my_headShll == my_nodeShll)
			return (my_iShll);
		my_headShll = my_headShll->my_nextShll;
		my_iShll++;
	}
	return (-1);
}
