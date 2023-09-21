#include "shell.h"

/**
 * _cd - Change the current working directory.
 * @args: The arguments of the command.
 *
 * Return: 1 on success, 0 on failure.
 */
int _cd(char **args)
{
	if (chdir(args[1]) != 0)
	{
		perror("error occurred");
	}
	return (1);
}

/**
 * _env - Print the current environment variables.
 *
 * Return: Always 1.
 */
int _env(void)
{
	int n, s;

	n = 0;
	while (environ[n])
	{
		s = 0;
		while (environ[n][s])
		{
			_putchar(environ[n][s]);
			s++;
		}

		if (s != 0)
			_putchar('\n');
		n++;
	}
	return (1);
}

/**
 * _out - Placeholder function.
 * @args: The arguments of the command.
 *
 * Return: 0.
 */
int _out(char **args)
{
	(void)args;
	return (0);
}

/**
 * _execute - Execute a command.
 * @args: The arguments of the command.
 *
 * Return: Result of the executed command.
 */
int _execute(char **args)
{
	int m;
	int co = 0;

	char *built_in_c[] = {
		"cd",
		"env",
		"exit"
	};

	int (*built_in_f[])() = {&_cd, &_env, &_out};

	co = (sizeof(built_in_c) / sizeof(char *));

	if (args[0] == NULL)
	{
		return (1);
	}

	for (m = 0; m < co; m++)
	{
		if (_strcmp(args[0], built_in_c[m]) == 0)
			return ((*built_in_f[m])(args));
	}

	return (_beg(args));
}
