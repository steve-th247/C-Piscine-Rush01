#ifndef VPTS_RULES_1_H
# define VPTS_RULES_1_H

void	apply_vpts_rule1(short int possi_grid[][4], short int *vpts);
void	apply_vpts_rule1_colup(short int possi_grid[][4], int col_ind, short int vpts);
void	apply_vpts_rule1_coldown(short int possi_grid[][4], int col_ind, short int vpts);
void	apply_vpts_rule1_rowleft(short int possi_grid[][4], int row_ind, short int vpts);
void	apply_vpts_rule1_rowright(short int possi_grid[][4], int row_ind, short int vpts);
#endif