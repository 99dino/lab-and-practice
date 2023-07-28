#include <stdio.h>
int main()
{
    int s = 0, n;
    scanf("%d", &n);
    for(int i=5;i<=n;i+=2){
        s+=i;
    }
    printf("Sum of series upto N = %d", s);
    return 0;
}