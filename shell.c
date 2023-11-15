nclude "shell.h"




/**
 * _prompt -function that Display the shell prompt.
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "CISFUN$ ", 8);
		fflush(stdout);
	}
}



/**
 * main - Entry point of the shell.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	int store;
	char *user_path, *_input = NULL;
	size_t _size = 0;
	ssize_t read_;

	while (1)
	{
		_prompt();
		read_ = my_getline(&_input, &_size, stdin);
		if (read_ == -1)
		{
			free(_input);
			return 0;
		}
		if (_input[read_ - 1] == '\n')
			_input[read_ - 1] = '\0';

		if (_strncmp(_input, "exit", 4) == 0)
		{
			free(_input);
			_input = NULL;
			_size = 0;
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(_strtrim(_input), "env") == 0)
		{
			_environment();
			continue;
		}
		if (_strncmp(_input, "cd", 2) == 0)
		{
			user_path = _strtrim(_input + 2);
			_directory(user_path);
			free(_input);
			_input = NULL;
			_size = 0;
			continue;
		}
		if (read_ > 1)
		{
			store = execute_(_input);
			if (store == -1)
				break;
		}
	}
	free(_input);
	return (0);
}



/**
 * _environment - Print the environment variables.
 * Return:void
 */
void _environment(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
