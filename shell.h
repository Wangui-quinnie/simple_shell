#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

char *getEnv(const char *name);
int printEnv(void);
void printString(char *str);
int printChar(char c);
char *fillMemory(char *s, char b, unsigned int n);
int compareStrings(const char *s1, const char *s2);
char *concatStrings(char *dest, char *src);
int getStringLength(char *s);
char *duplicateString(char *str);
int splitString(char *str);
int splitPath(char *str);
int comparePathString(const char *s1, const char *s2);
char *concatenateString(char *tmp, char **av, char *tok);
char **tokenizeInput(char *buffer);
int checkBuiltins(char **av, char *buffer, int exitStatus);
int forkProcess(char **av, char *buffer, char *fullPathBuffer);
int showPrompt(void);
char *readInput(void);
char *getFullPathBuffer(char **av, char *PATH, char *copy);

#endif

