#include "shell.h"

/**
 * exits_myshell - exits the shell
 *
 * @facts: pointer to a structure containing arguments
 * Return: 0 on success.
 */
int exits_myshell(Data *facts)
{
	unsigned int sstatus;
	int is_digit;
	int str_len;
	int exceed_maxx;

	if (facts->args[1] != NULL)
	{
		sstatus = atoi(facts->args[1]);
		is_digit = isdigit(facts->args[1]);
		str_len = strlen(facts->args[1]);
		exceed_maxx = sstatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || exceed_maxx)
		{
			get_error(facts, 2);
			facts->status = 2;
			return (1);
		}
		facts->status = (sstatus % 256);
	}
	return (0);
}
