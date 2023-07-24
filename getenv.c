#include "shell.h"

/**
  *getEnv - Gets the value of an environment variable
  *@name: name of the environment variable to retrieve
  *Return: value of the specified environment variable or NULL if not
  *found
  */

char *getEnv(const char *name)
{
	int x, result;

	for (x = 0; environ[x]; x++)
	{
		result = comparePathString(name, environ[x]);
		if (result == 0)
		{
			return (environ[x]);
		}

	}
	return (NULL);
}
