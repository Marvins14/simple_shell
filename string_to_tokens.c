#include "main.h"
/**
 * nbr_spaces - return the number of string
 * using the number of space
 * @s: string to check
 * Return: int
 */
unsigned int nbr_spaces(char *s)
{
	int i, cmpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			cmpt++;
	}
	return (cmpt);
}


/**
 * string_to_tokens - splits strings of different
 * words to tokens
 * @str: string pointer
 * Return: tokens
 */
char **string_to_tokens(char *str)
{
	int i = 0;
	const char separator[] = " ";
	int spaces = nbr_spaces(str);
	char **tokens = malloc(sizeof(char *) * (spaces + 1))
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(str, separator);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
