#include <stdio.h>

void add(int a, int b)
{
    printf("Sum = %d\n", a + b);
}

void multiply(int a, int b)
{
    printf("Product = %d\n", a * b);
}

int main()
{
    void (*ptr)(int, int);

    ptr = add;
    ptr(10, 5);

    ptr = multiply;
    ptr(10, 5);

    return 0;
}