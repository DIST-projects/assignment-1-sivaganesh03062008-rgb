#include <stdio.h>
#include <string.h>

int main()
{
    char str[20][50], temp[50];
    int n, i, j;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");

    for(i = 0; i < n; i++)
        scanf("%49s", str[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("Sorted strings:\n");

    for(i = 0; i < n; i++)
        printf("%s\n", str[i]);

    return 0;
}