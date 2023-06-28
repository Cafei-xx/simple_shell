#ifndef _CUSHELL_H_
#define _CUSHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE "simple_shell_history"
#define HIST_MAX 3000

extern char **environment;

/**
 * struct listint_str - linked list
 * @nbr: integer number
 * @nnode: points to the next node
 *
 */
typedef struct listint_str
{
	int nbr;
	char *s;
	struct listint_str *nnode;
} list_t;

/**
 * struct builtin - contains a builtin
 * @type: the command flag
 * @fn: the function
 * written
 */
typedef struct builtin
{
	int (*fn)(info_t *);
	char *type;
} builtin_table;
/**
 * struct arginfo - contains additional arguements
 * @argcount: the argument count
 * @cmdbuff_type: CMD_type ||, &&, ;
 * @fidread: the fid from which to read line input
 * @histocount: the history line counter
 * @err: the error code for exit()s
 * @errcount: counts the error
 * @chenv: detects if environment was changed
 * @st: the return status of the last exec'd command
 * @linecount: if true counts line of input
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @cpath: a string path for the current command
 * @environment: custom modified copy of environment from LL env
 * @finame: the program filename
 * @cmdbuff: address of pointer to cmd_buf, on if chaining
 * @envlst: linked list local copy of environment
 * @hist_n: the history node
 * @alias_n: the alias node
 */

typedef struct arginfo
{
	int argcount;
	int cmdbuff_type;
	int fidread;
	int chenv;
	int histocount;
	int err;
	int errcount;
	int st;
	unsigned int linecount;
	char *arg;
	char **argv;
	char *cpath;
	char **environment;
	char *finame;
	char **cmdbuff;
	list_t *envlst;
	list_t *hist_n;
	list_t *alias_n;
}

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
int inter_mode(shellinfo_t *shellinfo);
int _strlen(char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(char *str1, char *str2);
char *_strsub(const char *str, const char *substr);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _putchar(char ch);
char *_strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);
int _delimeter(char ch, char *d);
int _atoi(char *str);
int _isalpha(int ch);
char *_memset(char *ad, char v, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int free_ptr(void **p);
void free_str(char **str);
int _printdecimal(int a, int r);
void _inputstr(char *str);
int _writechar(char ch);
int _inpstr(char *str, int r);
int write_char(char ch, int r);
void _puts(char *str);

#endif
