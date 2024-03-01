#include "shell.h"

/**
 * gets_leng - Get the lenght of a numbe in the func.
 * @r: type int number.
 * Return: Lenght of a number.
 */
int gets_leng(int r)
{
	unsigned int r1;
	int lenght = 1;

	if (r < 0)
	{
		lenght++;
		r1 = r * -1;
	}
	else
	{
		r1 = r;
	}
	while (r1 > 9)
	{
		lenght++;
		r1 = r1 / 10;
	}

	return (lenght);
}

/**
 * my_conv - function converts int to string.
 * @r: type int number
 * Return: String.
 */
char *my_conv(int r)
{
	unsigned int r1;
	int lenght = gets_leng(r);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (r < 0)
	{
		r1 = r * -1;
		buffer[0] = '-';
	}
	else
	{
		r1 = r;
	}

	lenght--;
	do {
		*(buffer + lenght) = (r1 % 10) + '0';
		r1 = r1 / 10;
		lenght--;
	}
	while (1 > 0)
		;
	return (buffer);
}

/**
 * rkm_atoi - converts a string to an integer in my prog
 * @q: input string.
 * Return: integer.
 */
int rkm_atoi(char *q)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(q + count) != '\0')
	{
		if (size > 0 && (*(q + count) < '0' || *(q + count) > '9'))
			break;

		if (*(q + count) == '-')
			pn *= -1;

		if ((*(q + count) >= '0') && (*(q + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(q + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
