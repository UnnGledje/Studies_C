/* This is the board.h file. Here you can find the defined size of the 2-D array (matrix) and all the functions used */

#ifndef __BOARD_H__
#define __BOARD_H__


#define TOTAL_NR_OF_ROWS 100 
#define TOTAL_NR_OF_COLUMNS 50


int print_board(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns);

int reset_board(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns);

int reset_row(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns);

int add_cable(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns);

int remove_cable(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns);


#endif 

