/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vpts_rules4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:38:03 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:38:04 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vpts_rules4.h"
#include "possi_grid.h"

void	apply_vpts_rule4(short int solu_grid[][4], short int possi_grid[][4],
			short int *vpts)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i <= 3)
		{
			if (vpts[i] == 1 && vpts[i + 4] == 2)
				solu_grid[3][i] = 3;
			else if (vpts[i] == 2 && vpts[i + 4] == 1)
				solu_grid[0][i] = 3;
		}
		if (i >= 8 && i <= 11)
		{
			if (vpts[i] == 1 && vpts[i + 4] == 2)
				solu_grid[i][3] = 3;
			else if (vpts[i] == 2 && vpts[i + 4] == 1)
				solu_grid[i][0] = 3;
		}
		i++;
	}
	update_possi_grid(solu_grid, possi_grid);
}
