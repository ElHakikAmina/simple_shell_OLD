#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_set_aliasShll - Assigns an alias to a specified string.
 *
 * @my_infoShll: A structure containing relevant parameters.
 * @my_strShll: The string to be used as an alias.
 *
 * Return: 0 on success, 1 on error.
*/

int my_set_aliasShll(my_info_stShll *my_infoShll, char *my_strShll)
{
	char *my_pShll;

	my_pShll = _strchrShll(my_strShll, '=');
	if (!my_pShll)
		return (1);
	if (!*++my_pShll)
		return (my_unset_aliasShll(my_infoShll, my_strShll));

	my_unset_aliasShll(my_infoShll, my_strShll);
	return (my_add_node_endShll(&(my_infoShll->my_aliasShll), my_strShll, 0) == NULL);
}
