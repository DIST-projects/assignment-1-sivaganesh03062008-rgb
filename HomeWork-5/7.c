#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->bottom = NULL;

    return newNode;
}

void addBottom(Node *head, int data)
{
    Node *newNode = createNode(data);

    while (head->bottom != NULL)
        head = head->bottom;

    head->bottom = newNode;
}

/* Merge two sorted bottom lists */
Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    Node *result;

    if (a->data <= b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    return result;
}

/* Flatten multi-level list */
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);

    root = merge(root, root->next);

    return root;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->bottom != NULL)
            printf(" -> ");

        head = head->bottom;
    }

    printf("\n");
}

int main()
{
    Node *head1 = createNode(5);
    Node *head2 = createNode(10);
    Node *head3 = createNode(19);
    Node *head4 = createNode(28);

    /* Main list */
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;

    /* Bottom lists */
    addBottom(head1, 7);
    addBottom(head1, 8);

    addBottom(head2, 20);

    addBottom(head3, 22);

    addBottom(head4, 40);
    addBottom(head4, 45);

    head1 = flatten(head1);

    printf("Flattened sorted linked list:\n");
    display(head1);

    return 0;
}