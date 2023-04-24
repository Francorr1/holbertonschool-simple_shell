#include "main.h"
/*
*
*/

int exec(char **args)
{
	pid_t pid, wpid;
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
	do
	{
		wpid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (1);
}