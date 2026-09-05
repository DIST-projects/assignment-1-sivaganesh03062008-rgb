#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main()
{
    struct Employee emp[100];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Department: ");
        scanf(" %[^\n]", emp[i].department);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    printf("\n========== EMPLOYEE DETAILS ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("ID         : %d\n", emp[i].id);
        printf("Name       : %s\n", emp[i].name);
        printf("Department : %s\n", emp[i].department);
        printf("Salary     : %.2f\n", emp[i].salary);
    }

    return 0;
}