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
	int interactive = isatty(STDIN_FILENO), ret_status = 0;

	do {
		if (interactive == 1)
		{
			printf("$ ");
		}
		bufsize = getline(&lineptr, &n, stdin);
		if (bufsize == -1)
		{
			free(lineptr);
			return (ret_status);
		}
		args = tok_line(lineptr);
		if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
		{
			free_grid(args);
			free(lineptr);
			exit(ret_status);
		}
		status = exec(args);
		if (status != 1)
			ret_status = 2;
		free(args);
		if (interactive == 0 && bufsize == -1)
		{
			free(lineptr);
			exit(ret_status);
		}
	} while (status);

	return (ret_status);
}
