#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
char *command;
for (;;)
{
printf("$ ");
size_t size = getline(&command, 0, stdin);
if (size == 0)
{
break;
}
if (strcmp(command, "cd") == 0)
{
char *directory = getline(&command, 0, stdin);
if (size == 0)
{
continue;
}
if (chdir(directory) != 0)
{
perror("cd");
continue;
}
}
else if (strcmp(command, "exit") == 0)
{
break;
}
else
{
int status = system(command);
if (status != 0)
{
perror(command);
}
}
}
return (0);
}
