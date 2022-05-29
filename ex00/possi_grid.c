#include "possi_grid.h"

void	update_possi_grid(short int solu_grid[][4], short int possi_grid[][4])
{
	int	row_ind;
	int	col_ind;

	row_ind = 0;
	col_ind = 0;
	while (row_ind < 4)
	{
		while (col_ind < 4)
		{
			if (solu_grid[row_ind][col_ind] != 0)
				write_change_to_possi_grid(possi_grid, row_ind, col_ind, solu_grid[row_ind][col_ind]);
			col_ind++;
		}
		row_ind++;
	}
}

void	write_change_to_possi_grid(short int possi_grid[][4], int row_ind, int col_ind, short int val)
{
	short int	bitmask;
	int 		ind;

	ind = 0;
	while (ind < 4)
	{
		bitmask = ~(1 << (val - 1));
		possi_grid[row_ind][ind] = possi_grid[row_ind][ind] & bitmask;
		possi_grid[ind][col_ind] = possi_grid[ind][col_ind] & bitmask;
		possi_grid[row_ind][col_ind] = ~bitmask;
		ind++;
	}
}