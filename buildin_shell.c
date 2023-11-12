#include "main.h"

/**
  * command - A program that handle command pass to shell
  * @strline: getline argument pass for execute
  */

void command(char *strline)
	{
	char **argsline = NULL, *commmandpath = NULL;
	int status;

	if (strline[0] != '\0')
	{
		argsline = split_str(strline, " \n");
		if (!argsline)
		{
			perror("Error tokenizing command");
			free_(argsline);
			return;
		}

		if (cmpstr(strline, "exit") == 0)
		{
		if (argsline[1])
		{
			status = atoi(argsline[1]);
			free_(argsline);
			exit(status);
		}
		else
		{
			free_(argsline);
			exit(0);
		}
		}

		if (cmpstr(strline, "env") == 0)
		{	execute_env();
			free_(argsline);
			return;
		}
		commmandpath = _location(argsline[0]);
		if (commmandpath == NULL)
		{	perror("Command not found");
			free_(argsline);
		}
		else
		{	commandfork(argsline);
			free_(argsline);
		}
	}
}

/**
 * execute_env - program that execute the ennv variable
 * Return: nothing
 *
 */

void execute_env(void)
{
	char **envn = environ;

	while (*envn)
	{
		write(STDOUT_FILENO, *envn, lenstr(*envn));
		write(STDOUT_FILENO, "\n", 1);
		envn++;
	}
}

/**
 * _location - a program the describe to the path
 * @args_command: agument
 * Return: returns the path location
 */

char *_location(char *args_command)
{
	int num1, num2;
	char *pathenv, *pathcopy = NULL, *store, *pathfiles = NULL;
	struct stat str;

	pathenv = _envpath("PATH");
	if (pathenv)
	{
		pathcopy = _strdup(pathenv);
		if (!pathcopy)
			return (NULL);
		num1 = lenstr(args_command);
		store = strtok(pathcopy, ":");
		while (store != NULL)
		{
			num2 = lenstr(store);
			pathfiles = malloc(num1 + num2 + 2);
			cpystr(pathfiles, store);
			catstr(pathfiles, "/");
			catstr(pathfiles, args_command);
			catstr(pathfiles, "\0");
			if (stat(pathfiles, &str) == 0)
			{
				free(pathcopy);
				return (pathfiles);
			}
			else
			{
				free(pathfiles);
				store = strtok(NULL, ":");
			}
		}
		free(pathcopy);
		if (stat(args_command, &str) == 0)
			return (args_command);
		return (NULL);
	}
	return (NULL);
}
