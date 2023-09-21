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

	_loo();

	return (0);
}

/**
 * _loo - Executes the shell command loop.
 */
void _loo(void)
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
