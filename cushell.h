#ifndef CUSHELL_H
#define CUSHELL_H

#define TRUE (1 == 1)

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* path */
int _path(char *first, char **input, char **env, int *ex_st);


/* envt */
int printenv(char **env, int *ex_st);
char *cpy_env(char **env);


/* built--ins & exe func */
void builtins(char *line, char **args, char **env, int *ex_st);
void _execute(int status, char **args, int *ex_st, int *tal);


/* strings.c: functions related to strings */
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);


/* printf.c: functions related to printing strings/characters/numbers */
int _putchar(char c);
void print_str(char *s);
char *pathstr(char *right, char *first);
char **parser(char *l);
void print_int(int *tal);
void free_freely(int n, ...);
char *dup_string(char *s);
char *str_str(char *dest, char *src);
void free_dp(char **command);


/* helpers.c: helper functions */
void no_nl(char *l);
void free_grid(char **grid, int height);
int special_char(char *buffer, ssize_t bytes, int *ex_st);
char *int_charac_ter(int num);

#endif
