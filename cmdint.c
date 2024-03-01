#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * print_rkmprompt - Prints rkmshell prompt
 */
void print_rkmprompt(void)
{
	rkm_printfunc("$ ");
}

/**
 * executes_cmd - Executes the given command in a child process
 * @cmd: The command to execute
 */
void executes_cmd(char *cmd)
{
	int status;

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, (char *[]){ command, NULL }, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * main_entry - Entry point of the rkmsimple shell program
 * @argc: Number of arguments passed in the func
 * @argv: Vector of strings containing the arguments in the func
 * Return: Always 0 if success
 */
int main_entry(int argc, char **argv)
{
	char command[MAX_COMMAND_LENGTH];

	(void)argc;
	(void)argv;

	while (1)
	{
		print_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			if (feof(stdin))
			{
				rkm_printfunc("\n");
				break;
			}
			perror("fgets");
			exit(EXIT_FAILURE);
		}

		if (command[strlen(command) - 1] == '\n')
		{
			command[strlen(command) - 1] = '\0';
		}
		execute_command(char command);
	}
	return (0);
}

