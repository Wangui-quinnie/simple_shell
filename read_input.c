#include "shell.h"

/**
*readInput - Entry Point
*desc - a function that reads user input
*Return: buffer
*/
char *readInput(void)
{
ssize_t readCount = 0;
size_t y = 0;
char *buffer = NULL;
int x = 0;

readCount = getline(&buffer, &y, stdin);
if (readCount == -1)
{
free(buffer);
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
if (buffer[readCount - 1] == '\n' || buffer[readCount - 1] == '\t')
buffer[readCount - 1] = '\0';
for (x = 0; buffer[x]; x++)
{
if (buffer[x] == '#' && buffer[x - 1] == ' ')
{
buffer[x] = '\0';
break;
}
}
return (buffer);
}
