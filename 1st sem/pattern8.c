#include <stdio.h>

// 1
// 2 3
// 4 5 6
// 7 8 9 0
// 1 2 3 4 5

int main()
{

    int n, a = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a == 10)
            {
                a = 0;
            }
            printf("%d ", a);
            a++;
        }
        printf("\n");
    }

    return 0;
}