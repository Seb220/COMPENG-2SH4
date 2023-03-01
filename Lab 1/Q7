#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, i, x, sum;
    printf("Please input an integer greater than 1: \n");
    scanf("%d", &m);
    printf("All perfect numbers smaller than or equal to %d are below: \n", m);
    for(i = m; i>1; i--)         /* outer loop checks for perfect numbers less than or equal to the input value */
    {
        sum = 0;                /* reinitializes the value of sum each time the loop is run through */
        for(x = 1; x<i; x++)
        {                       /* inner loop checks for factors */
            if(i%x == 0)
            {
                sum += x;       /* sums all factors */
            }
        }
         if(sum == i)
         {
            printf("%d is a perfect number. \n", i);    /* prints to the screen if sum of factors is equal to the number being checked (perfect number) */
         }
    }
    return 0;
}
