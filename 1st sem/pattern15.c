#include <stdio.h>

//               1
//              121
//             12321
//            1234321
//           123454321
//          12345654321
//         1234567654321
//        123456787654321
//       12345678987654321
//      1234567890987654321
//     123456789010987654321
//    12345678901210987654321
//   1234567890123210987654321
//  123456789012343210987654321
// 12345678901234543210987654321

int main()
{

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a = 1;
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            if (a > 9)
            {
                a = 0;
            }
            printf("%d", a);
            a++;
        }
        a--;
        a--;
        for (int j = 1; j < i; j++)
        {
            if (a < 0)
            {
                a = 9;
            }
            printf("%d", a);
            a--;
        }
        printf("\n");
    }
    return 0;
}