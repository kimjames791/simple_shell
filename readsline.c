#include "shell.h"

/**
 * reads_strand - reads the inputmsg
 *
 * @i_eof: return value of getline function
 * Return: message
 */
char *reads_strand(int *i_eof)
{
	char *inputmsg = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&inputmsg, &bufsize, stdin);

	return (inputmsg);
}
