#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_find_builtinShll - finds a builtin command
 *
 * @my_infoShll: struct
 *
 * Return: -1 if builtin not found
 *         0 if builtin is executed
 *         1 if builtin found (but not successful)
 *         -2 if builtin signals exit()
*/

int my_find_builtinShll(my_info_stShll *my_infoShll)
{
        int my_iShll, my_builtin_in_retShll = -1;
        my_builtin_tableShll my_builtintblShll[] = {
                {"exit", _exitShll},
                {"env", _envShll},
                {"help", _helpShll},
                {"history", _historyShll},
                {"setenv", _setenvShll},
                {"unsetenv", _unsetenvShll},
                {"cd", _cdShll},
                {"alias", _aliasShll},
                {NULL, NULL}
        };

        for (my_iShll = 0; my_builtintblShll[my_iShll].my_typeShll; my_iShll++)
                if (_strcmpShll(my_infoShll->my_argvShll[0], my_builtintblShll[my_iShll].my_typeShll) == 0)
                {
                        my_infoShll->my_line_countShll++;
                        my_builtin_in_retShll = my_builtintblShll[my_iShll].my_funcShll(my_infoShll);
                        break;
                }
        return (my_builtin_in_retShll);
}

/**
 * my_hshShll - main shell loop
 *
 * @my_infoShll: it is a struct
 * @my_avShll: it is a argument vector
 *
 * Return: 0 (Succes), 1 otherwise
*/

int my_hshShll(my_info_stShll *my_infoShll, char **my_avShll)
{
	my_ssize_tShll my_rShll = 0;
	int my_builtin_retShll = 0;

	while (my_rShll != -1 && my_builtin_retShll != -2)
	{
		my_clear_infoShll(my_infoShll);
		if (my_interactiveShll(my_infoShll))
			_putsShll("$ ");
		_eputcharShll(MY_BUF_FLUSHSHLL);
		my_rShll = my_get_inputShll(my_infoShll);
		if (my_rShll != -1)
		{
			my_set_infoShll(my_infoShll, my_avShll);
			my_builtin_retShll = my_find_builtinShll(my_infoShll);
			if (my_builtin_retShll == -1)
				my_get_locationShll(my_infoShll);
		}
		else if (my_interactiveShll(my_infoShll))
			_putcharShll('\n');
		my_free_infoShll(my_infoShll, 0);
	}
	/* EL HAKIK Amina and EL Mehdi BELAAZRI*/
	my_write_historyShll(my_infoShll);
	my_free_infoShll(my_infoShll, 1);
	if (!my_interactiveShll(my_infoShll) && my_infoShll->my_statusShll)
	{
		if (my_infoShll->my_err_numShll == -1)
			exit(my_infoShll->my_statusShll);
		exit(my_infoShll->my_err_numShll);
	}
}
