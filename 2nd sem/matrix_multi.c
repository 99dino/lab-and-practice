#include<stdio.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ld long double
#define nl printf("\n")

int main(){
    int n,m;
    printf("Enter dimension of 1st matrix: ");
    scanf("%d%d",&n,&m);
    int a[n][m];
    printf("Enter 1st matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",(*a+i*m+j));
        }
    }
    int x,y;
    printf("Enter dimension of 2nd matrix: ");
    scanf("%d%d",&x,&y);
    int b[x][y];
    printf("Enter 2nd matrix:\n");
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            scanf("%d",(*b+i*y+j));
        }
    }
    int c[n][y];
    if(m!=x){
        printf("can't multiply");
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s=0;
                for(int k=0;k<m;k++){
                    s+=(*(*a+i*m+k)) * (*(*b+k*m+j));
                }
                *(*c+i*m+j)=s;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<y;j++){
            printf("%d ",*(*c+i*y+j));
        }
        printf("\n");
    }
    return 0;
}