#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_list_lenShll - Function that calculates the length of a linked list.
 *
 * @my_hShll: Pointer to the first node.
 *
 * Return: Returns the size of the list.
*/

size_t my_list_lenShll(const my_list_stShll *my_hShll)
{
        size_t my_iShll = 0;

        while (my_hShll)
        {
                my_hShll = my_hShll->my_nextShll;
                my_iShll++;
        }
        return (my_iShll);
}

/**
 * my_get_node_indexShll - Function that retrieves the index of a specific node.
 *
 * @my_headShll: Pointer to the list's head.
 * @my_nodeShll: Pointer to the node.
 *
 * Return: Returns the index of the node or -1 if not found.
*/

ssize_t my_get_node_indexShll(my_list_stShll *my_headShll, my_list_stShll *my_nodeShll)
{
        size_t my_iShll = 0;

        while (my_headShll)
        {
                if (my_headShll == my_nodeShll)
                        return (my_iShll);
                my_headShll = my_headShll->my_nextShll;
                my_iShll++;
        }
        return (-1);
}

/**
 * my_delete_node_at_indexShll - Function that deletes a node at a given index.
 *
 * @my_headShll: Address of a pointer to the first node.
 * @my_indexShll: Index of the node to be deleted.
 *
 * Return: Returns 1 on success, 0 on failure.
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
 * my_list_to_stringsShll - Function that converts a linked list to an array of strings.
 *
 * @my_headShll: Pointer to the first node.
 *
 * Return: Returns an array of strings.
*/

char **my_list_to_stringsShll(my_list_stShll *my_headShll)
{
	my_list_stShll *my_nodeShll = my_headShll;
	size_t my_iShll = my_list_lenShll(my_headShll), my_jShll;
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
