#include<stdio.h>
int N;

int overflow(int top,int bottom){
    if(top>=bottom){
        return 1;
        // printf("Stack Overflow.\n");
    }
    else{
        return 0;
        // printf("Stack is not Overflow.\n");
    }
}

int underflow(int top,int bottom){
    if(top<0||bottom>N-1)
        return 1;
    else
        return 0;
}

void push(int a[],int i,int* top,int* bottom){
    if(i==1){
        if(!overflow(*top,*bottom))
            printf("Enter a element-> "),scanf("%d",&a[++(*top)]);
        else
            printf("Stack Overflow.\n");
    }
    else{
        if(!overflow(*top,*bottom))
            printf("Enter a element-> "),scanf("%d",&a[--(*bottom)]);
        else
            printf("Stack Overflow.\n");
    }
}


void pop(int a[],int i,int* top,int* bottom){
    if(i==1){
        if(!underflow(*top,N-1))
            printf("Popped element is %d.\n",a[(*top)--]);
        else
            printf("Stack underflow.\n");
    }
    else{
        if(!underflow(0,*bottom))
            printf("Popped element is %d.\n",a[(*bottom)++]);
        else
            printf("Stack underflow.\n");

    }
}

void display(int a[],int top,int bottom){
    printf("|");
    for(int i=0;i<=top;i++){
        printf("%d ",a[i]);
    }
    for(int i=top+1;i<bottom;i++){
        printf(" - ");
    }
    for(int i=bottom;i<N;i++){
        printf("%d ",a[i]);
    }
    printf("|\n");
}

int main(){
    printf("SET THE MAXIMUM SIZE OF STACK -> ");scanf("%d",&N);
    int stack[N];
    // int stack2[N];
    int top=-1,bottom=N,a,x;
    do{
        printf("0.STOP\n1.Push\n2.Pop\n3.Display\n-> ");
        scanf("%d",&a);
        if(a==1||a==2){
            printf("\nChoose stack\n1.Front Stack\n2.Rear Stack\n");scanf("%d",&x);
        }
        switch(a){
            case 1:
                push(stack,x,&top,&bottom);break;
            case 2:
                pop(stack,x,&top,&bottom);break;
            case 3:
                display(stack,top,bottom);break;
            default:
                if(a!=0){printf("Invalid Option.\n");}
        }
    }while(a);

}