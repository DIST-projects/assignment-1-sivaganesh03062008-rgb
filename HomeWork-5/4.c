#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    q->data[++q->rear] = value;
}

void display(Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->data[i]);

    printf("\n");
}

int secondLargest(Queue *q, int *found)
{
    int largest = INT_MIN;
    int second = INT_MIN;

    *found = 0;

    for (int i = q->front; i <= q->rear; i++)
    {
        int x = q->data[i];

        if (x > largest)
        {
            second = largest;
            largest = x;
        }
        else if (x > second && x != largest)
        {
            second = x;
        }
    }

    if (second != INT_MIN)
        *found = 1;

    return second;
}

int main()
{
    Queue q;
    int n, value, found;

    initialize(&q);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter queue elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printf("Queue: ");
    display(&q);

    int result = secondLargest(&q, &found);

    if (found)
        printf("Second largest element = %d\n", result);
    else
        printf("Second largest element does not exist.\n");

    return 0;
}