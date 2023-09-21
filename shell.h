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
int _ex(char **args);
int beg(char **args);
char *get_tp(char *cmd);
char **s_t(char *theline);
char *r_t(void);
void loo(void);

/* Constants */
#define MAX_BUFFER_SIZE 1024

/* Custom getline function */
ssize_t my_own_getline(char **lineptr, size_t *n, FILE *stream);

/* Helper functions */
ssize_t R_input(char *buffer, FILE *stream);
int F_newline(char *buffer, int start, int end);
void c_line(char *buffer, int start, int end, char *line);

/* String manipulation functions */
char *_strt(char *thestring, const char *delim);
char *find_next_del(char *str, const char *delim);
char *find_next_t(char *str, const char *delim);
int is_del(char ch, const char *delim);

/* String utility functions */
int _putc(char m);
int _strc(const char *str1, char *str2);
int _strlen(const char *str);
char *_strca(char *destr, char *sourstr);
char *_strcp(char *destr, char *sourstr);

/* Built-in shell commands */
int _cd_(char **args);
int _out_(char **args);
int _env_(void);


#endif
