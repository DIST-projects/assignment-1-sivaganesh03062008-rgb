#include <stdio.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

int main()
{
    struct Student s[100], temp;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    /* Sort students alphabetically by name */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\nStudents sorted by Name:\n");
    printf("--------------------------------------\n");
    printf("Roll No\tName\t\tMarks\n");
    printf("--------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%-15s %.2f\n",
               s[i].rollNo, s[i].name, s[i].marks);
    }

    return 0;
}