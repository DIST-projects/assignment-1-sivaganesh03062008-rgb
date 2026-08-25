#include <stdio.h>

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5];

    int *p = arr1;
    int *q = arr2;

    int i;

    for(i = 0; i < 5; i++)
    {
        *(q + i) = *(p + i);
    }

    printf("Copied array:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", *(q + i));
    }

    return 0;
}