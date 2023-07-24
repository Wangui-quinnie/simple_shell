#include "shell.h"

/**
*printEnv - Entry Point
*desc: prints the current environment
* Return: 0
*/
int printEnv(void)
{
int x;

for (x = 0; environ[x]; x++)
printString(environ[x]);
return (0);
}
