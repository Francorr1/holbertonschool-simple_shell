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
	char *lineptr;
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
			return (-1);
		}
		args = tok_line(lineptr);
		if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
		{
			free_grid(args);
			exit(2);
		}
		status = exec(args);
		free_grid(args);
	} while (status);
	
	free(lineptr);
	free_grid(args);

	return (EXIT_SUCCESS);
}
