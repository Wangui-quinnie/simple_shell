#include "shell.h"
/**
  *forkProcess - create a child process
  *@av: pointer to an array of pointers to characters
  *@buffer: the buffer containing the commands
  *@fullPathBuffer: the buffer containing the full path the executable
  *Return: the exit status of the executed command
  */

int forkProcess(char **av, char *buffer, char *fullPathBuffer)
{
	int x, status, result, exitStatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(fullPathBuffer, av, environ);
		if (result == -1)
		{
			perror(av[0]);
			for (x = 0; av[x]; x++)
				free(av[x]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitStatus = WEXITSTATUS(status);
	}
	for (x = 0; av[x]; x++)
		free(av[x]);
	free(av);
	free(buffer);
	return (exitStatus);
}
