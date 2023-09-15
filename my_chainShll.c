#include "main.h"

/**
 * my_is_chainShll - test if current char in buffer is a chain delimeter
 *
 * @my_infoShll: the parameter struct
 * @my_bufShll: the char buffer
 * @my_pShll: address of current position in buffer
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */

int my_is_chainShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *my_pShll)
{
	size_t my_jShll = *my_pShll;

	if (my_bufShll[my_jShll] == '|' && my_bufShll[my_jShll + 1] == '|')
	{
		my_bufShll[my_jShll] = 0;
		my_jShll++;
		my_infoShll->my_cmd_buf_typeShll = CMD_OR;
	}
	else if (my_bufShll[my_jShll] == '&' && my_bufShll[my_jShll + 1] == '&')
	{
		my_bufShll[my_jShll] = 0;
		my_jShll++;
		my_infoShll->my_cmd_buf_typeShll = CMD_AND;
	}
	else if (my_bufShll[my_jShll] == ';')
	{
		my_bufShll[my_jShll] = 0;
		my_infoShll->my_cmd_buf_typeShll = CMD_CHAIN;
	}
	else
		return (0);
	*my_pShll = my_jShll;
	return (1);
}

/**
 * my_check_chainShll - checks we should continue chaining based on last status
 *
 * @my_infoShll: the parameter struct
 * @my_bufShll: the char buffer
 * @my_pShll: address of current position in buf
 * @my_iShll: starting position in buf
 * @my_lenShll: length of buf
 *
 * Return: Void
*/

void my_check_chainShll(my_info_stShll *my_infoShll, char *my_bufShll, size_t *my_pShll, size_t my_iShll, size_t my_lenShll)
{
	size_t my_jShll = *my_pShll;

	if (my_infoShll->my_cmd_buf_typeShll == CMD_AND)
	{
		if (my_infoShll->my_statusShll)
		{
			my_bufShll[my_iShll] = 0;
			my_jShll = my_lenShll;
		}
	}
	if (my_infoShll->my_cmd_buf_typeShll == CMD_OR)
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
 * my_replace_aliasShll - replaces an aliases in the tokenized string
 *
 * @my_infoShll: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
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
		p = _strchr(my_nodeShll->my_strShll, '=');
		if (!my_pShll)
			return (0);
		my_pShll = _strdup(my_pShll + 1);
		if (!my_pShll)
			return (0);
		my_infoShll->my_argvShll[0] = my_pShll;
	}
	return (1);
}
/**
 * my_replace_stringShll - replaces string
 *
 * @my_oldShll: address of old string
 * @my_newShll: new string
 *
 * Return: 1 if replaced, 0 otherwise
*/

int my_replace_stringShll(char **my_oldShll, char *my_newShll)
{
	free(*my_oldShll);
	*my_oldShll = my_newShll;
	return (1);
}

/**
 * my_replace_varsShll - replaces vars in the tokenized string
 *
 * @my_infoShll: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
*/

int my_replace_varsShll(my_info_stShll *my_infoShll)
{
	int my_iShll = 0;
	list_stShll *my_nodeShll;

	for (my_iShll = 0; my_infoShll->my_argvShll[my_iShll]; my_iShll++)
	{
		if (my_infoShll->my_argvShll[my_iShll][0] != '$' || !my_infoShll->my_argvShll[my_iShll][1])
			continue;

		if (!_strcmp(my_infoShll->my_argvShll[my_iShll], "$?"))
		{
			my_replace_stringShll(&(my_infoShll->my_argvShll[my_iShll]),
				_strdup(my_convert_numberShll(my_infoShll->my_statusShll, 10, 0)));
			continue;
		}
		if (!_strcmp(my_infoShll->my_argvShll[my_iShll], "$$"))
		{
			my_replace_stringShll(&(my_infoShll->my_argvShll[my_iShll]),
				_strdup(my_convert_numberShll(getpid(), 10, 0)));
			continue;
		}
		my_nodeShll = my_node_starts_withShll(my_infoShll->my_envShll, 
				&my_infoShll->my_argvShll[my_iShll][1], '=');
		if (my_nodeShll)
		{
			my_replace_stringShll(&(my_infoShll->my_argvShll[my_iShll]),
				_strdup(_strchr(my_nodeShll->my_strShll, '=') + 1));
			continue;
		}
		my_replace_stringShll(&my_infoShll->my_argvShll[my_iShll], _strdup(""));
	}
	return (0);
}
