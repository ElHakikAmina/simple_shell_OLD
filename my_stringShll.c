#include "main.h"

/**
 * _strlenShll - gets the length of a givin string
 *
 * @my_sShll: string
 *
 * Return: string length
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

/**
 * _strcatShll - this function concatenates 2 strings
 *
 * @my_destShll: it is the destination buffer
 * @my_srcShll: it is the source buffer
 *
 * Return: pointer to dest buffer
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
 * _strcpyShll - this function  copies a string
 *
 * @my_destShll: it is a destination
 * @my_srcShll: it is a source
 *
 * Return: pointer to dest
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
 * _strdupShll - this function duplicates a string
 *
 * @my_strShll: it is a string
 *
 * Return: it returns pointer the the dup string
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
 * my_starts_withShll - this function checkes if needle starts with haystack
 *
 * @my_haystackShll: it is a string to search
 * @my_needleShll: it is the substring to find
 *
 * Return: address of the next char of haystack or null
*/

char *my_starts_withShll(const char *my_haystackShll, const char *my_needleShll)
{
	while (*my_needleShll)
		if (*my_needleShll++ != *my_haystackShll++)
			return (NULL);
	return ((char *)my_haystackShll);
}
