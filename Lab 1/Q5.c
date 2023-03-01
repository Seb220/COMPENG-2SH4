#include <stdio.h>
#include <stdlib.h>

int main()
{
    double pi = 0, x = 1;             /* initializes both the value of pi, and the denominator in the infinite series used to calculate pi */
    int n, i;
    printf("Please input a positive integer: \n");
    scanf("%d", &n);
    for(i=1; i<(n+1); i++)          /* makes the number of times this for loop runs equal to the interger value inputted by the user */
    {
        if(i%2 != 0)
        {
          pi += (4/x);
        }
        else                      /* adds to the approximated value of pi if the term is odd and subtracts if even, to match the infinite series */
        {
            pi-= (4/x);
        }
       x+=2;
    }
    printf("The value of pi is %lf.", pi);   /* prints the value of pi to the screen */
    return 0;
}
