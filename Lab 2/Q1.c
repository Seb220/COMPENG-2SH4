#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//vector library:
//print function:
void print_vector(double array[], int size)
{
    int i;
    for(i = 0; i<size; i++)               // iterates through each component of the vector
    {
        printf("%f", array[i]);
        if(i != size - 1)
        {                                 // prints a comma after each component, excluding the last component
            printf(",");
        }
    }
}
//add function:
void add_vectors(double vector1[], double vector2[], double vector3[], int n)
{
   int i;
   for(i = 0; i<n; i++)
   {
     vector3[i] = vector1[i] + vector2[i];   // replaces each component of vector 3 with the sum of the corresponding components of vectors 1 and 2
   }
}
//scalar product function:
double scalar_prod(double vector1[], double vector2[], int n)
{
    double sum = 0;
    int i;
    for(i = 0; i<n; i++)
    {
        sum += vector1[i] * vector2[i];
    }
    return sum;
}
//L2 norm function:
double norm2(double vector[], int n)
{
    return sqrt(scalar_prod(vector, vector, n));   // square roots the value returned from the scalar_prod function
}

//library test program:
int main()
{
    double x[3] =  {2,3,4};         // test vectors
    double y[3] = {5,6,7};
    double z[3];

    //print function:
    printf("A vector: ");
    print_vector(x, 3);

    printf("\n");
    //add function:
    add_vectors(x, y, z, 3);
    printf("The vector resulting from the addition of vector x and y is: ");
    print_vector(z, 3);

    printf("\n");
    //scalar product function:
    printf("The scalar product of vector x and y is %f", scalar_prod(x,y,3));

    printf("\n");
    //L2 norm function:
    printf("The L2 norm of vector x is: %f", norm2(x, 3));
    return 0;
}
