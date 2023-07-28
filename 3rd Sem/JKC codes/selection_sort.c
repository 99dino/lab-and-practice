#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int arr[],int n){
    // traversing upto n-2 as last element gets automatically 
    // correctly placed when rest of the elements get sorted
	for(int i=0;i<n-1;i++){
        // assuming ith index is to be having smallest value among arr[i...n-1]
		int min=i;
		for(int j=i+1;j<n;j++){
            // finding the index having smallest value in arr[i...n-1]
			if(arr[j]<arr[min])
				min=j;
		}
        // swapping if ith element is not smallest among arr[i+1...n-1]
        if(min!=i)
    		swap(&arr[min],&arr[i]);
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
	selection_sort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}