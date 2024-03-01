#include "shell.h"

/**
 * signa_hand - Handles the crtl + c call in prompt in the func
 * @gest: Signal handler
 */
void signa_hand(int gest)
{
	(void)gest;
	write(STDOUT_FILENO, "\n#cisfun$ ", 9);
}
