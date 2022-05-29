#include "vpts_rules5.h"
#include "info_hidden.h"
#include "info_first_filled.h"
#include "bit_funcs.h"
#include "possi_grid.h"

void	apply_vpts_rule5(short int solu_grid[][4], short int possi_grid[][4], short int *vpts)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i <= 3)
			apply_vpts_rule5_colup(solu_grid, possi_grid, vpts, vpts[i]);
		else if (i >= 4 && i <= 7)
			apply_vpts_rule5_coldown(solu_grid, possi_grid, vpts, vpts[i]);
		else if (i >= 8 && i <= 11)
			apply_vpts_rule5_rowleft(solu_grid, possi_grid, vpts, vpts[i]);
		else if (i >= 12 && i <= 15)
			apply_vpts_rule5_rowright(solu_grid, possi_grid, vpts, vpts[i]);
		i++;
	}
}

void	apply_vpts_rule5_colup(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind)
{
	int			row_ind;
	int			col_ind;
	short int	sol_val;
	int			num_hidden;

	row_ind = 0;
	col_ind = vpts_ind % 4;
	num_hidden = get_hidden_num(solu_grid, vpts_ind);
	if (get_index_first_filled(solu_grid, vpts_ind) == (4 - vpts[vpts_ind] - num_hidden + 1))
	{
		sol_val = binary_to_ind(possi_grid[row_ind][col_ind]) + 1;
		solu_grid[row_ind][col_ind] = sol_val;
		update_possi_grid(solu_grid, possi_grid);
	}
}

void	apply_vpts_rule5_coldown(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind)
{
	int			row_ind;
	int			col_ind;
	short int	sol_val;
	int			num_hidden;

	row_ind = 3;
	col_ind = vpts_ind % 4;
	num_hidden = get_hidden_num(solu_grid, vpts_ind);
	if (get_index_first_filled(solu_grid, vpts_ind) == (4 - vpts[vpts_ind] - num_hidden + 1))
	{
		sol_val = binary_to_ind(possi_grid[row_ind][col_ind]) + 1;
		solu_grid[row_ind][col_ind] = sol_val;
		update_possi_grid(solu_grid, possi_grid);
	}
}

void	apply_vpts_rule5_rowleft(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind)
{
	int			row_ind;
	int			col_ind;
	short int	sol_val;
	int			num_hidden;

	row_ind = vpts_ind % 4;
	col_ind = 0;
	num_hidden = get_hidden_num(solu_grid, vpts_ind);
	if (get_index_first_filled(solu_grid, vpts_ind) == (4 - vpts[vpts_ind] - num_hidden + 1))
	{
		sol_val = binary_to_ind(possi_grid[row_ind][col_ind]) + 1;
		solu_grid[row_ind][col_ind] = sol_val;
		update_possi_grid(solu_grid, possi_grid);
	}
}

void	apply_vpts_rule5_rowright(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind)
{
	int			row_ind;
	int			col_ind;
	short int	sol_val;
	int			num_hidden;

	row_ind = vpts_ind % 4;
	col_ind = 3;
	num_hidden = get_hidden_num(solu_grid, vpts_ind);
	if (get_index_first_filled(solu_grid, vpts_ind) == (4 - vpts[vpts_ind] - num_hidden + 1))
	{
		sol_val = binary_to_ind(possi_grid[row_ind][col_ind]) + 1;
		solu_grid[row_ind][col_ind] = sol_val;
		update_possi_grid(solu_grid, possi_grid);
	}
}