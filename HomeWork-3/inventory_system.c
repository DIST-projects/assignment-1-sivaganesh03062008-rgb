#include <stdio.h>

struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
};

int main()
{
    struct Product p[100];
    int n, i;
    float totalValue = 0;

    printf("Enter number of products: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of product %d\n", i + 1);

        printf("Product ID: ");
        scanf("%d", &p[i].id);

        printf("Product Name: ");
        scanf(" %[^\n]", p[i].name);

        printf("Quantity: ");
        scanf("%d", &p[i].quantity);

        printf("Price per unit: ");
        scanf("%f", &p[i].price);

        totalValue += p[i].quantity * p[i].price;
    }

    printf("\n=========== INVENTORY ===========\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%-15s %d\t\t%.2f\n",
               p[i].id,
               p[i].name,
               p[i].quantity,
               p[i].price);
    }

    printf("---------------------------------------------\n");
    printf("Total Inventory Value = %.2f\n", totalValue);

    return 0;
}