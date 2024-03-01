#include "shell.h"

/**
 * frees_data - frees data structure
 *
 * @facts: data structure of the program
 * Return: no return
 */
void frees_data(Data *facts)
{
	unsigned int p;

	for (p = 0; facts->_envs[p]; p++)
	{
		free(facts->_envs[p]);
	}

	free(facts->_evns);
	free(facts->pid);
}

/**
 * sets_data - Initialize data structure
 *
 * @facts: data structure
 * @avect: argument vector
 * Return: no return always
 */
void sets_data(Data *facts, char **avect)
{
	unsigned int p;

	facts->avect = avect;
	facts->inputmsg = NULL;
	facts->args = NULL;
	facts->status = 0;
	facts->counter = 1;

	for (p = 0; evns[p]; p++)
		;

	facts->_environ = malloc(sizeof(char *) * (p + 1));

	for (p = 0; envs[p]; p++)
	{
		facts->_envs[p] = strdup(envs[p]);
	}

	facts->_envs[p] = NULL;
	facts->pid = my_conv(getpid());
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @avect: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char **avect)
{
	Data facts;
	(void) argc;

	signal(SIGINT, signa_hand);
	sets_data(&facts, avect);
	loops_shell(&facts);
	frees_data(&facts);
	if (facts.status < 0)
		return (256);
	return (facts.status);
}
