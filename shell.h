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
 *
 * Description: This structure is used to hold arguments.
 */
typedef struct Data
{
	char **args;
}
Data;

void rkm_printfunc(const char *inputmsg);
void shows_prompt(void);
void read_order(char *order);
int execute_order(const char *order);
void handle_args(char *command, char **args);
int exits_myshell(Data *facts);
void get_error(Data *facts, int error_code);


#endif /* SHELL_H */
