#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_unset_aliasShll - Renames a string alias.
 *
 * @my_infoShll: Parameter struct.
 * @my_strShll: New alias name.
 *
 * Return: 0 on success, 1 on error.
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

/**
 * _historyShll - Displays command history with line numbers.
 *
 * @my_infoShll: Parameter struct.
 *
 * Return: Always returns 0.
*/

int _historyShll(my_info_stShll *my_infoShll)
{
        my_print_listShll(my_infoShll->my_historyShll);
        return (0);
}
