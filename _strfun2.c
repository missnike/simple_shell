#include "main.h"

/**
 * strncmp_made - A program that takes three argument and compare
 * @st1: first args
 * @st2: second args
 * @i: third arg an int
 * Return: 0 on succes
 */

int strncmp_made(const char *st1, const char *st2, size_t i)
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
 * _strdup - program that duplicatin string
 * @str: sring to be duplicated
 * Return: duplicated string
 */


char *_strdup(const char *str)
{
	size_t strlen1;
	char *new_str1;

	strlen1 = lenstr(str) + 1;
	new_str1 = (char *)malloc(strlen1);
	if (new_str1 == NULL)
	{
		perror("Error on allocation");
		exit(98);
	}
	cpystr(new_str1, str);
	return (new_str1);
}


/**
 * cpystr - program that copies a string
 * @str: the the string destination
 * @src: the source
 *
 * Return: distination
 */

char *cpystr(char *str, const char *src)
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
