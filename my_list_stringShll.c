#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_print_liststrShll function that  prints only the str element of a list_t linked list
 *
 * @my_hShll: it is a pointer to first node
 *
 * Return: it returns size of list
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
 * my_add_nodeShll - function that adds a node to the start of the list
 *
 * @my_headShll: it is a address of pointer to head node
 * @my_strShll: it is a str field of node
 * @my_numShll: it is a node index used by history
 *
 * Return: it returns size of list
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
 * my_add_node_endShll - function that adds a node to the end of the list
 *
 * @my_headShll:it is a  address of pointer to head node
 * @my_strShll: it is a str field of node
 * @my_numShll: it is a  node index used by history
 *
 * Return: size of list
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

/**
 * my_print_listShll - function that prints all elements of a list_st linked list
 *
 * @my_hShll: it is a pointer to first node
 *
 * Return: it returns size of list
*/

my_size_tShll my_print_listShll(const my_list_stShll *my_hShll)
{
	my_size_tShll my_iShll = 0;

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
 * my_node_starts_withShll - function that  returns node whose string starts with prefix
 *
 * @my_nodeShll: it is a pointer to list head
 * @my_prefixShll: it is a string to match
 * @my_cShll: it is a the next character after prefix to match
 *
 * Return: it is a match node or null
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
