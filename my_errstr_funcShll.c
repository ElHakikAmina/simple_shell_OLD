#include "main.h"
/**
 *_eputsShll - prints an input string
 * @my_strShll: the string to be printed
 *
 * Return: Nothing
 */
void _eputsShll(char *my_strShll)
{
	int my_iShll = 0;

	if (!my_strShll)
		return;
	while (my_strShll[my_iShll] != '\0')
	{
		_eputcharShll(my_strShll[my_iShll]);
		my_iShll++;
	}
}

/**
 * _eputcharShll - writes the character c to stderr
 * @my_cShll: The character to print
 * Return: On success 1
 *         on error, -1 is returned, and errno is set appropriately.
*/

int _eputcharShll(char my_cShll)
{
	static int my_iShll;
	static char my_bufShll[MY_WRITE_BUF_SIZESHLL];

	if (my_cShll == MY_BUF_FLUSHSHLL || my_iShll >= MY_WRITE_BUF_SIZESHLL)
	{
		write(2, my_bufShll, my_iShll);
		my_iShll = 0;
	}
	if (my_cShll != MY_BUF_FLUSHSHLL)
		my_bufShll[my_iShll++] = my_cShll;
	return (1);
}
/**
 *_putsfdShll - prints an input string
 * @my_strShll: the string to be printed
 * @my_fdShll: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfdShll(char *my_strShll, int my_fdShll)
{
	int my_iShll = 0;

	if (!my_strShll)
		return (0);
	while (*my_strShll)
	{
		my_iShll += _putfdShll(*my_strShll++, my_fdShll);
	}
	return (my_iShll);
}
/**
 * _putfdShll - writes the character c to given fd
 * @my_cShll: The character to print
 * @my_fdShll: The filedescriptor to write to
 *
 * Return: On success 1
 *         on error, -1 is returned, and errno is set appropriately.
 */

int _putfdShll(char my_cShll, int my_fdShll)
{
	static int my_iShll;
	static char my_bufShll[MY_WRITE_BUF_SIZESHLL];

	if (my_cShll == MY_BUF_FLUSHSHLL || my_iShll >= MY_WRITE_BUF_SIZESHLL)
	{
		write(my_fdShll, my_bufShll, my_iShll);
		my_iShll = 0;
	}
	if (my_cShll != MY_BUF_FLUSHSHLL)
		my_bufShll[my_iShll++] = my_cShll;
	return (1);
}
