#include "main.h"
/**
 * nbr_spaces - return the number of string
 * using the number of space
 * @str: string to check
 * Return: int
 */
unsigned int str_counter(char *str)
{
	int i, cmpt = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			cmpt++;
	}
	return (cmpt + 1);
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
	int nbr_string = str_counter(str);
	char **tokens = malloc(sizeof(char *) * nbr_string);
	char *token;

	if (tokens == NULL)
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
