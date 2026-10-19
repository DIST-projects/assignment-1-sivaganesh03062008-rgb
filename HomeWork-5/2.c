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
        newNode->next = *head;
        return;
    }

    Node *temp = *head;

    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

Node *findPrevious(Node *head, int key)
{
    if (head == NULL)
        return NULL;

    Node *prev = head;
    Node *current = head->next;

    /* If key is at head, previous is last node */
    while (current != head)
    {
        if (current->data == key)
            return prev;

        prev = current;
        current = current->next;
    }

    /* Check head */
    if (head->data == key)
        return prev;

    return NULL;
}

void display(Node *head)
{
    if (head == NULL)
        return;

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

int main()
{
    Node *head = NULL;
    Node *previous;
    int n, data, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Circular Linked List: ");
    display(head);

    printf("Enter element to find previous node: ");
    scanf("%d", &key);

    previous = findPrevious(head, key);

    if (previous != NULL)
        printf("Previous node of %d = %d\n", key, previous->data);
    else
        printf("Element not found.\n");

    return 0;
}