#include <stdio.h>
#include "board.h"


void board_init(char board[MAX_SIZE][MAX_SIZE], int n) {
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++) {
         board[i][j] = EMPTY;
      }
   }
}

void board_print(char board[MAX_SIZE][MAX_SIZE], int n) {
   printf("  ");
   for (int i=0; i<n; i++) {printf("%d  ", i);}
   printf("\n");
   for (int i=0; i<n; i++) {
      printf("%d ", i);
      for (int j=0; j<n; j++) {
         printf("%c  ", board[i][j]);
      }
      printf("\n");
   }
}

int move_is_valid(char board[MAX_SIZE][MAX_SIZE], int n, int row, int col) {
   if (row>=n)                 {return 0;}
   if (col>=n)                 {return 0;}
   if (board[row][col]!=EMPTY) {return 0;}
   return 1;
}

int board_has_winner(char board[MAX_SIZE][MAX_SIZE], int n, char mark) {
   int count=0;
   // check columns
   // printf("\n%c columns", mark);
   for (int col=0; col<n; col++) {
      count=0;
      for (int row=0; row<n; row++) {
         if (board[row][col]==mark) {count++;}
         // printf("count: %d", count);
         if (count>=n) {return 1;}
      }
   }
   // check rows
   // printf("\nrows");
   for (int row=0; row<n; row++) {
      count=0;
      for (int col=0; col<n; col++) {
         if (board[row][col]==mark) {count++;}
         // printf("count: %d", count);
         if (count>=n) {return 1;}
      }
   }
   // check angle 1
   // printf("\nangle1");
   count=0;
   for (int i=0; i<n; i++) {
      if (board[i][i]==mark) {count++;}
      // printf("count: %d", count);
      if (count>=n) {return 1;}
   }
   // check angle 2
   // printf("\nangle2");
   count=0;
   for (int i=0; i<n; i++) {
      if (board[n-i][i]==mark) {count++;}
      // printf("count: %d", count);
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