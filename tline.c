#include "shell.h"

/**
 * split_theline - Split the input line into tokens.
 * @theline: The input line.
 *
 * Return: An array of tokens.
 */
char **split_theline(char *theline)
{
	int j = 0;
	const char *dlm;
	char **splits;
	char *split;

	dlm = " \n\t";
	splits = malloc(1024 * sizeof(char *));
	split = _strtok(theline, dlm);

	if (!splits)
	{
		perror("allocation error\n");
		exit(1);
	}

	while (split != NULL)
	{
		splits[j] = split;
		split = _strtok(NULL, dlm);
		j++;
	}
	splits[j] = NULL;

	return (splits);
}

/**
 * read_theline - Read a line of input from the user.
 *
 * Return: The input line.
 */
char *read_theline(void)
{
	char *theline = NULL;
	size_t bfs = 0;

	if (my_own_getline(&theline, &bfs, stdin) == -1)
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
