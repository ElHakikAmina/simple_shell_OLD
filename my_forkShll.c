#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_fork_cmdShll - Creates a new process to execute a command.
 *
 * @my_infoShll: A structure containing relevant information.
 *
 * Return: None.
*/

void my_fork_cmdShll(my_info_stShll *my_infoShll)
{
	pid_t my_child_pidShll;

	my_child_pidShll = fork();
	if (my_child_pidShll == -1)
	{
		perror("Error:");
		return;
	}
	if (my_child_pidShll == 0)
	{
		if (execve(my_infoShll->my_pathShll, my_infoShll->my_argvShll, my_get_environShll(my_infoShll)) == -1)
		{
			my_free_infoShll(my_infoShll, 1);
			if (errno == EACCES)
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
