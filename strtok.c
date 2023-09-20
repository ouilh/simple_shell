#include "shell.h"

/**
 * is_character_in_delimiters - Checks if a character is in a set of delimiters.
 * @character: The character to check.
 * @delimiters: The string of delimiters.
 *
 * Return: 1 if the character is in the delimiters, 0 otherwise.
 */
int is_character_in_delimiters(char character, const char *delimiters)
{
    size_t i;

    for (i = 0; delimiters[i] != '\0'; i++)
    {
        if (character == delimiters[i])
        {
            return 1;
        }
    }
    return 0;
}

/**
 * find_next_non_delimiter - Finds the next non-delimiter character in a string.
 * @str: The string to search.
 * @delimiters: The string of delimiters.
 *
 * Return: Pointer to the next non-delimiter character if found, NULL otherwise.
 */
char *find_next_non_delimiter(char *str, const char *delimiters)
{
    int is_delimiter = 0;

    while (*str != '\0')
    {
        is_delimiter = is_character_in_delimiters(*str, delimiters);

        if (!is_delimiter)
        {
            return str;
        }
        str++;
    }
    return NULL;
}

/**
 * find_next_delimiter - Finds the next delimiter character in a string.
 * @str: The string to search.
 * @delimiters: The string of delimiters.
 *
 * Return: Pointer to the next delimiter character if found, NULL otherwise.
 */
char *find_next_delimiter(char *str, const char *delimiters)
{
    int is_delimiter = 0;

    while (*str != '\0')
    {
        is_delimiter = is_character_in_delimiters(*str, delimiters);

        if (is_delimiter)
        {
            *str = '\0';
            str++;
            break;
        }
        str++;
    }
    return str;
}

/**
 * custom_strtok - Tokenizes a string into a sequence of tokens.
 * @input_string: The string to tokenize.
 * @delimiters: The string of delimiters.
 *
 * Return: Pointer to the next token if found, NULL otherwise.
 */
char *custom_strtok(char *input_string, const char *delimiters)
{
    static char *current_position;
    char *token = NULL;

    if (input_string != NULL)
    {
        current_position = input_string;
    }

    if (current_position == NULL || *current_position == '\0')
    {
        return NULL;
    }

    token = find_next_non_delimiter(current_position, delimiters);
    current_position = find_next_delimiter(token, delimiters);

    return token;
}
