#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* ..................... part a ..................... */
    int num, numin, revnum = 0, i;                         /* defines variables and specifies data type (also initializes the value of revnum) */

    printf("Part A: \nPlease input a seven-digit positive integer: \n");
    scanf("%d", &num);

    numin = num;          /* stores inputted integer to be used in output statement */

    for(i = 1; i<=7; i++)    /* loops once for each digit (7 times) */
    {
        revnum = (revnum*10) + (num%10);   /* reverses numin one digit at a time */
        num /= 10;                 /* used in previous line to reverse numin order */
    }
    printf("%d backwards is %d. \n\n\n", numin, revnum);


    /* ..................... part b ..................... */
    int num1, numin1, revnum1 = 0;                                   /* defines variables and specifies data type */

    printf("Part B: \nPlease input a positive integer: \n");
    scanf("%d", &num1);

    numin1 = num1;    /* stores inputted integer to be used in output statement */

    while(num1>0)        /* runs until num1 is broken down completely (division on num1 by 10 equals 0) */
    {
        revnum1 = (revnum1*10) + (num1%10);   /* reverses numin one digit at a time */
        num1 /= 10;       /* used in previous line to reverse numin order */
    }
    printf("%d backwards is %d.", numin1, revnum1);
    return 0;
}
