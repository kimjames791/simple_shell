#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void rkmprint_func(const char *inputmsg);
void shows_prompt(void);
char *read_order(void);
int execute_order(const char *order);

#endif /* SHELL_H */
