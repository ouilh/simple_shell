#include "shell.h"

/**
 * _genv - Get the value of an environment variable.
 * @envar: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_genv(const char *envar)
{
	int j = 0;
	char *sr = NULL;

	while (environ[j])
	{
		sr = _strtok(environ[j], "=");

		if (_strcmp(envar, sr) == 0)
			return (_strtok(NULL, "\n"));
		j++;
	}

	return (NULL);
}

/**
 * get_path - Get the full path of a command using the PATH variable.
 * @cmd: The command.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *get_path(char *cmd)
{
	char *thepath = _genv("PATH");
	char *split;
	char *ff;
	struct stat st;

	split = _strtok(thepath, ":");
	while (split)
	{
		ff = malloc(_strlen(split) + _strlen(cmd) + 2);

		if (ff == NULL)
		{
			perror("..memory allocation error..");
			exit(0);
		}

		_strcpy(ff, split);
		_strcat(ff, "/");
		_strcat(ff, cmd);
		if (stat(ff, &st) == 0)
			return (ff);
		free(ff);
		split = _strtok(NULL, ":");
	}
	return (NULL);
}
