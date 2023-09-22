#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_is_cmdShll - Determines whether a file is an executable command.
 * 
 * @my_infoShll: Information structure.
 * @my_pathShll: Path to the file.
 *
 * Return: 1 if it's an executable command, 0 otherwise.
*/

int my_is_cmdShll(my_info_stShll *my_infoShll, char *my_pathShll)
{
        struct stat my_stShll;

        (void)my_infoShll;
        if (!my_pathShll || stat(my_pathShll, &my_stShll))
                return (0);

        if (my_stShll.st_mode & S_IFREG)
                return (1);
        return (0);
}

/**
 * my_dup_charsShll - Duplicates characters from a string.
 *
 * @my_pathstrShll: The PATH string.
 * @my_startShll: Starting index.
 * @my_stopShll: Stopping index.
 *
 * Return: A pointer to a new character buffer.
*/

char *my_dup_charsShll(char *my_pathstrShll, int my_startShll, int my_stopShll)
{
	static char my_bufShll[1024];
	int my_iShll = 0, my_jShll = 0;

	for (my_jShll = 0, my_iShll = my_startShll; my_iShll < my_stopShll; my_iShll++)
		if (my_pathstrShll[my_iShll] != ':')
			my_bufShll[my_jShll++] = my_pathstrShll[my_iShll];
	my_bufShll[my_jShll] = 0;
	return (my_bufShll);
}

/**
 * my_get_pathShll - Finds the full path of a command in the PATH string.
 *
 * @my_infoShll: Information structure.
 * @my_pathstrShll: The PATH string.
 * @my_cmdShll: Command to locate.
 *
 * Return: The full path of the command if found, or NULL.
*/

char *my_get_pathShll(my_info_stShll *my_infoShll, char *my_pathstrShll, char *my_cmdShll)
{
	int my_iShll = 0, my_curr_posShll = 0;
	char *my_pathShll;

	if (!my_pathstrShll)
		return (NULL);
	if ((_strlenShll(my_cmdShll) > 2) && my_starts_withShll(my_cmdShll, "./"))
	{
		if (my_is_cmdShll(my_infoShll, my_cmdShll))
			return (my_cmdShll);
	}
	while (1)
	{
		if (!my_pathstrShll[my_iShll] || my_pathstrShll[my_iShll] == ':')
		{
			my_pathShll = my_dup_charsShll(my_pathstrShll, my_curr_posShll, my_iShll);
			if (!*my_pathShll)
				_strcatShll(my_pathShll, my_cmdShll);
			else
			{
				_strcatShll(my_pathShll, "/");
				_strcatShll(my_pathShll, my_cmdShll);
			}
				return (my_pathShll);
			if (!my_pathstrShll[my_iShll])
				break;
			my_curr_posShll = my_iShll;
		}
		my_iShll++;
	}
	return (NULL);
}
