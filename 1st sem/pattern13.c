#include <stdio.h>

//          1
//        1   1
//      1   2   1
//    1   3   3   1
//  1   4   6   4   1

int fact(int a, int b)
{

    int x = 1, y = 1, c = (a - b), z = 1, w;
    while (a)
    {
        x = x * a;
        a--;
    }
    while (b)
    {
        y = y * b;
        b--;
    }
    while (c)
    {
        z = z * c;
        c--;
    }
    w = x / (y * z);
    return w;
}

int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < (n - i); j++)
        {
            printf("  ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            int a = fact(i, j);
            printf(" %d  ", a);
        }
        printf("\n");
    }
    return 0;
}