#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <string.h>


#define BUFSIZE 1020
#define TOK_BUFSIZE 130
#define TOK_DELIM " \p\r\k\m"

/* Points to an array of pointers to strings called the "environment" */
extern char **envs;

/**
 * struct Data - struct contains relevant data in my ent prog
 * @avect: argument vector
 * @inputmsg: command line written by the user
 * @args: tokens of the command line and akk arguments
 * @status: last status of my shell
 * @counter: strands counter
 * @_envs: environment variable
 * @pid: process ID of my simple shell
 */
typedef struct Data
{
	char **avect;
	char *inputmsg;
	char **args;
	char **_envs;
	int status;
	int counter;
	char *pid;
} Data;

/**
 * struct sep_lists - all single linked lists
 * @separate: ; | @
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_lists
{
	char separate;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_lists - single linked list all in the prog
 * @strand: command/fact line
 * @next: next node
 * Description: single lists that are beinglinked to store command lines
 */
typedef struct line_lists
{
	char *strand;
	struct line_lists *next;
} line_list;

/**
 * struct r_var_lists - all single linked lists in the pro
 * @len_vari: length of the variable
 * @valu: value of the variable
 * @len_valu: length of the value
 * @upcoming: the following next node in the prog
 * Description: single linked list to store variables
 */
typedef struct r_var_lists
{
	int len_vari;
	char *valu;
	int len_valu;
	struct r_var_lists *upcoming;
} r_var;

/**
 * struct builtins - Builtin struct for command arguments in the pro
 * @term: The name of the command builtin i.e cd, exit, envn in the pro
 * @p: data type pointer function.
 */
typedef struct builtins
{
	char *term;
	int (*p)(Data *facts);
} builtin_t;

/**
 * struct env_node - Structure to represent an environment variable node
 * @key: Name of the environment variable
 * @val: Value of the environment variable
 * @next: Pointer to the next node in the linked lists
 */
typedef struct env_node
{
	char *val;
	char *key;
	struct env_node *next;
}
env_t;
/**
 * rkm_printfunc -This is a custom print function,prints to std output
 *This function iterates over the character input strin writes each character
 * to the standard output using the write system call.
 * @string: arguments passed
 */

void rkm_printfunc(char *string)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(STDOUT_FILENO, &string[i], 1);
}
/* finds_syntaxerr.c */
int charrep_count(char *inputmsg, int k);
int error_looks(char *inputmsg, int k, char pv);
int firstchar_find(char *input, int *r);
void shows_error(Data *facts, char *inputmsg, int i, int bool);
int check_syntax_error(Data *facts, char *input)

/* readsline.c */
char *reads_strand(int *i_eof);

/* sign_hand */
void signa_hand(int gest);
/* allocmem.c */
void info_copy(void *crtptr, const void *pr, unsigned int size);
void *allocates_mem(void *pr, unsigned int pv_size, unsigned int crt_size);
char **alloc_dab(char **pr, unsigned int pv_size, unsigned int crt_size);

/*looping.c*/
char *delates_comm(char *inmsg);
void loops_shell(Data *facts);

/* mysdlib.c */
int gets_leng(int r);
char *my_conv(int r);
int rkm_atoi(char *q);

/* source.c */
void frees_data(Data *facts);
void sets_data(Data *facts, char **avect);
int main(int argc, char **avect);

/* 1envimp.c */
int compr_term(const char *env, const char *term);
char *gets_env(const char *term, char **_envs);
int print_env(Data *facts);

#endif
