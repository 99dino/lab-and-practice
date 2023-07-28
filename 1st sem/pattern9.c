#include <stdio.h>

// A
// B A
// A B A
// B A B A
// A B A B A

int main()
{

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char a = 'A';
        int x = i % 2;
        a += i % 2;
        for (int j = 0; j <= i; j++)
        {
            printf("%c ", a);
            if (x == 0)
            {
                a++;
                x = 1;
            }
            else
            {
                a--;
                x = 0;
            }
        }
        printf("\n");
    }
    return 0;
}