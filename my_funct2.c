#include "main.h"
/**
* _erratoiShll - converts a string to an integer
* @my_sShll: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
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
 * my_remove_commentsShll - function replaces first instance of '#' with '\0'
 * @my_bufShll: address of the string to modify
 *
 * Return: Always 0;
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
