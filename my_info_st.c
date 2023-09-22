#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_free_infoShll - Releases the resources
 * associated with the my_info_tShll struct.
 *
 * @my_infoShll: A struct @
 * @my_allShll: A boolean flag to determine if all fields should be freed.
 *
 * Return: Always returns 0.
*/

void my_free_infoShll(my_info_stShll *my_infoShll, int my_allShll)
{
	my_ffreeShll(my_infoShll->my_argvShll);
	my_infoShll->my_argvShll = NULL;
	my_infoShll->my_pathShll = NULL;

	if (my_allShll)
	{
		if (!my_infoShll->my_cmd_bufShll)
			free(my_infoShll->my_argShll);
		if (my_infoShll->my_envShll)
			my_free_listShll(&(my_infoShll->my_envShll));
		if (my_infoShll->my_historyShll)
			my_free_listShll(&(my_infoShll->my_historyShll));
		if (my_infoShll->my_aliasShll)
			my_free_listShll(&(my_infoShll->my_aliasShll));
		my_ffreeShll(my_infoShll->environ);
			my_infoShll->environ = NULL;
		my_bfreeShll((void **)my_infoShll->my_cmd_bufShll);
		if (my_infoShll->my_readfdShll > 2)
			close(my_infoShll->my_readfdShll);
		_putcharShll(MY_BUF_FLUSHSHLL);
	}
}
