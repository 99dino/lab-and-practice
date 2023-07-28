#include <stdio.h>
// 6                       6
// 6 5                   5 6
// 6 5 4               4 5 6
// 6 5 4 3           3 4 5 6
// 6 5 4 3 2       2 3 4 5 6
// 6 5 4 3 2 1   1 2 3 4 5 6
// 6 5 4 3 2 1 0 1 2 3 4 5 6
// 6 5 4 3 2 1   1 2 3 4 5 6
// 6 5 4 3 2       2 3 4 5 6
// 6 5 4 3           3 4 5 6
// 6 5 4               4 5 6
// 6 5                   5 6
// 6                       6

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a = n;
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", a);
            a--;
        }
        a++;
        for (int j = 1; j <= 2 * (n - i + 1) - 1; j++)
        {
            printf("  ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", a);
            a++;
        }
        printf("\n");
    }
    for (int i = n; i >= 1; i--)
    {
        printf("%d ", i);
    }
    printf("0 ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        int a = n;
        for (int j = n; j >= i; j--)
        {
            printf("%d ", j);
        }
        for (int j = 1; j <= 2 * (i)-1; j++)
        {
            printf("  ");
        }
        for (int j = i; j <= n; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}