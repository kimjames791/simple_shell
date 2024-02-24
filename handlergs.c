#include "shell.h"
#define MAX_ARGS 20
/**
 * handle_args - a function that handles arguments
 *@args:arguments passed
 *@command: order or instruction
 * handle_args - this takes in the arguments passed handles them
 * my_program - a function that parses and executes user command
 */
void handle_args(char *command, char **args)
{
	int p;

	rkm_printfunc(command);
	rkm_printfunc("Arguments:\n");

	for (p = 0; args[p] != NULL; p++)
	{
		rkm_printfunc(args[p]);
	}
}
/**
 * my_program - a function that parses and executes user command
 * Description: implements basic commandline interface
 * Return: 0 always success
 */
int my_program(void)
{
	char input[100];
	char *args[MAX_ARGS];
	int p;
	char *token;

	while (1)
	{
		rkm_printfunc("Enter a command: ");
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

