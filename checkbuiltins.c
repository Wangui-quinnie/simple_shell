#include "shell.h"

/**
  *checkBuiltins - Check if the command is a built-in Command
  *@av: the array of command arguments
  *@buffer: the buffer containing the command
  *@exitStatus: the exit status to be used for the "exit' command
  *Return: 1, 0
  */

int checkBuiltins(char **av, char *buffer, int exitStatus)
{
	int x;

	if (compareStrings(av[0], "env") == 0)
	{
		printEnv();
		for (x = 0; av[x]; x++)
			free(av[x]);
		free(av);
		free(buffer);
		return (1);
	}
	else
		if (compareStrings(av[0], "exit") == 0)
		{
			for (x = 0; av[x]; x++)
				free(av[x]);
			free(av);
			free(buffer);
			exit(exitStatus);
		}
		else
			return (0);
}
