#include <stdio.h>

// A B C D E F G H I
// A B C D   E F G H
// A B C       D E F
// A B           C D
// A               B

int main()
{

    int n;
    scanf("%d", &n);
    char a = 'A';
    for (int i = 0; i < 2 * n - 1; i++)
    {
        printf("%c ", a);
        a++;
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        char c = 'A';
        for (int j = 0; j < n - i; j++)
        {
            printf("%c ", c);
            c++;
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < n - i; j++)
        {
            printf("%c ", c);
            c++;
        }
        printf("\n");
    }

    return 0;
}