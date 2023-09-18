#include "main.h"
/**
 * my_fork_cmdShll - function that forks an exec thread to run cmd
 * @my_infoShll:it is a  struct
 * Return: it is a void, no returns
 */
void my_fork_cmdShll(my_info_stShll *my_infoShll)
{
	my_pid_tShll my_child_pidShll;

	my_child_pidShll = fork();
	if (my_child_pidShll == -1)
	{
		my_perrorShll("Error:");
		return;
	}
	if (my_child_pidShll == 0)
	{
		if (my_execveShll(my_infoShll->my_pathShll, my_infoShll->argv, my_get_environShll(my_infoShll)) == -1)
		{
			my_free_infoShll(my_infoShll, 1);
			if (my_errnoShll == MY_EACCESSHLL)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(my_infoShll->my_statusShll));
		if (WIFEXITED(my_infoShll->my_statusShll))
		{
			my_infoShll->my_statusShll = WEXITSTATUS(my_infoShll->my_statusShll);
			if (my_infoShll->my_statusShll == 126)
				my_print_errorShll(my_infoShll, "Permission denied\n");
		}
	}
}

