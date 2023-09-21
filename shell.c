/* shell.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10

int main(void)
{
    char *input;
    size_t len = 0;
    pid_t child_pid;
    int status;

    while (1)
    {
        printf("$ ");
        getline(&input, &len, stdin);

        // Remove the newline character
        input[strlen(input) - 1] = '\0';

        // Split the command and arguments
        char *token = strtok(input, " ");
        char *args[MAX_ARGS];
        int arg_count = 0;

        while (token != NULL && arg_count < MAX_ARGS - 1)
        {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Check for the built-in commands
        if (args[0] != NULL)
        {
            if (strcmp(args[0], "exit") == 0)
            {
                free(input);
                exit(EXIT_SUCCESS);
            }
            else if (strcmp(args[0], "env") == 0)
            {
                // Print the current environment variables
                char **env = environ;
                while (*env)
                {
                    printf("%s\n", *env);
                    env++;
                }
            }
            else
            {
                // Fork and execute other commands
                child_pid = fork();
                if (child_pid == -1)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                if (child_pid == 0)
                {
                    // Child process
                    execve(args[0], args, NULL);
                    perror("execve");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    // Parent process
                    wait(&status);
                }
            }
        }
    }

    free(input);
    return (0);
}
