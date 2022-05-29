#include "vpts_rules3.h"
#include "mask_funcs.h"

void	apply_vpts_rule3(short int possi_grid[][4], short int *vpts)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i >= 0 && i <= 3)
			possi_grid[0][i] = possi_grid[0][i] & get_mask_n_bit(4 - (vpts[i] - 1));
		else if (i >= 4 && i <= 7)
			possi_grid[3][i - 3] = possi_grid[3][i - 3] & get_mask_n_bit(4 - (vpts[i] - 1));
		else if (i >= 8 && i <= 11)
			possi_grid[i - 7][0] = possi_grid[i - 7][0] & get_mask_n_bit(4 - (vpts[i] - 1));
		else if (i >= 12 && i <= 15)
			possi_grid[i - 11][3] = possi_grid[i - 11][3] & get_mask_n_bit(4 - (vpts[i] - 1));
		i++;
	}
}