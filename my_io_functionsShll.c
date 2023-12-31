#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

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
 * @inf: Parameter struct.
 *
 * Return: Returns the histcount on success, or 0 on failure.
*/

int my_read_historyShll(my_info_stShll *inf)
{
	int ii, last = 0, my_line = 0;
	ssize_t fdd, rdl, fs = 0;
	struct stat my_stShll;
	char *bufS = NULL, *filen =
		 my_get_history_fileShll(inf);

	if (!filen)
		return (0);

	fdd = open(filen, O_RDONLY);
	free(filen);
	if (fdd == -1)
		return (0);
	if (!fstat(fdd, &my_stShll))
		fs = my_stShll.st_size;
	if (fs < 2)
		return (0);
	bufS = malloc(sizeof(char) * (fs + 1));
	if (!bufS)
		return (0);
	rdl = read(fdd, bufS, fs);
	bufS[fs] = 0;
	if (rdl <= 0)
		return (free(bufS), 0);
	close(fdd);
	for (ii = 0; ii < fs; ii++)
		if (bufS[ii] == '\n')
		{
			bufS[ii] = 0;
			my_build_history_listShll(inf, bufS + last, my_line++);
			last = ii + 1;
		}
	if (last != ii)
		my_build_history_listShll(inf, bufS + last, my_line++);
	free(bufS);
	inf->my_histcountShll = my_line;
	while (inf->my_histcountShll-- >= MY_HIST_MAXSHLL)
		my_delete_node_at_indexShll(&(inf->my_historyShll), 0);
	my_renumber_historyShll(inf);
	return (inf->my_histcountShll);
}
