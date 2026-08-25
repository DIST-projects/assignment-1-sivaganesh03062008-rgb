#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[30];
    float mark;
};

int main()
{
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *p;

    p = (struct Student *)malloc(n * sizeof(struct Student));

    if(p == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &(p + i)->id);

        printf("Name: ");
        scanf("%s", (p + i)->name);

        printf("Mark: ");
        scanf("%f", &(p + i)->mark);
    }

    printf("\nStudent Details:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d %s %.2f\n",
               (p + i)->id,
               (p + i)->name,
               (p + i)->mark);
    }

    /* Modify first student's mark */
    (p + 0)->mark = 100;

    printf("\nAfter modification:\n");
    printf("%d %s %.2f",
           p->id,
           p->name,
           p->mark);

    free(p);

    return 0;
}
