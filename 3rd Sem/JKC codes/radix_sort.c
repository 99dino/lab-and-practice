#include <stdio.h>
#include<limits.h>
void counting_sort(int a[],int n,int div){
    int count[10];
    for(int i=0;i<10;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[(a[i]/div)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    int sort_arr[n];
    for(int i=n-1;i>=0;i--){
        sort_arr[count[(a[i]/div)%10]-1]=a[i];
        count[(a[i]/div)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=sort_arr[i];
    }
}

void radix_sort(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    for(int i=1;max/i>0;i*=10){
        counting_sort(arr,n,i);
    }
}

int main(){
    // this version supports only +ve values
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
	radix_sort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}