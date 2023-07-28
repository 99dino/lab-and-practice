#include<stdio.h>
int N;

void Create(int a[],int *size){
    if(*size!=0){
        printf("Queue already exist. Use Push Operation.\n");return;
    }
    int x;printf("Enter no of elements -> ");scanf("%d",&x);
    if(x>N){
        printf("Maximum Size of the Queue is %d.\n",N);
        return;
    }
    printf("Enter %d elements.\n",x);
    while(x--){
        scanf("%d",&a[(*size)++]);
    }
}

int Isfull(int size){
    if(size>=N){
        // printf("\nQueue is Full.\n");
        return 1;
    }
    else{
        // printf("\nQueue is not Full.\n");
        return 0;
    }
}

int Isempty(int size){
    if(size==0){
        // printf("\nQueue is Empty.\n");
        return 1;
    }
    else{
        // printf("\nQueue is not Empty.\n");
        return 0;
    }
}

void Insert(int a[],int *size,int *top){
    if(!Isfull(*size)){
        printf("Enter a element -> ");
        scanf("%d",&a[(*top+*size)%N]);
        (*size)++;
    }
    else
        printf("Queue is Full.\n");
}

void Delete(int a[],int* size,int* top){
    if(!Isempty(*size)){
        printf("\nPopped element is %d.\n",a[(*top)%N]);
        (*top)++;(*size)--;(*top)=(*top)%N;
    }
    else
        printf("Queue is Empty.\n");
}

void Display(int a[],int top,int size){
    if(size==0){
        printf("\nQueue is Empty.\n");
    }
    for(int i=0;i<size;i++)
        printf("%d ",a[(top+i)%N]);
    printf("\n");
}

int main(){

    printf("Set the maximum size of Queue-> ");
    scanf("%d",&N);int a[N];
    int size=0,top=0,b;

    do{
        printf("\nVarious Queue Operations are :\n0.Stop\n1.Create()\n2.IsEmpty()\n3.Insert()\n4.Delete()\n5.IsFull()\n6.Display\n-> ");
        scanf("%d",&b);
        switch(b){
            case 1:
                Create(a,&size);break;
            case 2:
                if(Isempty(size))
                    printf("\nQueue is Empty.\n");
                else
                    printf("\nQueue is Not Empty.\n");
                break;
            case 3:
                Insert(a,&size,&top);break;
            case 4:
                Delete(a,&size,&top);break;
            case 5:
                if(Isfull(size))
                    printf("\nQueue is Full.\n");
                else
                    printf("\nQueue is Not Full.\n");
                break;
            case 6:
                Display(a,top,size);break;
            default:
                if(b!=0){printf("Invalid option\n");}
        }
    }while(b);
    printf("TAATAA!!");

    return 0;
}
