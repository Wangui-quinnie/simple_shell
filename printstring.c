#include "shell.h"

/**
 * printString - Prints a string
 * @str: The input string to be printed
 */
void printString(char *str)
{
int x;
for (x = 0; str[x] != '\0'; x++)
printChar(str[x]);
printChar('\n');
}
