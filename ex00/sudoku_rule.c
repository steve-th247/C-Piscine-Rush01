#include "sudoku_rule.h"
#include "possi_grid.h"
#include "bit_funcs.h"

void	apply_sudoku_rule(short int solu_grid[][4], short int possi_grid[][4])
{
	short int	val;

	val = 0;
	while (++val <= 4)
	{
		apply_sudoku_rule_val(solu_grid, val);
	}
	update_possi_grid(solu_grid, possi_grid);
}

void	apply_sudoku_rule_val(short int solu_grid[][4], short int val)
{
	short int	row_has_num;
	short int	col_has_num;
	short int	row_ind;
	short int	col_ind;

	row_has_num = 0;
	col_has_num = 0;
	row_ind = -1;
	col_ind = -1;
	while (++val <= 4)
	{
		while (++row_ind < 4)
		{
			while (++col_ind < 4)
			{
				if (solu_grid[row_ind][col_ind] == val)
				{
					row_has_num = row_has_num | (1 << (4 - row_ind));
					col_has_num = col_has_num | (1 << (4 - col_ind));
				}
			}
		}
	}
	write_sudoku_change(solu_grid, val, row_has_num, col_has_num);
}

void	write_sudoku_change(short int solu_grid[][4], short int val
			, short int row_has_num, short int col_has_num)
{
	short int	row_num;
	short int	col_num;
	short int	*ptr;

	row_num = (~row_has_num) & 0b1111;
	col_num = (~col_has_num) & 0b1111;
	if ((count_bits(row_num) == 1) && (count_bits(col_num) == 1))
	{
		ptr = &solu_grid[binary_to_ind(row_num)][binary_to_ind(col_num)];
		*ptr = val;
	}
}