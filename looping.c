#include "shell.h"

/**
 * delates_comm - deletes comments from the input interface
 *
 * @inmsg: input string
 * Return: input without comments
 */

char *delates_comm(char *inmsg)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; inmsg[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(inmsg);
				return (NULL);
			}

			if (inmsg[i - 1] == ' ' || inmsg[i - 1] == '\t' || inmsg[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		inmsg = allocates_mem(in, i, up_to + 1);
		inmsg[up_to] = '\0';
	}

	return (inmsg);
}

/**
 * loops_shell - Loop of my simple shell
 * @facts: important (av, input, args)
 *
 * Return: no return.
 */

void loops_shell(Data *facts)
{
	int loop, i_eof;
	char *userin;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		userin = reads_strand(&i_eof);
		if (i_eof != -1)
		{
			userin = delates_comm(userin);
			if (userin == NULL)
				continue;

			if (check_syntax_error(facts, userin) == 1)
			{
				facts->status = 2;
				free(userin);
				continue;
			}
			userin = rep_var(userin, facts);
			loop = split_commands(facts, userin);
			facts->counter += 1;
			free(userin);
		}
		else
		{
			loop = 0;
			free(userin);
		}
	}
}
