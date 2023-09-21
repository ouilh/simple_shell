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
	int stat;
	char *cmd;

	pi = fork();

	if (pi == 0)
	{
		if (args[0][0] == '/')
			cmd = args[0];
		else
			cmd = get_thepath(args[0]);

		if (cmd)
		{
			execve(cmd, args, environ);
			perror("execve");
		}
		else
			perror("Command not found");

		exit(1);
	}
	else if (pi < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pi, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (1);
}
