#include <unistd.h>
#include "io_funcs.h"
#include "info_solve.h"
#include "edge_rules.h"
#include "sudoku_rule.h"
#include "elimination_rule.h"
#include "vpts_rules_main.h"

void	initialize_grids(short int solu_grid[][4], short int possi_grid[][4]);

int	main(int argc, char **argv)
{
	short int	solu_grid[4][4];
	short int	possi_grid[4][4];
	short int	vpts[16];

	if ((argc != 2) || !is_input_valid(argv[1]))
	{ 
		write(1, "Error\n", 6);
		return (-1);
	}
	str_split_to_int(vpts, argv[1]);
	initialize_grids(solu_grid, possi_grid);
	apply_edge_rules(solu_grid, vpts);
	while (!is_solved(solu_grid))
	{
		apply_sudoku_rule(solu_grid, possi_grid);
		apply_elimination_rule(solu_grid, possi_grid);
		apply_vpts_rules(solu_grid, possi_grid, vpts);
		if (is_unsolvable(solu_grid))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
	}
	write_sol_to_stdout(solu_grid);
	return (0);
}

void	initialize_grids(short int solu_grid[][4], short int possi_grid[][4])
{
	int	ind_row;
	int	ind_col;

	ind_row = 0;
	ind_col = 0;
	while (ind_row < 4)
	{
		while (ind_col < 4)
		{
			solu_grid[ind_row][ind_col] = 0;
			possi_grid[ind_row][ind_col] = 0b1111;
			
		}
	}
}






