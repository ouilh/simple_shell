#include "shell.h"

/**
 * is_del - Checks if a character is a delimiter.
 * @ch: The character to check.
 * @delim: The string of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_del(char ch, const char *delim)
{
	size_t i;
	i = 0;

	while (delim[i] != '\0')
	{
		if (ch == delim[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * find_next_token - Finds the next token in a string.
 * @str: The string to search.
 * @delim: The string of delimiters.
 *
 * Return: Pointer to the next token if found, NULL otherwise.
 */
char *find_next_token(char *str, const char *delim)
{
	int is_d = 0;

	while (*str != '\0')
	{
		is_d = is_del(*str, delim);

		if (!is_d)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

/**
 * find_next_delim - Finds the next delimiter in a string.
 * @str: The string to search.
 * @delim: The string of delimiters.
 *
 * Return: Pointer to the next delimiter if found, NULL otherwise.
 */
char *find_next_delim(char *str, const char *delim)
{
	int is_delim = 0;

	while (*str != '\0')
	{
		is_delim = is_del(*str, delim);

		if (is_delim)
		{
			*str = '\0';
			str++;
			break;
		}
		str++;
	}
	return (str);
}

/**
 * _strtok - Breaks a string into a sequence of tokens.
 * @thestring: The string to tokenize.
 * @delim: The string of delimiters.
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
