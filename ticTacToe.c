// Luke Dykstra, Deven Mathoo
// ENGG*1410
// Mini Project 1 - TicTacToe
// Oct 26, 2026


/*
Some notes:
The 'check win' algorithm is based on what a former programming teacher once told me (and had done himself).
Its main idea is to only check one edge column (first to make it easy), check the diagonal, then rotate the board. This will move the previously checked column and diagonal to be a row and other diagonal. check again, rotate, and intotal, rotate 4 times to get back where you started

-Luke
*/

#include <stdio.h>

void rotateBoard(char board[3][3]) {
    // will be a bunch of swap(a, b) with the outer ring of the board (center never moves)
}

// Returns an int based on what situation is true to be used in a switch case
// 0 = no win
// 1 = a win in first column
// 2 = a win in the diagonal
int checkForWinInBoard(char board[3][3]) {
    if (board[0][0] != ' ') { // make sure its not an empty first column/diagonal
        if ((board[0][0]==board[0][1])&&(board[0][1]==board[0][2])){ // first column is all one character
            return 1;
        }
        if ((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])){ // diagonal is all one character
            return 2;
        }
    }
    if (board[1][0]!=' ') { // make sure its not an empty middle column
        if ((board[1][0]==board[1][1])&&(board[1][1]==board[1][2])){ // middle column is all one character
            return 1;
        }
    } 
    return 0; // no win
}

void printBoard(char board[3][3]) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%c ", board[j][i]);
        }
        printf("\n"); // cant forget a newline each row
    }
}

int main(void){
    char theGameBoard[3][3] = {' '}; // initialize the board to be empty
    printf("Hello World\n");
    printf("from Deven Mathoo and Luke Dykstra\n");

    return 0;
}