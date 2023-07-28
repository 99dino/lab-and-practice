#include<stdio.h>

void merge(int array[],int start,int mid,int end){
    int temp_array[end-start+1];
    int k=0,i=start,j=mid+1;
    // putting elements of the subarray in temp_array in sorted manner
    while(i<=mid&&j<=end){
        if(array[i]<array[j]){
            temp_array[k++]=array[i++];
        }
        else{
            temp_array[k++]=array[j++];
        }
    }
    while(i<=mid){
        temp_array[k++]=array[i++];
    }
    while(j<=end){
        temp_array[k++]=array[j++];
    }
    // copied back the temp_array into the original subarray 
    for(int i=start;i<=end;i++){
    	array[i]=temp_array[i-start];
    }
}

void merge(int a[],int s,int m,int e){
    int arr[e-s+1];
    int x=s,y=m+1,i=0;
    while(x<=m&&y<=e){
        if(a[x]>a[y])
            arr[i++]=a[y++];
        else
            arr[i++]=a[x++];
    }
    while(x<=m)
        arr[i++]=a[x++];
    while(y<=e)
        arr[i++]=a[y++];
    for(int i=s;i<=e;i++){
        a[i]=arr[i-s];
    }
}

void merge_sort(int array[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        merge_sort(array,start,mid);
        merge_sort(array,mid+1,end);
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