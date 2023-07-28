#include <stdio.h>
#include<limits.h>

void counting_sort_adv(int a[],int n){
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>mx)
            mx=a[i];
        if(a[i]<mn)
            mn=a[i];
    }
    int count[mx-mn+1];
    for(int i=0;i<=mx-mn;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[a[i]-mn]++;
    }
    for(int i=1;i<=mx-mn;i++){
        count[i]+=count[i-1];
    }
    int sort_arr[n];
    for(int i=n-1;i>=0;i--){
        sort_arr[count[a[i]-mn]-1]=a[i];
        count[a[i]-mn]--;
    }
    for(int i=0;i<n;i++){
        a[i]=sort_arr[i];
    }
}

int main(){
    // this version can handle +ve & -ve values both
    // (range should be small)
    int n;
	printf("Enter No of elements: ");
    scanf("%d",&n);
	int arr[n];
    printf("Enter %d elements: ",n);
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	printf("Before sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
	counting_sort_adv(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}