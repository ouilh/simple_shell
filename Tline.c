#include "shell.h"

/**
 * s_t - Split the input line into tokens.
 * @theline: The input line.
 *
 * Return: An array of tokens.
 */
char **s_t(char *theline)
{
	int j = 0;
	const char *dlmtr;
	char **splits;
	char *split;

	dlmtr = " \n\t";
	splits = malloc(1024 * sizeof(char *));
	split = _strtok(theline, dlmtr);

	if (!splits)
	{
		perror("allocation error\n");
		exit(1);
	}

	while (split != NULL)
	{
		splits[j] = split;
		split = _strtok(NULL, dlmtr);
		j++;
	}
	splits[j] = NULL;

	return (splits);
}

/**
 * r_t - Read a line of input from the user.
 *
 * Return: The input line.
 */
char *r_t(void)
{
	char *theline = NULL;
	size_t bfsz = 0;

	if (my_own_getline(&theline, &bfsz, stdin) == -1)
	{
		if (theline != NULL && theline[0] == '\0')
		{
			exit(0);
		}
		else
		{
			exit(0);
		}
	}

	return (theline);
}
