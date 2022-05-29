/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vpts_rules1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:27:17 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:27:18 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vpts_rules1.h"

void	apply_vpts_rule1(short int possi_grid[][4], short int *vpts)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i <= 3)
			apply_vpts_rule1_colup(possi_grid, i, vpts[i]);
		else if (i >= 4 && i <= 7)
			apply_vpts_rule1_coldown(possi_grid, i - 3, vpts[i]);
		else if (i >= 8 && i <= 11)
			apply_vpts_rule1_rowleft(possi_grid, i - 7, vpts[i]);
		else if (i >= 12 && i <= 15)
			apply_vpts_rule1_rowright(possi_grid, i - 11, vpts[i]);
		i++;
	}
}

void	apply_vpts_rule1_colup(short int possi_grid[][4], int col_ind,
			short int vpts)
{
	int			row_ind;
	short int	*ptr;

	row_ind = 0;
	while (row_ind < (vpts - 1))
	{
		ptr = &possi_grid[row_ind][col_ind];
		*ptr = *ptr & 0b0111;
		row_ind++;
	}
}

void	apply_vpts_rule1_coldown(short int possi_grid[][4], int col_ind,
			short int vpts)
{
	int			row_ind;
	int			num_change;
	short int	*ptr;

	row_ind = 3;
	num_change = 0;
	while (num_change < (vpts - 1))
	{
		ptr = &possi_grid[row_ind][col_ind];
		*ptr = *ptr & 0b0111;
		num_change++;
		row_ind--;
	}
}

void	apply_vpts_rule1_rowleft(short int possi_grid[][4], int row_ind,
			short int vpts)
{
	int			col_ind;
	short int	*ptr;

	col_ind = 0;
	while (col_ind < (vpts - 1))
	{
		ptr = &possi_grid[row_ind][col_ind];
		*ptr = *ptr & 0b0111;
		col_ind++;
	}
}

void	apply_vpts_rule1_rowright(short int possi_grid[][4], int row_ind,
			short int vpts)
{
	int			col_ind;
	int			num_change;
	short int	*ptr;

	col_ind = 3;
	num_change = 0;
	while (num_change < (vpts - 1))
	{
		ptr = &possi_grid[row_ind][col_ind];
		*ptr = *ptr & 0b0111;
		num_change++;
		col_ind--;
	}
}
