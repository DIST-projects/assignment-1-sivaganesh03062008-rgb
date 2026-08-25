#include <stdio.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    int i;

    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int output[100];
    int count[10] = {0};
    int i;

    for(i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];

    for(i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    int exp;

    for(exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    int arr[] = {-170, -45, -75, -90, -802, -24, -2};
    int n = 7;

    int negative[100];
    int positive[100];

    int nNeg = 0, nPos = 0;
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] < 0)
            negative[nNeg++] = -arr[i];
        else
            positive[nPos++] = arr[i];
    }

    radixSort(negative, nNeg);
    radixSort(positive, nPos);

    printf("Sorted array:\n");

    /* Negative numbers in reverse order */
    for(i = nNeg - 1; i >= 0; i--)
        printf("%d ", -negative[i]);

    /* Positive numbers */
    for(i = 0; i < nPos; i++)
        printf("%d ", positive[i]);

    return 0;
}