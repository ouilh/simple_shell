#ifndef _SHELL_
#define _SHELL_

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

/* Functions prototypes */
char *_genv(const char *envar);
int _execute(char **args);
int _beg(char **args);
char *get_path(char *cmd);
char **split_theline(char *theline);
char *read_theline(void);
void _loo(void);

/* Constants */
#define MAX_BUFFER_SIZE 1024

/* Custom getline function */
ssize_t my_own_getline(char **lineptr, size_t *n, FILE *stream);

/* Helper functions */
ssize_t read_input(char *buffer, FILE *stream);
int f_newline(char *buffer, int start, int end);
void copy_to_line(char *buffer, int start, int end, char *line);

/* String manipulation functions */
char *_strtok(char *thestring, const char *delim);
char *find_next_delim(char *str, const char *delim);
char *find_next_token(char *str, const char *delim);
int is_delimiter(char ch, const char *delim);

/* String utility functions */
int _pchar(char m);
int _strcmp(const char *str1, char *str2);
int _strlen(const char *str);
char *_strcat(char *destr, char *sourstr);
char *_strcpy(char *destr, char *sourstr);

/* Built-in shell commands */
int _cd(char **args);
int _out(char **args);
int _env(void);


#endif
