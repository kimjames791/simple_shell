#include "shell.h"


void rkm_printfunc(const char *inputmsg)
{
write(STDOUT_FILENO, inputmsg, strlen(inputmsg));
}