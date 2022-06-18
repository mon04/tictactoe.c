#include "stdio.h"

int checkForResult(int playerNum, int row, int col);
void printGrid();

int grid[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
const int GRID_H = sizeof(grid)/sizeof(grid[0]);
const int GRID_W = sizeof(grid[0])/sizeof(int);

int main() {
    for(int i=0; i<sizeof(grid); i++) {
        for(int j=0; j < sizeof(grid[i]); j++) {
            grid[i][j] = 0;
        }
    }
    int active_player=1;
    int turn=1;
    while(turn <= 9) {
        int row, col;
        printf("Player %d, enter your row: ", active_player);
        scanf("%d", &row);
        printf("Player %d, enter your col: ", active_player);
        scanf("%d", &col);
        grid[row][col] = active_player;
        printGrid();
        int result = checkForResult(active_player, row, col);
        if(result > 0) {
            printf("Player %d wins!\n", active_player);
            return 0;
        }
        active_player = (active_player == 1) ?2 :1;
        turn++;
    }
    printf("The game has ended in a draw!\n");
    return 0;
}

int checkForResult(int playerNum, int row, int col) {
    if(grid[row][0] == playerNum && grid[row][1] == playerNum && grid[row][2] == playerNum) {
        return playerNum;
    }
    if(grid[0][col] == playerNum && grid[1][col] == playerNum && grid[2][col] == playerNum) {
        return playerNum;
    }
    if(grid[0][0] == playerNum && grid[1][1] == playerNum && grid[2][2] == playerNum) {
        return playerNum;
    }
    if(grid[0][2] == playerNum && grid[1][1] == playerNum && grid[2][0] == playerNum) {
        return playerNum;
    }
    return -1;
}

void printGrid() {
    char s[3] = {'-', 'X', 'O'};
    printf("\n");
    for(int i=0; i < GRID_H; i++) {
        for(int j=0; j < GRID_W; j++) {
            printf("%c ", s[grid[i][j]]);
        }
        printf("\n");
    }
    printf("\n");
}