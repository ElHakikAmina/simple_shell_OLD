#include "main.h"
/**
 * my_free_infoShll - function that  free info_t struct fields
 * @my_infoShll: it is a struct address
 * @my_allShll: it is true if freeing all fields
 * Return: Always returns  0
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
		my_ffreeShll(my_infoShll->my_environShll);
			my_infoShll->my_environShll = NULL;
		my_bfreeShll((void **)my_infoShll->my_cmd_bufShll);
		if (my_infoShll->my_readfdShll > 2)
			close(my_infoShll->my_readfdShll);
		_putcharShll(MY_BUF_FLUSHSHLL);
	}
}

