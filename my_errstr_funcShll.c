#include "main.h"

/**
 * _eputsShll - Outputs an input string.
 * @my_strShll: The string to be displayed.
 *
 * Return: None.
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
 * _eputcharShll - Writes the character 'my_cShll'
 * to the standard error stream.
 *
 * @my_cShll: The character to be printed.
 *
 * Return: On success, 1.
 *         On error, -1 is returned, and errno is set accordingly.
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
 * _putsfdShll - Writes an input string to a specified file descriptor.
 *
 * @my_strShll: The string to be written.
 * @my_fdShll: The file descriptor for output.
 *
 * Return: The number of characters written.
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
 * _putfdShll - Writes the character 'my_cShll'
 * to the provided file descriptor.
 *
 * @my_cShll: The character to be printed.
 * @my_fdShll: The file descriptor for output.
 *
 * Return: On success, 1.
 *         On error, -1 is returned, and errno is set appropriately.
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
