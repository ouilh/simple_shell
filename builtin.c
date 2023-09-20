#include "shell.h"

/**
 * change_directory - Change the current working directory.
 * @args: The arguments of the command.
 *
 * Return: 1 on success, 0 on failure.
 */
int change_directory(char **args)
{
    if (chdir(args[1]) != 0)
    {
        perror("Directory change error");
        return 0; // Return 0 on failure
    }
    return 1; // Return 1 on success
}

/**
 * print_environment - Print the current environment variables.
 *
 * Return: Always 1.
 */
int print_environment(void)
{
    int env_index, char_index;

    env_index = 0;
    while (environ[env_index])
    {
        char_index = 0;
        while (environ[env_index][char_index])
        {
            _putchar(environ[env_index][char_index]);
            char_index++;
        }

        if (char_index != 0)
            _putchar('\n');
        env_index++;
    }
    return 1;
}

/**
 * placeholder_function - Placeholder function.
 * @args: The arguments of the command.
 *
 * Return: 0.
 */
int placeholder_function(char **args)
{
    (void)args; // Avoid unused variable warning
    return 0;
}

/**
 * execute_command - Execute a command.
 * @args: The arguments of the command.
 *
 * Return: Result of the executed command.
 */
int execute_command(char **args)
{
    int i;
    int built_in_count = 0;

    char *built_in_commands[] = {
        "cd",
        "env",
        "exit"
    };

    int (*built_in_functions[])() = {&change_directory, &print_environment, &placeholder_function};

    built_in_count = sizeof(built_in_commands) / sizeof(char *);

    if (args[0] == NULL)
    {
        return 1; // No command provided
    }

    for (i = 0; i < built_in_count; i++)
    {
        if (_strcmp(args[0], built_in_commands[i]) == 0)
            return (*built_in_functions[i])(args); // Execute the built-in function
    }

    return execute_external_command(args); // Execute an external command
}
