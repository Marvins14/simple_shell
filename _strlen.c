#include "main.h"
/**
 * _strlen - function that returns the length of string
 * @str: pointer to the string
 * Return: the number of charaters of the string
 */
int _strlen(const char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}
