#include <stdio.h>
int main()
{
    int a = 0, s, n;
    scanf("%d", &n);   
    if(n==0){s=0;}
    else{s=1;}
    for(int i=0;i<n;i++){
        s+=a;
        a+=5;
    }
    printf("Sum of series upto N terms = %d", s);
    return 0;
}
