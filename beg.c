#include "shell.h"

/**
 * _beg - Execute a command using fork and execve.
 * @args: The arguments of the command.
 *
 * Return: Always 1.
 */
int _beg(char **args)
{
	pid_t pi;
	int st;
	char *c;

	pi = fork();

	if (pi < 0)
	{
		perror("fork");
	}
	else if (pi == 0)
	{
		if (args[0][0] == '/')
			c = args[0];
		else
			c = get_thepath(args[0]);

		if (c)
		{
			execve(c, args, environ);
			perror("execve");
		}
		else
			perror("Command not found");

		exit(1);
	}
	else
	{
		do {
			waitpid(pi, &st, WUNTRACED);
		} while (!WIFEXITED(st) && !WIFSIGNALED(st));
	}
	return (1);
}
