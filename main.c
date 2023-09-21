#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * main - Entry point
 *
 * @my_argcShll: number of arguments
 * @my_argvShll: list of arguments
 *
 * Return: 0 (Success), 1 otherwise
*/

int main(int my_argcShll, char **my_argvShll)
{
	my_info_stShll my_infoShll[] = { MY_INFO_INITSHLL };

	int my_fdShll = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (my_fdShll)
			: "r" (my_fdShll));

	if (my_argcShll == 2)
	{
		my_fdShll = open(my_argvShll[1], O_RDONLY);
		if (my_fdShll == -1)
		{
			if (errno == EACCES)
				exit(126);

			if (errno == ENOENT)
			{
				_eputsShll(my_argvShll[0]);
				_eputsShll(": 0: can't open ");
				_eputsShll(my_argvShll[1]);
				_eputcharShll('\n');
				_eputcharShll(MY_BUF_FLUSHSHLL);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		/*This code is created by Mehdi and Amina*/
		my_infoShll->my_readfdShll = my_fdShll;
	}
	my_populate_env_listShll(my_infoShll);
	my_read_historyShll(my_infoShll);
	my_hshShll(my_infoShll, my_argvShll);
	return (EXIT_SUCCESS);
}
