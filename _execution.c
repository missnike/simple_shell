#include "shell.h"
/**
 * execute_child - A function that Execute
 * a command in a child process with full path.
 * @command: The command to execute.
 * @args: The args for the command.
*/
void execute_child(char *command, char *args[])
{
	char *path = find_full_path(command);

	if (path != NULL)
	{
		if (execve(path, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else if (access(command, X_OK) == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("./hsh");
		_exit(EXIT_FAILURE);
	}
}

/**
 * execute_ - A function that Execute a command with args
 * @command_with_args: The command with its args.
 * Return: 0 on success, -1 on failure.
 */
int execute_(char *command_with_args)
{
	pid_t child_pid;
	int status;
	int arg_count = 0;
	char *token, *args[MAX_INPUT / 2 + 2];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failedd");
		return (-1);
	}
	if (child_pid == 0)
	{

		token = strtok(command_with_args, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execute_child(args[0], args);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * my_getline - A custome custom getline function
 * @line: line buffer
 * @len: length of buffer
 * @stream: stream to read from
 * Return: number of characters read or -1 if fail
 */
ssize_t my_getline(char **line, size_t *len, FILE *stream)
{
	char *getline;
	ssize_t read;

	if (*line == NULL || *len == 0)
	{
		*len = 1024;
		*line = malloc(*len);
		if (*line == NULL)
		{
			return (-1);
		}
	}

	getline = fgets(*line, *len, stream);
	if (getline != NULL)
	{
		read = _strlen(*line);

		if (read > 0 && (*line)[read - 1] == '\n')
		{
			(*line)[read - 1] = '\0';
			read--;
		}
		return (read);
	}
	else
	{
		return (-1);
	}
}
