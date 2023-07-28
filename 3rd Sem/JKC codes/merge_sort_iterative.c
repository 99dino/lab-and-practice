#include<stdio.h>
// in built power function returns float/double values
// (causing some issue on applying that formula)
int power(int x, int y)
{
    int res = 1;
    for(int i=0;i<y;i++){
        res=res*x;
    }
    return res;
}

void merge(int array[],int start,int mid,int end){
    // using half array method
    int left[mid-start+1];
    int right[end-mid];
    for(int i=start;i<=mid;i++){
        left[i-start]=array[i];
    }
    for(int i=mid+1;i<=end;i++){
        right[i-mid-1]=array[i];
    }
    int i=0,j=0,k=start;
    while(i<mid-start+1&&j<end-mid){
        if(left[i]<right[j]){
            array[k++]=left[i++];
        }
        else{
            array[k++]=right[j++];
        }
    }
    while(i<mid-start+1){
        array[k++]=left[i++];
    }
    while(j<end-mid){
        array[k++]=right[j++];
    }
}

void mergesort(int a[],int n){
    // for loop runs log(n) times
    // length variable is the size of the array being sorted
    for(int length=1;length<n;length=length*2){
        // below for loops runs n times(linearly covering each element)
        // sorting subarray of size 'length'
        for(int i=0;i<n;i+=length*2){
            int start=i;
            int mid=i+length-1;
            int end=i+length*2-1;
            merge(a,start,mid,end);
        }
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
	mergesort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}