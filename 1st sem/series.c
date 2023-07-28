#include<stdio.h>

// sum of series 
// 1 - x^2/2! + x^4/4! - x^6/6!...................x^n/n!

int main(){

    float n,x,s=1;scanf("%f %f",&n,&x);
    float nu=1,de=1,j=1,a=1;
    for(int i=1;i<n;i++){
        de=de*j*(j+1);j+=2;
        nu=nu*x*x;
        a=a*(-1);
        s+=a*nu/de;
    }
    printf("%f",s);
    return 0;
}

