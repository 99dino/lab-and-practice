#include <stdio.h>

void counting_sort_beg(int arr[],int n){
    int mx=0,temp,start=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mx)
            mx=arr[i];
    }
    int count[mx+1];
    for(int i=0;i<=mx;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    // cummulative starting index
    for(int i=0;i<=mx;i++){
        temp=count[i];
        count[i]=start;
        start+=temp;
    }
    int sort_arr[n];
    for(int i=n-1;i>=0;i--){
        sort_arr[count[arr[i]]]=arr[i];
        count[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        arr[i]=sort_arr[i];
    }
}

void counting_sort_end(int arr[],int n){
    int mx=0;
    // finding max element
    for(int i=0;i<n;i++){
        if(arr[i]>mx)
            mx=arr[i];
    }
    // declaring frequency array
    int count[mx+1];
    // initialising it with 0
    for(int i=0;i<=mx;i++){
        count[i]=0;
    }
    // counting the frequency
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    // cummulative sum
    for(int i=1;i<=mx;i++){
        count[i]+=count[i-1];
    }
    // for(int i=0;i<n;i++){printf("%d ",count[i]);}printf("\n");
    // declaring the final sorted array
    int sort_arr[n];
    // started from last index to make it stable
    for(int i=n-1;i>=0;i--){
        // pasting number to its corresponding index
        sort_arr[count[arr[i]]-1]=arr[i];
        // and decrementing index
        count[arr[i]]--;
    }
    // copying back the sorted array in the original array
    for(int i=0;i<n;i++){
        arr[i]=sort_arr[i];
    }
}

int main(){
    // this version supports only +ve and small values(approx 10e5)
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
	counting_sort_beg(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}