#include "shell.h"
/**
* main - Entry Point
* desc: starts the shell
* Return: -1, 0
*/
int main(void)
{
char *fullPathBuffer = NULL;
char *copy = NULL;
char *buffer = NULL;
char *PATH = NULL;
char **av = NULL;
int exitStatus = 0;

signal(SIGINT, SIG_IGN);
PATH = getEnv("PATH");
if (PATH == NULL)
return (-1);

while (1)
{
av = NULL;
showPrompt();
buffer = readInput();
if (*buffer != '\0')
{
av = tokenizeInput(buffer);
if (av == NULL)
{
free(buffer);
continue;
}
fullPathBuffer = getFullPathBuffer(av, PATH, copy);
if (checkBuiltins(av, buffer, exitStatus) != 0)
continue;
exitStatus = forkProcess(av, buffer, fullPathBuffer);
}
else
free(buffer);
}
return (0);
}
