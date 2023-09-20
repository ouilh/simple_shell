#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

/* Function prototypes */
char *get_environment_variable(const char *variable_name);
int execute_command(char **args);
int execute_external_command(char **args);
char *find_command_path(char *command_name);
char **split_input_line(char *input_line);
char *read_input_line(void);
void run_shell(void);

/* Constants */
#define MAX_BUFFER_SIZE 1024

/* Custom getline function */
ssize_t my_own_getline(char **lineptr, size_t *n, FILE *stream);

/* Helper functions */
ssize_t read_from_stream(char *buffer, FILE *stream);
int find_first_newline(char *buffer, int start, int end);
void copy_buffer_to_line(char *buffer, int start, int end, char *line);

/* String manipulation functions */
char *_strtok(char *thestring, const char *delim);
char *find_next_delim(char *str, const char *delim);
char *find_next_token(char *str, const char *delim);
int is_delimiter(char ch, const char *delim);

/* String utility functions */
int _putchar(char character);
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
char *_strcat(char *destination, const char *source);
char *_strcpy(char *destination, const char *source);

/* Built-in shell commands */
int change_directory(char **args);
int placeholder_function(char **args);
int print_environment(void);

#endif
