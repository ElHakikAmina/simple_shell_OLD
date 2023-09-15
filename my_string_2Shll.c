#include "main.h"
/**
 * _strncpy - this function copies string
 * @my_dest: it is a destination
 * @my_srcShll: it is a source string
 * @my_n: it is a  the amoount of char to be copied
 * Return: it returns the concatenated string
 */
char *_strncpyShll(char *my_destShll, char *my_srcShll, int my_nShll)
{
	int my_iShll, my_jShll;
	char *my_sShll = my_destShll;

	my_iShll = 0;
	while (my_srcShll[my_iShll] != '\0' && my_iShll < my_nShll - 1)
	{
		my_destShll[iShll] = my_srcShll[my_i];
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

/**
 * _strncat - concatenates 2 strings
 * @my_destShll: it is a  destination
 * @my_srcShll: it is a source
 * @my_nShll: it is a the amount of bytes to be used
 * Return: it returns the concatenated string
 */
char *_strncatShll(char *my_destShll, char *my_srcShll, int my_nShll)
{
	int my_iShll, my_jShll;
	char *my_sShll = my_destShll;

	my_iShll = 0;
	my_jShll = 0;
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
 * _strchr - locates a char in a string
 * @sShll: string
 * @cShll: character to be located
 * Return: a pointer to memory area
 */
char *_strchrShll(char *my_sShll, char my_cShll)
{
	do {
		if (*my_sShll == my_cShll)
			return (my_sShll);
	} while (*my_sShll++ != '\0');

	return (NULL);
}

