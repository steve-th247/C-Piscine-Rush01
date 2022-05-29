/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_unfilled.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:11:21 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:11:23 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_unfilled.h"

int	get_unfilled_num(short int solu_grid[][4], int vpts_ind)
{
	if (vpts_ind >= 0 && vpts_ind <= 7)
		return (get_unfilled_num_col(solu_grid, vpts_ind));
	else if (vpts_ind >= 8 && vpts_ind <= 15)
		return (get_unfilled_num_col(solu_grid, vpts_ind));
	else
		return (-1);
}

int	get_unfilled_num_col(short int solu_grid[][4], int vpts_ind)
{
	int	row_ind;
	int	col_ind;
	int	num_unfilled;

	row_ind = 0;
	col_ind = 0;
	num_unfilled = 0;
	col_ind = vpts_ind % 4;
	while (row_ind >= 0 && row_ind <= 3)
	{
		if (solu_grid[row_ind][col_ind] == 0)
			num_unfilled++;
		row_ind++;
	}
	return (num_unfilled);
}

int	get_unfilled_num_row(short int solu_grid[][4], int vpts_ind)
{
	int	row_ind;
	int	col_ind;
	int	num_unfilled;

	row_ind = 0;
	col_ind = 0;
	num_unfilled = 0;
	row_ind = vpts_ind % 4;
	while (col_ind >= 0 && col_ind <= 3)
	{
		if (solu_grid[row_ind][col_ind] == 0)
			num_unfilled++;
		col_ind++;
	}
	return (num_unfilled);
}
