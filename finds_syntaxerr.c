#include "shell.h"

/**
 * charrep_count - counts the repetitions of a char in the func
 *
 * @inputmsg: input string
 * k: index
 * Return: repetitions all
 */

int charrep_count(char *inputmsg, int k)
{
	if (*(inputmsg - 1) == *inputmsg)
		return (repeated_char(inputmsg - 1, p + 1));

	return (p);
}

/**
 * error_looks - finds syntax errors in the prog
 *
 * @inputmsg: user message
 * k: index of num
 * @pv: previous char seen
 * Return: index of error. 0 if non
 */

int error_looks(char *inputmsg, int k, char pv)
{
	int count;

	count = 0;
	if (*inputmsg == '\0')
		return (0);

	if (*inputmsg == ' ' || *inputmsg == '\t')
		return (error_sep_op(inputmsg + 1, k + 1, pv));

	if (*inputmsg == ';')
		if (pv == '|' || pv == '@' || last == ';')
			return (k);

	if (*inputmsg == '|')
	{
		if (pv == ';' || pv == '@')
			return (k);

		if (pv == '|')
		{
			count = charrep_count(inputmsg, 0);
			if (count == 0 || count > 1)
				return (k);
		}
	}

	if (*inputmsg == '@')
	{
		if (pv == ';' || pv == '|')
			return (k);

		if (pv == '@')
		{
			count = charrep_count(input, 0);
			if (count == 0 || count > 1)
				return (k);
		}
	}

	return (error_looks(inputmsg + 1, k + 1, *inputmsg));
}

/**
 * firstchar_find - finds index of the first char
 *
 * @input: input string
 * @r: index
 * Return: 1 if there is an error. 0 in other case.
 */

int firstchar_find(char *input, int *r)
{
	for (*r = 0; input[*r]; *r += 1)
	{
		if (input[*r] == ' ' || input[*r] == '\t')
			continue;

		if (input[*r] == ';' || input[*r] == '|' || input[r] == '@')
			return (-1);

		break;
	}

	return (0);
}

/**
 * shows_error - prints when a syntax error encounted
 *
 * @facts: data structure
 * @inputmsg: input string
 * @i: index of the error
 * @bool: to control msg error encountered
 * Return: no return in this
 */

void shows_error(Data *facts, char *inputmsg, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (inputmsg[i] == ';')
	{
		if (bool == 0)
			msg = (inputmsg[i + 1] == ';' ? ";;" : ";");
		else
			msg = (inputmsg[i - 1] == ';' ? ";;" : ";");
	}

	if (inputmsg[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (inputmsg[i] == '@')
		msg = (input[i + 1] == '@' ? "@@" : "@");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = my_conv(facts->counter);
	length = _strlen(facts->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, facts->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax error
 * @facts: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */

int check_syntax_error(Data *facts, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = firstchar_find(input, &begin);
	if (f_char == -1)
	{
		shows_error(facts, input, begin, 0);
		return (1);
	}

	i = error_looks(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		shows_error(facts, input, begin + i, 1);
		return (1);
	}

	return (0);
}
