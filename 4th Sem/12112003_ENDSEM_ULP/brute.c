#include<stdio.h>

int main(){
	int a,r,n;
	scanf("%d%d%d",&a,&r,&n);
	int gpsum=0;
	for(int i=0;i<n;i++){
		gpsum+=a;
		a=a*r;
	}
	printf("%d",gpsum);
	return 0;
}

