#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

typedef struct link_list{
    float data;
    struct link_list* next;
}link_list;

void bucket_sort(float arr[],int n)
{
    int mx = INT_MIN,index=0;
    for (int i=0;i<n;i++){
        if (arr[i]>mx)
            mx = arr[i];
    }
    link_list* list[n];
    for(int i=0;i<n;i++){
        list[i]=NULL;
    }

    for(int i=0;i<n;i++){
        int bucket_no=n*arr[i]/(mx+1);
        link_list* temp=(link_list*)malloc(sizeof(link_list));
        temp->data=arr[i];
        temp->next=NULL;
        if(list[bucket_no]==NULL){
            list[bucket_no]=temp;
        }
        else{
            link_list* temp1=list[bucket_no];
            if(arr[i]<temp1->data){
                temp->next=temp1;
                list[bucket_no]=temp;
            }
            else{
                while(temp1->next!=NULL&&temp1->next->data<arr[i]){
                    temp1=temp1->next;
                }
                temp->next=temp1->next;
                temp1->next=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        link_list* temp=list[i];
        while(temp){
            arr[index++]=temp->data;
            // printf("%d ",temp->data);
            temp=temp->next;
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
		printf("%.2f " ,arr[i]);
	}
	bucket_sort(arr,n);
	printf("\nAfter sorting\n-> ");
	for(int i=0;i<n;i++){
		printf("%.2f " ,arr[i]);
	}
}