#include "main.h"
/**
 * tok_line - Separates the input into tokens
 * @line: The input line
 *
 * Return: Said tokens
*/

char **tok_line(char *line)
{
	int bufsize = BUFFER_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
{
	fprintf(stderr, "insertar error\n");
	exit(EXIT_FAILURE);
}

token = strtok(line, TOK_DELIMITER);
while (token != NULL)
{
	tokens[position] = token;
	position++;

	if (position >= bufsize)
	{
		bufsize += BUFFER_SIZE;
		tokens = realloc(tokens, bufsize * sizeof(char *));

if (!tokens)
{
	fprintf(stderr, "insertar error\n");
			exit(EXIT_FAILURE);
}
}
token = strtok(NULL, TOK_DELIMITER);
}
tokens[position] = NULL;
return (tokens);
}
