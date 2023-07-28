#include <stdio.h>
#include <string.h>

int main()
{

    char a[100000];
    printf("enter a string\n-> ");
    gets(a);
    for (int i = 0; a[i] != '\0'; i++)
    {
        //difference of 32 in ascii value of small and capital letter 
        if (a[i] <= 90 && a[i] >= 65)
        {
            a[i] = a[i] + 32;
        }
        else if (a[i] <= 122 && a[i] >= 97)
        {
            a[i] = a[i] - 32;
        }
    }
    puts(a);
    return 0;
}