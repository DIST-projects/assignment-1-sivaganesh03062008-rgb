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

void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;

    do
    {
        printf("%d", temp->data);
        temp = temp->next;

        if (temp != head)
            printf(" -> ");

    } while (temp != head);

    printf(" -> HEAD\n");
}

void insertAtPosition(Node **head, int data, int position)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        if (position == 1)
        {
            *head = newNode;
            newNode->next = newNode;
        }
        else
        {
            printf("Invalid position\n");
            free(newNode);
        }

        return;
    }

    /* Insert at beginning */
    if (position == 1)
    {
        Node *last = *head;

        while (last->next != *head)
            last = last->next;

        newNode->next = *head;
        last->next = newNode;
        *head = newNode;

        return;
    }

    Node *temp = *head;

    for (int i = 1; i < position - 1 && temp->next != *head; i++)
        temp = temp->next;

    if (temp->next == *head && position > 2)
    {
        /* Allow insertion at the end */
        newNode->next = *head;
        temp->next = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main()
{
    Node *head = NULL;

    int values[] = {10, 20, 30, 40};

    for (int i = 0; i < 4; i++)
        insertAtPosition(&head, values[i], i + 1);

    printf("Original list:\n");
    display(head);

    insertAtPosition(&head, 25, 3);

    printf("After inserting 25 at position 3:\n");
    display(head);

    return 0;
}