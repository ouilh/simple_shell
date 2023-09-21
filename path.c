#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @envar: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *envar)
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
	char *thepath = _getenv("PATH");
	char *split;
	char *fcmd;
	struct stat st;

	split = _strtok(thepath, ":");
	while (split)
	{
		fcmd = malloc(_strlen(split) + _strlen(cmd) + 2);

		if (fcmd == NULL)
		{
			perror("..memory allocation error..");
			exit(0);
		}

		_strcpy(fcmd, split);
		_strcat(fcmd, "/");
		_strcat(fcmd, cmd);
		if (stat(fcmd, &st) == 0)
			return (fcmd);
		free(fcmd);
		split = _strtok(NULL, ":");
	}
	return (NULL);
}
