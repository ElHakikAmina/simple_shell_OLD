#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * _strchrShll - Finds a character in a string.
 *
 * @my_sShll: The input string.
 * @my_cShll: The character to locate.
 *
 * Return: A pointer to the memory area.
*/

char *_strchrShll(char *my_sShll, char my_cShll)
{
        do {
                if (*my_sShll == my_cShll)
                        return (my_sShll);
        } while (*my_sShll++ != '\0');

        return (NULL);
}

/**
 * _strncatShll - Combines two strings.
 *
 * @my_destShll: The destination.
 * @my_srcShll: The source.
 * @my_nShll: The number of bytes to utilize.
 *
 * Return: The resulting concatenated string.
*/

char *_strncatShll(char *my_destShll, char *my_srcShll, int my_nShll)
{
        int my_iShll = 0, my_jShll = 0;
        char *my_sShll = my_destShll;

        while (my_destShll[my_iShll] != '\0')
                my_iShll++;
        while (my_srcShll[my_jShll] != '\0' && my_jShll < my_nShll)
        {
                my_destShll[my_iShll] = my_srcShll[my_jShll];
                my_iShll++;
                my_jShll++;
        }
        if (my_jShll < my_nShll)
                my_destShll[my_iShll] = '\0';
        return (my_sShll);
}

/**
 * _strncpyShll - This function duplicates a string.
 *
 * @my_destShll: The target destination.
 * @my_srcShll: The source string.
 * @my_nShll: The count of characters to be copied.
 *
 * Return: The duplicated string.
*/

char *_strncpyShll(char *my_destShll, char *my_srcShll, int my_nShll)
{
	int my_iShll = 0, my_jShll;
	char *my_sShll = my_destShll;

	while (my_srcShll[my_iShll] != '\0' && my_iShll < my_nShll - 1)
	{
		my_destShll[my_iShll] = my_srcShll[my_iShll];
		my_iShll++;
	}
	if (my_iShll < my_nShll)
	{
		my_jShll = my_iShll;
		while (my_jShll < my_nShll)
		{
			my_destShll[my_jShll] = '\0';
			my_jShll++;
		}
	}
	return (my_sShll);
}
