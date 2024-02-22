#include "shell.h"

/**
 * execute_order - Executes a shell command
 * @order: The command to be executed
 *
 * Return: None
 */
int execute_order(const char *order)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execlp(order, order, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

