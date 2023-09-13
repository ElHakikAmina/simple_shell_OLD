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
		info->cmd_buf_type = CMD_OR;
	}
	else if (my_bufShll[my_jShll] == '&' && my_bufShll[my_jShll + 1] == '&')
	{
		my_bufShll[my_jShll] = 0;
		my_jShll++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (my_bufShll[my_jShll] == ';')
	{
		my_bufShll[my_jShll] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*my_pShll = my_jShll;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 * Return: Void
 */
void check_chain(info_st *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_st *info)
{
	int i;
	list_st *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 * Return: 1 if replaced, 0 otherwise
 */

int replace_vars(info_st *info)
{
	int i = 0;
	list_st *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}
