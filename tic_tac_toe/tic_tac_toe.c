#include <stdio.h>

void printBoard();
void playerMove();
char isWinner();

char board[3][3] = {
  {' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '}
};

char player = 'X';

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("\n");
    printf("\n");
    printBoard();

    while(1){
        playerMove();
        printf("Board after move:\n");
        printBoard();
        char winner = isWinner();
        if (winner != ' ') {
            printf("Player %c wins!\n", winner);
            break;
        }

        int full = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    full = 0;
                }
            }
        }
        if (full) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

void printBoard(){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c", board[i][j]);
            if(j < 2){
                printf("|");
            }
        }
        printf("\n");
        if(i < 2){
            printf("------\n");
        }
    }
}

void playerMove(){
    int row, col;
    printf("Player %c's turn.\n", player);
    printf("Enter row (0-2): ");
    scanf("%d", &row);
    printf("Enter column (0-2): ");
    scanf("%d", &col);
    printf("row = %d, col = %d\n", row, col);
    board[row][col] = player;
    if(player == 'X'){
        player = 'O';
    } else {
        player = 'X';
    }
    printf("Player %c's turn.\n", player);
}

char isWinner(){
    // rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // main diagonal
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return board[0][0];
    }

    // anti-diagonal
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}