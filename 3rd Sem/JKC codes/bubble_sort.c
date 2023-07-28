#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int arr[],int n){
	for(int i=0;i<n;i++){
        // tarversing upto n-i-1 in ith pass
        // as last i elements gets correctly placed already
		for(int j=0;j<n-i;j++){
			if(arr[j]>arr[j+1]){
                // comparing neighbours
                // swapping if not in correct order 
				swap(&arr[j],&arr[j+1]);
			}
		}
        // after each pass, elements placed correctly from the end
	}
}

void bubble_sort_improvised(int arr[],int n){
	for(int i=0;i<n;i++){
		int flag=1;
		for(int j=0;j<n-i;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				// if swapping done - ok, else break
				flag=0;
			}
		}
		if(flag==1)
			break;
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
	bubble_sort_improvised(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}