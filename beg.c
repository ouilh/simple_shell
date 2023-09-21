#include "shell.h"

/**
 * _begin - Execute a command using fork and execve.
 * @args: The arguments of the command.
 *
 * Return: Always 1.
 */
int _begin(char **args)
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

		if (!c)
		{
			perror("Command not found");
		}
		else
			execve(c, args, environ);
			perror("execve");
			
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
