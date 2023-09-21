#include "shell.h"

/**
 * r_input - Reads input from a stream into a buffer.
 * @buffer: Pointer to the buffer.
 * @stream: Pointer to the stream to read from.
 *
 * Return: Number of bytes read on success, -1 on failure.
 */
ssize_t r_input(char *buffer, FILE *stream)
{
	return (read(fileno(stream), buffer, MAX_BUFFER_SIZE));
}

/**
 * f_newline - Finds the index of the first newline character in a buffer.
 * @buffer: Pointer to the buffer.
 * @start: Starting index to search from.
 * @end: Ending index to search until.
 *
 * Return: Index of the first newline character if found, -1 otherwise.
 */
int f_newline(char *buffer, int start, int end)
{
	int i = start;

	while (i < end)
	{
		if (buffer[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

/**
 * copy_to_line - Copies a portion of a buffer into a line.
 * @buffer: Pointer to the buffer.
 * @start: Starting index of the portion to copy.
 * @end: Ending index of the portion to copy.
 * @line: Pointer to the line where the portion will be copied to.
 */
void copy_to_line(char *buffer, int start, int end, char *line)
{
	int line_length = end - start;
	int i;

	for (i = 0; i < line_length; i++)
	{
		line[i] = buffer[start + i];
	}
	line[line_length] = '\0';
}

/**
 * my_own_getline - Reads a line from a stream
 * -into a dynamically allocated buffer.
 * @lineptr: Pointer to a pointer to the buffer where the line will be stored
 * @n: Pointer to the size of the buffer.
 * @stream: Pointer to the stream to read from.
 *
 * Return: Number of characters read on success, -1 on failure or end of file.
 */
ssize_t my_own_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[MAX_BUFFER_SIZE];
	static int buffer_index;
	static int num_chars;
	int newline_index;
	size_t line_length;
	char *new_lineptr;
	char *line;

	if (buffer_index >= num_chars)
	{
		num_chars = read_input(buffer, stream);

		if (num_chars <= 0)
			return (-1);
		buffer_index = 0;
	}

	newline_index = f_newline(buffer, buffer_index, num_chars);
	line_length = newline_index - buffer_index;

	if (*n < line_length + 1)
	{
		*n = line_length + 1;
		new_lineptr = (char *)malloc(*n);

		if (new_lineptr == NULL)
		{
			perror("malloc failed");
			exit(1);
		}
		free(*lineptr);
		*lineptr = new_lineptr;
	}
	line = *lineptr;

	copy_to_line(buffer, buffer_index, newline_index, line);
	buffer_index = newline_index + 1;
	return (line_length);
}
