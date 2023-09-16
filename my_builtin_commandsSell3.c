#include "main.h"

/**
 * _historyShll - this function will : displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @my_infoShll: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always returns 0
 */

int _historyShll(my_info_stShll *my_infoShll)
{
	my_print_listShll(my_infoShll->my_historyShll);
	return (0);
}

/**
 * my_unset_aliasShll - this function will : sets alias to string
 * @my_infoShll: parameter struct
 * @my_strShll: the string alias
 * Return: Always returns 0 on success, 1 on error
 */

int my_unset_aliasShll(my_info_stShll *my_infoShll, char *my_strShll)
{
	char *my_pShll, my_cShll;
	int my_retShll;

	my_pShll = _strchrShll(my_strShll, '=');
	if (!my_pShll)
		return (1);
	my_cShll = *my_pShll;
	*my_pShll = 0;
	my_retShll = my_delete_node_at_indexShll(&(my_infoShll->my_aliasShll),
		my_get_node_indexShll(my_infoShll->my_aliasShll, my_node_starts_withShll(my_infoShll->my_aliasShll, my_strShll, -1)));
	*my_pShll = my_cShll;
	return (my_retShll);
}
