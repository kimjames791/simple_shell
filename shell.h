#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void rkm_printfunc(const char *inputmsg);
void shows_prompt(void);
void read_order(char *order);
int execute_order(const char *order);
void handle_args(char *command, char **args);

#endif /* SHELL_H */
