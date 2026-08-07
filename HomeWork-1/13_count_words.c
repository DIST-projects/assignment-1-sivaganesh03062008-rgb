#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[200];
    int i, words = 0;
    int inWord = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(!isspace((unsigned char)str[i]) && inWord == 0)
        {
            words++;
            inWord = 1;
        }
        else if(isspace((unsigned char)str[i]))
        {
            inWord = 0;
        }
    }

    printf("Number of words = %d\n", words);

    return 0;
}