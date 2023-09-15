#include "main.h"

/**
 * my_set_aliasShll - this function will : sets alias to string
 * @my_infoShll: this will : parameter struct
 * @my_strShll: this will :the string alias
 * Return: Always returns 0 on success, 1 on error
 */

int my_set_aliasShll(my_info_stShll *my_infoShll, char *my_strShll)
{
	char *my_pShll;

	my_pShll = _strchrShll(my_strShll, '=');
	if (!my_mu_pShll)
		return (1);
	if (!*++my_pShll)
		return (my_unset_aliasShll(my_infoShll, my_strShll));

	my_unset_aliasShll(my_infoShll, my_strShll);
	return (my_add_node_endShll(&(my_infoShll->my_aliasShll), my_strShll, 0) == NULL);
}
