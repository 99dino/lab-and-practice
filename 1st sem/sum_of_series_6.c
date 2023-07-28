#include <stdio.h>
int main()
{
    int a = 0, s, n;
    scanf("%d", &n);
    if(n==0){s=0;}
    else{s=1;}    
    for(int i=0;i<=n;i+=5){
        s+=i;
    }
    printf("Sum of series upto N = %d", s);
    return 0;
}