#include <stdio.h>

// * * * * * * * * *
// * * * *   * * * *
// * * *       * * *
// * *           * *
// *               *

int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2*n-1; i++)
    {
        printf("%s", "* ");
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            printf("%s", "* ");
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < n-i; j++)
        {
            printf("%s", "* ");
        }
        printf("\n");
    }
    return 0;
}