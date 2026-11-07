// Luke Dykstra, Deven Mathoo
// ENGG*1410
// Mini Project 1 - TicTacToe
// Oct 26, 2026


#include <stdio.h>
#include "board.h"
#include "input.h"

void delay(float seconds) {
    for (int i=0; i<seconds*1000000000; i++) {continue;}
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

int bot_try_win(char board[MAX_SIZE][MAX_SIZE], int n, char botMark) {
    printf("bot try win ");
    int count=0;
    // check columns
    // printf("\n%c columns", botMark);
   for (int col=0; col<n; col++) {
      count=0;
      for (int row=0; row<n; row++) {
         if (board[row][col]==botMark) {count++;}
        //  printf("count: %d", count);
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][col]==EMPTY) {
                    board[i][col]=botMark;
                    return 1;
                }
            }
        }
      }
   }
   // check rows
   // printf("\nrows");
   for (int row=0; row<n; row++) {
      count=0;
      for (int col=0; col<n; col++) {
         if (board[row][col]==botMark) {count++;}
         // printf("count: %d", count);
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[row][i]==EMPTY) {
                    board[row][i]=botMark;
                    return 1;
                }
            }
        }
      }
   }
   // check angle 1
   // printf("\nangle1");
   count=0;
   for (int i=0; i<n; i++) {
      if (board[i][i]==botMark) {count++;}
      // printf("count: %d", count);
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][i]==EMPTY) {
                    board[i][i]=botMark;
                    return 1;
                }
            }
        }
   }
   // check angle 2
   // printf("\nangle2");
   count=0;
   for (int i=0; i<n; i++) {
      if (board[n-i-1][i]==botMark) {count++;}
      // printf("count: %d", count);
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[n-i-1][i]==EMPTY) {
                    board[n-i-1][i]=botMark;
                    return 1;
                }
            }
        }
   }
   return 0;
}

int bot_try_stop_win(char board[MAX_SIZE][MAX_SIZE], int n, char botMark, char oppMark) {
    printf("bot try stop win ");
    int count=0;
    // check columns
    // printf("\n%c columns", botMark);
   for (int col=0; col<n; col++) {
      count=0;
      for (int row=0; row<n; row++) {
         if (board[row][col]==oppMark) {count++;}
        //  printf("count: %d", count);
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][col]==EMPTY) {
                    board[i][col]=botMark;
                    return 1;
                }
            }
        }
      }
   }
   // check rows
   // printf("\nrows");
   for (int row=0; row<n; row++) {
      count=0;
      for (int col=0; col<n; col++) {
         if (board[row][col]==oppMark) {count++;}
         // printf("count: %d", count);
         if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[row][i]==EMPTY) {
                    board[row][i]=botMark;
                    return 1;
                }
            }
        }
      }
   }
   // check angle 1
   // printf("\nangle1");
   count=0;
   for (int i=0; i<n; i++) {
      if (board[i][i]==oppMark) {count++;}
      // printf("count: %d", count);
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[i][i]==EMPTY) {
                    board[i][i]=botMark;
                    return 1;
                }
            }
        }
   }
   // check angle 2
   // printf("\nangle2");
   count=0;
   for (int i=0; i<n; i++) {
      if (board[n-i-1][i]==oppMark) {count++;}
      // printf("count: %d", count);
        if (count==n-1) {
            for (int i=0; i<n; i++) {
                if (board[n-i-1][i]==EMPTY) {
                    board[n-i-1][i]=botMark;
                    return 1;
                }
            }
        }
   }
   return 0;
}

int bot_make_move(char board[MAX_SIZE][MAX_SIZE], int n, char botMark) {
    printf("bot make move ");
    for (int row=0; row<n; row++) {
        for (int col=0; col<n; col++) {
            if (board[row][col]==EMPTY) {
                board[row][col]=botMark;
                return 1;
            }
        }
    }
    return 0;
}

int main(void){
    startup();
    int playGame=1;
    int player1Wins=0;
    int player2Wins=0;
    int playerBotWins=0;
    int catGameWins=0;
    char player1char =   'X';
    char player2char =   'O';
    char playerBotChar = player2char;
    printf("\nCurrent Wins:\n");
    printf("Player 1   (%c) %5d\n", player1char, player1Wins);
    printf("Player 2   (%c) %5d\n", player2char, player2Wins);
    printf("Player Bot (%c) %5d\n", playerBotChar, playerBotWins);
    printf("Tie games      %5d\n", catGameWins);
    while (playGame) {
        // creation of the game board
        char theGameBoard[MAX_SIZE][MAX_SIZE];
        int gameBoardSize=0;
        printf("\nHow big do you want the game board to be?\n");
        while (playGame) {
            if ((3<=gameBoardSize)&&(gameBoardSize<=10)) {break;} // valid answer, done
            else {printf("Value must be integer from 3-10 inclusive: ");} // not valid answer
            gameBoardSize = read_int();
        }
        board_init(theGameBoard, gameBoardSize);

        // how many players
        int gameMode=0;
        printf("What game mode:\n1: player vs player\n2: player vs bot\n");
        while (playGame) {
            if ((gameMode==1)||(gameMode==2)) {break;} // valid answer, done
            else {printf("Value must be integer from 1-2 inclusive: ");} // not valid answer
            gameMode = read_int();
        }
        int botActive = (gameMode==2);
        int turn = 0;

        // main game loop
        while (playGame) {
            // print board
            printf("Current game Board:\n");
            board_print(theGameBoard, gameBoardSize);
            // win check
            if (board_has_winner(theGameBoard, gameBoardSize, player1char)) {
                printf("Player %c has won!\n", player1char);
                player1Wins++;
                break;
            }
            if ((board_has_winner(theGameBoard, gameBoardSize, player2char))&&(botActive==0)) {
                printf("Player %c has won!\n", player2char);
                player2Wins++;
                break;
            }
            if ((board_has_winner(theGameBoard, gameBoardSize, playerBotChar))&&(botActive==1)) {
                printf("You lost against bot %c\n", playerBotChar);
                playerBotWins++;
                break;
            }
            if (board_is_full(theGameBoard, gameBoardSize)) {
                printf("No winner, cat game : (\n");
                catGameWins++;
                break;
            }

            int currPosX=-1;
            int currPosY=-1;
            if (turn%2==0) {
                while (playGame) {
                    printf("Player %c: What is the horizontal index of the position to place %c?\n", player1char, player1char);
                    currPosX = read_int();
                    if ((0<=currPosX)&&(currPosX<gameBoardSize)) {
                        break;
                    }
                }
                while (playGame) {
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
                else {printf("Not an available position.\n");}
            }
            else if (turn%2==1&&!botActive) {
                while (playGame) {
                    printf("Player %c: What is the horizontal index of the position to place %c?\n", player2char, player2char);
                    currPosX = read_int();
                    if ((0<=currPosX)&&(currPosX<gameBoardSize)) {
                        break;
                    }
                }
                while (playGame) {
                    printf("Player %c: What is the vertical index of the position to place %c?\n", player2char, player2char);
                    currPosY = read_int();
                    if ((0<=currPosY)&&(currPosY<gameBoardSize)) {
                        break;
                    }
                }
                if (theGameBoard[currPosY][currPosX]==EMPTY) {
                    theGameBoard[currPosY][currPosX] = player2char;
                    turn++;
                }
                else {printf("Not a available position.\n");}
            }
            else if (turn%2==1&&botActive) {
                if (!bot_try_win(theGameBoard, gameBoardSize, playerBotChar)) {
                    if (!bot_try_stop_win(theGameBoard, gameBoardSize, playerBotChar, player1char)) {
                        if (!bot_make_move(theGameBoard, gameBoardSize, playerBotChar)) {
                            // something must've gone wrong, as the only way to get here is the board is full full which should've been detected BEFORE the bot played its turn...
                            printf("Advancement made!\nHow did we get here?");
                        }
                    }
                }
                turn++;
            }
            else {printf("Advancement made!\nHow did we get here?");}
        }
        printf("\nCurrent Wins:\n");
        printf("Player 1   (%c) %5d\n", player1char, player1Wins);
        printf("Player 2   (%c) %5d\n", player2char, player2Wins);
        printf("Player Bot (%c) %5d\n", playerBotChar, playerBotWins);
        printf("Tie games      %5d\n", catGameWins);
        while (playGame) {
            printf("Do you want to play again?\n'y' to play again, any other character/letter else to exit.\n");
            char answer = read_char();
            if ((answer=='y')||(answer=='Y')) {
                playGame=1;
                break;
            }
            else {playGame=0;break;}
        }
    }

    printf("\n");
    return 0;
}

#include <stdio.h>