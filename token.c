#include "shell.h"

/**
*tokenizeInput - Entry Point
*desc: splits or tokenizes user input
*@buffer: pointer
*
* Return: pointer
*/
char **tokenizeInput(char *buffer)
{
char *token = NULL;
int x = 0, wordcount = 0;
char *delimiter = " \n";
char **av = NULL;

wordcount = splitString(buffer);
if (!wordcount)
return NULL;
av = malloc((wordcount + 1) * sizeof(char *));
if (av == NULL)
exit(1);
token = strtok(buffer, delimiter);
while (token != NULL)
{
av[x] = duplicateString(token);
token = strtok(NULL, delimiter);
x++;
}
av[x] = NULL;
return av;
}
