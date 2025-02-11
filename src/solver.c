#include "../include/solver.h"

static bool isSafe(int *s, int len, int row, int col, int n)
{
    for (int i = 0; i < len; i++)
    {
        if (*(s + row * len + i) == n)
        {
            return false;
        }
        if (*(s + i * len + col) == n)
        {
            return false;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (*(s + (j + startRow) * len + (k + startCol)) == n)
            {
                return false;
            }
        }
    }

    return true;
}

static bool solve_sudoku_rec(int *s, int len, int row, int col)
{

    if (row == len - 1 && col == len)
    {
        return true;
    }

    if (col == len)
    {
        row++;
        col = 0;
    }

    if (*(s + row * len + col) != 0)
    {
        return solve_sudoku_rec(s, len, row, col + 1);
    }

    for (int n = 1; n <= len; n++)
    {
        if (isSafe(s, len, row, col, n))
        {
            *(s + row * len + col) = n;
            if (solve_sudoku_rec(s, len, row, col + 1))
            {
                return true;
            }
            *(s + row * len + col) = 0;
        }
    }
    return false;
}

void solve_sudoku(int *s, int len)
{
    solve_sudoku_rec(s, len, 0, 0);
}