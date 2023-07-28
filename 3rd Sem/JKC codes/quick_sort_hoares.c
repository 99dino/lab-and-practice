#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int array[],int start,int end){
    // this version takes first element as the PIVOT element
    int i=start, j=end, pivot=array[start];
    while(i<j){
        // finding leftmost element greater than the pivot element
        while(i<=end && array[i]<=pivot){
            i++;
        }

        // finding rightmost element less than the pivot element
        while(j>=start && array[j]>pivot){
            j--;
        }

        if(i<j){
            swap(&array[i],&array[j]);
        }
    }
    // swapping end with pivot to place pivot at its correct position
    swap( &array[start], &array[j]);
    return j;
}

void quick_sort(int array[],int start,int end){
    if(start < end){
        int p=partition(array,start,end);
        quick_sort(array,start,p-1);
        quick_sort(array,p+1,end);
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
    // passing array, starting index = 0 and ending index = n-1
	quick_sort(arr,0,n-1);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}