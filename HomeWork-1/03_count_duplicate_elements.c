#include <stdio.h>

int main()
{
    int a[100], n, i, j;
    int count = 0, duplicate;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
    {
        duplicate = 0;

        for(j = 0; j < i; j++)
        {
            if(a[i] == a[j])
            {
                duplicate = 1;
                break;
            }
        }

        if(duplicate == 0)
        {
            for(j = i + 1; j < n; j++)
            {
                if(a[i] == a[j])
                {
                    count++;
                    break;
                }
            }
        }
    }

    printf("Total number of duplicate elements = %d\n", count);

    return 0;
}