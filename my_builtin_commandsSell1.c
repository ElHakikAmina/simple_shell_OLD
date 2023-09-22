#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_print_aliasShll - Display an alias string.
 *
 * @my_nodeShll: The alias node.
 *
 * Return: 0 on success, 1 on error.
*/

int my_print_aliasShll(my_list_stShll *my_nodeShll)
{
	char *my_pShll = NULL, *my_aShll = NULL;

	if (my_nodeShll)
	{
		my_pShll = _strchrShll(my_nodeShll->my_strShll, '=');
		for (my_aShll = my_nodeShll->my_strShll; my_aShll <= my_pShll; my_aShll++)
			_putcharShll(*my_aShll);
		_putcharShll('\'');
		_putsShll(my_pShll + 1);
		_putsShll("'\n");
		return (0);
	}
	return (1);
}

/**
 * _helpShll - This function is responsible for updating the current
 * working directory of the process.
 *
 * @my_infoShll: A structure that may contain additional arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Returns 0 upon successful execution.
*/

int _helpShll(my_info_stShll *my_infoShll)
{
	char **my_arg_arrayShll;

	my_arg_arrayShll = my_infoShll->my_argvShll;
	_putsShll("help call works. Function not yet implemented \n");
	if (0)
		_putsShll(*my_arg_arrayShll);
	return (0);
}

/**
 * _exitShll - Exits the shell if info.argv[0] is not exit.
 *
 * @my_infoShll: A structure that may contain pertinent arguments,
 * ensuring a consistent function prototype.
 *
 * Return: Exits the shell with a specified exit status (0).
*/

int _exitShll(my_info_stShll *my_infoShll)
{
	int my_exitcheckShll;

	if (my_infoShll->my_argvShll[1])
	{
		my_exitcheckShll = _erratoiShll(my_infoShll->my_argvShll[1]);
		if (my_exitcheckShll == -1)
		{
			my_infoShll->my_statusShll = 2;
			my_print_errorShll(my_infoShll, "Illegal number: ");
			_eputsShll(my_infoShll->my_argvShll[1]);
			_eputcharShll('\n');
			return (1);
		}
		my_infoShll->my_err_numShll = _erratoiShll(my_infoShll->my_argvShll[1]);
		return (-2);
	}
	my_infoShll->my_err_numShll = -1;
	return (-2);
}
