#include<stdio.h>
int Initial_size;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void non_recursive_max_heapify(int arr[],int i,int n){
    for(int j=i;j<=n;){
        int max=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=n && arr[left]>arr[max])
            max=left;
        if(right<=n && arr[right]>arr[max])
            max=right;
        if(max!=i){
            swap(&arr[max],&arr[i]);
            j=max;
            // shifting j to that place on which heapify is to
            // be applied(in iterative way using for loop)
        }
        else
            break;
    }
}

void max_heapify(int arr[],int i,int n){
    int max=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left]>arr[max])
        max=left;
    if(right<=n && arr[right]>arr[max])
        max=right;
    if(max!=i){
        swap(&arr[max],&arr[i]);
        max_heapify(arr,max,n);
    }
}

void build_max_heap(int arr[],int n){
    for(int i=n/2;i>=1;i--){
        non_recursive_max_heapify(arr,i,n);
        // max_heapify(arr,i,n);
    }
}

void recursive_heap_sort(int arr[],int n){
    if(n==Initial_size){
        build_max_heap(arr,n);
    }
    if(n>1){
        swap(&arr[1],&arr[n]);
        n--;
        max_heapify(arr,1,n);
        recursive_heap_sort(arr,n);
    }
}
// iterative heap sort
void heap_sort(int arr[],int n){
    build_max_heap(arr,n);
    while(n>1){
        swap(&arr[1],&arr[n]);
        n--;
        max_heapify(arr,1,n);
    }
}

int main(){
    int n;
	printf("Enter No of elements: ");
    scanf("%d",&n);
    Initial_size=n; // used for recursive 'heap_sort' function
	int arr[n+1];
    printf("Enter %d elements: ",n);
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	printf("Before sorting\n-> ");
	for(int i=1;i<=n;i++){
		printf("%d " ,arr[i]);
	}
	// recursive_heap_sort(arr,n);
    heap_sort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=1;i<=n;i++){
		printf("%d " ,arr[i]);
	}
}