#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_is_cmdShll - function that determines if a file is executable command
 * 
 * @my_infoShll: it is the info struct
 * @my_pathShll: it is path to the file
 *
 * Return: 1 if true, 0 if false
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
 * my_dup_charsShll - function that duplicates characters
 *
 * @my_pathstrShll: it is the PATH string
 * @my_startShll: it is starting index
 * @my_stopShll: it is stopping index
 *
 * Return: a pointer to new buffer
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
 * my_get_pathShll - function finds this ccommand in the PATH string
 *
 * @my_infoShll: it is the info struct
 * @my_pathstrShll: it is the PATH string
 * @my_cmdShll: it is command to find
 *
 * Return: the full path of cmd if success or NULL
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
