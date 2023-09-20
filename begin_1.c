#include "shell.h"

/**
 * execute_command - Execute a command using fork and execve.
 * @args: The arguments of the command.
 *
 * Return: Always 1.
 */
int execute_command(char **args)
{
	pid_t child_pid;
	int child_status;
	char *command_path;

	child_pid = fork();

	if (child_pid == 0)
	{
		// Determine the full path of the command
		if (args[0][0] == '/')
			command_path = args[0];
		else
			command_path = find_command_path(args[0]);

		if (command_path)
		{
			// Execute the command
			execve(command_path, args, environ);
			perror("execve");
		}
		else
		{
			perror("Command not found");
		}

		exit(1);
	}
	else if (child_pid < 0)
	{
		perror("fork");
	}
	else
	{
		// Wait for the child process to complete
		do {
			waitpid(child_pid, &child_status, WUNTRACED);
		} while (!WIFEXITED(child_status) && !WIFSIGNALED(child_status));
	}
	return 1;
}
