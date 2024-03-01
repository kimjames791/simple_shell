#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <ctype.h>
/**
 * struct Data - Structure to hold arguments
 * @args: Array of strings representing arguments
 * @status member for error handling
 * Description: This structure is used to hold arguments.
 */
typedef struct Data
{
	char **args;
	int status;
	char **envs;
}
Data;

void rkm_printfunc(const char *inputmsg);
void shows_prompt(void);
void read_order(char *order);
int execute_order(const char *order);
void handle_args(char *command, char **args);
int exits_myshell(Data *facts);
void get_error(Data *facts __attribute__((unused)),int error_code);
int compr_term(const char *env, const char *term);
int print_env(Data *facts);
char *gets_env(const char *term, char **_envs);
int parse_command(char *command);
void execute_command(char **tokenized_command, int command_type);
char *check_path(char *command);
void (*get_func(char *command))(char **);
char *_getenv(char *name);
void print_message(void);
void print_rkmprompt(void);
void executes_cmd(char *cmd);
int main_entry(int argc, char **argv);

#endif /* SHELL_H */
