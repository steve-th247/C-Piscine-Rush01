#include "edge_rules.h"

void	apply_edge_rules(short int solu_grid[][4], short int *vpts)
{
	apply_edge_rules1(solu_grid, vpts);
	apply_edge_rules4(solu_grid, vpts);
}

void	apply_edge_rules1(short int solu_grid[][4], short int *vpts)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (vpts[i] == 1)
		{
			if (i >= 0 && i <= 3)
				solu_grid[0][i] = 4;
			else if (i >= 4 && i <= 7)
				solu_grid[3][i - 3] = 4;
			else if (i >= 8 && i <= 11)
				solu_grid[i - 7][0] = 4;
			else if (i >= 12 && i <= 15)
				solu_grid[i - 11][3] = 4;
		}
		i++;
	}
}

void	apply_edge_rules4(short int solu_grid[][4], short int *vpts)
{
	int 	i;

	i = 0;
	while (i < 16)
	{
		if (vpts[i] == 4)
		{
			if (i >= 0 && i <= 3)
				change_col_rules4(solu_grid, i, 1);
			else if (i >= 4 && i <= 7)
				change_col_rules4(solu_grid, i - 3, -1);
			else if (i >= 8 && i <= 11)
				change_row_rules4(solu_grid, i - 7, 1);
			else if (i >= 12 && i <= 15)
				change_row_rules4(solu_grid, i - 11, -1);
		}
		i++;
	}
}

void	change_col_rules4(short int solu_grid[][4], int col_num, int mode)
{
	int	ind;

	ind = 0;
	while (ind < 4)
	{
		if (mode == 1)
			solu_grid[ind][col_num] = ind + 1;
		else
			solu_grid[3 - ind][col_num] = ind + 1;
		ind++;
	}
}

void	change_row_rules4(short int solu_grid[][4], int row_num, int mode)
{
	int	ind;

	ind = 0;
	while (ind < 4)
	{
		if (mode == 1)
			solu_grid[row_num][ind] = ind + 1;
		else
			solu_grid[row_num][3 - ind] = ind + 1;
		ind++;
	}
}