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

    run_shell();

    return 0;
}

/**
 * run_shell - Executes the shell command loop.
 */
void run_shell(void)
{
    char *input_line;
    char **command_args;
    int execution_status;

    do {
        input_line = read_input_line();
        command_args = split_input_line(input_line);
        execution_status = execute_command(command_args);

        free(input_line);
        free(command_args);
    } while (execution_status);
}
