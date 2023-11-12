#include "main.h"

/**
 * split_str- program the split string into two
 * @str: string to be tokenalized
 * @delim: slipting params
 * Return: returns the slipted string
 */
char **split_str(char *str, const char *delim)
{
	int counttok = 0, i;
	char *tokcpy = _strdup(str);
	char **args = NULL;
	char *argtok;

	argtok = strtok(str, delim);
	while (argtok != NULL)
	{
		counttok++;
		argtok = strtok(NULL, delim);
	}

	args = (char **)malloc(sizeof(char *) *  (counttok + 1));
	if (args == NULL)
	{
		perror("allocated memory failed");
		exit(98);
	}

	argtok = strtok(tokcpy, delim);
	for (i = 0; argtok != NULL; i++)
	{
		args[i] = _strdup(argtok);
		argtok = strtok(NULL, delim);
	}
	args[counttok] = NULL;
	free(tokcpy);
	return (args);
}
