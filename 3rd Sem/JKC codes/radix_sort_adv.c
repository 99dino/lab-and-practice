#include<stdio.h>
#include<limits.h>
void counting_sort(int a[],int n,int div){
    int count[10];
    for(int i=0;i<10;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[(a[i]/div)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    int sort_arr[n];
    for(int i=n-1;i>=0;i--){
        sort_arr[count[(a[i]/div)%10]-1]=a[i];
        count[(a[i]/div)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=sort_arr[i];
    }
}

void radix_sort(int a[],int n){
    int neg_size=0,pos_size=0;
    int max_neg=INT_MAX,max_pos=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            neg_size++;
            if(a[i]<max_neg)
                max_neg=a[i];
        }
        else{
            pos_size++;
            if(a[i]>max_pos)
                max_pos=a[i];
        }
    }
    max_neg*=-1;
    int neg[neg_size],pos[pos_size];
    // traversing -ve elements in such a way that results in stable sort
    for(int i=0,po=0,ne=neg_size-1;i<n;i++){
        if(a[i]<0){
            neg[ne--]=-a[i];
            // changing -ve elements to +ve 
        }
        else{
            pos[po++]=a[i];
        }
    }
    // if -ve elements exists/ applying radix sort on those -ve elements
    if(neg_size){
        for(int i=1;i<max_neg/i;i*=10){
            counting_sort(neg,neg_size,i);
        }
    }
    if(pos_size){
        for(int i=1;0<(max_pos)/i;i*=10){
            counting_sort(pos,pos_size,i);
        }
    }
    // copying back in the original array
    for(int i=0,po=0,ne=neg_size-1;i<n;i++){
        if(ne>-1)
            a[i]=-neg[ne--];
        else
            a[i]=pos[po++];
    }
}

int main(){
    // this version supports +ve & -ve values
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
	radix_sort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%d " ,arr[i]);
	}
}