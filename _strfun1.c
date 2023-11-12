#include "main.h"

/**
 * lenstr - program that returns the lenght of a string
 * @str: argument passed
 * Return: the length
 */

int lenstr(const char *str)
{
	int lencount = 0;

	while (str[lencount] != '\0')
	{
		lencount++;
	}

	return (lencount);
}

/**
 * cmpstr - proram that performs comparison of two strings
 * @st1: first string
 * @st2: second string
 *
 * Return: its returns negative if s1 < s2
 */

int cmpstr(const char *st1, const char *st2)
{
	int i;

	for (i = 0; st1[i] || st2[i]; i++)
	{
		if (st1[i] != st2[i])
		{
			return (st1[i] - st2[i]);
		}
	}
	return (0);
}

/**
 * catstr - A program that  concatenates two strings
 * @str: the string destination
 * @src: the source
 *
 * Return: a pointer to destination
 */

char *catstr(char *str, char *src)
{
	char *len = str;

	while (*str)
		str++;
	while (*src)
		*str++ = *src++;
	*str = *src;
	return (len);
}
