#include "shell.h"

/**
 *main - this is the main source code
 * Description: this is a function that shows the main entry point
 *
 * Return:0 always
 */

int main(void)
{
	char order[125];

	while (1)
{
	shows_prompt();
	read_order(order);
	execute_order(order);
}

return (0);
}
