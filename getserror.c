#include "shell.h"

/**
 * get_error - a function that gets error and prints it out
 *@facts: user input
 *@error_code: error displayed
 */

void get_error(Data *facts, int error_code)
{
	switch (error_code)
	{
		case 1:
			rkm_printfunc("Error: Invalid argument\n");
			break;
		case 2:
			rkm_printfunc("Error: Maximum value exceeded\n");
			break;
		default:
			rkm_printfunc("Unknown error\n");
			break;
	}
}
