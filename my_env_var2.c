#include "main.h"

/**
 * _munsetenvShll - Remove an environment variable.
 *
 * @my_infoShll: Parameter structure.
 *
 * Return: Always returns 0.
*/

int _munsetenvShll(my_info_stShll *my_infoShll)
{
	int my_iShll;

	if (my_infoShll->my_argcShll == 1)
	{
		_eputsShll("Too few arguments.\n");
		return (1);
	}
	for (my_iShll = 1; my_iShll <= my_infoShll->my_argcShll; my_iShll++)
		_unsetenvShll(my_infoShll, my_infoShll->my_argvShll[my_iShll]);

	return (0);
}

/**
 * _unsetenvShll - Delete an environment variable.
 *
 * @my_infoShll: Parameter structure.
 * @my_varShll: The string representing the environment variable.
 *
 * Return: Returns 1 upon deletion, 0 if not found.
 */

int _unsetenvShll(my_info_stShll *my_infoShll, char *my_varShll)
{
	my_list_stShll *my_nodeShll = my_infoShll->my_envShll;
	size_t my_iShll = 0;
	char *my_pShll;

	if (!my_nodeShll || !my_varShll)
		return (0);

	while (my_nodeShll)
	{
		my_pShll = my_starts_withShll(my_nodeShll->my_strShll, my_varShll);
		if (my_pShll && *my_pShll == '=')
		{
			my_infoShll->my_env_changedShll = my_delete_node_at_indexShll
				(&(my_infoShll->my_envShll), my_iShll);
			my_iShll = 0;
			my_nodeShll = my_infoShll->my_envShll;
			continue;
		}
		my_nodeShll = my_nodeShll->my_nextShll;
		my_iShll++;
	}
	return (my_infoShll->my_env_changedShll);
}

/**
 * _setenvShll - Initialize or modify an environment variable.
 *
 * @my_infoShll: Parameter structure.
 * @my_varShll: The string representing the environment variable.
 * @my_valueShll: The string representing the environment variable's value.
 *
 * Return: Always returns 0.
*/

int _setenvShll(my_info_stShll *my_infoShll, char *my_varShll,
		 char *my_valueShll)
{
	char *my_bufShll = NULL;
	my_list_stShll *my_nodeShll;
	char *my_pShll;

	if (!my_varShll || !my_valueShll)
		return (0);

	my_bufShll = malloc(_strlenShll(my_varShll) + _strlenShll(my_valueShll) + 2);
	if (!my_bufShll)
		return (1);
	_strcpyShll(my_bufShll, my_varShll);
	_strcatShll(my_bufShll, "=");
	_strcatShll(my_bufShll, my_valueShll);
	my_nodeShll = my_infoShll->my_envShll;
	while (my_nodeShll)
	{
		my_pShll = my_starts_withShll(my_nodeShll->my_strShll, my_varShll);
		if (my_pShll && *my_pShll == '=')
		{
			free(my_nodeShll->my_strShll);
			my_nodeShll->my_strShll = my_bufShll;
			my_infoShll->my_env_changedShll = 1;
			return (0);
		}
		my_nodeShll = my_nodeShll->my_nextShll;
	}
	my_add_node_endShll(&(my_infoShll->my_envShll), my_bufShll, 0);
	free(my_bufShll);
	my_infoShll->my_env_changedShll = 1;
	return (0);
}
