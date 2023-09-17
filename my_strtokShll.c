#include "main.h"

/**
 * **my_str_tokShll - this function splits a string into words repeated delimeters are ignored
 *
 * @my_strShll: it is a string
 * @my_dShll: it is a the delimeter string
 *
 * Return: it returns a pointer to an array of strings, or NULL for fail
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
		if (!my_is_delimShll(my_strShll[my_iShll], my_dShll) && (my_is_delimShll(my_strShll[my_iShll + 1], my_dShll) || !my_strShll[my_iShll + 1]))
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
		while (!my_is_delimShll(my_strShll[my_iShll + my_kShll], my_dShll) && my_strShll[my_iShll + my_kShll])
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
			my_sShll[my_jShll][my_mShll] = my_strShll[i++];
		my_sShll[my_jShll][my_mShll] = 0;
	}
	my_sShll[my_jShll] = NULL;
	return (my_sShll);
}

/**
 * **my_str_tok2Shll - this function do : splits a string into words
 *
 * @my_strShll: it is a string
 * @my_dShll: it is a the delimeter string
 *
 * Return: it returns pointer to an array of strings, or NULL for fail
*/

char **my_str_tok2Shll(char *my_strShll, char my_dShll)
{
	int my_iShll, my_jShll, my_kShll, my_mShll, my_numwordsShll = 0;
	char **my_sShll;

	if (my_strShll == NULL || my_strShll[0] == 0)
		return (NULL);
	for (my_iShll = 0; my_strShll[iShll] != '\0'; my_iShll++)
		if ((my_strShll[my_iShll] != my_dShll && my_strShll[my_iShll + 1] == my_dShll) ||
			(my_strShll[my_iShll] != my_dShll && !my_strShll[my_iShll + 1]) || my_strShll[my_iShll + 1] == my_dShll)
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
		while (my_strShll[my_iShll + my_kShll] != my_dShll && my_strShll[my_iShll + my_kShll] && my_strShll[my_iShll + my_kShll] != my_dShll)
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
