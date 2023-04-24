#include "main.h"
/**
 * exec - Executes the command given to the shell
 * @args: Arguments passed to said command
 *
 * Return: 1 on success
*/

int exec(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Insertar error");
		}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Fork error");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

return (1);
}
