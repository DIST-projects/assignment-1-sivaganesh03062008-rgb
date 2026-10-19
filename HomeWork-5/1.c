#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} Node;

/* Create a new polynomial term */
Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

/* Insert term in descending order of exponent */
void insertTerm(Node **head, int coeff, int exp)
{
    if (coeff == 0)
        return;

    Node *newNode = createNode(coeff, exp);

    if (*head == NULL || (*head)->exp < exp)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;

    while (temp->next != NULL && temp->next->exp > exp)
        temp = temp->next;

    /* Same exponent */
    if (temp->next != NULL && temp->next->exp == exp)
    {
        temp->next->coeff += coeff;

        free(newNode);

        if (temp->next->coeff == 0)
        {
            Node *del = temp->next;
            temp->next = del->next;
            free(del);
        }

        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Add two polynomials */
Node *addPolynomial(Node *p, Node *q)
{
    Node *result = NULL;

    while (p != NULL)
    {
        insertTerm(&result, p->coeff, p->exp);
        p = p->next;
    }

    while (q != NULL)
    {
        insertTerm(&result, q->coeff, q->exp);
        q = q->next;
    }

    return result;
}

/* Scalar multiplication */
Node *scalarMultiply(Node *p, int scalar)
{
    Node *result = NULL;

    while (p != NULL)
    {
        insertTerm(&result, p->coeff * scalar, p->exp);
        p = p->next;
    }

    return result;
}

/* Display polynomial */
void display(Node *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }

    printf("\n");
}

int main()
{
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *sum = NULL;
    Node *scaled = NULL;

    int n, coeff, exp, scalar, i;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&p1, coeff, exp);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&p2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    sum = addPolynomial(p1, p2);

    printf("Addition: ");
    display(sum);

    printf("\nEnter scalar value: ");
    scanf("%d", &scalar);

    scaled = scalarMultiply(p1, scalar);

    printf("Scalar multiplication of Polynomial 1: ");
    display(scaled);

    return 0;
}