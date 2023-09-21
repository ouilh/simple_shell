#include "shell.h"

/**
 * _pchar - writes the character m to stdout
 * @m: The character to print
 *
 * Return: 1 On success.
 * -1 On error and errno is set appropriately.
 */
int _pchar(char m)
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
	int c = 0;

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
	c = *str1 - *str2;
	return (c);
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
	char *r = destr;

	while (*sourstr)
	{
		*destr = *sourstr;
		destr++;
		sourstr++;
	}
	*destr = '\0';
	return (r);
}

/**
  * _strlen - it Counts length of string
  * @str: The string to counts the length
  *
  * Return: length of string
  */
int _strlen(const char *str)
{
	int l = 0;

	while (str[l])
		l++;

	return (l);
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
	int des, j;

	des = 0;

	while (destr[des])
		des++;

	for (j = 0; sourstr[j] != '\0'; j++)
	{
		destr[des] = sourstr[j];
		des++;
	}

	destr[des] = '\0';
	return (destr);
}
