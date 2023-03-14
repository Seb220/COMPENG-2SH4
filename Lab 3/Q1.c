#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat( const char * const str1, const char * const str2)
{
    char *temp1 = str1, *temp2 = str2;      // initializes pointers to each string
    char *str3final = malloc(strlen(str1) + strlen(str2) +1);
    char *str3 = str3final;                 // ensures that the begining of the string is pointed to in the return statement
    while(*temp1 != '\0')        // adds first string to str3 one element at a time; stops at the null character
    {
        *str3 = *temp1;
        temp1++;          // increments address of temp1, in order to get the next element
        str3++;           // increments address of str3, in order to replace the next element
    }
    while(*temp2 != '\0')
    {
        *str3 = *temp2;
        temp2++;
        str3++;
    }
    *str3 = '\0';              // adds null character to complete string

    return str3final;

}


int main()
{
    printf("Concatenated string = %s\n", my_strcat("Hello", "World!"));
    return 0;
}

