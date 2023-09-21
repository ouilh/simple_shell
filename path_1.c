#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @variable_name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *variable_name)
{
    int i = 0;
    char *current_variable = NULL;

    while (environ[i])
    {
        current_variable = _strtok(environ[i], "=");

        if (_strcmp(variable_name, current_variable) == 0)
            return _strtok(NULL, "\n");

        i++;
    }

    return NULL;
}

/**
 * find_command_path - Find the full path of a command using the PATH variable.
 * @command_name: The name of the command.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *find_command_path(char *command_name)
{
    char *path_variable = get_environment_variable("PATH");
    char *path_segment;
    char *full_command;
    struct stat file_stat;

    path_segment = _strtok(path_variable, ":");
    while (path_segment)
    {
        full_command = malloc(_strlen(path_segment) + _strlen(command_name) + 2);

        if (full_command == NULL)
        {
            perror("Memory allocation error");
            exit(0);
        }

        _strcpy(full_command, path_segment);
        _strcat(full_command, "/");
        _strcat(full_command, command_name);
        if (stat(full_command, &file_stat) == 0)
            return full_command;

        free(full_command);
        path_segment = _strtok(NULL, ":");
    }
    return NULL;
}
