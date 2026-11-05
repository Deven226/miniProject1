// Luke Dykstra, Deven Mathoo
// ENGG*1410
// Mini Project 1 - TicTacToe
// Oct 26, 2026


#include <stdio.h>
#include "board.h"
#include "input.h"

void delay(float seconds) {
    for (int i=0; i<seconds*1000000000; i++) { continue;}
}

void startup() {
    printf("Version: [unknown]\n");
    printf("Initializing");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf(".");
    delay(1);
    printf("\nCheating devices ready...\n");
    delay(1);
    printf("Ready.");
    printf("\n\n\nWelcome to TicTacToe - MiniProject 1 by Luke Dykstra and Deven Mathoo");
}

int main(void){
    startup();

    // creation of the game board
    char theGameBoard[MAX_SIZE][MAX_SIZE];
    int gameBoardSize=0;
    printf("\nHow big do you want the game board to be?\n");
    while (1) {
        if ((3<=gameBoardSize)&&(gameBoardSize<=10)) {break;} // valid answer, done
        else {printf("Value must be integer from 3-10 inclusive: ");} // not valid answer
        gameBoardSize = read_int();
    }
    board_init(theGameBoard, gameBoardSize);

    // how many players
    int numPlayers=0;
    printf("\nHow many players?\n");
    while (1) {
        if ((numPlayers==1)||(numPlayers==2)) {break;} // valid answer, done
        else if (numPlayers==0) {printf("Ok, goodbye."); return 0;} // no one wants to play. ok, goodbye
        else {printf("Value must be integer from 1-2 inclusive: ");} // not valid answer
        numPlayers = read_int();
    }

    // main game loop
    while (1) {
        // win check
        if (board_has_winner(theGameBoard, gameBoardSize, player1char)) {
            printf("%c has won!\n", player1char);
            break;
        }
    }

    printf("\n");
    return 0;
}

#include <stdio.h>