#include "shell.h"

/**
* splitString - Entry Point
* desc: splits a string
* @str: pointer to string
* Return: wordcount
*/
int splitString(char *str)
{
int x, searchflag = 1, wordcount = 0;

for (x = 0; str[x]; x++)
{
if (str[x] != ' ' && searchflag == 1)
{
wordcount += 1;
searchflag = 0;
}
if (str[x + 1] == ' ')
searchflag = 1;
}
return (wordcount);
}

/**
* splitPath - Entry Point
* desc: splits PATH
* @str: pointer
* Return: wordcount
*/
int splitPath(char *str)
{
int x, searchflag = 1, wordcount = 0;

for (x = 0; str[x]; x++)
{
if (str[x] != ':' && searchflag == 1)
{
wordcount += 1;
searchflag = 0;
}
if (str[x + 1] == ':')
{
searchflag = 1;
}
}
return (wordcount);
}

/**
* comparePathString - Entry Point
* desc: compares PATH strings
* @s1: P1
* @s2: P2
* Return: 0 and -1
*/
int comparePathString(const char *s1, const char *s2)
{
int x;

for (x = 0; s2[x] != '='; x++)
{
if (s1[x] != s2[x])
return (-1);
}
return (0);
}

/**
* concatenateString - Entry Point
*desc: concatenates two strings
*@tmp:P1
*@av:P2
*@tok:P3
* Return:tmp
*/
char *concatenateString(char *tmp, char **av, char *tok)
{
int len = 0;

fillMemory(tmp, 0, 256);
len = getStringLength(tok) + getStringLength(av[0]) + 2;
concatStrings(tmp, tok);
concatStrings(tmp, "/");
concatStrings(tmp, av[0]);
tmp[len - 1] = '\0';
return (tmp);
}
