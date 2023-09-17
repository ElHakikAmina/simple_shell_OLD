#include "main.h"
/**
 * my_get_history_fileShll - function that gets the history file
 * @my_infoShll: it returns  parameter struct
 *
 * Return: it returns  allocated string containg history file
 */

char *my_get_history_fileShll(my_info_stShll *my_infoShll)
{
	char *my_bufShll, *my_dirShll;

	my_dirShll = _getenvShll(my_infoShll, "HOME=");
	if (!my_dirShll)
		return (NULL);
	my_bufShll = malloc(sizeof(char) * (_strlenShll(my_dirShll) + _strlenShll(MY_HIST_FILESHLL) + 2));
	if (!my_bufShll)
		return (NULL);
	my_bufShll[0] = 0;
	_strcpyShll(my_bufShll, my_dirShll);
	_strcatShll(my_bufShll, "/");
	_strcatShll(my_bufShll, MY_HIST_FILESHLL);
	return (my_bufShll);
}

/**
 * my_read_historyShll - function that reads history from file
 * @my_infoShll: it is a the parameter struct
 *
 * Return: it returns histcount on success, 0 otherwise
 */

int my_read_historyShll(my_info_stShll *my_infoShll)
{
	int my_iShll, my_lastShll = 0, my_linecountShll = 0;
	ssize_t my_fdShll, my_rdlen, my_fsizeShll = 0;
	struct my_statShll my_stShll;
	char *my_bufShll = NULL, *my_filenameShll = my_get_history_fileShll(my_infoShll);

	if (!my_filenameShll)
		return (0);

	my_fdShll = open(my_filenameShll, MY_O_RDONLYSHLL);
	free(my_filenameShll);
	if (my_fdShll == -1)
		return (0);
	if (!my_fstatShll(my_fdShll, &my_stShll))
		my_fsizeShll = my_stShll.my_st_sizeShll;
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
			my_build_history_listShll(my_infoShll, my_bufShll + my_lastShll, my_linecountShll++);
			my_lastShll = my_iShll + 1;
		}
	if (my_lastShll != my_iShll)
		my_build_history_listShll(my_infoShll, my_bufShll + my_lastShll, my_linecountShll++);
	free(my_bufShll);
	my_infoShll->my_histcountShll = my_linecountShll;
	while (my_infoShll->my_histcountShll-- >= MY_HIST_MAXSHLL)
		my_delete_node_at_indexShll(&(my_infoShll->my_historyShll), 0);
	my_renumber_historyShll(my_infoShll);
	return (my_infoShll->my_histcountShll);
}
/**
 * my_write_historyShll - function that creates a file, or appends to an existing file
 * @my_infoShll: it is a the parameter struct
 *
 * Return: it returns  1 on success, else -1
 */

int my_write_historyShll(my_info_stShll *my_infoShll)
{
	my_ssize_tShll my_fdShll;
	char *my_filenameShll = my_get_history_fileShll(my_infoShll);
	my_list_stShll *my_nodeShll = NULL;

	if (!my_filenameShll)
		return (-1);

	my_fdShll = open(my_filenameShll, MY_O_CREATSHLL | MY_O_TRUNCSHLL | MY_O_RDWRSHLL, 0644);
	free(my_filenameShll);
	if (my_fdShll == -1)
		return (-1);
	for (my_nodeShll = my_infoShll->my_historyShll; my_nodeShll; my_nodeShll = my_nodeShll->my_nextShll)
	{
		_putsfdShll(my_nodeShll->my_strShll, my_fdShll);
		_putfdShll('\n', fdShll);
	}
	_putfdShll(MY_BUF_FLUSHSHLL, my_fdShll);
	close(fdShll);
	return (1);
}

/**
 * my_build_history_listShll - function that adds entry to a history linked list
 * @my_infoShll: it is a Structure containing potential arguments. Used to maintain
 * @my_bufShll: it is a buffer
 * @my_linecountShll: it si a the history linecount, histcount
 * Return: it returns Always 0
 */
int my_build_history_listShll(my_info_stShll *my_infoShll, char *my_bufShll, int my_linecountShll)
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
 * my_renumber_historyShll  : :-function that  renumbers the history linked list after changes
 * @my_infoShll: it is a Structure containing potential arguments. Used to maintain
 * Return: it returns the new histcount
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
