#include <stdio.h>
#include <stdlib.h>

void letter_freq(const char word[], int freq[])
{
    int i = 0, j;
    while(word[i] != '\0')       // runs if the string is not empty
    {
        if(word[i]>='a' && word[i]<='z')
        {
            freq[word[i] - 'a']++;    // uses the difference of the character value and a to update the frequency array for lowercase letters
        }
        else
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                freq[word[i] - 'A']++;     // uses the difference of the character value and A to update the frequency array for capital letters
            }
        }
        i++;
    }
    for(j = 0; j<26; j++)      // loops through each letter
    {
        printf("The count of %c and %c is %d\n", (j + 'A'), (j + 'a'), freq[j]); // prints the count of each letter (lower and upper case) on a seperate line
    }
}

// function test program:
int main()
{
   char x[] = "Sebastian";  // test case
   int freq[26] = {0};      // initalizes all components to 0

    letter_freq(x, freq);   // calling of function
    return 0;
}
