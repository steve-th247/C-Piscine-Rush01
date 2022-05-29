#include "bit_funcs.h"

int	is_solved(short int solu_grid[][4])
{
	int	row_ind;
	int col_ind;

	row_ind = 0;
	col_ind = 0;
	while (row_ind < 4)
	{
		while (col_ind < 4)
		{
			if (solu_grid[row_ind][col_ind] == 0)
				return (0);
			col_ind++;
		}
		row_ind++;
	}
	return (1);
}

int	is_unsolvable(short int possi_grid[][4])
{
	int	row_ind;
	int col_ind;

	row_ind = 0;
	col_ind = 0;
	while (row_ind < 4)
	{
		while (col_ind < 4)
		{
			if (count_bits(possi_grid[row_ind][col_ind]) == 0)
				return (1);
			col_ind++;
		}
		row_ind++;
	}
	return (0);
}