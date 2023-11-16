#include "shell.h"


/**
 * _strcpy - A program that copies a string
 * @str: the the string destination
 * @src: the source
 *
 * Return: distination
 */

char *_strcpy(char *str, const char *src)
{
	int i = 0;

	if (str == src || src == 0)
		return  (str);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/**
 * strncmp - A function that takes three argument and compare
 * @st1: first args
 * @st2: second args
 * @i: third arg an int
 * Return: 0 on succes
 */

int _strncmp(const char *st1, const char *st2, size_t i)
{
	for (; i > 0; i--)
	{
		if (*st1 != *st2)
		{
			return (*st1 - *st2);
		}
		if (*st1 == '\0')
		{
			return (0);
		}
		st1++;
		st2++;
	}
	return (0);
}

/**
 * _strtrim - A function that Trim leading and trailing whitespace
 * @str: The string to trim.
 * Return: A pointer to the trimmed string.
 */
char *_strtrim(char *str)
{
	char *end;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
	{
		str++;
	}

	if (*str == '\0')
	{
		return (str);
	}

	end = str + _strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		end--;
	}
	*(end + 1) = '\0';

	return (str);
}
