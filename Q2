#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, i, num, min;          /* specifies the data type of each variable */

    printf("Please enter how many numbers you would like to compare: \n");
    scanf("%d", &n);

    for (;;)                     /* infinite for loop because user may repeatedly enter an incorrect input value (refer to outer else staement */
    {
        if(n>=1)
        {
            printf("Please input each number you would like to compare (seperate with enter): \n");
                                                     /* each run of for loop is triggered to run by user pressing enter */
                for (i = 1; i<=n; i++)
                {
                    scanf("%d",&num);          /* value of num changes on each interation of for loop */

                    if(i == 1)
                    {
                        min = num;          /* this initializes min as the first number inputted by the user */
                    }

                    else
                    {
                        if(num<min)
                        {
                            min = num;     /* this updates min to the smallest number inputted by the user so far */
                        }
                    }
                }
            printf("The smallest number is: %d", min);  /* prints the smallest number to the screen */
            break;                                      /* breaks out of the infinite for loop */
        }

        else
        {
            printf("Please enter a valid input (a positive integer): "); /* Prompts the user for a correct input if the first input was invalid (negative integer) */
            scanf("%d", &n);
        }
    }
    return 0;
}
