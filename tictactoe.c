#include <stdio.h>
#include <stdlib.h>

int check_for_result(int playerNum, int row, int col);
void print_grid();

int grid[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
const int GRID_H = sizeof(grid)/sizeof(grid[0]);
const int GRID_W = sizeof(grid[0])/sizeof(int);
const char symbols[3] = {'-', 'X', 'O'};

int main() {
    for(int i=0; i < GRID_H; i++) {
        for(int j=0; j < GRID_W; j++) {
            grid[i][j] = 0;
        }
    }
    int active_player=1;
    int turn=1;
    while(turn <= 9) {
        int row, col;
        printf("\e[1;1H\e[2J");
        print_grid();
        printf("\n\'%c\' player, enter your next move: ", symbols[active_player]);
        scanf("%d%d", &row, &col);
        grid[row][col] = active_player;
        int result = check_for_result(active_player, row, col);
        if(result > 0) {
            printf("\e[1;1H\e[2J");
            print_grid();
            printf("\nPlayer %c wins!\n", symbols[active_player]);
            return 0;
        }
        active_player = (active_player == 1) ?2 :1;
        turn++;
    }
    printf("\e[1;1H\e[2J");
    print_grid();
    printf("\nThe game has ended in a draw!\n");
    return 0;
}

int check_for_result(int playerNum, int row, int col) {
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

void print_grid() {
    //printf("\n");
    for(int i=0; i < GRID_H; i++) {
        for(int j=0; j < GRID_W; j++) {
            printf("%c ", symbols[grid[i][j]]);
        }
        printf("\n");
    }
    //printf("\n");
}