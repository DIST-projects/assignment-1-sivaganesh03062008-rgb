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

void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position)
{
    Node *newNode = createNode(data);

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void makeFirstAndThirdSame(Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        printf("At least 3 nodes are required.\n");
        return;
    }

    Node *first = head;
    Node *third = head->next->next;

    third->data = first->data;
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

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Original list:\n");
    display(head);

    insertAtPosition(&head, 99, 3);

    printf("After inserting 99 at position 3:\n");
    display(head);

    makeFirstAndThirdSame(head);

    printf("After making 1st and 3rd elements same:\n");
    display(head);

    return 0;
}