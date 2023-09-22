#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * _strcmpShll - Compares two strings.
 *
 * @my_s1Shll: First string.
 * @my_s2Shll: Second string.
 *
 * Return: Negative if s1 < s2, positive if s1 > s2, zero otherwise.
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

/**
 * _putcharShll - Writes a character 'c' to standard output.
 *
 * @my_cShll: Character to write.
 *
 * Return: 1 on success, -1 on error with errno set accordingly.
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
 * _putsShll - Outputs a string.
 *
 * @my_strShll: The string to display.
 *
 * Return: Always returns 0.
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
