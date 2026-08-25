#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    int i;

    printf("Array elements:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }

    /* Modify elements */
    for(i = 0; i < 5; i++)
    {
        *(p + i) = *(p + i) + 5;
    }

    printf("\nAfter modification:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}