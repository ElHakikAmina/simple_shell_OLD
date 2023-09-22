#include "main.h"

/**
 * _erratoiShll - Converts a given string into an integer.
 *
 * @my_sShll: The input string to convert.
 *
 * Return: Returns the converted number if numbers are found in the string; 
 *         otherwise, it returns -1 in case of an error or 0 if no numbers are present.
*/

int _erratoiShll(char *my_sShll)
{

	int my_iShll = 0;
	unsigned long int my_resultShll = 0;

	if (*my_sShll == '+')
		my_sShll++;
	for (my_iShll = 0; my_sShll[my_iShll] != '\0'; my_iShll++)
	{
		if (my_sShll[my_iShll] >= '0' && my_sShll[my_iShll] <= '9')
		{
			my_resultShll *= 10;
			my_resultShll += (my_sShll[my_iShll] - '0');
			if (my_resultShll > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (my_resultShll);
}

/**
 * my_remove_commentsShll - Replaces the first instance of '#' with a null 
 *                          terminator '\0' in the provided string.
 *
 * @my_bufShll: The address of the string to be modified.
 *
 * Return: Always returns 0.
*/

void my_remove_commentsShll(char *my_bufShll)
{
	int my_iShll;

	for (my_iShll = 0; my_bufShll[my_iShll] != '\0'; my_iShll++)
		if (my_bufShll[my_iShll] == '#' && (!my_iShll || my_bufShll[my_iShll - 1] == ' '))
		{
			my_bufShll[my_iShll] = '\0';
			break;
		}
}
