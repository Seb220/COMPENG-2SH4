#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, triple = 0;   /* creates variables and specifies data type (also initializes the counter value) */
       for(i=1; i<=400; i++)    /* tries all possibilites for side 1 */
       {
            for(j=1; j<=400; j++) /* tries all possibilites for side 2 */
            {
                for(k=1; k<=400; k++) /* tries all possibilites for side 3 */
                {
                    if(((i*i)+(j*j)==(k*k)) && (i<=j))
                    {
                        printf("%d, %d, %d \n", i, j, k);    /* prints combinations to screen that obey the pythagorean theorem and side1<=side2 */
                        triple++;            /* updates counter value */
                    }
                }
            }
       }
    printf("The total number of triples is %d", triple);  /* prints counter value to screen */
    return 0;
}
