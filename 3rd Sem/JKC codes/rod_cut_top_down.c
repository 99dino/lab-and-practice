#include<stdio.h>
// meomized top down version

int max(int a,int b){
    return (a>b?a:b);
}

int rod_cut(int profit[],int result[],int n){
    int max_prof=profit[n];
    for(int i=1;i<n;i++){
        if(result[n-i]==0){
            result[n-i]=rod_cut(profit,result,n-i);
        }
        max_prof=max(max_prof,profit[i]+result[n-i]);
    }
    return max_prof;
}

int main(){
    int n;
    printf("Enter total size of rod : ");
    scanf("%d",&n);
    int profit[n+1],result[n+1];
    printf("Enter profit of rods of respective sizes : ");
    for(int i=1;i<=n;i++){
        scanf("%d",&profit[i]);
        result[i]=0;
    }
    printf("Maximum profit is %d",rod_cut(profit,result,n));
}