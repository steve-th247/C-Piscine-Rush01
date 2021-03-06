/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_first_visible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:06:42 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:09:55 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info_first_visible.h"

int	get_first_visible_height(short int solu_grid[][4], int vpts_ind)
{
	if (vpts_ind >= 0 && vpts_ind <= 7)
		return (get_first_visible_height_col(solu_grid, vpts_ind));
	else if (vpts_ind >= 8 && vpts_ind <= 15)
		return (get_first_visible_height_row(solu_grid, vpts_ind));
	else
		return (-1);
}

int	get_first_visible_height_col(short int solu_grid[][4], int vpts_ind)
{
	int	row_ind;
	int	col_ind;
	int	dir;

	col_ind = vpts_ind % 4;
	if (vpts_ind <= 3)
		dir = 1;
	else
		dir = -1;
	if (dir > 0)
		row_ind = 0;
	else
		row_ind = 3;
	while (row_ind >= 0 && row_ind <= 3)
	{
		if (solu_grid[row_ind][col_ind] != 0)
			return (solu_grid[row_ind][col_ind]);
		row_ind += dir;
	}
	return (-1);
}

int	get_first_visible_height_row(short int solu_grid[][4], int vpts_ind)
{
	int	row_ind;
	int	col_ind;
	int	dir;

	row_ind = vpts_ind % 4;
	if (vpts_ind <= 11)
		dir = 1;
	else
		dir = -1;
	if (dir > 0)
		col_ind = 0;
	else
		col_ind = 3;
	while (col_ind >= 0 && col_ind <= 3)
	{
		if (solu_grid[row_ind][col_ind] != 0)
			return (solu_grid[row_ind][col_ind]);
		col_ind += dir;
	}
	return (-1);
}
