#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Node *append(Node *head, int data)
{
    Node *newNode = createNode(data);

    if (head == NULL)
        return newNode;

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

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

Node *swapKth(Node *head, int k)
{
    int n = length(head);

    if (k < 1 || k > n)
        return head;

    int pos2 = n - k + 1;

    /* Same node */
    if (k == pos2)
        return head;

    /* Make first node position smaller */
    if (k > pos2)
    {
        int temp = k;
        k = pos2;
        pos2 = temp;
    }

    Node *x = head;
    Node *xPrev = NULL;

    for (int i = 1; i < k; i++)
    {
        xPrev = x;
        x = x->next;
    }

    Node *y = head;
    Node *yPrev = NULL;

    for (int i = 1; i < pos2; i++)
    {
        yPrev = y;
        y = y->next;
    }

    /* Adjacent nodes */
    if (x->next == y)
    {
        if (xPrev != NULL)
            xPrev->next = y;
        else
            head = y;

        x->next = y->next;
        y->next = x;
    }
    else
    {
        if (xPrev != NULL)
            xPrev->next = y;
        else
            head = y;

        if (yPrev != NULL)
            yPrev->next = x;

        Node *temp = x->next;

        x->next = y->next;
        y->next = temp;
    }

    return head;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main()
{
    Node *head = NULL;

    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    head = append(head, 40);
    head = append(head, 50);
    head = append(head, 60);
    head = append(head, 70);

    int k = 2;

    printf("Original list:\n");
    display(head);

    head = swapKth(head, k);

    printf("After swapping %dth node from beginning and end:\n", k);
    display(head);

    return 0;
}