#include<stdio.h>

long int power(long int a,long int b){
	long int ans=1;
	for(int i=1;i<=b;i++){
		ans*=a;
	}
	return ans;
}

int main(){
	long int a,r,n;
	scanf("%ld%ld%ld",&a,&r,&n);
	long int gpsum=a*(power(r,n)-1)/(r-1);
	printf("%ld",gpsum);
	return 0;
}
