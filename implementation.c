#include "shell.h"



/**
 * _directory -A function that Change the current working directory.
 * @path_value: The path_value to the directory to change to.
 * If the path_value is "-", the previous working directory is used.
 */

void _directory(char *path_value)
{
	char *new_direct;
	char *old_direct = getenv("PWD");

	if (path_value == NULL || strlen(path_value) == 0)
	{
		path_value = getenv("HOME");
	}
	else if (strcmp(path_value, "-") == 0)
	{
		path_value = getenv("OLDPWD");
	}
	if (chdir(path_value) != 0)
	{
		perror("chdir");
		return;
	}
	new_direct = getcwd(NULL, 0);
	if (new_direct != NULL)
	{
		setenv("OLDPWD", old_direct, 1);
		setenv("PWD", new_direct, 1);
		free(new_direct);
	}
	else
	{
		perror("getcwd");
	}
}




/**
 * get_env - A function that Get environment variable.
 * @var: The name of the environment variable.
 * Return: A pointer to the result_ of the environment variable if found,
 * otherwise NULL.
 */

char *get_env(const char *var)
{
	int i, name_;
	char **env;
	char *result_;

	if (!var)
		return (NULL);
	nv = environ;

	for (i = 0; env[i]; i++)
	{
		for (name_ = 0; env[i][name_] != '='; name_++)
			;
		if (_strncmp(var, env[i], name_) == 0)
		{
			result_ = &env[i][name_ + 1];
			return (result_);
		}
	}
	return (NULL);
}


/**
 * find_full_path - A function that Find the full path_value of a command.
 * @cmd_value: The command for which to determine the full path_value.
 * Return: A dynamically allocated string containing the full path_value of the
 */
char *find_full_path(char *cmd_value)
{
	size_t path_len, full_path_len, cmd_len;
	char *path_value, *full_path, *path_env = get_env("PATH");

	if (path_env == NULL)
	{
		return (NULL);
	}
	path_value = strtok(path_env, ":");
	while (path_value != NULL)
	{
		path_len = _strlen(path_value);
		cmd_len = _strlen(cmd_value);
		full_path_len = path_len + cmd_len + 2;
		full_path = malloc(full_path_len);
		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		_strcpy(full_path, path_value);
		full_path[path_len] = '/';
		_strcpy(full_path + path_len + 1, cmd_value);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		path_value = strtok(NULL, ":");
	}
	return (NULL);
}
