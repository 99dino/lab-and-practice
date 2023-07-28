#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int array[],int start,int end){
    // this version takes last as element as the PIVOT element
    int pivot=array[end];
    int j=start-1;

    for(int i=start;i<end;i++){
        // element found smaller than the pivot element gets-
        // -placed from the left side of the subarray
        if(array[i]<pivot){
            j++;
            swap(&array[j],&array[i]);
        }
    }
    // placing pivot at its correct position
    swap(&array[j+1],&array[end]);
    // returned the index of pivot element when placed at its correct position
    return j+1;
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