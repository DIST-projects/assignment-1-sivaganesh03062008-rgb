#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int digit;
    struct Node *next;
} Node;

Node *createNode(int digit)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->digit = digit;
    newNode->next = NULL;

    return newNode;
}

/* Create linked list from a number string */
Node *createFromString(char str[])
{
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            continue;

        Node *newNode = createNode(str[i] - '0');

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int length(Node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

/* Convert linked list into digit array */
void listToArray(Node *head, int arr[])
{
    int i = 0;

    while (head != NULL)
    {
        arr[i++] = head->digit;
        head = head->next;
    }
}

/* Convert result array into linked list */
Node *arrayToList(int arr[], int n)
{
    int i = 0;

    /* Remove leading zeroes */
    while (i < n - 1 && arr[i] == 0)
        i++;

    Node *head = NULL;
    Node *tail = NULL;

    for (; i < n; i++)
    {
        Node *newNode = createNode(arr[i]);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

/* Multiply two linked-list numbers */
Node *multiply(Node *a, Node *b)
{
    int n = length(a);
    int m = length(b);

    int *x = (int *)calloc(n, sizeof(int));
    int *y = (int *)calloc(m, sizeof(int));
    int *result = (int *)calloc(n + m, sizeof(int));

    listToArray(a, x);
    listToArray(b, y);

    /* Multiply digit pairs */
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int position = i + j + 1;

            result[position] += x[i] * y[j];
        }
    }

    /* Handle carries */
    for (int i = n + m - 1; i > 0; i--)
    {
        result[i - 1] += result[i] / 10;
        result[i] = result[i] % 10;
    }

    Node *answer = arrayToList(result, n + m);

    free(x);
    free(y);
    free(result);

    return answer;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->digit);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main()
{
    char num1[100];
    char num2[100];

    printf("Enter first number: ");
    scanf("%99s", num1);

    printf("Enter second number: ");
    scanf("%99s", num2);

    Node *a = createFromString(num1);
    Node *b = createFromString(num2);

    printf("\nNumber 1: ");
    display(a);

    printf("Number 2: ");
    display(b);

    Node *product = multiply(a, b);

    printf("Product: ");
    display(product);

    return 0;
}