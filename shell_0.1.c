#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
char command[MAX_COMMAND_LENGTH];
char prompt[] = "simple_shell> ";

while (1)
{
printf("%s", prompt);

if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n");
break;
}

command[strcspn(command, "\n")] = '\0';

if (strlen(command) == 0)
{
continue;
}

int status = system(command);

if (status == -1)
{
fprintf(stderr, "Error executing the command.\n");
}
else if (status != 0)
{
fprintf(stderr, "Command exited with non-zero status: %d\n", status);
}
}

return (0);
}
