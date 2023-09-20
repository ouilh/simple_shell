#include "shell.h"

/**
 * _putchar - writes the character m to stdout
 * @m: The character to print
 *
 * Return: 1 On success.
 * -1 On error and errno is set appropriately.
 */
int _putchar(char m)
{
	return (write(1, &m, 1));
}

/**
  * _strcmp - a function to compare 2 strings
  * @str1: first string
  * @str2: second string
  *
  * Return: int
  */
int _strcmp(const char *str1, char *str2)
{
	int cmp = 0;

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
	cmp = *str1 - *str2;
	return (cmp);
}
/**
  *_strcpy - copies the string pointed
  *to by sourstr, including the terminating null byte
  *to the buffer pointed to by dest
  * @destr: points to buffer
  * @sourstr: points to string
  *
  * Return: pointer
  */
char *_strcpy(char *destr, char *sourstr)
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
  * _strcat - Concatenates two strings
  * @destr: destination string
  * @sourstr: source string
  *
  * Return: A pointer to result string destr
  */

char *_strcat(char *destr, char *sourstr)
{
	int destlen, i;

	destlen = 0;

	while (destr[destlen])
		destlen++;

	for (i = 0; sourstr[i] != '\0'; i++)
	{
		destr[destlen] = sourstr[i];
		destlen++;
	}

	destr[destlen] = '\0';
	return (destr);
}
