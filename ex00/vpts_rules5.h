#ifndef VPTS_RULES_5_H
# define VPTS_RULES_5_H

void	apply_vpts_rule5(short int solu_grid[][4], short int possi_grid[][4], short int *vpts);
void	apply_vpts_rule5_colup(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind);
void	apply_vpts_rule5_coldown(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind);
void	apply_vpts_rule5_rowleft(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind);
void	apply_vpts_rule5_rowright(short int solu_grid[][4], short int possi_grid[][4], short int *vpts, 
			short int vpts_ind);
#endif