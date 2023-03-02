#include <stdio.h>
#include <stdlib.h>
#define N 3
void diag_scan(int mat[][N])
{
    int i;
    for(i = 0; i<N; i++)                                            // Outputs the first half of the diagonaly rows including the middle row
                                            // i = The row (up/down) length starting at 0. Limitation of i < N = 0 to  n-1.
    {
        int row = i, col = 0;

        while(row>=0&&col<N)
                                          // this loop will print out one entire diagonal
                                                    // loop will run until value of row is greater than 0
                                                   // and value of column is less than N (3 in example)
        {
            printf(" %d", mat[row][col]);
                                                    // prints the matrix values
                                                    // now a shift of one up Aka row --;
                                                // and a shift of one right Aka col ++;
            row --;                                   // decreases row value by 1, = row = row-1
            col ++;                               // increases col value by 1 = col = col+1
        }
    }
    for(i = 1; i<N; i++)
                               // Outputs the second half of the diagonal rows not including the middle row
                                      // colum is now = i
                                   // row is = N-1 because Its needs to start at the bottom
                                // and is one row right of the middle diagonal as seen below
    /* [* * * x
        * * x 8
        * x 2 3
        x 5 6 7]
        Middle diagonal represented by x
        */
    {
        int row = N-1, col = i;

        while(row >= 0 && col <N)
        {
            printf(" %d", mat[row][col]);
                                                           // prints the matrix values (Second half of the diagonals)
            row --;                                         // decreases row value by 1, = row = row-1
            col ++;                                    // increases col value by 1 = col = col+1
        }
    }
}
// function test program:
int main()                      // Main calls the function diag_scan();
{
    int x[][N] = {{1,2,3}, {4,5,6}, {7,8,6}}; // Test case with global var N
    diag_scan(x);
    return 0;
}
