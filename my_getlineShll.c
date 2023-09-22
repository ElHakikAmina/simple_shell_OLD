#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_sigintHandlerShll - Function that blocks
 * the handling of the Ctrl-C signal.
 *
 * @my_sig_numShll: The signal number (SIGINT).
 *
 * Return: Nothing.
*/

void my_sigintHandlerShll(__attribute__((unused))int my_sig_numShll)
{
	_putsShll("\n");
	_putsShll("$ ");
	_putcharShll(MY_BUF_FLUSHSHLL);
}

/**
 * my_read_bufShll - Function that reads data into a buffer.
 *
 * @my_infoShll: A structure containing information.
 * @my_bufShll: The buffer to read data into.
 * @my_iShll: The size of data to read.
 *
 * Return: The number of bytes read.
*/

ssize_t my_read_bufShll(my_info_stShll *my_infoShll,
		 char *my_bufShll, size_t *my_iShll)
{
	ssize_t my_rShll = 0;

	if (*my_iShll)
		return (0);
	my_rShll = read(my_infoShll->my_readfdShll, my_bufShll, MY_READ_BUF_SIZESHLL);
	if (my_rShll >= 0)
		*my_iShll = my_rShll;
	return (my_rShll);
}

/**
 * my_input_bufShll - This function buffers chained commands.
 *
 * @my_infoShll: A structure holding necessary information.
 * @my_bufShll: The address of the buffer.
 * @my_lenShll: The address of the length variable.
 *
 * Return: The number of bytes read.
*/

ssize_t my_input_bufShll(my_info_stShll *my_infoShll,
		 char **my_bufShll, size_t *my_lenShll)
{
	ssize_t my_rShll = 0;
	size_t my_len_pShll = 0;

	if (!*my_lenShll)
	{
		free(*my_bufShll);
		*my_bufShll = NULL;
		signal(SIGINT, my_sigintHandlerShll);
#if MY_USE_GETLINESHLL
		my_rShll = getline(my_bufShll, &my_len_pShll, my_stdinShll);
#else
		my_rShll = _getlineShll(my_infoShll, my_bufShll, &my_len_pShll);
#endif
		if (my_rShll > 0)
		{
			if ((*my_bufShll)[my_rShll - 1] == '\n')
			{
				(*my_bufShll)[my_rShll - 1] = '\0';
				my_rShll--;
			}
			my_infoShll->my_linecount_flagShll = 1;
			my_remove_commentsShll(*my_bufShll);
			my_build_history_listShll(my_infoShll, *my_bufShll,
					 my_infoShll->my_histcountShll++);
			{
				*my_lenShll = my_rShll;
				my_infoShll->my_cmd_bufShll = my_bufShll;
			}
		}
	}
	return (my_rShll);
}

/**
 * my_get_inputShll - This function reads a line of input,
 * excluding the newline character.
 *
 * @my_infoShll: A structure containing relevant data.
 *
 * Return: The number of bytes read.
*/

ssize_t my_get_inputShll(my_info_stShll *my_infoShll)
{
	static char *my_bufShll;
	static size_t my_iShll, my_jShll, my_lenShll;
	ssize_t my_rShll = 0;
	char **my_buf_pShll = &(my_infoShll->my_argShll), *my_pShll;

	_putcharShll(MY_BUF_FLUSHSHLL);
	my_rShll = my_input_bufShll(my_infoShll, &my_bufShll, &my_lenShll);
	if (my_rShll == -1)
		return (-1);
	if (my_lenShll)
	{
		my_jShll = my_iShll;
		my_pShll = my_bufShll + my_iShll;

		my_check_chainShll(my_infoShll, my_bufShll, &my_jShll, my_iShll, my_lenShll);
		while (my_jShll < my_lenShll)
		{
			if (my_is_chainShll(my_infoShll, my_bufShll, &my_jShll))
				break;
			my_jShll++;
		}

		my_iShll = my_jShll + 1;
		if (my_iShll >= my_lenShll)
		{
			my_iShll = my_lenShll = 0;
			my_infoShll->my_cmd_buf_typeShll = MY_CMD_NORMSHLL;
		}

		*my_buf_pShll = my_pShll;
		return (_strlenShll(my_pShll));
	}
	*my_buf_pShll = my_bufShll;
	return (my_rShll);
}

/**
 * _getlineShll - This function retrieves the next line of input from stdin.
 *
 * @my_infoShll: A structure with essential information.
 * @my_ptrShll: The address of a pointer to the buffer.
 * @my_lengthShll: The size of the preallocated buffer (if not NULL).
 *
 * Return: The result of the function.
*/

int _getlineShll(my_info_stShll *my_infoShll,
		 char **my_ptrShll, size_t *my_lengthShll)
{
	static char my_bufShll[MY_READ_BUF_SIZESHLL];
	static size_t my_iShll, my_lenShll;
	size_t my_kShll;
	ssize_t my_rShll = 0, my_sShll = 0;
	char *my_pShll = NULL, *my_new_pShll = NULL, *my_cShll;

	my_pShll = *my_ptrShll;
	if (my_pShll && my_lengthShll)
		my_sShll = *my_lengthShll;
	if (my_iShll == my_lenShll)
		my_iShll = my_lenShll = 0;

	my_rShll = my_read_bufShll(my_infoShll, my_bufShll, &my_lenShll);
	if (my_rShll == -1 || (my_rShll == 0 && my_lenShll == 0))
		return (-1);

	my_cShll = _strchrShll(my_bufShll + my_iShll, '\n');
	my_kShll = my_cShll ? 1 + (unsigned int)(my_cShll - my_bufShll) : my_lenShll;
	my_new_pShll = _reallocShll(my_pShll, my_sShll, my_sShll ?
			 my_sShll + my_kShll : my_kShll + 1);
	if (!my_new_pShll)
		return (my_pShll ? free(my_pShll), -1 : -1);

	if (my_sShll)
		_strncatShll(my_new_pShll, my_bufShll + my_iShll, my_kShll - my_iShll);
	else
		_strncpyShll(my_new_pShll, my_bufShll + my_iShll, my_kShll - my_iShll + 1);

	my_sShll += my_kShll - my_iShll;
	my_iShll = my_kShll;
	my_pShll = my_new_pShll;

	if (my_lengthShll)
		*my_lengthShll = my_sShll;
	*my_ptrShll = my_pShll;
	return (my_sShll);
}
