#include "shell.h"

/**
 * _cd_ - Change the current working directory.
 * @args: The arguments of the command.
 *
 * Return: 1 on success, 0 on failure.
 */
int _cd_(char **args)
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
	int e, v;

	e = 0;
	while (environ[e])
	{
		v = 0;
		while (environ[e][v])
		{
			_putchar(environ[e][v]);
			v++;
		}

		if (v != 0)
			_putchar('\n');
		e++;
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
	int i;
	int count = 0;

	char *built_in_c[] = {
		"cd",
		"env",
		"exit"
	};

	int (*built_in_f[])() = {&_cd, &_env, &_out};

	count = (sizeof(built_in_c) / sizeof(char *));

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < count; i++)
	{
		if (_strcmp(args[0], built_in_c[i]) == 0)
			return ((*built_in_f[i])(args));
	}

	return (_beg(args));
}
