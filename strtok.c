#include "shell.h"

/**
 * is_delimiter - Checks if a character is in a set of delimiters.
 * @character: The character to check.
 * @delimiters: The string of delimiters.
 *
 * Return: 1 if the character is in the delimiters, 0 otherwise.
 */
int is_delimiter(char character, const char *delimiters)
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
 * find_next_token - Finds the next non-delimiter character in a string.
 * @str: The string to search.
 * @delimiters: The string of delimiters.
 *
 * Return: Pointer to the next non-delimiter character if found, NULL otherwise.
 */
char *find_next_token(char *str, const char *delimiters)
{
    int is_delimiter = 0;

    while (*str != '\0')
    {
        is_delimiter = is_delimiter(*str, delimiters);

        if (!is_delimiter)
        {
            return str;
        }
        str++;
    }
    return NULL;
}

/**
 * find_next_delim - Finds the next delimiter character in a string.
 * @str: The string to search.
 * @delimiters: The string of delimiters.
 *
 * Return: Pointer to the next delimiter character if found, NULL otherwise.
 */
char *find_next_delim(char *str, const char *delimiters)
{
    int is_delimiter = 0;

    while (*str != '\0')
    {
        is_delimiter = is_delimiter(*str, delimiters);

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
 * _strtok - Tokenizes a string into a sequence of tokens.
 * @input_string: The string to tokenize.
 * @delimiters: The string of delimiters.
 *
 * Return: Pointer to the next token if found, NULL otherwise.
 */
char *_strtok(char *thestring, const char *delim)
{
	static char *strpos;
	char *token = NULL;

	if (thestring != NULL)
	{
		strpos = thestring;
	}

	if (strpos == NULL || *strpos == '\0')
	{
		return (NULL);
	}

	token = find_next_token(strpos, delim);
	strpos = find_next_delim(token, delim);

	return (token);
}
