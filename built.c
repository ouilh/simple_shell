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
 * _env_ - Print the current environment variables.
 *
 * Return: Always 1.
 */
int _env_(void)
{
	int t, l;

	t = 0;
	while (environ[t])
	{
		l = 0;
		while (environ[t][l])
		{
			_put(environ[t][l]);
			v++;
		}

		if (v != 0)
			_put('\n');
		t++;
	}
	return (1);
}

/**
 * _out_ - Placeholder function.
 * @args: The arguments of the command.
 *
 * Return: 0.
 */
int _out_(char **args)
{
	(void)args;
	return (0);
}

/**
 * _ex - Execute a command.
 * @args: The arguments of the command.
 *
 * Return: Result of the executed command.
 */
int _ex(char **args)
{
	int j;
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
  i = 0;
  
  while (i < count)
  {
	
		if (_strcmp(args[0], built_in_c[j]) == 0)
			return ((*built_in_f[j])(args));
	  i++;
  }
	return (_begin(args));
}
