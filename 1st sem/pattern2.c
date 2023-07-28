#include <stdio.h>

// *                 *
// * *             * *
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *
// * * * * * * * * * *
// * * * *     * * * *
// * * *         * * *
// * *             * *
// *                 *

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        for (int j = 1; j <= n * 2 - 2 * i; j++)
        {
            printf("  ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            printf("* ");
        }
        for (int j = 1; j <= 2 * i; j++)
        {
            printf("  ");
        }
        for (int j = n - i; j > 0; j--)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}