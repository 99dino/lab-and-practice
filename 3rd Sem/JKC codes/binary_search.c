#include<stdio.h>

int main(){
    printf("Enter no od elements in an array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k,loc=-1;
    printf("enter no to search in the given array\n-> ");
    scanf("%d",&k);
    int beg=0,end=n-1;
    while(beg<=end){
        int mid=(beg+end)/2;
        if(a[mid]==k){
            loc=mid;
            break;
        }
        else if(a[mid]<k){
            beg=mid+1;
        }
        else{end=mid-1;}
    }
    if(loc!=-1){
        printf("found at index %d\n",loc+1);
    }
    else{
        printf("not found");
    }
    return 0;
}