#include <stdio.h>
int main()
{
    int a = 1, b = 1, s = 0, n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        s+=b*a;
        a=a+2;
        b=b*(-1);
    }
    printf("Sum of series upto N times = %d", s);
    return 0;
}
