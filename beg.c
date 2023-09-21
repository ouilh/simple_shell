#include "shell.h"

/**
 * beg - Execute a command using fork and execve.
 * @args: The arguments of the command.
 *
 * Return: Always 1.
 */
int beg(char **args)
{
	pid_t pi;
	int stat;
	char *cm;

	pi = fork();

	if (pi < 0)
	{
    perror("fork");		
	}
	else if (pi == 0)
	{
		if (args[0][0] == '/')
			cmd = args[0];
		else
			cm = get_thepath(args[0]);

		if (cm)
		{
			execve(cm, args, environ);
			perror("execve");
		}
		else
			perror("Command not found");

		exit(1);
	}
	else
	{
		do {
			waitpid(pi, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (1);
}
