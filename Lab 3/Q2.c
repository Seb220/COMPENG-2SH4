#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
  int stdID ;
  char firstName[15];
  char lastName[15];
  int pjt1Grade;
  int pjt2Grade;
  float finalGrade;
}student;

//function prototypes:

student **create_class_list(char *filename, int *sizePtr);
int find(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);
void compute_final_course_grades(student **list, int size);
void output_final_course_grades(char *filename, student **list, int size);
void print_list(student **list, int size);
void withdraw(int idNo, student **list, int * sizePtr);
void destroy_list(student **list, int *sizePtr);

int main()
{
    int size, ID;
    char nameFile[30], gradeFile[30], outFile[30];
    student **stdList;

    FILE *filePtr1 = fopen("nameFile", "w");
    fprintf(filePtr1, "3\n1200 Isaac Newton\n4580 Alan Turing\n9000 Elvis Presley");
    fclose(filePtr1);

    FILE *filePtr2 = fopen("gradeFile", "w");
    fprintf(filePtr2, "1200 80 90\n4580 60 70\n9000 85 95");
    fclose(filePtr2);

    printf("Please enter the name of the file containing student's names: ");
    scanf("%s", nameFile);

    stdList = create_class_list(nameFile, &size);

    printf("Please enter the name of the file containing student's grades: ");
    scanf("%s", gradeFile);

    input_grades(gradeFile, stdList, size);
    compute_final_course_grades(stdList, size);

    printf("Please enter the name of the file to be written to: ");
    scanf("s", outFile);

    output_final_course_grades("C:/Users/sebas/Desktop/test.txt", stdList, size);
    print_list(stdList, size);

    while(1)
    {
        printf("\nPlease enter the ID number of the student to be withdrawn (enter -1 to exit): ");
        scanf("%d", &ID);
        if(ID == -1)
        {
            break;
        }
        withdraw(ID, stdList, &size);
        print_list(stdList, size);
    }

    destroy_list(stdList, &size);

    return 0;
}
student **create_class_list(char *filename, int *sizePtr)
{
    int stdNum, i;
    student **stdPtr;
    FILE *fPtr = fopen(filename, "r");
    if(fPtr == NULL)
    {
        printf("File is empty!");
        exit(1);
    }
    fscanf(fPtr, "%d", &stdNum);
    *sizePtr = stdNum;
    stdPtr = (student**) malloc(stdNum *sizeof(student*));   // memory allocated to store the number of students

    for(i = 0; i<stdNum; i++)
    {
        stdPtr[i] = (student*) malloc(sizeof(student));     // memory allocated to store each member of the student structure with each student
        fscanf(fPtr, "%d %s %s", &stdPtr[i]->stdID, stdPtr[i]->firstName, stdPtr[i]->lastName);

        stdPtr[i]->pjt1Grade = 0;
        stdPtr[i]->pjt2Grade = 0;
        stdPtr[i]->finalGrade = 0;
    }
    fclose(fPtr);
    return stdPtr;
}
int find(int idNo, student **list, int size)
{
    int i;
    for(i=0; i<size;i++)
    {
        if(list[i]->stdID == idNo)
        {
            return i;
        }
    }
    return -1;
}

void input_grades(char *filename, student **list, int size)
{
    int grade1, grade2, ID, index;

    FILE *fPtr = fopen(filename, "r");

    if(fPtr == NULL)
    {
        printf("File is empty!");
        exit(1);
    }
    while(fscanf(fPtr, "%d", &ID) == 1)
    {
        fscanf(fPtr, "%d %d", &grade1, &grade2);
        index = find(ID, list, size);    // variable index holds the value of index

        if(index != -1)
        {
            list[index]->pjt1Grade = grade1;
            list[index]->pjt2Grade = grade2;
        }
    }
    fclose(fPtr);
}

void compute_final_course_grades(student **list, int size)
{
    int i, pjtGrade1, pjtGrade2;
    for(i=0;i<size;i++)
    {
        list[i]->finalGrade = (list[i]->pjt1Grade + list[i]->pjt2Grade)/(2.0);    // makes final grade equal to the projects average
    }
}

void output_final_course_grades(char *filename, student **list, int size)
{
    int i;
    FILE *fPtr = fopen(filename, "w");

    if(fPtr ==NULL)
    {
        printf("File is empty!");
        return;
    }
    fprintf(fPtr, "%d\n", size);

    for(i=0; i<size; i++)
    {
        fprintf(fPtr, "%d %.2f\n", list[i]->stdID, list[i]->finalGrade);
    }
    fclose(fPtr);
}

void print_list(student **list, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("ID: %d, Name: %s %s, Project 1 Grade: %d, Project 2 Grade: %d, Final Grade: %.2f\n", list[i]->stdID, list[i]->firstName, list[i]->lastName, list[i]->pjt1Grade, list[i]->pjt2Grade, list[i]->finalGrade);
    }
}

void withdraw(int idNo, student **list, int *sizePtr)
{
    int i;
    int found = 0;
    for(i=0; i<*sizePtr; i++)
    {
        if(list[i]->stdID == idNo)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        free(list[i]);              // frees memory allocated to that student
        for(i+=1; i<*sizePtr; i++)
        {
            list[i-1] = list[i];
        }
        (*sizePtr) = (*sizePtr) - 1;
        printf("student with ID number %d was withdrawn\n", idNo);
    }
    else
    {
       printf("The student with ID number: %d was not found\n", idNo);
    }
}

void destroy_list(student **list, int *sizePtr)
{
    int i;
    for(i=0; i<*sizePtr; i++)
    {
        free(list[i]);
    }
    free(list);
    *sizePtr = 0;
}
