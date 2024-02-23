#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void rkmprint_func(const char *inputmsg);
void shows_prompt(void);
void read_order(char *order);
int execute_order(const char *order);

#endif /* SHELL_H */
