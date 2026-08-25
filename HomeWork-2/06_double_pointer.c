#include <stdio.h>

int main()
{
    int x = 10;

    int *p = &x;

    int **q = &p;

    printf("Value of x = %d\n", x);
    printf("Address of x = %p\n", (void *)&x);

    printf("\nValue of p = %p\n", (void *)p);
    printf("Address of p = %p\n", (void *)&p);
    printf("Value pointed by p = %d\n", *p);

    printf("\nValue of q = %p\n", (void *)q);
    printf("Address of q = %p\n", (void *)&q);
    printf("Value pointed by q = %p\n", (void *)*q);
    printf("Final value = %d\n", **q);

    return 0;
}