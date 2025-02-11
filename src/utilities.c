#include "../include/utilities.h"

void print_sudoku(int *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%d ", *(s + i * len + j));
        }
        printf("\n");
    }
}