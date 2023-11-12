#include "main.h"
/**
*_envpath - a program that get envnv variable
* @line: an argument
* Return: the path
*/

char *_envpath(const char *line)
{
	int lenght = lenstr(line);
	char **envn = NULL;


	envn =  environ;
	while (*envn != NULL)
	{
	if (strncmp_made(line, *envn, lenght) == 0 && (*envn)[lenght] == '=')
	{
	return (&(*envn)[lenght + 1]);
	}
	envn++;
	}
	return (NULL);
}


/**
 * _exec - a function the execute command
 * @strargs: takes in command
 * Return: void
 */

void _exec(char **strargs)
{
	char *command = NULL;
	char *_strarg = NULL;

	_strarg = strargs[0];
	command = _location(_strarg);

	if (execve(command, strargs, NULL) == -1)
	{
		perror("command not found");
		exit(1);
	}
}
