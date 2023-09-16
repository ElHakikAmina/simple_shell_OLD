#include "main.h"

/**
 * _exitShll - This function is responsible for gracefully exiting the shell.
 * @my_infoShll: A structure that may contain relevant arguments, ensuring a consistent
 * function prototype.
 * Return: This function exits the shell with a specified exit status (0) if info.argv[0] is not equal to "exit".
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

/**
 * _helpShll - this function is responsible for changing the current directory of the process.
 * @my_infoShll: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always return 0
*/

int _helpShll(info_stShll *infoShll)
{
	char **my_arg_arrayShll;

	my_arg_arrayShll = my_infoShll->my_argvShll;
	_putsShll("help call works. Function not yet implemented \n");
	if (0)
		_putsShll(*my_arg_arrayShll);
	return (0);
}

/**
 * my_print_aliasShll - this function is responsible for : prints an alias string.
 * @my_nodeShll: variable the alias node.
 *
 * Return: Always 0 on success, 1 on error
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
