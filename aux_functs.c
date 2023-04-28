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
