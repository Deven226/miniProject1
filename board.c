/*
board.c
by Luke Dykstra 1440689, Deven Mathoo 1423575
contains all the functions to create, use, and detect winning of a tictactoe board
*/


#include <stdio.h>
#include "board.h"

/*initialize the board to be EMPTY*/
void board_init(char board[MAX_SIZE][MAX_SIZE], int n) {
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++) {
         board[i][j] = EMPTY;
      }
   }
}

/*prints out board to size n*/
void board_print(char board[MAX_SIZE][MAX_SIZE], int n) {
   printf("   ");
   for (int i=0; i<n; i++) {printf("%d  ", i);}
   printf("\n");
   for (int i=0; i<n; i++) {
      printf("%d  ", i);
      for (int j=0; j<n; j++) {
         printf("%c  ", board[i][j]);
      }
      printf("\n");
   }
}

/*checks if move at board[row][col] is valid and within size n*/
int move_is_valid(char board[MAX_SIZE][MAX_SIZE], int n, int row, int col) {
   if (row>=n)                 {return 0;}
   if (col>=n)                 {return 0;}
   if (board[row][col]!=EMPTY) {return 0;}
   return 1;
}

/*check if board has a straight line (vertical, horizontal, or either diagonal) of mark*/
int board_has_winner(char board[MAX_SIZE][MAX_SIZE], int n, char mark) {
   int count=0;
   // check columns
   // printf("\n%c columns", mark); // debug
   for (int col=0; col<n; col++) {
      count=0;
      for (int row=0; row<n; row++) {
         if (board[row][col]==mark) {count++;}
         // printf("count: %d", count); // debug
         if (count>=n) {return 1;}
      }
   }
   // check rows
   // printf("\nrows"); // debug
   for (int row=0; row<n; row++) {
      count=0;
      for (int col=0; col<n; col++) {
         if (board[row][col]==mark) {count++;}
         // printf("count: %d", count); // debug
         if (count>=n) {return 1;}
      }
   }
   // check angle 1
   // printf("\nangle1"); // debug
   count=0;
   for (int i=0; i<n; i++) {
      if (board[i][i]==mark) {count++;}
      // printf("count: %d", count); // debug
      if (count>=n) {return 1;}
   }
   // check angle 2
   // printf("\nangle2"); // debug
   count=0;
   for (int i=0; i<n; i++) {
      if (board[n-i-1][i]==mark) {count++;}
      // printf("count: %d", count); // debug
      if (count>=n) {return 1;}
   }
   return 0;
}

int board_is_full(char board[MAX_SIZE][MAX_SIZE], int n) {
   for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
         if (board[i][j]==EMPTY) {return 0;}
      }
   }
   return 1;
}

void ai_move(char board[MAX_SIZE][MAX_SIZE], int n, char ai_mark, char human_mark) {
   // bot try to win
    int count=0;
    // check columns
    // printf("\n%c columns", botMark); // debug
   for (int col=0; col<n; col++) {
      count=0;
      for (int row=0; row<n; row++) {
         if (board[row][col]==ai_mark) {count++;}
        //  printf("count: %d", count); // debug
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][col]==EMPTY) {
                    board[i][col]=ai_mark;
                    return;
                }
            }
        }
      }
   }
   // check rows
   // printf("\nrows"); // debug
   for (int row=0; row<n; row++) {
      count=0;
      for (int col=0; col<n; col++) {
         if (board[row][col]==ai_mark) {count++;}
         // printf("count: %d", count); // debug
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[row][i]==EMPTY) {
                    board[row][i]=ai_mark;
                    return;
                }
            }
        }
      }
   }
   // check angle 1
   // printf("\nangle1"); // debug
   count=0;
   for (int i=0; i<n; i++) {
      if (board[i][i]==ai_mark) {count++;}
      // printf("count: %d", count); // debug
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][i]==EMPTY) {
                    board[i][i]=ai_mark;
                    return;
                }
            }
        }
   }
   // check angle 2
   // printf("\nangle2"); // debug
   count=0;
   for (int i=0; i<n; i++) {
      if (board[n-i-1][i]==ai_mark) {count++;}
      // printf("count: %d", count); // debug
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[n-i-1][i]==EMPTY) {
                    board[n-i-1][i]=ai_mark;
                    return;
                }
            }
        }
   }

   // bot try to stop human from win
   // printf("bot try stop win "); // debug
   count=0;
   // check columns
   // printf("\n%c columns", botMark); // debug
   for (int col=0; col<n; col++) {
      count=0;
      for (int row=0; row<n; row++) {
         if (board[row][col]==human_mark) {count++;}
        //  printf("count: %d", count); // debug
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][col]==EMPTY) {
                    board[i][col]=ai_mark;
                    return;
                }
            }
        }
      }
   }
   // check rows
   // printf("\nrows"); // debug
   for (int row=0; row<n; row++) {
      count=0;
      for (int col=0; col<n; col++) {
         if (board[row][col]==human_mark) {count++;}
         // printf("count: %d", count); // debug
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[row][i]==EMPTY) {
                    board[row][i]=ai_mark;
                    return;
                }
            }
        }
      }
   }
   // check angle 1
   // printf("\nangle1"); // debug
   count=0;
   for (int i=0; i<n; i++) {
      if (board[i][i]==human_mark) {count++;}
      // printf("count: %d", count); // debug
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][i]==EMPTY) {
                    board[i][i]=ai_mark;
                    return;
                }
            }
        }
   }
   // check angle 2
   // printf("\nangle2"); // debug
   count=0;
   for (int i=0; i<n; i++) {
      if (board[n-i-1][i]==human_mark) {count++;}
      // printf("count: %d", count); // debug
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[n-i-1][i]==EMPTY) {
                    board[n-i-1][i]=ai_mark;
                    return;
                }
            }
        }
   }

   // bot make move
   // printf("bot make move "); // debug
    for (int row=0; row<n; row++) {
        for (int col=0; col<n; col++) {
            if (board[row][col]==EMPTY) {
                board[row][col]=ai_mark;
                return;
            }
        }
    }
}