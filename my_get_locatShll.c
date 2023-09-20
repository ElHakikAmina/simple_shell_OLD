#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_get_locationShll function that finds a command in path
 *
 * @my_infoShll: it is a struct
 *
 * Return: 0 (Always)
*/

void my_get_locationShll(my_info_stShll *my_infoShll)
{
	char *my_pathShll = NULL;
	int my_iShll, my_kShll;

	my_infoShll->my_pathShll = my_info->my_argv[0];
	if (my_infoShll->my_linecount_flagShll == 1)
	{
		my_infoShll->my_line_countShll++;
		my_infoShll->my_linecount_flagShll = 0;
	}
	
	for (my_iShll = 0, my_kShll = 0; my_infoShll->arg[i]; i++)
		if (!my_is_delimShll(my_infoShll->arg[i], "\t\n"))
			my_kShll++;
	if (!my_kShll)
		return;

	my_pathShll = my_get_pathShll(my_infoShll, _getenvShll(my_infoShll, "PATH"), my_infoShll->argv[0]);
	if (my_pathShll)
	{
		my_infoShll->my_pathShll = my_pathShll;
		my_fork_cmdShll(my_infoShll);
	}
	else
	{
		if ((my_interactiveShll(my_infoShll) || _getenv(my_infoShll, "PATH")
			|| my_infoShll->argv[0][0] == '/') && my_is_cmdShll(my_infoShll, my_infoShll->argv[0]))
			my_fork_cmdShll(my_infoShll);
		else if (*(my_infoShll->my_argShll) != '\n')
		{
			my_infoShll->my_statusShll = 127;
			my_print_errorShll(my_infoShll, "not found\n");
		}
	}
}

