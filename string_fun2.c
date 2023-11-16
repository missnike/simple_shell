#include "shell.h"

/**
 * _strlen - A function that returns the lenght of a string
 * @str: argument passed
 * Return: the length
 */

int _strlen(const char *str)
{
	int lencount = 0;

	while (str[lencount] != '\0')
	{
		lencount++;
	}

	return (lencount);
}

/**
 * _strlen_const - A function Calculates the length of a string.
 * @s: Pointer to the input string.
 *
 * Return: Length of the string.
 */
int _strlen_const(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
/**
 * _strdup -A function that duplicatin string
 * @str: sring to be duplicated
 * Return: duplicated string
 */


char *_strdup(const char *str)
{
	size_t strlen1;
	char *new_str1;

	strlen1 = _strlen(str) + 1;
	new_str1 = (char *)malloc(strlen1);
	if (new_str1 == NULL)
	{
		perror("Error on allocation");
		exit(98);
	}
	_strcpy(new_str1, str);
	return (new_str1);
}



/**
 * _strcat - A  function that  concatenates two strings
 * @str: the string destination
 * @src: the source
 *
 * Return: a pointer to destination
 */

char *_strcat(char *str, char *src)
{
	char *len = str;

	while (*str)
		str++;
	while (*src)
		*str++ = *src++;
	*str = *src;
	return (len);
}
/**
 * _strcmp - A function compare two strings
 * @s1: string value 1
 * @s2: string value 2
 *
 * Return: interger value
 */

int _strcmp(char *s1, char *s2)
{
	int res;

	res = strcmp(s1, s2);

	if (res == 0)
		return (res);

	else if (res < 0)
		return (res);
	else
		return (res);
}
