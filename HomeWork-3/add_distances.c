#include <stdio.h>

struct Distance
{
    int feet;
    float inch;
};

int main()
{
    struct Distance d[100], sum = {0, 0};
    int n, i;

    printf("Enter number of distances: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter distance %d\n", i + 1);

        printf("Feet: ");
        scanf("%d", &d[i].feet);

        printf("Inches: ");
        scanf("%f", &d[i].inch);

        sum.feet += d[i].feet;
        sum.inch += d[i].inch;
    }

    /* Convert inches greater than or equal to 12 into feet */
    sum.feet += (int)(sum.inch / 12);
    sum.inch = sum.inch - ((int)(sum.inch / 12) * 12);

    printf("\nTotal Distance = %d feet %.2f inches\n",
           sum.feet, sum.inch);

    return 0;
}