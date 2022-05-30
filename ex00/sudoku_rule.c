/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_rule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:25:12 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:25:14 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_rule.h"
#include "possi_grid.h"
#include "bit_funcs.h"

static void	sudoku_rule_state_init(short int *row_has_num,
				short int *col_has_num, short int *row_ind, short int *col_ind);

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

	sudoku_rule_state_init(&row_has_num, &col_has_num, &row_ind, &col_ind);
	while (++val <= 4)
	{
		while (++row_ind < 4)
		{
			while (++col_ind < 4)
			{
				if (solu_grid[row_ind][col_ind] == val)
				{
					row_has_num = row_has_num | (1 << row_ind);
					col_has_num = col_has_num | (1 << col_ind);
				}
			}
			col_ind = -1;
		}
		write_sudoku_change(solu_grid, val, row_has_num, col_has_num);
		sudoku_rule_state_init(&row_has_num, &col_has_num, &row_ind, &col_ind);
	}
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
		ptr = &solu_grid[get_ind_most_sig(row_num)][get_ind_most_sig(col_num)];
		*ptr = val;
	}
}

static void	sudoku_rule_state_init(short int *row_has_num,
				short int *col_has_num, short int *row_ind, short int *col_ind)
{
	*row_has_num = 0;
	*col_has_num = 0;
	*row_ind = -1;
	*col_ind = -1;
}
