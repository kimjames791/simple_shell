#include "shell.h"

**
* @read_order - this is to command the shell to input 
* the commands
*
* Return - (0) on success otherwise (-1) on failure .
* /

char *read_order(void)
{
      if (fgets(command, size, stdin) == NULL) {
        if (feof(stdin)) {
            rkmprint_func("\n");
            exit(EXIT_SUCCESS);
        } else {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
    }
    command[strcspn(command, "\n")] = '\0'; // Remove newline
}
