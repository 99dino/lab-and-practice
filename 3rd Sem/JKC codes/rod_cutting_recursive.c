// recursive version of rod cut( exponenetial)

#include<stdio.h>

int max(int a,int b){
    return (a>b?a:b);
}

int rod_cut(int profit[],int n){
    if(n>0){
        for(int i=1;i<=n-1;i++){
            profit[n]=max(profit[n],profit[i]+rod_cut(profit,n-i));
        }
    }
    return profit[n];
}

int main(){
    int n;
    printf("Enter total size of rod : ");
    scanf("%d",&n);
    int profit[n+1];
    printf("Enter profit of rods of respective sizes : ");
    for(int i=1;i<=n;i++){
        scanf("%d",&profit[i]);
    }
    printf("Maximum profit is %d",rod_cut(profit,n));
}