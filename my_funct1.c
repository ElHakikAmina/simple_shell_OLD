#include "main.h"

/**
 * my_print_errorShll - Displays an error message.
 *
 * @my_infoShll: Pointer to parameter and return info structure.
 * @my_estrShll: String containing the specified error type.
 *
 * Return: Returns the converted number if no numbers in the string, -1 on error.
*/

void my_print_errorShll(my_info_stShll *my_infoShll, char *my_estrShll)
{
	_eputsShll(my_infoShll->my_fnameShll);
	_eputsShll(": ");
	my_print_dShll(my_infoShll->my_line_countShll, STDERR_FILENO);
	_eputsShll(": ");
	_eputsShll(my_infoShll->my_argvShll[0]);
	_eputsShll(": ");
	_eputsShll(my_estrShll);
}

/**
 * my_print_dShll - Prints a decimal number.
 *
 * @my_inputShll: The input number.
 * @my_fdShll: The file descriptor to write to.
 *
 * Return: Returns the number of characters printed.
*/

int my_print_dShll(int my_inputShll, int my_fdShll)
{
	int (*__putcharShll)(char) = _putcharShll;
	int my_iShll, my_countShll = 0;
	unsigned int _abs_Shll, my_currentShll;

	if (my_fdShll == STDERR_FILENO)
		__putcharShll = _eputcharShll;
	if (my_inputShll < 0)
	{
		_abs_Shll = -my_inputShll;
		__putcharShll('-');
		my_countShll++;
	}
	else
		_abs_Shll = my_inputShll;
	my_currentShll = _abs_Shll;
	for (my_iShll = 1000000000; my_iShll > 1; my_iShll /= 10)
	{
		if (_abs_Shll / my_iShll)
		{
			__putcharShll('0' + my_currentShll / my_iShll);
			my_countShll++;
		}
		my_currentShll %= my_iShll;
	}
	__putcharShll('0' + my_currentShll);
	my_countShll++;

	return (my_countShll);
}

/**
 * my_interactiveShll - Determines if the shell is in interactive mode.
 *
 * @my_infoShll: Pointer to the struct address.
 *
 * Return: Returns 1 if the shell is in interactive mode, 0 otherwise.
*/

int my_interactiveShll(my_info_stShll *my_infoShll)
{
	return (isatty(STDIN_FILENO) && my_infoShll->my_readfdShll <= 2);
}

/**
 * my_is_delimShll - Checks if a character is a delimiter.
 *
 * @my_cShll: The character to check.
 * @my_delimShll: The delimiter string.
 *
 * Return: Returns 1 if the character is a delimiter, 0 otherwise.
*/

int my_is_delimShll(char my_cShll, char *my_delimShll)
{
	while (*my_delimShll)
		if (*my_delimShll++ == my_cShll)
		return (1);
	return (0);
}

/**
 * my_convert_numberShll - Conversion function, similar to itoa.
 *
 * @my_numShll: The number to convert.
 * @my_baseShll: The base for conversion.
 * @my_flagsShll: Argument flags.
 *
 * Return: Returns the converted string.
*/

char *my_convert_numberShll(long int my_numShll, int my_baseShll, int my_flagsShll)
{
	static char *my_arrayShll;
	static char my_bufferShll[50];
	char my_signShll = 0;
	char *my_ptrShll;
	unsigned long my_nShll = my_numShll;

	if (!(my_flagsShll & MY_CONVERT_UNSIGNEDSHLL) && my_numShll < 0)
	{
		my_nShll = -my_numShll;
		my_signShll = '-';

	}
	my_arrayShll = my_flagsShll & MY_CONVERT_LOWERCASESHLL ? "0123456789abcdef" : "0123456789ABCDEF";
	my_ptrShll = &my_bufferShll[49];
	*my_ptrShll = '\0';

	do	{
		*--my_ptrShll = my_arrayShll[my_nShll % my_baseShll];
		my_nShll /= my_baseShll;
	} while (my_nShll != 0);

	if (my_signShll)
		*--my_ptrShll = my_signShll;
	return (my_ptrShll);
}
