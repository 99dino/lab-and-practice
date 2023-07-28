#include<stdio.h>
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n,m;scanf("%d%d",&n,&m);
    int a[n][m];
    rep(i,n){
        rep(j,m){
            scanf("%d",(*a+i*m+j));
        }
    }
    rep(i,n){
        //j is the address of the first element of ith row
        //k is the address of the last element of ith row
        int *j=(*a+i*m),*k=(*a+i*m+m-1);
        //two pointer way
        //loop will run till pointer j is less tha pointer k
        while(j<k){
            *k=*j+*k;
            *j=*k-*j;
            *k=*k-*j;
            j++;k--;
            //inc pointer p and dec pointer k
        }
    }
    printf("\nafter reversing row:\n");
    //printing array
    rep(i,n){
        rep(j,m){
            printf("%d ",*(*a+i*m+j));
        }
        printf("\n");
    }
    return 0;
}