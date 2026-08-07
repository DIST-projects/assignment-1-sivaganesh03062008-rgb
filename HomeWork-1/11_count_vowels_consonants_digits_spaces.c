#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[200];
    int i;
    int vowels = 0, consonants = 0;
    int digits = 0, spaces = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(isalpha((unsigned char)str[i]))
        {
            if(str[i] == 'a' || str[i] == 'e' ||
               str[i] == 'i' || str[i] == 'o' ||
               str[i] == 'u' ||
               str[i] == 'A' || str[i] == 'E' ||
               str[i] == 'I' || str[i] == 'O' ||
               str[i] == 'U')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        else if(isdigit((unsigned char)str[i]))
        {
            digits++;
        }
        else if(isspace((unsigned char)str[i]))
        {
            spaces++;
        }
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);
    printf("Digits = %d\n", digits);
    printf("White spaces = %d\n", spaces);

    return 0;
}