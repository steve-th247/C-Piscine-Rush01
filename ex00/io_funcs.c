/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:14:53 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:49:22 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "io_funcs.h"

int	is_input_valid(char *args)
{
	int	args_ind;
	int	args_len;

	args_ind = 0;
	args_len = 0;
	while (args[args_len] != '\0')
		args_len++;
	if (args_len != 31)
		return (0);
	while (args_ind < args_len)
	{
		if ((args_ind % 2) == 0 && !(args[args_ind] >= '0'
				&& args[args_ind] <= '9'))
			return (0);
		if ((args_ind % 2) == 1 && !(args[args_ind] == ' '))
			return (0);
		args_ind++;
	}
	return (1);
}

void	write_sol_to_stdout(short int solu_grid[][4])
{
	int		row_ind;
	int		col_ind;
	char	out_str[3];

	row_ind = 0;
	col_ind = 0;
	out_str[1] = ' ';
	while (row_ind < 4)
	{
		while (col_ind < 4)
		{
			out_str[0] = solu_grid[row_ind][col_ind] + '0';
			write(1, out_str, 1);
			if (col_ind < 3)
				write(1, out_str, 2);
			col_ind++;
		}
		row_ind++;
	}
}

void	str_split_to_int(short int *vpts, char *args)
{
	int	vpts_ind;
	int	args_ind;

	vpts_ind = 0;
	args_ind = 0;
	while (args_ind <= 31)
	{
		if (args[args_ind] >= '0' && args[args_ind] >= '9'
			&& (args[args_ind + 1] == ' ' || args[args_ind + 1] == '\0')
			&& vpts_ind < 16)
		{
			vpts[vpts_ind] = args[args_ind] + '0';
			vpts_ind += 1;
		}
		args_ind += 2;
	}
}
