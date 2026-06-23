#include <stdio.h>

#define N 8

int board[N][N];

// Knight's possible moves
int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Check if move is valid
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Backtracking function
int solveKT(int x, int y, int movei)
{
    int k, nextX, nextY;

    if (movei == N * N)
        return 1;

    for (k = 0; k < 8; k++)
    {
        nextX = x + xMove[k];
        nextY = y + yMove[k];

        if (isSafe(nextX, nextY))
        {
            board[nextX][nextY] = movei;

            if (solveKT(nextX, nextY, movei + 1))
                return 1;

            // Backtracking
            board[nextX][nextY] = -1;
        }
    }
    return 0;
}

int main()
{
    int i, j;

    // Initialize board
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = -1;

    // Start from (0,0)
    board[0][0] = 0;

    if (solveKT(0, 0, 1))
    {
        printf("Knight's Tour Solution:\n\n");

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                printf("%2d\t", board[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}
