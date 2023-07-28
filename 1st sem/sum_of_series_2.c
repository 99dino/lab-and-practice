#include <stdio.h>
int main()
{
    int n,s=0;
    scanf("%d", &n);
    for(int i=11;i<=n;i++){
        s+=i;
    }
    printf("Sum of series upto N = %d", s);
    return 0;
}