#include "shell.h"

/**
 * R_input - Reads input from a stream into a buffer.
 * @buffer: Pointer to the buffer.
 * @stream: Pointer to the stream to read from.
 *
 * Return: Number of bytes read on success, -1 on failure.
 */
ssize_t R_input(char *buffer, FILE *stream)
{
	return (read(fileno(stream), buffer, MAX_BUFFER_SIZE));
}

/**
 * F_newline - Finds the index of the first newline character in a buffer.
 * @buffer: Pointer to the buffer.
 * @start: Starting index to search from.
 * @end: Ending index to search until.
 *
 * Return: Index of the first newline character if found, -1 otherwise.
 */
int F_newline(char *buffer, int start, int end)
{
	int j;

	for (j = start; j < end; j++)
	{
		if (buffer[j] == '\n')
		{
			return (j);
		}
	}
	return (-1);
}

/**
 * c_line - Copies a portion of a buffer into a line.
 * @buffer: Pointer to the buffer.
 * @start: Starting index of the portion to copy.
 * @end: Ending index of the portion to copy.
 * @line: Pointer to the line where the portion will be copied to.
 */
void c_line(char *buffer, int start, int end, char *line)
{
	int line_length = end - start;
	int i = 0;

	while (i < line_length)
	{
		line[i] = buffer[start + i];
    i++;
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
	int newline_i;
	size_t line_length;
	char *new_lineptr;
	char *line;

	if (buffer_index >= num_chars)
	{
		num_chars = R_input(buffer, stream);

		if (num_chars <= 0)
			return (-1);
		buffer_index = 0;
	}

	newline_i= F_newline(buffer, buffer_index, num_chars);
	line_length = newline_i - buffer_index;

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

	c_line(buffer, buffer_index, newline_i, line);
	buffer_index = newline_i + 1;
	return (line_length);
}
