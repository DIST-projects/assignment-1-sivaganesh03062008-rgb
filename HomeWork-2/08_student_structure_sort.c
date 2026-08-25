#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    char name[30];
    float grade;
};

int main()
{
    struct Student s[5] =
    {
        {3, "Arun", 8.5},
        {1, "Bala", 9.2},
        {5, "David", 7.8},
        {2, "Cathy", 8.9},
        {4, "Ezhil", 9.5}
    };

    struct Student temp;
    int i, j, choice;

    printf("1. Sort by ID\n");
    printf("2. Sort by Name\n");
    printf("3. Sort by Grade\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    for(i = 0; i < 4; i++)
    {
        for(j = i + 1; j < 5; j++)
        {
            int condition = 0;

            if(choice == 1 && s[i].id > s[j].id)
                condition = 1;

            if(choice == 2 && strcmp(s[i].name, s[j].name) > 0)
                condition = 1;

            if(choice == 3 && s[i].grade > s[j].grade)
                condition = 1;

            if(condition)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    printf("\nSorted Students:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d %s %.2f\n",
               s[i].id,
               s[i].name,
               s[i].grade);
    }

    return 0;
}