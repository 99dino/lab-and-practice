#include<stdio.h>
const int N;
void Create(int a[],int* top){
    if(*top!=-1){
        printf("Stack already exist. Use Push Operation.\n");return;
    }
    int x;printf("No of elements to enter in a stack -> ");
    scanf("%d",&x);
    if(x>N){
        printf("Maximum Size of the stack is %d.\n",N);
        return;
    }
    printf("Enter %d elements.\n-> ",x);
    while(x--){
        (*top)++;
        scanf("%d",&a[*top]);
    }
}

int Isfull(int top){
    if(top>=N){
        printf("\nStack is Full.\n");return 1;
    }
    else{
        printf("\nStack is not Full.\n");return 0;
    }
}

int Isempty(int top){
    if(top==-1){
        printf("\nStack is Empty.\n");return 1;
    }
    else{
        printf("\nStack is not Empty.\n");return 0;
    }
}

void Push(int a[],int* top){
    if(Isfull(*top))
        return;
    printf("Enter a element -> ");(*top)++;
    scanf("%d",&a[*top]);
}

void Pop(int a[],int* top){
    if(Isempty(*top))
        return;
    printf("\nPopped element is %d.\n",a[*top]);
    (*top)--;
}



void Display(int a[N],int top){
    if(top==-1){
        printf("\nStack is Empty.\n");
    }
    for(int i=0;i<=top;i++)
        printf("%d ",a[i]);
    printf("\n");
}


int main(){
    printf("Set the maximum size of stack!! -> ");
    scanf("%d",&N);
    int a[N],top=-1,b;
    do{
        printf("\nVarious Stack Operations are :\n0.Stop\n1.Create()\n2.IsEmpty()\n3.Push()\n4.Pop()\n5.IsFull()\n6.Display\n-> ");
        scanf("%d",&b);
        switch(b){
            case 1:
                Create(a,&top);break;
            case 2:
                Isempty(top);break;
            case 3:
                Push(a,&top);break;
            case 4:
                Pop(a,&top);break;
            case 5:
                Isfull(top);break;
            case 6:
                Display(a,top);break;
            default:
                if(b!=0){printf("Invalid option\n");}
        }
    }while(b);
    printf("TAATAA!!");
    // getch();

}