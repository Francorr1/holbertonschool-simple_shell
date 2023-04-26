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

	do {
		printf("$ ");
		bufsize = getline(&lineptr, &n, stdin);
		if (bufsize == -1)
		{
			return (-1);
		}
		args = tok_line(lineptr);
		status = exec(args);
	} while (status);

	free(lineptr);
	free(args);

	return (EXIT_SUCCESS);
}
