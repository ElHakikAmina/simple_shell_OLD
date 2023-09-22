#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * _strcpyShll - Function for copying a string.
 *
 * @my_destShll: Destination buffer.
 * @my_srcShll: Source buffer.
 *
 * Return: Pointer to the destination buffer.
*/

char *_strcpyShll(char *my_destShll, char *my_srcShll)
{
        int my_iShll = 0;

        if (my_destShll == my_srcShll || my_srcShll == 0)
                return (my_destShll);
        while (my_srcShll[my_iShll])
        {
                my_destShll[my_iShll] = my_srcShll[my_iShll];
                my_iShll++;
        }
        my_destShll[my_iShll] = 0;
        return (my_destShll);
}

/**
 * _strdupShll - Function to create a duplicate of a string.
 *
 * @my_strShll: The input string.
 *
 * Return: A pointer to the duplicated string.
*/

char *_strdupShll(const char *my_strShll)
{
        int my_lenShll = 0;
        char *my_resShll;

        if (my_strShll == NULL)
                return (NULL);

        while (*my_strShll++)
                my_lenShll++;
        my_resShll = malloc(sizeof(char) * (my_lenShll + 1));
        if (!my_resShll)
                return (NULL);
        for (my_lenShll++; my_lenShll--;)
                my_resShll[my_lenShll] = *--my_strShll;
        return (my_resShll);
}

/**
 * _strcatShll - Function to concatenate two strings.
 *
 * @my_destShll: The destination buffer.
 * @my_srcShll: The source buffer.
 *
 * Return: A pointer to the destination buffer.
*/

char *_strcatShll(char *my_destShll, char *my_srcShll)
{
	char *my_resShll = my_destShll;

	while (*my_destShll)
		my_destShll++;
	while (*my_srcShll)
		*my_destShll++ = *my_srcShll++;
	*my_destShll = *my_srcShll;
	return (my_resShll);
}

/**
 * my_starts_withShll - This function checks if `needle` is found at the start of `haystack`.
 *
 * @my_haystackShll: The string to search.
 * @my_needleShll: The substring to find.
 *
 * Return: An address pointing to the character in `haystack` immediately after `needle` or NULL if not found.
*/

char *my_starts_withShll(const char *my_haystackShll, const char *my_needleShll)
{
	while (*my_needleShll)
		if (*my_needleShll++ != *my_haystackShll++)
			return (NULL);
	return ((char *)my_haystackShll);
}

/**
 * _strlenShll - This function calculates the length of a given string.
 *
 * @my_sShll: The input string.
 *
 * Return: The length of the string.
*/

int _strlenShll(char *my_sShll)
{
        int my_lShll = 0;

        if (!my_sShll)
                return (0);

        while (*my_sShll++)
                my_lShll++;
        return (my_lShll);
}
