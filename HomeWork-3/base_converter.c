#include <stdio.h>

void decimalToBinary(int n)
{
    int binary[32];
    int i = 0;

    if (n == 0)
    {
        printf("0");
        return;
    }

    while (n > 0)
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    while (i > 0)
    {
        printf("%d", binary[--i]);
    }
}

void decimalToOctal(int n)
{
    int octal[32];
    int i = 0;

    if (n == 0)
    {
        printf("0");
        return;
    }

    while (n > 0)
    {
        octal[i] = n % 8;
        n = n / 8;
        i++;
    }

    while (i > 0)
    {
        printf("%d", octal[--i]);
    }
}

void decimalToHexadecimal(int n)
{
    char hex[32];
    int remainder;
    int i = 0;

    if (n == 0)
    {
        printf("0");
        return;
    }

    while (n > 0)
    {
        remainder = n % 16;

        if (remainder < 10)
            hex[i] = remainder + '0';
        else
            hex[i] = remainder - 10 + 'A';

        n = n / 16;
        i++;
    }

    while (i > 0)
    {
        printf("%c", hex[--i]);
    }
}

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("\nBinary      = ");
    decimalToBinary(decimal);

    printf("\nOctal       = ");
    decimalToOctal(decimal);

    printf("\nHexadecimal = ");
    decimalToHexadecimal(decimal);

    printf("\n");

    return 0;
}