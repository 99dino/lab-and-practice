#include <stdio.h>
int main()
{
    int a = 2, s = 0, n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        s+=a;
        a=a*2;
    }
    printf ("Sum of series upto N terms = %d", s);
    return 0;
}
