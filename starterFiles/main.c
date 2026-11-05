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
    delay(1);
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
    printf("\n\n\nWelcome to TicTacToe MiniProject 1 by Luke Dykstra and Deven Mathoo\n");
}

int main(void){
    startup();
    char theGameBoard[MAX_SIZE][MAX_SIZE];
    return 0;
}

#include <stdio.h>