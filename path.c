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
	char *srt = NULL;

	while (environ[j])
	{
		srt = _strt(environ[j], "=");

		if (_strc(envar, srt) == 0)
			return (_strtok(NULL, "\n"));
		j++;
	}

	return (NULL);
}

/**
 * get_tp - Get the full path of a command using the PATH variable.
 * @cmd: The command.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *get_tp(char *cmd)
{
	char *thepath = _genv("PATH");
	char *split;
	char *fcmd;
	struct stat st;

	split = _strt(thepath, ":");
	while (split)
	{
		fcmd = malloc(_strlen(split) + _strlen(cmd) + 2);

		if (fcmd == NULL)
		{
			perror("..memory allocation error..");
			exit(0);
		}

		_strcp(fcmd, split);
		_strca(fcmd, "/");
		_strca(fcmd, cmd);
		if (stat(fcmd, &st) == 0)
			return (fcmd);
		free(fcmd);
		split = _strtok(NULL, ":");
	}
	return (NULL);
}
