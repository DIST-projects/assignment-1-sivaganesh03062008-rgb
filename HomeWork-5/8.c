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

/* Merge two sorted lists */
Node *mergeTwo(Node *a, Node *b)
{
    Node dummy;
    Node *tail = &dummy;

    dummy.next = NULL;

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    if (a != NULL)
        tail->next = a;
    else
        tail->next = b;

    return dummy.next;
}

/* Divide and conquer */
Node *mergeK(Node *lists[], int left, int right)
{
    if (left > right)
        return NULL;

    if (left == right)
        return lists[left];

    int mid = (left + right) / 2;

    Node *leftList = mergeK(lists, left, mid);
    Node *rightList = mergeK(lists, mid + 1, right);

    return mergeTwo(leftList, rightList);
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
    Node *lists[10];

    int k;

    printf("Enter number of sorted lists: ");
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        int n, value;

        lists[i] = NULL;

        printf("Enter number of elements in List %d: ", i + 1);
        scanf("%d", &n);

        printf("Enter sorted elements:\n");

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &value);
            lists[i] = append(lists[i], value);
        }
    }

    Node *result = mergeK(lists, 0, k - 1);

    printf("\nMerged sorted list:\n");
    display(result);

    return 0;
}