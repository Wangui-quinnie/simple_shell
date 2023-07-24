#include "shell.h"

/**
 * printChar - Print a character to the standard output.
 * @c: The character to be printed
 * Return: number of bytes on success, -1 else
 */
int printChar(char c)
{
return (write(1, &c, 1));
}
