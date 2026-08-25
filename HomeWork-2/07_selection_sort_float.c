#include <stdio.h>

int main()
{
    float arr[5] = {4.5, 2.1, 8.3, 1.2, 5.6};
    int i, j, min;
    float temp;

    for(i = 0; i < 4; i++)
    {
        min = i;

        for(j = i + 1; j < 5; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%.2f ", arr[i]);
    }

    return 0;
}