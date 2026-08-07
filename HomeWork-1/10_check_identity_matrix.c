#include <stdio.h>

int main()
{
    int a[10][10], n, i, j;
    int identity = 1;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix:\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j && a[i][j] != 1)
                identity = 0;

            if(i != j && a[i][j] != 0)
                identity = 0;
        }
    }

    if(identity)
        printf("The matrix is an identity matrix.\n");
    else
        printf("The matrix is not an identity matrix.\n");

    return 0;
}