#include "main.h"

/**
 * _putsShll - this function  prints a string
 *
 * @my_strShll:it is a  string
 *
 * Return: it Always returns  0
*/

void _putsShll(char *my_strShll)
{
	int my_iShll = 0;

	if (!my_strShll)
		return;
	while (my_strShll[my_iShll] != '\0')
	{
		_putcharShll(my_strShll[my_iShll]);
		my_iShll++;
	}
}

/**
 * _putcharShll - ths function write a char c to standard output
 *
 * @my_cShll: character
 *
 * Return:it returns  1 on success, -1 on error and errno is set
*/

int _putcharShll(char my_cShll)
{
	static int my_iShll;
	static char my_bufShll[MY_WRITE_BUF_SIZESHLL];

	if (my_cShll == MY_BUF_FLUSHSHLL || my_iShll >= MY_WRITE_BUF_SIZESHLL)
	{
		write(1, my_bufShll, my_iShll);
		my_iShll = 0;
	}
	if (my_cShll != MY_BUF_FLUSHSHLL)
		my_bufShll[my_iShll++] = my_cShll;
	return (1);
}

/**
 * _strcmpShll - compares between two strings
 *
 * @my_s1Shll: first string
 * @my_s2Shll: second string
 *
 * Return: neg if s1 < s2, pos if s1 > s2, zero if s1 == s2
*/

int _strcmpShll(char *my_s1Shll, char *my_s2Shll)
{
	while (*my_s1Shll && *my_s2Shll)
	{
		if (*my_s1Shll != *my_s2Shll)
			return (*my_s1Shll - *my_s2Shll);
		my_s1Shll++;
		my_s2Shll++;
	}
	if (*my_s1Shll == *my_s2Shll)
		return (0);
	else
		return (*my_s1Shll < *my_s2Shll ? -1 : 1);
}
