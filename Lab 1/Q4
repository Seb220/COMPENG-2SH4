#include <stdio.h>
#include <stdlib.h>

int main()
{
    double A;
    printf("Please input the student's average: \n");
    scanf("%lf", &A);                                   /* asks the user to input the student's average, and attaches the value to the variable A */
    if(A>=90 && A<=100)
    {
        printf("The student's average is a 4.");
    }
    else
    {
        if(A>=80 && A<90)
        {
           printf("The student's average is a 3.");
        }
        else
        {
            if(A>=70 && A<80)
            {
                printf("The student's average is a 2.");  /* outputs the student's average on the 0-4 scale */
            }
            else
            {
              if(A>=60 && A<70)
              {
                 printf("The student's average is a 1.");
              }
              else
              {
                if(A>=0 && A<60)
                {
                  printf("The student's average is a 0.");
                }
                else
                {
                    printf("Invalid input! Please enter a value between 0 and 100.");
                }
              }
            }
        }
    }
    return 0;
}
