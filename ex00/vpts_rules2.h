#ifndef VPTS_RULES_2_H
# define VPTS_RULES_2_H

void	apply_vpts_rule2(short int solu_grid[][4], short int possi_grid[][4], short int *vpts);
void	apply_vpts_rule2_colup(short int solu_grid[][4], short int possi_grid[][4], int col_ind, 
			short int vpts);
void	apply_vpts_rule2_coldown(short int solu_grid[][4], short int possi_grid[][4], int col_ind, 
			short int vpts);
void	apply_vpts_rule2_rowleft(short int solu_grid[][4], short int possi_grid[][4], int row_ind, 
			short int vpts);
void	apply_vpts_rule2_rowright(short int solu_grid[][4], short int possi_grid[][4], int row_ind, 
			short int vpts);
#endif