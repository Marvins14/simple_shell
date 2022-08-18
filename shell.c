#include "main.h"
/**
 * execute - executes the command
 * @cmd: command to run
 * Return: 0 on success, -1 if cmd is exit, 1 on any other error
 */
int execute(char **cmd)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);
	return (0);
}

/**
 * main - main simple shell
 * @argc: number of arguments
 * @argv: list of command line arguments
 * Return: Always 0, -1 on error.
 */
int main(int argc, char **argv)
{
	int response;
	size_t bufsize = BUFSIZ;
	char *buffer;
	char **tokens;

	if (argc == 2)
	{
		/* handle cases where there's no arguments only the command */
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	do {
		_puts("#cisfun$ ");

		getline(&buffer, &bufsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		tokens = string_to_tokens(buffer);
		response = execute(tokens);
	} while (response != -1);

	return (0);
}
