#include<stdio.h>

struct item{
    int value;int weight; double ratio;
}typedef item;

void swap(item *a,item *b){
    item temp=*a;
    *a=*b;
    *b=temp;
}

int min(int a,int b){
    return (a>b?b:a);
}

void min_heapify(item arr[],int i,int n){
    int min=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left].ratio<arr[min].ratio)
        min=left;
    if(right<=n && arr[right].ratio<arr[min].ratio)
        min=right;
    if(min!=i){
        swap(&arr[min],&arr[i]);
        min_heapify(arr,min,n);
    }
}

void build_max_heap(item arr[],int n){
    for(int i=n/2;i>=1;i--){
        min_heapify(arr,i,n);
        // min_heapify(arr,i,n);
    }
}

void heap_sort(item arr[],int n){
    build_max_heap(arr,n);
    while(n>1){
        swap(&arr[1],&arr[n]);
        n--;
        min_heapify(arr,1,n);
    }
}

int main(){
    printf("Enter no of items: ");
    int n,w,ind=1;
    double ans=0;
    scanf("%d",&n);
    printf("Enter total capacity of Knapsack: ");
    scanf("%d",&w);
    item arr[n+1];
    // applying heap sort which is working on index  1 to n
    printf("Enter {weight,value} pair\n");
    for(int i=1;i<=n;i++){
        scanf("%d%d",&arr[i].weight,&arr[i].value);
        arr[i].ratio=(double)arr[i].value/(double)arr[i].weight;
    }
    heap_sort(arr,n);
    // for(int i=1;i<=n;i++){
    //     printf("{%d,",arr[i].weight);
    //     printf("%d,",arr[i].value);
    //     printf("%f}",arr[i].ratio);
    // }
    while(w>0&&ind<=n){
        ans+=min(w,arr[ind].weight)*arr[ind].ratio;
        w-=min(w,arr[ind].weight);
        ind++;
    }
    printf("Total value that can be collected: %lf",ans);
}