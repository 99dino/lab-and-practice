#include<stdio.h>

void merge(int array[],int start,int mid,int end){
    int left[mid-start+1];
    int right[end-mid];
    // copying left half in array named 'left'
    for(int i=start;i<=mid;i++){
        left[i-start]=array[i];
    }
    // copying right half in array named 'right'
    for(int i=mid+1;i<=end;i++){
        right[i-mid-1]=array[i];
    }

    int i=0,j=0,k=start;
    // merging 2 sorted arrays in linear time
    while(i<mid-start+1&&j<end-mid){
        // comparing leftmost uncovered element of both the arrays and 
        // putting it right back into the original array at its correct place
        if(left[i]<right[j]){
            array[k++]=left[i++];
        }
        else{
            array[k++]=right[j++];
        }
    }
    // making sure that each sub_array is fully covered
    while(i<mid-start+1){
        array[k++]=left[i++];
    }
    while(j<end-mid){
        array[k++]=right[j++];
    }
}

void merge_sort(int array[],int start,int end){
    if(start<end){
        // dividing in half
        int mid=(start+end)/2;
        // recursively called merge_sort on both the sub_problems
        merge_sort(array,start,mid);
        merge_sort(array,mid+1,end);
        // merging two sorted arrays
        merge(array, start,mid, end);
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
	merge_sort(arr,0,n-1);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}