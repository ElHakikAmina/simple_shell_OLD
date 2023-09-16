#include "main.h"

/**
 * _myaliasShll - mimics the alias builtin (man alias)
 * @my_infoShll: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int _myaliasShll(my_info_stShll *my_infoShll)
{
	int my_iShll = 0;
	char *my_pShll = NULL;
	my_list_stShll *my_nodeShll = NULL;

	if (my_infoShll->my_argcShll == 1)
	{
		my_nodeShll = my_infoShll->my_aliasShll;
		while (my_nodeShll)
		{
			my_print_aliasShll(my_nodeShll);
			my_nodeShll = my_nodeShll->my_nextShll;
		}
		return (0);
	}
	for (my_iShll = 1; my_infoShll->my_argvShll[i]; my_iShll++)
	{
		my_pShll = _mystrchrShll(my_infoShll->my_argvShll[i], '=');
		if (my_pShll)
			my_set_aliasShll(my_infoShll, my_infoShll->my_argvShll[i]);
		else
			my_print_aliasShll(my_node_starts_withShll(my_infoShll->my_aliasShll,
					       	my_infoShll->my_argvShll[i], '='));
	}
	return (0);
}

/**
 * _mycdShll - this function is responsible for changes the current directory of the process
 * @my_infoShll: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycdShll(my_info_stShll *my_infoShll)
{
	char *my_sShll, *my_dirShll, my_bufferShll[1024];
	int my_chdir_retShll;

	my_sShell = my_getcwdShll(my_bufferShll, 1024);
	if (!my_sShll)
		_myputsShll("TODO: >>getcwd failure emsg here<<\n");
	if (!my_infoShll->my_argvShll[1])
	{
		my_dirShll = _mygetenvShll(my_infoShll, "HOME=");
		if (!my_dirShll)
			my_chdir_retShll = my_chdirShll((my_dirShll = _mygetenvShll(my_infoShll, "PWD=")) ? my_dirShll : "/");
		else
			my_chdir_retShll = my_chdirShll(my_dirShll);
	}
	else if (_mystrcmpShll(my_infoShll->my_argvShll[1], "-") == 0)
	{
		if (!_mygetenvShll(my_infoShll, "OLDPWD="))
		{
			_myputsShll(my_sShll);
			_myputcharShll('\n');
			return (1);
		}
		_myputsShll(_mygetenvShll(my_infoShll, "OLDPWD=")), _myputcharShll('\n');
		my_chdir_retShll = my_chdirShll((my_dirShll = _mygetenvShll(my_infoShll, "OLDPWD=")) ? my_dirShll : "/");
	}
	else
		my_chdir_retShll = my_chdirShll(my_infoShll->my_argvShll[1]);
	if (my_chdir_retShll == -1)
	{
		my_print_errorShll(my_infoShll, "can't cd to ");
		_myeputsShll(my_infoShll->my_argvShll[1]), _myeputcharShll('\n');
	}
	else
	{
		_mysetenvShll(my_infoShll, "OLDPWD", _mygetenvShll(my_infoShll, "PWD="));
		_mysetenvShll(my_infoShll, "PWD", my_getcwdShll(my_bufferShll, 1024));
	}
	return (0);
}

