#include "main.h"
/**
 * exec - Executes the command given to the shell
 * @args: Arguments passed to said command
 *
 * Return: 1 on success, -1 on failure
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
			return (-1);
		}
	}
	else if (pid < 0)
	{
		perror("Fork error");
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status));
	}

return (1);
}
