#include "main.h"
/* This file is created by EL HAKIK Amina and Mehdi Belaazri */

/**
 * my_str_tok2Shll - This function divides a string into
 * words using a specified delimiter.
 *
 * @my_strShll: The input string to be split.
 * @my_dShll: The delimiter string.
 *
 * Return: A pointer to an array of strings, or NULL in case of failure.
*/

char **my_str_tok2Shll(char *my_strShll, char my_dShll)
{
	int my_iShll, my_jShll, my_kShll, my_mShll, my_numwordsShll = 0;
	char **my_sShll;

	if (my_strShll == NULL || my_strShll[0] == 0)
		return (NULL);
	for (my_iShll = 0; my_strShll[my_iShll] != '\0'; my_iShll++)
		if ((my_strShll[my_iShll] != my_dShll && my_strShll[my_iShll + 1]
					 == my_dShll) ||
			(my_strShll[my_iShll] != my_dShll && !my_strShll[my_iShll + 1])
			 || my_strShll[my_iShll + 1] == my_dShll)
			my_numwordsShll++;
	if (my_numwordsShll == 0)
		return (NULL);
	my_sShll = malloc((1 + my_numwordsShll) * sizeof(char *));
	if (!my_sShll)
		return (NULL);
	for (my_iShll = 0, my_jShll = 0; my_jShll < my_numwordsShll; my_jShll++)
	{
		while (my_strShll[my_iShll] == my_dShll && my_strShll[my_iShll] != my_dShll)
			my_iShll++;
		my_kShll = 0;
		while (my_strShll[my_iShll + my_kShll] != my_dShll &&
				 my_strShll[my_iShll + my_kShll] &&
				 my_strShll[my_iShll + my_kShll] != my_dShll)
			my_kShll++;
		my_sShll[my_jShll] = malloc((my_kShll + 1) * sizeof(char));
		if (!my_sShll[my_jShll])
		{
			for (my_kShll = 0; my_kShll < my_jShll; my_kShll++)
				free(my_sShll[my_kShll]);
			free(my_sShll);
			return (NULL);
		}
		for (my_mShll = 0; my_mShll < my_kShll; my_mShll++)
			my_sShll[my_jShll][my_mShll] = my_strShll[my_iShll++];
		my_sShll[my_jShll][my_mShll] = 0;
	}
	my_sShll[my_jShll] = NULL;
	return (my_sShll);
}

/**
 * my_str_tokShll - This function divides a string into words
 * while ignoring repeated delimiters.
 *
 * @my_strShll: The input string to be split.
 * @my_dShll: The delimiter string.
 *
 * Return: A pointer to an array of strings, or NULL if the operation fails.
*/

char **my_str_tokShll(char *my_strShll, char *my_dShll)
{
	int my_iShll, my_jShll, my_kShll, my_mShll, my_numwordsShll = 0;
	char **my_sShll;

	if (my_strShll == NULL || my_strShll[0] == 0)
		return (NULL);
	if (!my_dShll)
		my_dShll = " ";
	for (my_iShll = 0; my_strShll[my_iShll] != '\0'; my_iShll++)
		if (!my_is_delimShll(my_strShll[my_iShll], my_dShll) &&
				 (my_is_delimShll(my_strShll[my_iShll + 1], my_dShll)
				 || !my_strShll[my_iShll + 1]))
			my_numwordsShll++;

	if (my_numwordsShll == 0)
		return (NULL);
	my_sShll = malloc((1 + my_numwordsShll) * sizeof(char *));
	if (!my_sShll)
		return (NULL);
	for (my_iShll = 0, my_jShll = 0; my_jShll < my_numwordsShll; my_jShll++)
	{
		while (my_is_delimShll(my_strShll[my_iShll], my_dShll))
			my_iShll++;
		my_kShll = 0;
		while (!my_is_delimShll(my_strShll[my_iShll + my_kShll], my_dShll)
				 && my_strShll[my_iShll + my_kShll])
			my_kShll++;
		my_sShll[my_jShll] = malloc((my_kShll + 1) * sizeof(char));
		if (!my_sShll[my_jShll])
		{
			for (my_kShll = 0; my_kShll < my_jShll; my_kShll++)
				free(my_sShll[my_kShll]);
			free(my_sShll);
			return (NULL);
		}
		for (my_mShll = 0; my_mShll < my_kShll; my_mShll++)
			my_sShll[my_jShll][my_mShll] = my_strShll[my_iShll++];
		my_sShll[my_jShll][my_mShll] = 0;
	}
	my_sShll[my_jShll] = NULL;
	return (my_sShll);
}
