#include "shell.h"

/**
* showPrompt - Entry Point
* desc: a function that prints a prompt for the user to type a cmd
* Return: 0
*/
int showPrompt(void)
{
char *prompt = "# ";
ssize_t writeCount = 0;

if (isatty(STDIN_FILENO) == 1)
{
writeCount = write(STDOUT_FILENO, prompt, 2);
if (writeCount == -1)
exit(0);
}
return (0);
}
