#include <stdio.h>
#include <limits.h>
void bucket_sort(float arr[], int n)
{
    // assumes input is randomly uniformly distributed
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>mx)
            mx=arr[i];
    }

    float bucket[n][n];
    int ind = 0;
    // to keep record of size of each bucket
    int top[n];

    for(int i=0;i<n;i++){
        top[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        // bucket no is calculated as below
        int bucket_no = n*arr[i]/(mx + 1);
        int j=top[bucket_no];
        // inserted in sorted manner
        while(j>-1 && bucket[bucket_no][j]>arr[i]){
            bucket[bucket_no][j + 1] = bucket[bucket_no][j];
            j--;
        }
        bucket[bucket_no][j + 1] = arr[i];
        top[bucket_no]++;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= top[i]; j++){
            arr[ind++] = bucket[i][j];
        }
    }
}

int main(){
    int n;
	printf("Enter No of elements: ");
    scanf("%d",&n);
	float arr[n];
    printf("Enter %d elements: ",n);
	for(int i=0;i<n;i++){
		scanf("%f",arr+i);
	}
	printf("Before sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%f " ,arr[i]);
	}
	bucket_sort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%f " ,arr[i]);
	}
}