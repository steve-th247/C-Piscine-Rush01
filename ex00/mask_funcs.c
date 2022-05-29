/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjien-ji <tjien-ji@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:15:33 by tjien-ji          #+#    #+#             */
/*   Updated: 2022/05/29 18:15:41 by tjien-ji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short int	get_mask_most_sig(short int bin_num)
{
	if (bin_num & 0b1000)
		return (0b1111);
	else if (bin_num & 0b0100)
		return (0b0111);
	else if (bin_num & 0b0010)
		return (0b0011);
	else if (bin_num & 0b0001)
		return (0b0001);
	else
		return (0b0000);
}

short int	get_mask_n_bit(int n)
{
	int			nbit;
	short int	bitmask;

	nbit = 0;
	bitmask = 0;
	if (n < 0)
		return (0);
	while (nbit < n)
	{
		bitmask = bitmask | (1 << nbit);
		nbit++;
	}
	return (bitmask);
}
