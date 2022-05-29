#include "info_first_filled.h"
#include "info_first_visible.h"

int	get_index_first_filled(short int solu_grid[][4], int vpts_ind)
{
	if (vpts_ind >= 0 && vpts_ind <= 7)
		return (get_index_first_filled_col(solu_grid, vpts_ind));
	else if (vpts_ind >= 8 && vpts_ind <= 15)
		return (get_index_first_filled_row(solu_grid, vpts_ind));
	else
		return (-1);
}

int	get_index_first_filled_col(short int solu_grid[][4], int vpts_ind)
{
	int row_ind;
	int col_ind;
	int	dir;

	col_ind = vpts_ind % 4;
	if (vpts_ind <= 3)
		dir = 1;
	else
		dir = -1;
	if (dir > 1)
		row_ind = 0;
	else
		row_ind = 3;
	while (row_ind >= 0 && row_ind <= 3)
	{
		if (solu_grid[row_ind][col_ind] != 0)
			return (row_ind);
		row_ind += dir;
	}
	return (-1);
}

int	get_index_first_filled_row(short int solu_grid[][4], int vpts_ind)
{
	int row_ind;
	int col_ind;
	int	dir;

	row_ind = vpts_ind % 4;
	if (vpts_ind <= 11)
		dir = 1;
	else
		dir = -1;
	if (dir > 1)
		col_ind = 0;
	else
		col_ind = 3;
	while (col_ind >= 0 && col_ind <= 3)
	{
		if (solu_grid[row_ind][col_ind] != 0)
			return (col_ind);
		col_ind += dir;
	}
	return (-1);
}