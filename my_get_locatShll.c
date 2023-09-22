#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_get_locationShll - This function searches
 * for a command within the system's PATH.
 *
 * @my_infoShll: A structure containing relevant information.
 *
 * Return: Always returns 0.
*/

void my_get_locationShll(my_info_stShll *my_infoShll)
{
	char *my_pathShll = NULL;
	int my_iShll, my_kShll;

	my_infoShll->my_pathShll = my_infoShll->my_argvShll[0];
	if (my_infoShll->my_linecount_flagShll == 1)
	{
		my_infoShll->my_line_countShll++;
		my_infoShll->my_linecount_flagShll = 0;
	}

	for (my_iShll = 0, my_kShll = 0;
			 my_infoShll->my_argShll[my_iShll]; my_iShll++)
		if (!my_is_delimShll(my_infoShll->my_argShll[my_iShll], "\t\n"))
			my_kShll++;
	if (!my_kShll)
		return;

	my_pathShll = my_get_pathShll(my_infoShll, _getenvShll
			(my_infoShll, "PATH"), my_infoShll->my_argvShll[0]);
	if (my_pathShll)
	{
		my_infoShll->my_pathShll = my_pathShll;
		my_fork_cmdShll(my_infoShll);
	}
	else
	{
		if ((my_interactiveShll(my_infoShll) || _getenvShll(my_infoShll, "PATH")
			|| my_infoShll->my_argvShll[0][0] == '/') && my_is_cmdShll
				(my_infoShll, my_infoShll->my_argvShll[0]))
			my_fork_cmdShll(my_infoShll);
		else if (*(my_infoShll->my_argShll) != '\n')
		{
			my_infoShll->my_statusShll = 127;
			my_print_errorShll(my_infoShll, "not found\n");
		}
	}
}
