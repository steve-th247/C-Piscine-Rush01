/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vpts_rules2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:31:56 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:34:59 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vpts_rules2.h"
#include "mask_funcs.h"

void	apply_vpts_rule2(short int solu_grid[][4], short int possi_grid[][4],
			short int *vpts)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i <= 3)
			apply_vpts_rule2_colup(solu_grid, possi_grid, i, vpts[i]);
		else if (i >= 4 && i <= 7)
			apply_vpts_rule2_coldown(solu_grid, possi_grid, i % 4, vpts[i]);
		else if (i >= 8 && i <= 11)
			apply_vpts_rule2_rowleft(solu_grid, possi_grid, i % 4, vpts[i]);
		else if (i >= 12 && i <= 15)
			apply_vpts_rule2_rowright(solu_grid, possi_grid, i % 4, vpts[i]);
		i++;
	}
}

void	apply_vpts_rule2_colup(short int solu_grid[][4],
			short int possi_grid[][4], int col_ind, short int vpts)
{
	int			row_ind;
	short int	*ptr;
	short int	bitmask;
	short int	n_bit_shift;

	row_ind = vpts - 2;
	n_bit_shift = 0;
	if (solu_grid[vpts - 1][col_ind] == 4)
	{
		bitmask = get_mask_most_sig(possi_grid[row_ind][col_ind]);
		while (row_ind >= 0)
		{
			ptr = &possi_grid[row_ind][col_ind];
			*ptr = *ptr & (bitmask >> n_bit_shift);
			n_bit_shift++;
			row_ind--;
		}
	}
}

void	apply_vpts_rule2_coldown(short int solu_grid[][4],
			short int possi_grid[][4], int col_ind, short int vpts)
{
	int			row_ind;
	short int	*ptr;
	short int	bitmask;
	short int	n_bit_shift;

	row_ind = 5 - vpts;
	n_bit_shift = 0;
	if (solu_grid[4 - vpts][col_ind] == 4)
	{
		bitmask = get_mask_most_sig(possi_grid[row_ind][col_ind]);
		while (row_ind < 4)
		{
			ptr = &possi_grid[row_ind][col_ind];
			*ptr = *ptr & (bitmask >> n_bit_shift);
			n_bit_shift++;
			row_ind++;
		}
	}
}

void	apply_vpts_rule2_rowleft(short int solu_grid[][4],
			short int possi_grid[][4], int row_ind, short int vpts)
{
	int			col_ind;
	short int	*ptr;
	short int	bitmask;
	short int	n_bit_shift;

	col_ind = vpts - 2;
	n_bit_shift = 0;
	if (solu_grid[row_ind][vpts - 1] == 4)
	{
		bitmask = get_mask_most_sig(possi_grid[row_ind][col_ind]);
		while (col_ind >= 0)
		{
			ptr = &possi_grid[row_ind][col_ind];
			*ptr = *ptr & (bitmask >> n_bit_shift);
			n_bit_shift++;
			col_ind--;
		}
	}
}

void	apply_vpts_rule2_rowright(short int solu_grid[][4],
			short int possi_grid[][4], int row_ind, short int vpts)
{
	int			col_ind;
	short int	*ptr;
	short int	bitmask;
	short int	n_bit_shift;

	col_ind = 5 - vpts;
	n_bit_shift = 0;
	if (solu_grid[row_ind][4 - vpts] == 4)
	{
		bitmask = get_mask_most_sig(possi_grid[row_ind][col_ind]);
		while (col_ind < 4)
		{
			ptr = &possi_grid[row_ind][col_ind];
			*ptr = *ptr & (bitmask >> n_bit_shift);
			n_bit_shift++;
			col_ind++;
		}
	}
}
