#include "shell.h"

/**
 * inter_active - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int inter_active(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delim(char c, char *delim)
{
    char *current = delim;
    while (*current)
    {
        if (*current == c)
            return (1);
        current++;
    }
    return (0);
}

/**
 * alpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int alpha(int c)
{
	if ((c < 'a' && c > 'z') || (c < 'A' && c > 'Z'))
		return (0);
	else
		return (1);
}

/**
 * atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int atoi(char *s)
{
	int j, sign = 1, fl = 0, out;
	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && fl != 2; i++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			fl = 1;
			result *= 10;
			result += (s[j] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}

	if (sign == -1)
		out = -result;
	else
		out = result;

	return (out);
}
