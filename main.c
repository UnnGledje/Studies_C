/* This is the main.c file. Here you can find the menu as well as the board function. The size of the board is set by the user. */


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


#include "board.h"

//Function for the switch menu.
static void show_menu(char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS], int rows, int columns) { 

  int user_choice;

  printf("####################################\n");
  printf("#   Enter option in menu below:    #\n");
  printf("# \t1: Print Board             #\n");
  printf("# \t2: Add                     #\n");
  printf("# \t3: Remove                  #\n");
  printf("# \t4: Reset Board             #\n");
  printf("# \t5: Reset Row               #\n");
  printf("# \t6: Exit                    #\n");
  printf("####################################\n");
  scanf("%d", &user_choice);
  
  getc(stdin);
  switch (user_choice) {
  case 1:
    print_board(matrix, rows, columns);
    break;
  case 2:
    add_cable(matrix, rows, columns);
    break;
  case 3:
    remove_cable(matrix, rows, columns);
    break;
  case 4:
    reset_board(matrix, rows, columns);
    break;
  case 5:
    reset_row(matrix, rows, columns);
    break;
  case 6:
    exit(0);
  default:
    printf("Invalid choice, try again\n");
  }
}


int main(int argc, char const *argv[])
{
static char matrix[TOTAL_NR_OF_ROWS][TOTAL_NR_OF_COLUMNS];
    
    // If argument counter is less than 3, giving error.
    if(argc != 3) {

        printf("Wrong nr of args\n Usage %s rows, columns\n ", argv[0]);
          return -1;
    }

    int rows = atoi(argv[1]);
    int columns = atoi(argv[2]);
    
    //If the board is less than one row or column or the board is bigger than the defined size = error.
    if (rows <= 1 || columns <= 1 || rows > TOTAL_NR_OF_ROWS || columns > TOTAL_NR_OF_COLUMNS ) {  
        printf("Illegal argument\n");
          return -1;
    }
    
    printf("nr of rows %d\n", rows);
    printf("nr of columns %d\n", columns);

    // Giving the "empty" board the character '0'.
    for(int x = 0; x < rows; x++) { 

        for(int y = 0; y < columns; y++) {

            matrix[x][y] = '0';
        }
    }

    //Printing the board.
    for(int x = 0; x < rows; x++) { 

        for(int y = 0; y < columns; y++) {

            printf("%c", matrix[x][y]);
        }

      printf("\n"); 
    }


while(1) {
  


show_menu(matrix, rows, columns);


}
return 0;

}
