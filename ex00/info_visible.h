#ifndef INFO_VISIBLE_H
# define INFO_VISIBLE_H

int	get_visible_num(short int solu_grid[][4], int vpts_ind);
int	get_visible_col(short int solu_grid[][4], int vpts_ind, int dir);
int	get_visible_row(short int solu_grid[][4], int vpts_ind, int dir);
#endif