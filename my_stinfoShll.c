#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_clear_infoShll - function that initializes info_t structure
 *
 * @my_infoShll: it is a struct address
 *
 * Return: Always returns 0
*/

void my_clear_infoShll(my_info_stShll *my_infoShll)
{
	my_infoShll->my_argShll = NULL;
	my_infoShll->my_argvShll = NULL;
	my_infoShll->my_pathShll = NULL;
	my_infoShll->my_argcShll = 0;
}

/**
 * my_set_infoShll - function that initializes info_t structure
 *
 * @my_avShll: it is argument vector
 * @my_infoShll: it is a struct address
 *
 * Return: Always return 0
*/

void my_set_infoShll(my_info_stShll *my_infoShll, char **my_avShll)
{
	int my_iShll = 0;

	my_infoShll->my_fnameShll = my_avShll[0];
	if (my_infoShll->my_argShll)
	{
		my_infoShll->my_argvShll = my_str_tokShll(my_infoShll->my_argShll, " \t");
		if (!my_infoShll->my_argvShll)
		{
			my_infoShll->my_argvShll = malloc(sizeof(char *) * 2);
			if (my_infoShll->my_argvShll)
			{
				my_infoShll->my_argvShll[0] = _strdupShll(my_infoShll->my_argShll);
				my_infoShll->my_argvShll[1] = NULL;
			}
		}
		for (my_iShll = 0; my_infoShll->my_argvShll && my_infoShll->my_argvShll[my_iShll]; my_iShll++)
			;
		my_infoShll->my_argcShll = 1;
		my_replace_aliasShll(my_infoShll);
		my_replace_varsShll(my_infoShll);
	}
}
