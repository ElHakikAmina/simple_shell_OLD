#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_check_chainShll - Check if chaining should
 * continue based on the last status.
 *
 * @my_infoShll: Parameter structure.
 * @my_bufShll: Character buffer.
 * @my_pShll: Current position in buf.
 * @my_iShll: Starting position in buf.
 * @my_lenShll: Buffer length.
 *
 * Return: Void
*/

void my_check_chainShll(my_info_stShll *my_infoShll, char *my_bufShll,
		 size_t *my_pShll, size_t my_iShll, size_t my_lenShll)
{
	size_t my_jShll = *my_pShll;

	if (my_infoShll->my_cmd_buf_typeShll == MY_CMD_ANDSHLL)
	{
		if (my_infoShll->my_statusShll)
		{
			my_bufShll[my_iShll] = 0;
			my_jShll = my_lenShll;
		}
	}
	if (my_infoShll->my_cmd_buf_typeShll == MY_CMD_ORSHLL)
	{
		if (!my_infoShll->my_statusShll)
		{
			my_bufShll[my_iShll] = 0;
			my_jShll = my_lenShll;
		}
	}

	*my_pShll = my_jShll;
}

/**
 * my_replace_aliasShll - Replace aliases in the tokenized string.
 *
 * @my_infoShll: Parameter structure.
 *
 * Return: 1 if replaced, 0 otherwise.
*/

int my_replace_aliasShll(my_info_stShll *my_infoShll)
{
	int my_iShll;
	my_list_stShll *my_nodeShll;
	char *my_pShll;

	for (my_iShll = 0; my_iShll < 10; my_iShll++)
	{
		my_nodeShll = my_node_starts_withShll(my_infoShll->my_aliasShll,
			 my_infoShll->my_argvShll[0], '=');
		if (!my_nodeShll)
			return (0);
		free(my_infoShll->my_argvShll[0]);
		my_pShll = _strchrShll(my_nodeShll->my_strShll, '=');
		if (!my_pShll)
			return (0);
		my_pShll = _strdupShll(my_pShll + 1);
		if (!my_pShll)
			return (0);
		my_infoShll->my_argvShll[0] = my_pShll;
	}
	return (1);
}

/**
 * my_replace_stringShll - Replace a string.
 *
 * @my_oldShll: Old string address.
 * @my_newShll: New string.
 *
 * Return: 1 if replaced, 0 otherwise.
*/

int my_replace_stringShll(char **my_oldShll, char *my_newShll)
{
	free(*my_oldShll);
	*my_oldShll = my_newShll;
	return (1);
}

/**
 * my_replace_varsShll - Replaces variables in the tokenized string.
 *
 * @my_infoShll: The parameter structure.
 *
 * Return: 1 if replaced, 0 otherwise.
*/

int my_replace_varsShll(my_info_stShll *my_infoShll)
{
	int my_iShll = 0;
	my_list_stShll *my_nodeShll;

	for (my_iShll = 0; my_infoShll->my_argvShll[my_iShll]; my_iShll++)
	{
		if (my_infoShll->my_argvShll[my_iShll][0] != '$' ||
				 !my_infoShll->my_argvShll[my_iShll][1])
			continue;

		if (!_strcmpShll(my_infoShll->my_argvShll[my_iShll], "$?"))
		{
			my_replace_stringShll(&(my_infoShll->my_argvShll[my_iShll]),
				_strdupShll(my_convert_numberShll(my_infoShll->my_statusShll, 10, 0)));
			continue;
		}
		if (!_strcmpShll(my_infoShll->my_argvShll[my_iShll], "$$"))
		{
			my_replace_stringShll(&(my_infoShll->my_argvShll[my_iShll]),
					 _strdupShll(my_convert_numberShll(getpid(), 10, 0)));
			continue;
		}
		my_nodeShll = my_node_starts_withShll(my_infoShll->my_envShll,
				 &my_infoShll->my_argvShll[my_iShll][1], '=');
		if (my_nodeShll)
		{
			my_replace_stringShll(&(my_infoShll->my_argvShll[my_iShll]),
				_strdupShll(_strchrShll(my_nodeShll->my_strShll, '=') + 1));
			continue;
		}
		my_replace_stringShll(&my_infoShll->my_argvShll[my_iShll], _strdupShll(""));
	}
	return (0);
}

/**
 * my_is_chainShll - Tests if the current character in
 * the buffer is a chain delimiter.
 *
 * @my_infoShll: The parameter structure.
 * @my_bufShll: The character buffer.
 * @my_pShll: The address of the current position in the buffer.
 *
 * Return: 1 if it's a chain delimiter, 0 otherwise.
*/

int my_is_chainShll(my_info_stShll *my_infoShll,
		 char *my_bufShll, size_t *my_pShll)
{
	size_t my_jShll = *my_pShll;

	if (my_bufShll[my_jShll] == '|' && my_bufShll[my_jShll + 1] == '|')
	{
		my_bufShll[my_jShll] = 0;
		my_jShll++;
		my_infoShll->my_cmd_buf_typeShll = MY_CMD_ORSHLL;
	}
	else if (my_bufShll[my_jShll] == '&' && my_bufShll[my_jShll + 1] == '&')
	{
		my_bufShll[my_jShll] = 0;
		my_jShll++;
		my_infoShll->my_cmd_buf_typeShll = MY_CMD_ANDSHLL;
	}
	else if (my_bufShll[my_jShll] == ';')
	{
		my_bufShll[my_jShll] = 0;
		my_infoShll->my_cmd_buf_typeShll = MY_CMD_CHAINSHLL;
	}
	else
		return (0);
	*my_pShll = my_jShll;
	return (1);
}
