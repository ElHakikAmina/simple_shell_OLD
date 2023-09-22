#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_add_nodeShll - Function that inserts a node at the beginning of a linked list.
 *
 * @my_headShll: Address of a pointer to the head node.
 * @my_strShll: String field of the new node.
 * @my_numShll: Node index used for history.
 *
 * Return: Returns the updated size of the list.
*/

my_list_stShll *my_add_nodeShll(my_list_stShll **my_headShll, const char *my_strShll, int my_numShll)
{
        my_list_stShll *my_new_headShll;

        if (!my_headShll)
                return (NULL);
        my_new_headShll = malloc(sizeof(my_list_stShll));
        if (!my_new_headShll)
                return (NULL);
        _memsetShll((void *)my_new_headShll, 0, sizeof(my_list_stShll));
        my_new_headShll->my_numShll = my_numShll;
        if (my_strShll)
        {
                my_new_headShll->my_strShll = _strdupShll(my_strShll);
                if (!my_new_headShll->my_strShll)
                {
                        free(my_new_headShll);
                        return (NULL);
                }
        }
        my_new_headShll->my_nextShll = *my_headShll;
        *my_headShll = my_new_headShll;
        return (my_new_headShll);
}

/**
 * my_print_listShll - Prints all elements of a list_st linked list.
 *
 * @my_hShll: Pointer to the first node.
 *
 * Return: The size of the list.
*/

size_t my_print_listShll(const my_list_stShll *my_hShll)
{
        size_t my_iShll = 0;

        while (my_hShll)
        {
                _putsShll(my_convert_numberShll(my_hShll->my_numShll, 10, 0));
                _putcharShll(':');
                _putcharShll(' ');
                _putsShll(my_hShll->my_strShll ? my_hShll->my_strShll : "(nil)");
                _putsShll("\n");
                my_hShll = my_hShll->my_nextShll;
                my_iShll++;
        }
        return (my_iShll);
}

/**
 * my_node_starts_withShll - Finds a node whose string begins with a given prefix.
 *
 * @my_nodeShll: Pointer to the list head.
 * @my_prefixShll: Prefix string to match.
 * @my_cShll: Next character after the matched prefix.
 *
 * Return: The matching node or NULL if not found.
*/

my_list_stShll *my_node_starts_withShll(my_list_stShll *my_nodeShll, char *my_prefixShll, char my_cShll)
{
        char *my_pShll = NULL;

        while (my_nodeShll)
        {
                my_pShll = my_starts_withShll(my_nodeShll->my_strShll, my_prefixShll);
                if (my_pShll && ((my_cShll == -1) || (*my_pShll == my_cShll)))
                        return (my_nodeShll);
                my_nodeShll = my_nodeShll->my_nextShll;
        }
        return (NULL);
}

/**
 * my_print_liststrShll - Prints only the 'str' element of a list_t linked list.
 *
 * @my_hShll: Pointer to the first node.
 *
 * Return: The size of the list.
*/

size_t my_print_liststrShll(const my_list_stShll *my_hShll)
{
	size_t my_iShll = 0;

	while (my_hShll)
	{
		_putsShll(my_hShll->my_strShll ? my_hShll->my_strShll : "(nil)");
		_putsShll("\n");
		my_hShll = my_hShll->my_nextShll;
		my_iShll++;
	}
	return (my_iShll);
}

/**
 * my_add_node_endShll - Appends a node to the end of a linked list.
 *
 * @my_headShll: Pointer to the head node.
 * @my_strShll: String for the new node.
 * @my_numShll: Node index used in history.
 *
 * Return: The updated list size.
*/

my_list_stShll *my_add_node_endShll(my_list_stShll **my_headShll, const char *my_strShll, int my_numShll)
{
	my_list_stShll *my_new_nodeShll, *my_nodeShll;

	if (!my_headShll)
		return (NULL);

	my_nodeShll = *my_headShll;
	my_new_nodeShll = malloc(sizeof(my_list_stShll));
	if (!my_new_nodeShll)
		return (NULL);
	_memsetShll((void *)my_new_nodeShll, 0, sizeof(my_list_stShll));
	my_new_nodeShll->my_numShll = my_numShll;
	if (my_strShll)
	{
		my_new_nodeShll->my_strShll = _strdupShll(my_strShll);
		if (!my_new_nodeShll->my_strShll)
		{
			free(my_new_nodeShll);
			return (NULL);
		}
	}
	if (my_nodeShll)
	{
		while (my_nodeShll->my_nextShll)
			my_nodeShll = my_nodeShll->my_nextShll;
		my_nodeShll->my_nextShll = my_new_nodeShll;
	}
	else
		*my_headShll = my_new_nodeShll;
	return (my_new_nodeShll);
}
