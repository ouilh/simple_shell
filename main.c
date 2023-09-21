#include "shell.h"
#include "Tline.c"
#include "beg.c"
#include "built.c"
#include "my_og.c"
#include "path.c"
#include "str_f.c"

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

	loo();

	return (0);
}

/**
 * loo - Executes the shell command loop.
 */
void loo(void)
{
	char *line;
	char **cmdarg;
	int exe;

	line = r_t();
	cmdarg = s_t(line);
	exe = _ex(cmdarg);

	free(theline);
	free(cmdarg);

	while (exe)
	{
		line = r_t();
		cmdarg = s_t(line);
		exe = _ex(cmdarg);

		free(theline);
		free(cmdarg);
	}
}
