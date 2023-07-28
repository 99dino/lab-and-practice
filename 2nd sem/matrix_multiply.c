#include <stdio.h>

int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];int b[m][n],c[n][n];
    printf("enter matrix a of order %d %d",n,m);


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d ",&a[i][j]);
        }
    }

    printf("\nenter matrix b of order %d %d",m,n);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d ",&b[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int s=0;
            for(int k=0;k<m;k++){
                s+=a[i][k]*b[k][j];
            }
            c[i][j]=s;
        }
    }

    printf("\nmatrix c of order %d %d\n",n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}