#include "shell.h"

/**
 * split_input_line - Split the input line into tokens.
 * @input_line: The input line.
 *
 * Return: An array of tokens.
 */
char **split_input_line(char *input_line)
{
    int token_count = 0;
    const char *delimiters;
    char **tokens;
    char *token;

    delimiters = " \n\t";
    tokens = malloc(1024 * sizeof(char *));
    token = custom_strtok(input_line, delimiters);

    if (!tokens)
    {
        perror("Allocation error\n");
        exit(1);
    }

    while (token != NULL)
    {
        tokens[token_count] = token;
        token = custom_strtok(NULL, delimiters);
        token_count++;
    }
    tokens[token_count] = NULL;

    return tokens;
}

/**
 * read_input_line - Read a line of input from the user.
 *
 * Return: The input line.
 */
char *read_input_line(void)
{
    char *input_line = NULL;
    size_t buffer_size = 0;

    if (my_own_getline(&input_line, &buffer_size, stdin) == -1)
    {
        if (input_line != NULL && input_line[0] == '\0')
        {
            exit(0);
        }
        else
        {
            exit(0);
        }
    }

    return input_line;
}
