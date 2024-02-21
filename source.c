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
	void shows_prompt(void);
	reads_order((order) sizeof(order));
	execute_order(order);
}

return (0);

}

