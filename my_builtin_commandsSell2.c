#include "main.h"

/**
 * _myaliasShll - mimics the alias builtin (man alias)
 * @infoShll: Structure containing potential arguments. Used to maintain
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
			print_alias(my_nodeShll);
			my_nodeShll = my_nodeShll->my_nextShll;
		}
		return (0);
	}
	for (my_i = 1; my_infoShll->my_argvShll[i]; my_i++)
	{
		my_p = _strchrShll(infoShll->argvShll[i], '=');
		if (pShll)
			my_set_aliasShll(my_infoShll, my_infoShll->my_argvShll[i]);
		else
			my_print_aliasShll(my_node_starts_withShll(my_infoShll->my_aliasShll, my_infoShll->my_argvShll[i], '='));
	}

	return (0);
}
/**
 * _mycdShll - this function is responsible for changes the current directory of the process
 * @infoShll: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycdShll(my_info_stShll *my_infoShll)
{
	char *my_sShll, *my_dirShll, my_bufferShll[1024];
	int my_chdir_retShll;

	my_sShell = my_getcwdShll(my_bufferShll, 1024);
	if (!my_sShll)
		_putsShll("TODO: >>getcwd failure emsg here<<\n");
	if (!my_infoShll->my_argvShll[1])
	{
		dir = _getenvShll(my_info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(my_infoShll, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(my_infoShll->my_argvShll[1], "-") == 0)
	{
		if (!_getenvShll(my_infoShll, "OLDPWD="))
		{
			_putsShll(s);
			_putcharShll('\n');
			return (1);
		}
		_putsShll(_getenvShll(my_infoShll, "OLDPWD=")), _putcharShll('\n');
		my_chdir_retShll = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		my_chdir_retShll = my_chdirShll(info->argv[1]);
	if (my_chdir_retShll == -1)
	{
		print_error(my_infoShll, "can't cd to ");
		_eputsShll(my_infoShll->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenvShll(my_infoShll, "OLDPWD", _getenv(info, "PWD="));
		_setenvShll(my_infoShll, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

