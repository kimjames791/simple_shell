#include "shell.h"

/**
* read_order - reads all the user input commands
* of the shell 
* @order: inputs all user commands
* Return: 0 on success otherwise (-1) on failure .
*/

void read_order(char *order)
{
      if (fgets(order, 125, stdin) == NULL) 
      {
        if (feof(stdin))
	{
            rkmprint_func("\n");
            exit(EXIT_SUCCESS);
        } else
	{
            perror("fgets");
            exit(EXIT_FAILURE);
        }
      }
            order[strcspn(order, "\n")] = '\0';
}
