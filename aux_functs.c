#include "main.h"
/**
 * free_grid - Frees a grid from memory
 * @grid: Said grid
*/
void free_grid(char **grid)
{
	int height = 0, i;

	if (!grid)
		return;
	for (i = 0; grid[i]; i++)
		height++;
	for (i = 0; i < height; i++)
		free(grid);
}

/**
 * _strcmp - Compares two strings
 * @s1: First string to be compared
 * @s2: Second string to be compared
 *
 * Return: Difference of characters in their ASCII numeric value or 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
