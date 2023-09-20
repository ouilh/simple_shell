#include "shell.h"

/**
 * main - Entry point of the Shell program.
 *@argc: Number of arguments passed.
 *@argv: Array of arguments passed.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	_loop();

	return (0);
}

/**
 * _loop - Executes the shell command loop.
 */
void _loop(void)
{
	char *theline;
	char **cmdarg;
	int execstat;

	do {
		theline = read_theline();
		cmdarg = split_theline(theline);
		execstat = _execute(cmdarg);

		free(theline);
		free(cmdarg);
	} while (execstat);
}
