#include "shell.h"

/**
 * _putc - writes the character m to stdout
 * @m: The character to print
 *
 * Return: 1 On success.
 * -1 On error and errno is set appropriately.
 */
int _putc(char m)
{
	return (write(1, &m, 1));
}

/**
  * _strc - a function to compare 2 strings
  * @str1: first string
  * @str2: second string
  *
  * Return: int
  */
int _strc(const char *str1, char *str2)
{
	int cm = 0;

	while (*str1 && *str2)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			break;
	}
	cm = *str1 - *str2;
	return (cm);
}
/**
  *_strcp - copies the string pointed
  *to by sourstr, including the terminating null byte
  *to the buffer pointed to by dest
  * @destr: points to buffer
  * @sourstr: points to string
  *
  * Return: pointer
  */
char *_strcp(char *destr, char *sourstr)
{
	char *ret = destr;

	while (*sourstr)
	{
		*destr = *sourstr;
		destr++;
		sourstr++;
	}
	*destr = '\0';
	return (ret);
}

/**
  * _strlen - it Counts length of string
  * @str: The string to counts the length
  *
  * Return: length of string
  */
int _strlen(const char *str)
{
	int leng = 0;

	while (str[leng])
		leng++;

	return (leng);
}
/**
  * _strca - Concatenates two strings
  * @destr: destination string
  * @sourstr: source string
  *
  * Return: A pointer to result string destr
  */

char *_strca(char *destr, char *sourstr)
{
	int dlen, i;

	dlen = 0;

	while (destr[dlen])
		dlen++;

	for (i = 0; sourstr[i] != '\0'; i++)
	{
		destr[dlen] = sourstr[i];
		dlen++;
	}

	destr[dlen] = '\0';
	return (destr);
}
