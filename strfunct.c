#include "shell.h"

/**
 * write_character - Writes the character to stdout.
 * @character: The character to print.
 *
 * Return: 1 on success, -1 on error, and errno is set appropriately.
 */
int write_character(char character)
{
    return write(1, &character, 1);
}

/**
 * compare_strings - Compares two strings.
 * @string1: First string.
 * @string2: Second string.
 *
 * Return: 0 if the strings are equal, a positive or negative value otherwise.
 */
int compare_strings(const char *string1, const char *string2)
{
    int comparison = 0;

    while (*string1 && *string2)
    {
        if (*string1 == *string2)
        {
            string1++;
            string2++;
        }
        else
        {
            break;
        }
    }
    comparison = *string1 - *string2;
    return comparison;
}

/**
 * copy_string - Copies the source string, including the null byte, to the destination buffer.
 * @destination: Pointer to the destination buffer.
 * @source: Pointer to the source string.
 *
 * Return: Pointer to the destination buffer.
 */
char *copy_string(char *destination, const char *source)
{
    char *result = destination;

    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return result;
}

/**
 * calculate_string_length - Counts the length of a string.
 * @string: The string to calculate the length of.
 *
 * Return: Length of the string.
 */
size_t calculate_string_length(const char *string)
{
    size_t length = 0;

    while (string[length])
    {
        length++;
    }
    return length;
}

/**
 * concatenate_strings - Concatenates two strings.
 * @destination: Destination string.
 * @source: Source string.
 *
 * Return: A pointer to the result string (destination).
 */
char *concatenate_strings(char *destination, const char *source)
{
    int destination_length = 0;

    while (destination[destination_length])
    {
        destination_length++;
    }

    int i;

    for (i = 0; source[i] != '\0'; i++)
    {
        destination[destination_length] = source[i];
        destination_length++;
    }

    destination[destination_length] = '\0';
    return destination;
}
