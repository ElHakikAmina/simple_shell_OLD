#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_build_history_listShll - Function for adding
 * an entry to a history linked list.
 *
 * @my_infoShll: A structure containing potential arguments, used to maintain
 * @my_bufShll: A buffer.
 * @my_linecountShll: The history line count, histcount.
 *
 * Return: Always returns 0.
*/

int my_build_history_listShll(my_info_stShll *my_infoShll,
		 char *my_bufShll, int my_linecountShll)
{
	my_list_stShll *my_nodeShll = NULL;

	if (my_infoShll->my_historyShll)
		my_nodeShll = my_infoShll->my_historyShll;
	my_add_node_endShll(&my_nodeShll, my_bufShll, my_linecountShll);

	if (!my_infoShll->my_historyShll)
		my_infoShll->my_historyShll = my_nodeShll;
	return (0);
}

/**
 * my_renumber_historyShll - Function designed to renumber
 * the history linked list after making changes.
 *
 * @my_infoShll: Structure containing potential arguments,
 * used for maintenance.
 *
 * Return: Returns the updated histcount.
*/

int my_renumber_historyShll(my_info_stShll *my_infoShll)
{
	my_list_stShll *my_nodeShll = my_infoShll->my_historyShll;
	int my_iShll = 0;

	while (my_nodeShll)
	{
		my_nodeShll->my_numShll = my_iShll++;
		my_nodeShll = my_nodeShll->my_nextShll;
	}
	return (my_infoShll->my_histcountShll = my_iShll);
}

/**
 * my_get_history_fileShll - Function responsible
 * for obtaining the history file.
 *
 * @my_infoShll: Parameter struct.
 *
 * Return: Returns an allocated string containing the history file.
*/

char *my_get_history_fileShll(my_info_stShll *my_infoShll)
{
	char *my_bufShll, *my_dirShll;

	my_dirShll = _getenvShll(my_infoShll, "HOME=");
	if (!my_dirShll)
		return (NULL);
	my_bufShll = malloc(sizeof(char) * (_strlenShll(my_dirShll) +
				 _strlenShll(MY_HIST_FILESHLL) + 2));
	if (!my_bufShll)
		return (NULL);
	my_bufShll[0] = 0;
	_strcpyShll(my_bufShll, my_dirShll);
	_strcatShll(my_bufShll, "/");
	_strcatShll(my_bufShll, MY_HIST_FILESHLL);
	return (my_bufShll);
}

/**
 * my_write_historyShll - Function that creates
 * a new file or appends to an existing file.
 *
 * @my_infoShll: Parameter struct.
 *
 * Return: Returns 1 on success, or -1 on failure.
*/

int my_write_historyShll(my_info_stShll *my_infoShll)
{
	ssize_t my_fdShll;
	char *my_filenameShll = my_get_history_fileShll(my_infoShll);
	my_list_stShll *my_nodeShll = NULL;

	if (!my_filenameShll)
		return (-1);

	my_fdShll = open(my_filenameShll, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(my_filenameShll);
	if (my_fdShll == -1)
		return (-1);
	for (my_nodeShll = my_infoShll->my_historyShll;
			 my_nodeShll; my_nodeShll = my_nodeShll->my_nextShll)
	{
		_putsfdShll(my_nodeShll->my_strShll, my_fdShll);
		_putfdShll('\n', my_fdShll);
	}
	_putfdShll(MY_BUF_FLUSHSHLL, my_fdShll);
	close(my_fdShll);
	return (1);
}

/**
 * my_read_historyShll - Function that reads history data from a file.
 *
 * @my_infoShll: Parameter struct.
 *
 * Return: Returns the histcount on success, or 0 on failure.
*/

int my_read_historyShll(my_info_stShll *my_infoShll)
{
	int my_iShll, my_lastShll = 0, my_linecountShll = 0;
	ssize_t my_fdShll, my_rdlenShll, my_fsizeShll = 0;
	struct stat my_stShll;
	char *my_bufShll = NULL, *my_filenameShll =
		 my_get_history_fileShll(my_infoShll);

	if (!my_filenameShll)
		return (0);

	my_fdShll = open(my_filenameShll, O_RDONLY);
	free(my_filenameShll);
	if (my_fdShll == -1)
		return (0);
	if (!fstat(my_fdShll, &my_stShll))
		my_fsizeShll = my_stShll.st_size;
	if (my_fsizeShll < 2)
		return (0);
	my_bufShll = malloc(sizeof(char) * (my_fsizeShll + 1));
	if (!my_bufShll)
		return (0);
	my_rdlenShll = read(my_fdShll, my_bufShll, my_fsizeShll);
	my_bufShll[my_fsizeShll] = 0;
	if (my_rdlenShll <= 0)
		return (free(my_bufShll), 0);
	close(my_fdShll);
	for (my_iShll = 0; my_iShll < my_fsizeShll; my_iShll++)
		if (my_bufShll[my_iShll] == '\n')
		{
			my_bufShll[my_iShll] = 0;
			my_build_history_listShll(my_infoShll,
					 my_bufShll + my_lastShll, my_linecountShll++);
			my_lastShll = my_iShll + 1;
		}
	if (my_lastShll != my_iShll)
		my_build_history_listShll(my_infoShll,
				 my_bufShll + my_lastShll, my_linecountShll++);
	free(my_bufShll);
	my_infoShll->my_histcountShll = my_linecountShll;
	while (my_infoShll->my_histcountShll-- >= MY_HIST_MAXSHLL)
		my_delete_node_at_indexShll(&(my_infoShll->my_historyShll), 0);
	my_renumber_historyShll(my_infoShll);
	return (my_infoShll->my_histcountShll);
}
