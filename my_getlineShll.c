#include "main.h"
/**
 * my_input_buf - function that buffer chained commands
 * @my_infoShll: it is a struct
 * @my_bufShll: it is a address to buffer
 * @my_lenShll: it is a  address to length of var
 * Return: it returns a bytes read
 */
my_ssize_tShll my_input_bufShll(my_info_stShll *my_infoShll, char **my_bufShll, my_size_tShll *my_lenShll)
{
	my_ssize_tShll my_rShll = 0;
	my_size_tShll my_len_pShll = 0;

	if (!*my_lenShll)
	{
		free(*my_bufShll);
		*my_bufShll = NULL;
		signal(MY_SIGINTSHLL, my_sigintHandlerShll);
#if USE_GETLINE
		my_rShll = my_getlineShll(my_bufShll, &my_len_pShll, my_stdinShll);
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
			my_build_history_listShll(my_infoShll, *my_bufShll, my_infoShll->my_histcountShll++);
			{
				*my_lenShll = my_rShll;
				my_infoShll->my_cmd_bufShll = my_bufShll;
			}
		}
	}
	return (my_rShll);
}

/**
 * my_get_inputShll - function that gets a line minus the newline
 * @my_infoShll: it is a  struct
 * Return: it retruns bytes read
 */
my_ssize_tShll my_get_inputShll(my_info_stShll *my_infoShll)
{
	static char *my_bufShll;
	static my_size_tShll my_iShll, my_jShll, my_lenShll;
	ssize_t my_rShll = 0;
	char **my_buf_pShll = &(infoShll->arg), *my_pShll;

	_putcharShll(BUF_FLUSHSHLL);
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
			my_infoShll->my_cmd_buf_typeShll = MY_CMD_NORMShll;
		}

		*my_buf_pShll = my_pShll;
		return (_strlenShll(my_pShll));
	}
	*my_buf_pShll = my_bufShll;
	return (my_rShll);
}

/**
 * read_bufShll - function that reads a buffer
 * @my_infoShll: it is a struct
 * @my_bufShll: it is a buffer
 * @my_iShll: it is a size
 * Return: it retrurns r
 */
my_ssize_tShll my_read_bufShll(my_info_stShll *my_infoShll, char *my_bufShll, my_size_tShll *my_iShll)
{
	my_ssize_tShll my_rShll = 0;

	if (*my_iShll)
		return (0);
	my_rShll = read(my_infoShll->my_readfdShll, my_bufShll, MY_READ_BUF_SIZESHLL);
	if (my_rShll >= 0)
		*my_iShll = my_rShll;
	return (my_rShll);
}

/**
 * _getlineShll - function that  gets the next line of input from stdin
 * @my_infoShll: it is a struct
 * @my_ptrShll: it is a address of pointer to buffer
 * @my_lengthShll: it is a  size of preallocated ptr buffer if not NULL
 * Return:function that  s
 */
int _getlineShll(my_info_stShll *my_infoShll, char **my_ptrShll, my_size_tShll *my_lengthShll)
{
	static char my_bufShll[MY_READ_BUF_SIZESHLL];
	static my_size_tShll my_iShll, my_lenShll;
	my_size_tShll my_kShll;
	my_ssize_tShll my_rShll = 0, my_sShll = 0;
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
	my_new_pShll = _realloc(my_pShll, my_sShll, my_sShll ? my_sShll + my_kShll : my_kShll + 1);
	if (!my_new_pShll)
		return (my_pShll ? free(my_pShll), -1 : -1);

	if (my_sShll)
		_strncat(my_new_pShll, my_bufShll + my_iShll, my_kShll - my_iShll);
	else
		_strncpy(my_new_pShll, my_bufShll + my_iShll, my_kShll - my_iShll + 1);

	my_sShll += my_kShll - my_iShll;
	my_iShll = my_kShll;
	my_pShll = my_new_pShll;

	if (my_lengthShll)
		*my_lengthShll = my_sShll;
	*my_ptrShll = my_pShll;
	return (my_sShll);
}

/**
 * my_sigintHandlerShll - function that  blocks ctrl-c
 * @my_sig_numShll: it is a the signal number
 * Return: it is a void no retrun
 */
void my_sigintHandlerShll(__attribute__((unused))int my_sig_numShll)
{
	_putsShll("\n");
	_putsShll("$ ");
	_putcharShll(MY_BUF_FLUSHSHLL);
}

