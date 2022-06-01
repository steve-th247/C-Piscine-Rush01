/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:55:25 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/06/01 10:52:59 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_bits(short int bin_num)
{
	short int	num_bits;

	num_bits = 0;
	num_bits += ((bin_num & 0b1000) > 0);
	num_bits += ((bin_num & 0b0100) > 0);
	num_bits += ((bin_num & 0b0010) > 0);
	num_bits += ((bin_num & 0b0001) > 0);
	return (num_bits);
}

int	get_ind_most_sig(short int bin_num)
{
	if (bin_num & 0b1000)
		return (3);
	else if (bin_num & 0b0100)
		return (2);
	else if (bin_num & 0b0010)
		return (1);
	else if (bin_num & 0b0001)
		return (0);
	else
		return (-1);
}

int	get_ind_least_sig(short int bin_num)
{
	if (bin_num & 0b0001)
		return (0);
	else if (bin_num & 0b0010)
		return (1);
	else if (bin_num & 0b0100)
		return (2);
	else if (bin_num & 0b1000)
		return (3);
	else
		return (-1);
}
