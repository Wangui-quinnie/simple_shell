#include "shell.h"

/**
  *fillMemory - fills a block of memory
  *@s: pointer to block of memory to be filled
  *@b: value to be used to fill the memory
  *@n: number of bytes to be filled
  *Return: pointer to the start of the filled mem block
  */

char *fillMemory(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}
