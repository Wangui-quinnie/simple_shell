#include "shell.h"

/**
*compareStrings - Entry Point
* desc: compares two strings
*@s1:P1
*@s2:P2
* Return: 0 if strings are equal
*/
int compareStrings(const char *s1, const char *s2)
{
while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 - *s2);
}

/**
* concatStrings - Entry Point
* desc: concatenates two srings
*@dest: P1
*@src: P2
* Return: void
*/
char *concatStrings(char *dest, char *src)
{
int x, y;

for (x = 0; dest[x] != '\0'; x++)
;
for (y = 0; src[y] != '\0'; y++, x++)
dest[x] = src[y];
dest[x] = '\0';
return (dest);
}

/**
* getStringLength - Entry Point
* desc: gets string length
* @s: pointer to string
* Return: length of string input
*/
int getStringLength(char *s)
{
int x;

for (x = 0; s[x]; x++)
;
return (x);
}

/**
* duplicateString - entry Point
* desc: duplicates a string
* @str: Pointer
* Return: void
*/
char *duplicateString(char *str)
{
int x;
char *dest_str = NULL;
if (str == NULL)
return (NULL);
for (x = 0; str[x] != '\0'; x++)
;
dest_str = malloc(sizeof(char) * (x + 1));
if (dest_str == NULL)
return (NULL);
for (x = 0; str[x] != '\0'; x++)
{
dest_str[x] = str[x];
}
dest_str[x] = '\0';
return (dest_str);
}
