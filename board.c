/* This is the board.c file where the implementation of the functions from the board.h file are made.*/

#include "board.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>


//Used for occupied, chosen slots by user
const char USER = 'X'; 


//Function for printing the board.
int print_board(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns) { 
    
    for(int x = 0; x <= rows; x++) {

        for(int y = 0; y <= columns; y++) {

            printf("%c", matrix[x][y]);
        }
        printf("\n");
    }
    return 0; 
}
 
//Function used for resetting the whole board back to '0'.
int reset_board(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns) { 

    for(int x =0; x <rows; x++) {

            for(int y=0; y <columns; y++) {

                matrix[x][y] = '0';

                    printf("%c", matrix[x][y]);
            }
            printf("\n");
        }
    return 0;
}

//Function for resetting only one chosen row to '0'.
int reset_row(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns) { 

    int the_row; 

    printf("Enter row number: \n");
    scanf("%d", &the_row);
    the_row--;

    if(matrix[the_row][columns] != '0' && matrix[the_row][columns] != '0') {

        for(int x = 0; x <= the_row; x++) {

            for(int y = 0; y < columns; y++) {

                matrix[the_row][y] = '0';
            }
        }
        print_board(matrix, rows, columns);

    return 0;
    }
    return 0; 
}

//Function for adding cable to the board.
int add_cable(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns) {
  
    int the_row;
    int column_one;
    int column_two;

    char string_the_row[3];
    char string_column_one[2];
    char string_column_two[2];

    //Using atoi after input to convert string to integer, an error returns 0, and an error message will reach the user.
    printf("Enter row number: \n");
    scanf("%s", string_the_row);
    the_row = atoi(string_the_row);
    the_row--;

    printf("Enter column one: \n");
    scanf("%s", string_column_one);  
    column_one = atoi(string_column_one);
    column_one--;

    printf("Enter column two:\n");
    scanf("%s", string_column_two); 
    column_two = atoi(string_column_two);
    column_two--;

   

    //Some error checking
    if(the_row > rows || column_one > columns || column_two > columns) {

        printf("Row number or column number to big for defined board size.\n");
            return -1;
    }

    else if (the_row < 0 || column_one < 0 || column_two < 0 ) {

        printf("Row number or column number to small for defined board size, or you have failed to enter only integers.\n");
            return -1;
    }

    else if (column_one == column_two) {

        printf("Please enter two different column numbers.\n");
            return -1;
    }
  
 
    //Iterating the two columns, checking if any the slots are occupied so that you cant put a cable over another cable.
    if(column_one < column_two) {

        for(int y = column_one; y <= column_two; y++) {

            if (matrix[the_row][y] != '0') {

                printf("Slot is occupied\n");

                    print_board(matrix, columns, rows);
            return -1;
            }
        }
    }
    else if (column_one > column_two) {

        for(int y = column_two; y <= column_one; y++) {

            if (matrix[the_row][y] != '0') {

                printf("Slot is occupied\n");

                    print_board(matrix, columns, rows);
            return -1;
            }
        }
    }

    //If slots are unoccupied, setting the columns to 'X' and every slot in between to '+'.
    if (matrix[rows][columns] == 0 || matrix[rows][columns] == 0) {

        matrix[the_row][column_one] = USER;
        matrix[the_row][column_two] = USER; 

        if(column_one < column_two) {
            for(int y = (column_one + 1); y < column_two; y++) {

                matrix[the_row][y] = '+';
            }
        }
        else if (column_one > column_two) {
            for(int y = (column_two + 1); y < column_one; y++) {

                matrix[the_row][y] = '+';
            }
        }
        
        print_board(matrix, rows, columns);

    }
   
    return 0; 
}

//Function to remove one cable.
int remove_cable(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns) {

    int the_row;
    int column_one;
    
    char string_the_row[3];
    char string_column_one[2];

    printf("Enter row number of cable you want to remove: \n");
    scanf("%s", string_the_row);
    the_row = atoi(string_the_row);
    the_row--;
    

    printf("Enter column one of the cable you want to remove: \n");
    scanf("%s", string_column_one);  
    column_one = atoi(string_column_one);
    column_one--;
    
    // Iterating through all possibilities, checking for beginning and end of cable and setting columns to '0'
    if(matrix[the_row][column_one] == 'X') {

        matrix[the_row][column_one] = '0';
    
    
    if(matrix[the_row][column_one + 1] == '+') {

        for(int y = column_one; y < columns; y++) {

            if(matrix[the_row][y] == 'X') {

                matrix[the_row][y] = '0';
       
                    break;
            }
         
        matrix[the_row][y] = '0'; 
        }
    }

    if(matrix[the_row][column_one - 1] == '+') {

        for(int y = column_one; y >= 0; y--) {

            if(matrix[the_row][y] == 'X') {

                matrix[the_row][y] = '0';

                    break;
            }
          
        matrix[the_row][y] = '0'; 
        }
    }

    if(matrix[the_row][column_one - 1] == 'X') {

        for(int y = column_one; y >= 0; y--) {

            if(matrix[the_row][y] == 'X') {

                matrix[the_row][y] = '0';

                    break;
            }

        matrix[the_row][y] = '0';
        }
    }

    if(matrix[the_row][column_one + 1] == 'X') {

        for(int y = column_one; y < columns; y++) {

            if(matrix[the_row][y] == 'X') {

                matrix[the_row][y] = '0';
       
                    break;
            }

        matrix[the_row][y] = '0'; 
        }
    }
   
    print_board(matrix, rows, columns);
    }
    else {

        printf("You have entered incorrect values \n");
            return -1;

    }

    
    return 0;
}


    
    
    
   