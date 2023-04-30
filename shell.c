#include "main.h"
/**
 * main - A simple linux shell
 *
 * Return: EXIT_SUCCESS on success
 */

int main(void)
{
	char **args;
	int status;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t bufsize;
	int interactive = isatty(STDIN_FILENO);

	do {
		if (interactive == 1)
		{
			printf("$ ");
		}
		bufsize = getline(&lineptr, &n, stdin);
		if (bufsize == -1)
		{
			free(lineptr);
			return (-1);
		}
		args = tok_line(lineptr);
		if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
		{
			free_grid(args);
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		status = exec(args);
		free(args);
	} while (status);

	if (interactive == 0)
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}

	return (EXIT_SUCCESS);
}
