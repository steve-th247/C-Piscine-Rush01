#ifndef SUDOKU_RULE_H
# define SUDOKU_RULE_H

void	apply_sudoku_rule(short int solu_grid[][4], short int possi_grid[][4]);
void	apply_sudoku_rule_val(short int solu_grid[][4], short int val);
void	write_sudoku_change(short int solu_grid[][4], short int val
			, short int row_has_num, short int col_has_num);
#endif