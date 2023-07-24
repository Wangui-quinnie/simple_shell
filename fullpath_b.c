#include "shell.h"

/**
  **getFullPathBuffer - gets the full path buffer for the command
  *@av: a pointer to an array of pointers to characters
  *@PATH: value of the PATH environment variable
  *@copy: copy of the PATH environment variable for processing
  *Return: The full path to the executable command
  */
char *getFullPathBuffer(char **av, char *PATH, char *copy)
{
	char *tok = NULL, *fullPathBuffer = NULL, *concatStr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullPathFlag = 0, z = 0, tokLen = 0;
	struct stat h;

	copy = NULL;
	copy = duplicateString(PATH);
	PATHcount = splitPath(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatStr = concatenateString(tmp, av, tok);
		if (stat(concatStr, &h) == 0)
		{
			fullPathBuffer = concatStr;
			fullPathFlag = 1;
			break;
		}
		if (z < PATHcount - 2)
		{
			tokLen = getStringLength(tok);
			if (tok[tokLen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					fullPathBuffer = av[0];
					fullPathFlag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullPathFlag == 0)
		fullPathBuffer = av[0];
	free(copy);
	return (fullPathBuffer);
}
