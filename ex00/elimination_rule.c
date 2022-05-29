/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elimination_rule.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:02:31 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:03:21 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elimination_rule.h"
#include "possi_grid.h"

void	apply_elimination_rule(short int solu_grid[][4],
			short int possi_grid[][4])
{
	int	ind;

	ind = 0;
	while (ind < 4)
	{
		apply_exclusivity_row(solu_grid, possi_grid, ind);
		ind++;
	}
	ind = 0;
	while (ind < 4)
	{
		apply_exclusivity_col(solu_grid, possi_grid, ind);
		ind++;
	}
	update_possi_grid(solu_grid, possi_grid);
}

void	apply_exclusivity_row(short int solu_grid[][4],
			short int possi_grid[][4], int row_ind)
{
	int	col_ind;
	int	sum_bit;
	int	bit_ind;

	col_ind = 0;
	sum_bit = 0;
	bit_ind = 0;
	while (bit_ind < 4)
	{
		while (col_ind < 4)
		{
			sum_bit += ((possi_grid[row_ind][col_ind] & (1 << bit_ind)) > 0);
			col_ind++;
		}
		if (sum_bit == 1)
			apply_exclusivity_row_bit(solu_grid, possi_grid, row_ind, bit_ind);
		col_ind = 0;
		sum_bit = 0;
		bit_ind++;
	}
}

void	apply_exclusivity_row_bit(short int solu_grid[][4],
			short int possi_grid[][4], int row_ind, int bit_ind)
{
	int	col_ind;

	col_ind = 0;
	while (col_ind < 4)
	{
		if (possi_grid[row_ind][col_ind] & (1 << bit_ind))
			solu_grid[row_ind][col_ind] = bit_ind + 1;
		col_ind++;
	}
}

void	apply_exclusivity_col(short int solu_grid[][4],
			short int possi_grid[][4], int col_ind)
{
	int	row_ind;
	int	sum_bit;
	int	bit_ind;

	row_ind = 0;
	sum_bit = 0;
	bit_ind = 0;
	while (bit_ind < 4)
	{
		while (row_ind < 4)
		{
			sum_bit += ((possi_grid[row_ind][col_ind] & (1 << bit_ind)) > 0);
			row_ind++;
		}
		if (sum_bit == 1)
			apply_exclusivity_col_bit(solu_grid, possi_grid, col_ind, bit_ind);
		row_ind = 0;
		sum_bit = 0;
		bit_ind++;
	}
}

void	apply_exclusivity_col_bit(short int solu_grid[][4],
			short int possi_grid[][4], int col_ind, int bit_ind)
{
	int	row_ind;

	row_ind = 0;
	while (row_ind < 4)
	{
		if (possi_grid[row_ind][col_ind] & (1 << bit_ind))
			solu_grid[row_ind][col_ind] = bit_ind + 1;
		row_ind++;
	}
}
