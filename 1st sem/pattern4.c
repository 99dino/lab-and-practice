#include <stdio.h>

//         A
//       B A
//     C B A
//   D C B A
// E D C B A

int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char c = 'A';
        c += i - 1;
        for (int j = 0; j < n - i; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("%c ", c);
            c--;
        }
        printf("\n");
    }
    return 0;
}