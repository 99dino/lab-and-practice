#include<stdio.h>

void insertion_sort(int arr[],int n){
	for(int i=1;i<n;i++){
		// stored ith element to avoid override or loss
        int key=arr[i];
        int j=i-1;
		while(j>=0&&arr[j]>key){
            // shifting right if jth element is greater than the key
			arr[j+1]=arr[j];
			j--;
		}
        // putting key element to its correct position
		arr[j+1]=key;
	}
}

int main(){
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
	insertion_sort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}