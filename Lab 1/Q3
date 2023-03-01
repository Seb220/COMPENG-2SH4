#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i;                                 /* defines variables as integer data type */
    printf("Please input an integer (0 to end): ");
    for(;;)                         /* infinite for loop becuase user can continue to input integers until they press 0 */
    {
        if(x != 0)
        {
            scanf("%d", &x);        /* looks for an integer value and stores the value in the variable x */
            if(x>9999 || x<-9999)
            {
                printf("Your input is a five-digit number: %d \n", x);
                printf("Please input an integer (0 to end): ");      /* allows user to input another integer after a 5-digit number is inputted */
            }
            else
            {
                if(x != 0)          /* prevents below printf statement from printing to the screen if 0 is inputted */
                {
                   printf("Please input an integer (0 to end): ");     /* allows user to input another integer after a non-5-digit number is inputted */
                }
            }
        }
        else
        {
            printf("Thank you for using my software. Bye!");    /* prints end of program message if input is 0 */
            break;                             /* to break out of infinite for loop */
        }
    }
    return 0;
}
