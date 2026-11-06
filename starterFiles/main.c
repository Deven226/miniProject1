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
    printf("Go.");
    printf("\n\n\nWelcome to TicTacToe - MiniProject 1 by Luke Dykstra and Deven Mathoo");
}

int main(void){
    startup();
    int playGame=1;
    while (playGame) {
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
        int gameMode=0;
        printf("What game mode:\n1: player vs player\n2: player vs bot\n");
        while (1) {
            if ((gameMode==1)||(gameMode==2)) {break;} // valid answer, done
            else {printf("Value must be integer from 1-2 inclusive: ");} // not valid answer
            gameMode = read_int();
        }
        char player1char =   'X';
        char player2char =   'O';
        char playerBotChar = player2char;
        int botActive = (gameMode==2);
        int turn = 0;

        // main game loop
        while (1) {
            // print board
            printf("Current game Board:\n");
            board_print(theGameBoard, gameBoardSize);
            // win check
            if (board_has_winner(theGameBoard, gameBoardSize, player1char)) {
                printf("Player %c has won!\n", player1char);
                break;
            }
            if (board_has_winner(theGameBoard, gameBoardSize, player2char)&&!botActive) {
                printf("Player %c has won!\n", player2char);
                break;
            }
            if (board_has_winner(theGameBoard, gameBoardSize, playerBotChar)&&botActive) {
                printf("You lost against bot %c\n", playerBotChar);
                break;
            }
            if (board_is_full(theGameBoard, gameBoardSize)) {
                printf("No winner, cat game : (\n");
                break;
            }

            if (turn%2==0) {
                int currPosX=-1;
                while (1) {
                    printf("Player %c: What is the horizontal index of the position to place %c?\n", player1char, player1char);
                    currPosX = read_int();
                    if ((0<=currPosX)&&(currPosX<gameBoardSize)) {
                        break;
                    }
                }
                int currPosY=-1;
                while (1) {
                    printf("Player %c: What is the vertical index of the position to place %c?\n", player1char, player1char);
                    currPosY = read_int();
                    if ((0<=currPosY)&&(currPosY<gameBoardSize)) {
                        break;
                    }
                }
                if (theGameBoard[currPosY][currPosX]==EMPTY) {
                    theGameBoard[currPosY][currPosX] = player1char;
                    turn++;
                }
                else {printf("Not a available position.\n");}

            }
        }
        while (1) {
            printf("Do you want to play gain?\n'y' to play again, anything else to exit.\n");
            if ((read_char()=='y')||(read_char()=='Y')) {
                playGame=0;
            }
            else {playGame=1;}
        }
    }

    printf("\n");
    return 0;
}

#include <stdio.h>