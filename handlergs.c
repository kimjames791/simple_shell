#include "shell.h"
#define MAX_ARGS 20
/**
 * main - a function that handles args
 *@args:arguments passed
 *@command: order or instruction
 * handle_args - this takes in the arguments passed handles them
 */
void handle_args(char *command, char **args)
{
	rkmprint_func("Executing command: %s\n", command);
	rkmprint_func("Arguments:\n");
	int p;

	for (p = 0; args[p] != NULL; p++)
	{
		rkmprint_func("%s\n", args[p]);
	}
}

int main(void)
{
	char input[100];
	char *args[MAX_ARGS];
	int p;
	char *token;

	while (1)
	{
		rkmprint_func("Enter a command: ");
		fgets(input, sizeof(input), stdin);

		token = strtok(input, " \n");
		for (p = 0; token != NULL && p < MAX_ARGS - 1; p++)
		{
			args[p] = token;
			token = strtok(NULL, " \n");
		}
		args[p] = NULL;

		if (args[0] != NULL)
	{
		handle_args(args[0], args);
	}
	}
	return (0);
}

