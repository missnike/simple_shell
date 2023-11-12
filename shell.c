#include "main.h"

/**
* main - program that thats in args and  execute command
* Return: 0 on success
*/

int main(void)
{
	ssize_t len;
	char *line;
	size_t len1 = 0;

	while (1)
	{

	write(STDIN_FILENO, "Cisfun$ ", 8);

	len = getline(&line, &len1, stdin);

	if (len == -1)
	{
		break;
	}

	if (line[len - 1] == '\n')
		line[len - 1] = '\0';

	command(line);
	}

	free(line);
	return (0);
}



/**
  * free_ - program that free allocated space
  * @argstr: argument
  */

void free_(char **argstr)
{
	int j;

	for (j = 0; argstr[j] != NULL; j++)
	{
		free(argstr[j]);
	}
	free(argstr);
}

/**
* commandfork - program that duplicate process
* @argstr: take in argument
*/


void commandfork(char **argstr)
{
	pid_t first = fork();

	if (first == -1)
	{
		perror("error the process fail");
		exit(1);
	}
	if (first == 0)
	{
		_exec(argstr);
		exit(0);
	}
	else
	{
		wait(NULL);
	}

}
