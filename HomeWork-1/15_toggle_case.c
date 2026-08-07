#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[200];
    int i;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(islower((unsigned char)str[i]))
            str[i] = toupper((unsigned char)str[i]);

        else if(isupper((unsigned char)str[i]))
            str[i] = tolower((unsigned char)str[i]);
    }

    printf("Toggled sentence:\n%s", str);

    return 0;
}