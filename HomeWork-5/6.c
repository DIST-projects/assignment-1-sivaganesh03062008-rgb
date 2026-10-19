#include <stdio.h>

#define MAX 10

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow\n");
        return;
    }

    arr[++top1] = value;
}

void push2(int value)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow\n");
        return;
    }

    arr[--top2] = value;
}

int pop1()
{
    if (top1 == -1)
    {
        printf("Stack 1 Underflow\n");
        return -1;
    }

    return arr[top1--];
}

int pop2()
{
    if (top2 == MAX)
    {
        printf("Stack 2 Underflow\n");
        return -1;
    }

    return arr[top2++];
}

void displayStacks()
{
    printf("\nStack 1: ");

    for (int i = top1; i >= 0; i--)
        printf("%d ", arr[i]);

    printf("\nStack 2: ");

    for (int i = top2; i < MAX; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void displayArray()
{
    printf("\nArray contents:\n");

    for (int i = 0; i < MAX; i++)
    {
        if (i <= top1)
            printf("[%d] ", arr[i]);
        else if (i >= top2)
            printf("[%d] ", arr[i]);
        else
            printf("[ ] ");
    }

    printf("\n");
}

int main()
{
    push1(10);
    push1(20);
    push1(30);

    push2(90);
    push2(80);
    push2(70);

    printf("After pushing elements:\n");

    displayStacks();
    displayArray();

    printf("\nPop Stack 1 = %d\n", pop1());
    printf("Pop Stack 2 = %d\n", pop2());

    printf("\nAfter pop operations:\n");

    displayStacks();
    displayArray();

    return 0;
}