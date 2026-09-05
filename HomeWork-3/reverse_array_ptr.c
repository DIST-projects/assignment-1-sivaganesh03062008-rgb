#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = &arr[n - 1];

    printf("Array in reverse order:\n");

    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", *ptr);
        ptr--;
    }

    printf("\n");

    return 0;
}