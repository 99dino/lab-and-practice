#include <stdio.h>
#include <string.h>

int main()
{

    char s[100000];
    printf("Enter a string\n-> ");
    gets(s);
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            c++;
        }
        else
        {
            if (c == 1)
            {
                printf("  ");
            }
            else if (c == 2)
            {
                printf("\t");
            }
            else if (c == 3)
            {
                printf("\n");
            }
            printf("%c", s[i]);
            c = 0;
        }
    }
    return 0;
}