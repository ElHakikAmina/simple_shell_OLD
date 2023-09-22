#include "main.h"

/**
 * _menvShll - Print the current environment.
 *
 * @my_infoShll: Parameter structure.
 *
 * Return: Always returns 0.
*/

int _menvShll(my_info_stShll *my_infoShll)
{
	my_print_liststrShll(my_infoShll->my_envShll);
	return (0);
}

/**
 * _getenvShll - Retrieve the value of an environment variable.
 *
 * @my_infoShll: Parameter structure.
 * @my_nameShll: Environment variable name.
 *
 * Return: Environment variable value.
 */

char *_getenvShll(my_info_stShll *my_infoShll, const char *my_nameShll)
{
	my_list_stShll *my_nodeShll = my_infoShll->my_envShll;
	char *my_pShll;

	while (my_nodeShll)
	{
		my_pShll = my_starts_withShll(my_nodeShll->my_strShll, my_nameShll);
		if (my_pShll && *my_pShll)
			return (my_pShll);
		my_nodeShll = my_nodeShll->my_nextShll;
	}
	return (NULL);
}

/**
 * my_get_environShll - Return a copy of the string
 * array containing our environment.
 *
 * @my_infoShll: Parameter structure.
 *
 * Return: Environment array.
 */

char **my_get_environShll(my_info_stShll *my_infoShll)
{
	if (!my_infoShll->environ || my_infoShll->my_env_changedShll)
	{
		my_infoShll->environ = my_list_to_stringsShll(my_infoShll->my_envShll);
		my_infoShll->my_env_changedShll = 0;
	}
	return (my_infoShll->environ);
}

/**
 * my_populate_env_listShll - Populate the environment linked list.
 *
 * @my_infoShll: Parameter structure.
 *
 * Return: Always returns 0.
 */

int my_populate_env_listShll(my_info_stShll *my_infoShll)
{
	my_list_stShll *my_nodeShll = NULL;
	size_t my_iShll;

	for (my_iShll = 0; environ[my_iShll]; my_iShll++)
		my_add_node_endShll(&my_nodeShll, environ[my_iShll], 0);
	my_infoShll->my_envShll = my_nodeShll;
	return (0);
}

/**
 * _msetenvShll - Initialize a new environment variable
 * or modify an existing one.
 *
 * @my_infoShll: Parameter structure.
 *
 * Return: Always returns 0.
 */

int _msetenvShll(my_info_stShll *my_infoShll)
{
	if (my_infoShll->my_argcShll != 3)
	{
		_eputsShll("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenvShll(my_infoShll, my_infoShll->my_argvShll[1],
				 my_infoShll->my_argvShll[2]))
		return (0);
	return (1);
}
