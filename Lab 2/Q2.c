#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 3

int is_diag_dom(int mat[][N])
{
   int i, j;
   for(i = 0; i<N; i++)
   {
      int sum_row = 0;    // resets the value of sum_row before moving on to the next row
      for(j = 0; j<N; j++)   // iterates through each vector component; from left to right; row by row
      {
          if(i != j)
          {
            sum_row += fabs(mat[i][j]);    // adds non-diagonal elements from the same row together
          }
      }
      if(fabs(mat[i][i]) < sum_row)
      {
          return 0;       // returns 0 as soon as one row does not represent a diagonally dominant matrix
      }
   }
   return 1;    // returns 0 if every row passes the above condition
}
//function test program:
int main()
{
    int x[N][N] = {{15,6,7}, {2,-4,-2}, {3,2,6}}, i, j;   // diagonally dominant test case matrix
    for(i = 0; i<N; i++)
    {
        for(j = 0; j<N; j++)
        {
            printf("%d  ", x[i][j]);      // prints matrix to screen in output statement
        }
        printf("\n");
    }
    if(is_diag_dom(x) == 1)        // uses the is_diag_dom function to check if the test case matrix is diagonally dominant
    {
        printf("is diagonally dominant");
    }
    else
    {
            printf("x is not diagonally dominant");

    }
    return 0;
}
