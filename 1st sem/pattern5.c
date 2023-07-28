#include <stdio.h>

int main()
{

    int n=5;
    int a = 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a);
        a++;
    }
    a--;
    a--;
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", a);
        a--;
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        int c = 1;
        for (int j = 0; j < n - i; j++)
        {
            printf("%d ", c);
            c++;
        }
        c--;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < n - i; j++)
        {
            printf("%d ", c);
            c--;
        }
        printf("\n");
    }
    return 0;
}

// A B C D E D C B A
// A B C D   D C B A
// A B C       C B A
// A B           B A
// A               A
